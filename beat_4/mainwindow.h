#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"
namespace Ui {
class MainWindow;
}
class QSoundEffect;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MyDialog *dialog;
    ~MainWindow();

private slots:
    void on_mainbutton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QSoundEffect *effect;
};

#endif // MAINWINDOW_H
