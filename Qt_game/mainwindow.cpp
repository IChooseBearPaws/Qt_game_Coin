#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>
#include<QPushButton>
#include<mybtn.h>
#include<QWidget>
#include<QDebug>
#include<QTimer>
#include<QFileDialog>
#include<QFile>
#include<QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //窗口大小 固定
    this ->setFixedSize(400, 650);

    //菜单退出
    connect(ui ->actiontuichu,&QAction::triggered, [=] () {
        this -> close();
    });

    //创建音效
    QSound* s = new QSound(":/coinfiles/start.wav");

    //背景音效
    QSound* wel = new QSound(":/coinfiles/wel.wav");
    wel ->play();

    //菜单说明
    connect(ui ->caption, &QAction::triggered, [=] () {
        cap = new caption();
        cap ->resize(400, 650);
        cap ->show();
    });

    //标题
    this ->setWindowTitle("coinGames");

    //软件图标
    this ->setWindowIcon(QIcon(":/coinfiles/Coin0001.png"));

    //设置 开始按钮图标
    mybtn * starebtn = new mybtn(":/coinfiles/MenuSceneStartButton.png");
    starebtn ->setParent(this);
    starebtn ->move(150, this ->height() - starebtn->height() * 2 );


    //点击按钮跳转 窗口 到选关窗口
    connect(starebtn,&mybtn::clicked,[=] () {
        starebtn->uper();
        wel ->stop();
        s ->play();
        starebtn->down();
        //延时进入 选关界面
        QTimer::singleShot(500,this, [=] () {
            win = new chooseWin();
            win ->capcity = size;
            this ->hide();
            win -> setFixedSize(400, 650);
            win->show();                      

            //接收 由choosewindow 发送过来的信号 实现 开始窗口重现, 选择窗口关闭
            connect(win, &chooseWin::backwindow, [=] () {
                wel ->play();
                QTimer ::singleShot(200, this, [=] () {
                    size = win ->capcity;
                    win -> hide();
                    this -> show();
                });
            });
        });
    });
}


//主背景设置
void MainWindow::paintEvent(QPaintEvent *event) {
    QPixmap pix;
    QPainter pain (this);
    pix.load(":/coinfiles/MenuSceneBg.png");
    pain.drawPixmap(0,0,this->width(), this->height(), pix);
}


MainWindow::~MainWindow()
{
    delete ui;
}
