#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void buton_bas_1();
    void buton_bas_2();
    void buton_bas_3();



private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void label_bas_1();
    void label_bas_2();
    void label_bas_3();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
