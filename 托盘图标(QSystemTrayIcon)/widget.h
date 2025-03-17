#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    QSystemTrayIcon *SysIcon;
    QAction *min; // 最小化
    QAction *max; // 最大化
    QAction *restor; // 恢复
    QAction *quit; // 退出
    QMenu *menu;

    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

public slots:
    void onCtrlAltA();
};
#endif // WIDGET_H
