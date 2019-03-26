#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDateEdit>
#include <QLabel>
QDate now_date=QDate::currentDate();
QDate before_date;
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setDisplayFormat(tr("yyyy-MM-dd"));
    QDate now_date;
    now_date=QDate::currentDate();
   this->setObjectName("dialog");
   this->setStyleSheet("QDialog#dialog{border-image:url(dlgback.png)}");
}

MyDialog::~MyDialog()
{
    delete ui;
}
int MyDialog::calculate_days()
{
    int dd;

    switch (now_date.month())
    {
    case 1:dd = now_date.day(); break;
    case 2:dd = 31 + now_date.day(); break;
    case 3:dd = 31 + 28 + now_date.day(); break;
    case 4:dd = 31 + 28 + 31 + now_date.day(); break;
    case 5:dd = 31 + 28 + 31 + 30 + now_date.day(); break;
    case 6:dd = 31 + 28 + 31 + 30 + 31 + now_date.day(); break;
    case 7:dd = 31 + 28 + 31 + 30 + 31 + 30 + now_date.day(); break;
    case 8:dd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + now_date.day(); break;
    case 9:dd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + now_date.day(); break;
    case 10:dd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + now_date.day(); break;
    case 11:dd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + now_date.day(); break;
    case 12:dd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + now_date.day(); break;
    default:
        break;
    }
    if (now_date.month()>2) { if (now_date.year() % 4 == 0 && now_date.year() % 100 != 0 || now_date.year() % 400 == 0) { dd++; } }
    return dd;
}
void MyDialog::on_dateEdit_dateChanged(const QDate &date)
{
    before_date=ui->dateEdit->date();
        switch (before_date.month())
        {
        case 1:cd = before_date.day(); break;
        case 2:cd = 31 + before_date.day(); break;
        case 3:cd = 31 + 28 + before_date.day(); break;
        case 4:cd = 31 + 28 + 31 + before_date.day(); break;
        case 5:cd = 31 + 28 + 31 + 30 + before_date.day(); break;
        case 6:cd = 31 + 28 + 31 + 30 + 31 + before_date.day(); break;
        case 7:cd = 31 + 28 + 31 + 30 + 31 + 30 + before_date.day(); break;
        case 8:cd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + before_date.day(); break;
        case 9:cd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + before_date.day(); break;
        case 10:cd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + before_date.day(); break;
        case 11:cd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + before_date.day(); break;
        case 12:cd = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + before_date.day(); break;
        default:
            break;
        }
        if (before_date.month()>2) { if (before_date.year() % 4 == 0 && before_date.year() % 100 != 0 || before_date.year() % 400 == 0) { cd++; } }
}

void MyDialog::on_pushButton_clicked()
{
    if (now_date.year()== before_date.year())//同一年
    {
        if ((calculate_days() - cd < 0))
        {
            ui->label_2->setText(tr("请输入正确的日期"));
        }
        else
           ui->label_2->setText(tr("我们已经")+QString::number(calculate_days() - cd +1)+tr("天了"));
    }
    else if (now_date.year() > before_date.year())//一年以上
    {
        int midday = 0, forwardday, backday;
        if (before_date.year() % 4 == 0 && before_date.year() % 100 != 0 || before_date.year() % 400 == 0)
        {
            forwardday = 366 - cd;
        }
        else
        {
            forwardday = 365 - cd;
        }

        backday = calculate_days();
        for (int i = before_date.year() + 1; i < now_date.year(); i++)
        {
            if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            {
                midday += 366;
            }
            else
            {
                midday += 365;
            }
        }

        //(now_date.month()==before_date.month())&&(now_date.day()==before_date.day())

        ui->label_2->setText( tr("我们已经") +QString::number(forwardday + midday + backday+1)+ tr("天了"));
        if((now_date.month()==before_date.month())&&(now_date.day()==before_date.day()))
        {
            ui->label_2->setText( tr("我们已经在一起一年了\n一周年快乐\n"));
        }
    }
    else if(now_date.year() < before_date.year())
    {
        ui->label_2->setText( tr("日期错误"));
    }
}
