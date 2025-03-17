#include "widget.h"

#include <QApplication>
#include <QHotkey>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget w;

    QHotkey hotkey(QKeySequence("Ctrl+Alt+A"),true,&app);
    qDebug() << "Is segistered:" << hotkey.isRegistered();
    QObject::connect(&hotkey,&QHotkey::activated,&w,&Widget::onCtrlAltA);

    w.show();
    return app.exec();
}
//只要项目没有关闭，则全局可用快捷键
