#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "action_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    lineedits_t *les = new lineedits_t;
    params_t *params = new params_t;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
