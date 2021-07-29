#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

private slots:
    void critical_new_slot();
    void warning_new_slot();
    void information_new_slot();
    void question_new_slot();
    void ozel_kullanim_slot();
private:
    Ui::MainWindow *ui;
    void new_connect();

};
#endif // MAINWINDOW_H
