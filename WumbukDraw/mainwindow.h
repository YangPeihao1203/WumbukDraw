#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPixmap>
#include<QPainter>
#include<QMouseEvent>
#include<QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include<QColorDialog>
#include "MainPaintScene.h"
#include "Shape.h"
#include "circular.h"
#include "image.h"
#include "QDebug"
#include"staticimage.h"
#include "gif.h"
#include "utility.h"

#define SHOW_MESSAGE_TIME 3000   //消息显示时间
#define DOCK_WIDGET_WIDTH 160    //左侧组件的宽度
#define DEFAULT_WIDTH 1000      //默认的窗口宽度
#define DEFAULT_HEIGHT 700      //默认的窗口高度

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    //该宏表示该类要使用信号与槽机制
    Q_OBJECT
public:
    ~MainWindow();
    //静态方法，获取该单例模式下的唯一对象
    static MainWindow* getMainWindow(int width=DEFAULT_WIDTH,
                                     int height=DEFAULT_HEIGHT,
                                     QWidget *parent = 0){
        if(instance==nullptr){
            instance=new MainWindow(width,height);
        }
        return instance;
    }

protected:
    void saveFile();


//信号
signals:
    //改变当前的画笔形状
    void changeCurrentShape(Shape::Code);

//下面这我先不往那个类里面放
private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveToEdit_triggered();
    void on_pushButtonColor_clicked();
    void on_pushButtonBackgroundColor_clicked();
    void on_SliderWidth_valueChanged(int value);
    void on_pushButtonPen_clicked();
    void on_pushButtonEraser_clicked();
    void on_actionUndo_triggered();
    void on_actionReform_triggered();
    void on_actionAbout_triggered();
    void on_insertImg_clicked();
    void on_textButton_clicked();
    void on_pushButtonPenPath_clicked();
    void on_pushButtonLine_clicked();
    void on_pushButtonRect_clicked();
    void on_pushButtonCircle_clicked();
    void on_pushButtonEllipse_clicked();
    void on_pushButtonTextBold_clicked();
    void on_pushButtonTextItatic_clicked();
    void on_textSize_actionTriggered(int action);
    void on_actionNoRegretMode_triggered();






private:
    //将构造方法声明为私有，是为了实现单例模式
    explicit MainWindow(int width=DEFAULT_WIDTH,int height=DEFAULT_HEIGHT,QWidget *parent = 0);
    //指向Ui::MainWindow的指针
    Ui::MainWindow *ui;
    //静态变量，MainWindow的单一实例，为了实现单例模式
    static MainWindow* instance;
    MainPaintScene *_mainPaintScene;
    Utility *_utility;
    //状态栏信息
    QStatusBar *sBarPermanent;
    QStatusBar *sBarTemporary;

};

#endif // MAINWINDOW_H
