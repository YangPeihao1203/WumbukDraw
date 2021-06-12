#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int width,int height,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("WumDraw画板");

}

MainWindow::~MainWindow()
{
    delete ui;
}
