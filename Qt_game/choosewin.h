#ifndef CHOOSEWIN_H
#define CHOOSEWIN_H

#include <QMainWindow>
#include<QVector>
#include<QSound>
#include"mainplaywin.h"
#include"caption.h"
#include"mybtn.h"

class chooseWin : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseWin(QWidget *parent = nullptr);
       void paintEvent(QPaintEvent *event);
       Mainplaywin * play = NULL; // 创建 游戏主窗口
       caption* cp = nullptr;

       int capcity = 0;  //  一共过了几关

       QVector<mybtn*> choosearr;  // 存储20个 关卡入口
       QVector<Mainplaywin*> playarr; // 存储20个关卡
signals:
        void backwindow(); // 点击 back 按钮 则 发送 信号 , 关闭选关界面, 重现开始 页面
public slots:
};

#endif // CHOOSEWIN_H
