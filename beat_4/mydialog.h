#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    int calculate_days();
    int cd;
    ~MyDialog();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
