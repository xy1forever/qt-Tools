#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    menu = new QMenu(this);
    QIcon icon(":/asserts/window-icon.png");
    SysIcon = new QSystemTrayIcon(this);
    SysIcon->setIcon(icon);
    SysIcon->setToolTip("Qt托盘");

    min = new QAction("窗口最小化", this);
    connect(min,&QAction::triggered,this,&Widget::hide);
    max = new QAction("窗口最大化", this);
    connect(max,&QAction::triggered,this,&Widget::showMaximized);
    restor = new QAction("恢复原来的样子", this);
    connect(restor, &QAction::triggered, this, &Widget::showNormal);
    quit = new QAction("退出", this);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    menu->addAction(min);
    menu->addAction(max);
    menu->addAction(restor);
    menu->addSeparator();
    menu->addAction(quit);

    SysIcon->setContextMenu(menu);
    SysIcon->show();

    connect(SysIcon, &QSystemTrayIcon::activated, this, &Widget::on_activatedSysTrayIcon);

    close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    if(SysIcon->isVisible()){
        hide();
        SysIcon->showMessage("Qt托盘", "程序已最小化到托盘");
        event->ignore();
    }
    else{
        qDebug() << "111";
        event->accept();
    }
}


void Widget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::DoubleClick:
        show();
        break;
    default:
        break;
    }
}





void Widget::onCtrlAltA()
{
    qDebug()<<"333";
}

