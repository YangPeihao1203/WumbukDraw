#include "mainwindow.h"
#include "ui_mainwindow.h"

//单例模式一定要给静态变量申请一个内存，在类内声明，在类外定义
MainWindow* MainWindow::instance=nullptr;
/**
 * @brief MainWindow::MainWindow
 * @param width
 * @param height
 * @param parent
 * 构造函数，设置应用名、图标，大小，确定setScene、状态栏设定、信号处理绑定
 */
MainWindow::MainWindow(int width,int height,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //设置窗口样式相关操作
    ui->setupUi(this);
    setWindowTitle("WumDraw画板");
    int poorHeight=ui->menuBar->height()+ui->statusBar->height()+iconSize().height();   //画布与显示器高度的差
    setFixedSize(width,height-poorHeight);
    setWindowIcon(QIcon(":/new/logo.png"));
    ui->dockWidget->setContentsMargins(0,0,0,0);
    ui->scrollArea->setFixedSize(width-ui->dockWidget->width(),height-poorHeight-50);
    _mainPaintScene=new MainPaintScene(ui->graphicsView);
    ui->graphicsView->setScene(_mainPaintScene);
    ui->graphicsView->centerOn(0,0);
    //状态栏
    sBarPermanent=statusBar();
    sBarPermanent->addPermanentWidget(new QLabel("Drawing Board",this));
    sBarTemporary=statusBar();
    sBarTemporary->showMessage("PenType:Pencil;Shape:DEFAULT",SHOW_MESSAGE_TIME);
    _utility=new Utility;
    //设置两个颜色选择按钮的默认颜色，其中画笔颜色为黑色、背景颜色为白色
    ui->pushButtonColor->setStyleSheet("background-color: rgb(0, 0, 0);");
    ui->pushButtonBackgroundColor->setStyleSheet("background-color: rgb(255, 255, 255);");
    //连接信号与接收信号的对象
    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),
          _mainPaintScene, SLOT(setCurrentShape(Shape::Code)));
}


/**
 * @brief MainWindow::~MainWindow
 * 析构函数
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete sBarPermanent;
}









void MainWindow::saveFile()
{
//    if(filePath.endsWith(".svg")){
//        tool->saveSvg(filePath);
//    }
//    else{
//        tool->savePngOrJpg(filePath);
//    }

}








/**
 * @brief MainWindow::on_actionNew_triggered
 * 新建窗口，保留
 */
void MainWindow::on_actionNew_triggered()
{
    QMessageBox *messageBox=new QMessageBox(this);
    messageBox->setIcon(QMessageBox::Warning);
    messageBox->setWindowTitle("确认");
    messageBox->setText("新建画板将清空当前画板，是否确认新建？");
    messageBox->addButton("取消",QMessageBox::RejectRole);
    messageBox->addButton("确定",QMessageBox::AcceptRole);
}


//读取文件功能暂未完成
void MainWindow::on_actionOpen_triggered()
{
}

void MainWindow::on_actionSave_triggered()
{
    //通过对话框让用户进行选择
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image","",
                                            "PNG (*.png);;JPEG (*.jpg *.jpeg);"
                                            ";SVG files (*.svg);;All files (*.*)");
    if (filePath == "")
        return;
    //直接调用工具类的方法
    _utility->saveFile(filePath,this->_mainPaintScene);
}

void MainWindow::on_actionSaveToEdit_triggered()
{
    QString filePath=QFileDialog::getSaveFileName(this,"Save Image","",
                                          "PNG (*.png);;JPEG(*.jpg *.jpeg);"
                                          ";SVG files (*.svg);;All files (*.*)");
    if (filePath=="")
        return;
    _utility->saveFileToEdit(filePath,this->_mainPaintScene);
}





void MainWindow::on_pushButtonPen_clicked()
{

}

void MainWindow::on_pushButtonEraser_clicked()
{

}



void MainWindow::on_actionUndo_triggered()
{
    qDebug("MainWindow::on_actionUndo_triggered");
    sBarTemporary=statusBar();
    sBarTemporary->showMessage("撤销",SHOW_MESSAGE_TIME);
    _mainPaintScene->callback();
}

