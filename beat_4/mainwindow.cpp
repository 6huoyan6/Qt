#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QFileInfo>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("love.ico"));
    setWindowTitle(tr("For My Honey"));
    effect=new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile("./zmql.wav"));
    effect->setVolume(0.25f);
    effect->play();
//    QFileInfo fileInfo("./zmql.wav");
//    if (fileInfo.exists()) { //if exists
//        qDebug()<<fileInfo.size(); //return size
//        qDebug()<<fileInfo.path(); // return "/home/hebbe"
//        qDebug()<<fileInfo.filePath(); //return "/home/hebbe/xyz.tar.gz"
//        qDebug()<<fileInfo.fileName(); // return "xyz.tar.gz"
//        qDebug()<<fileInfo.baseName(); // return "xyz"
//        qDebug()<<fileInfo.completeBaseName(); // return "xyz.tar"
//        qDebug()<<fileInfo.suffix(); // return "gz"
//        qDebug()<<fileInfo.completeSuffix(); // return "tar.gz"
//        qDebug()<<fileInfo.created();  //return creat time
//        qDebug()<<fileInfo.lastModified(); //return modify time
//        qDebug()<<fileInfo.lastRead();      // return last read time
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainbutton_clicked()
{
    dialog=new MyDialog(this);
    dialog->setModal(true);
    dialog->setWindowTitle(tr("选择日期"));
    dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this,tr("关于"),tr(""));
}



void MainWindow::on_radioButton_clicked()
{
if(ui->radioButton->isChecked()==true)
    effect->play();

if(ui->radioButton->isChecked()==false)
    effect->stop();

}
