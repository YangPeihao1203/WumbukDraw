#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    QDesktopWidget *desktopWidget=a.desktop();
    QRect screenRect =desktopWidget->screenGeometry();
    int width=screenRect.width();
    int height=screenRect.height();
    MainWindow *w= MainWindow::getMainWindow(width,height);
    w->move(-10,0);
    w->show();
    return a.exec();
	
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return a.exec();

}