void MainWindow::on_actionReform_triggered()
{
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"I know","Wumbukh著作...");
}




void MainWindow::on_insertImg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,tr("Open Image"),
                                                   ".",tr("Image Files (*.png *.jpg *.bmp *.gif)"));
    Gif *image=new Gif;
    if (fileName.endsWith(".png")||fileName.endsWith("image")){
       StaticImage *image=new StaticImage;
    }

    this->_mainPaintScene->_currItem=image;
    this->_mainPaintScene->addItem(image);
    this->_mainPaintScene->_shapeList.push_back(image);
    image->inSertPicture(fileName,this->_mainPaintScene);
}


void MainWindow::on_pushButtonColor_clicked()
{
   QColor color= QColorDialog::getColor(Qt::black,this,"调色板");
   if(color.isValid()==false) //设置调色盘选择cancel时的颜色
        color=this->_mainPaintScene->_color;
     this->_mainPaintScene->setColor(color);
   this->_mainPaintScene->_color=color;
   QString style=_utility->cssFromColor(color);
   ui->pushButtonColor->setStyleSheet(style);
}

void MainWindow::on_pushButtonBackgroundColor_clicked()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"调色板");
    if(color.isValid()==false) //设置调色盘选择cancel时的颜色
        color=ui->pushButtonBackgroundColor->palette().color(QPalette::Background);
    this->_mainPaintScene->setBackgroundBrush(QBrush(color));
    QString style=_utility->cssFromColor(color);
    ui->pushButtonBackgroundColor->setStyleSheet(style);
}

void MainWindow::on_SliderWidth_valueChanged(int value)
{

    qDebug("MainWindow::on_SliderWidth_valueChanged");
    qDebug("%d",value);
    this->_mainPaintScene->_width=value;
}
void MainWindow::on_textButton_clicked()
{
    emit changeCurrentShape(Shape::Text);
}

void MainWindow::on_pushButtonPenPath_clicked()
{
    emit changeCurrentShape(Shape::PenPath);
}

void MainWindow::on_pushButtonLine_clicked()
{
    emit changeCurrentShape(Shape::Line);
}

void MainWindow::on_pushButtonRect_clicked()
{
    emit changeCurrentShape(Shape::Rect);
}

void MainWindow::on_pushButtonCircle_clicked()
{
    emit changeCurrentShape(Shape::Circular);
}

void MainWindow::on_pushButtonEllipse_clicked()
{
    emit changeCurrentShape(Shape::Ellipse);
}


//设置字体是否加粗
void MainWindow::on_pushButtonTextBold_clicked()
{
    this->_mainPaintScene->_isTextBold=!this->_mainPaintScene->_isTextBold;
    if (this->_mainPaintScene->_isTextBold){
        sBarTemporary=statusBar();
        sBarTemporary->showMessage("字体加粗",SHOW_MESSAGE_TIME);
    }
    else{
        sBarTemporary=statusBar();
        sBarTemporary->showMessage("取消字体加粗",SHOW_MESSAGE_TIME);
    }
}

//设置字体是否倾斜
void MainWindow::on_pushButtonTextItatic_clicked()
{
    this->_mainPaintScene->_isTextItatic=!this->_mainPaintScene->_isTextItatic;
    if (this->_mainPaintScene->_isTextItatic){
        sBarTemporary=statusBar();
        sBarTemporary->showMessage("字体倾斜",SHOW_MESSAGE_TIME);
    }
    else{
        sBarTemporary=statusBar();
        sBarTemporary->showMessage("取消字体倾斜",SHOW_MESSAGE_TIME);
    }
}
//设置字体的大小
void MainWindow::on_textSize_actionTriggered(int val)
{
    this->_mainPaintScene->_textSize=val*TEXT_STEP;
        sBarTemporary=statusBar();
        sBarTemporary->showMessage("字号更新",SHOW_MESSAGE_TIME);
}

/**
 * @brief MainWindow::on_actionNoRegretMode_triggered
 * 无后悔药模式，这是一个观察者模式
 */
void MainWindow::on_actionNoRegretMode_triggered()
{

}
