#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(720,30,275,250);
    settingBg(571 , 301);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg(int x_start , int y_end)
{
    QImage bg;
    bg.load(":/image/img/25037_86336831AB1B4E321F95_1.jpeg");
    bg = bg.scaled(x_start,y_end);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init(x_start);
}
