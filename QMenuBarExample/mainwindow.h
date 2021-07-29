#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_blue_triggered();

    void on_action_red_triggered();

    void on_action_green_triggered();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
