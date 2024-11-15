#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QString("The info about the system will be here soon!"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
