#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>
#include<QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{//
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStack<QString> stk;
    QString str = ui->textEdit->toPlainText(),str2;
bool f2=false;

    if (str.isEmpty())
            ui->textEdit_2->insertPlainText("Error");
    for(int i=0;i<str.count();i++)
    {
        if (str.at(i)=='1')
            for(int j=0;j<i;j++)
                if (str.at(j)=='0')
                    f2=true;
    }

    for (int i =0;i<str.count();i++)
{
        if ((str.at(0)=='0')||(f2))
        {ui->textEdit_2->insertPlainText("Error");
            break;
        }
               stk.push(str.at(i));
}
     int j=0;
    while(!stk.isEmpty())
       { str2.prepend( stk.pop());
        if (str2.at(j)=='0')
           { str2.replace(j,1,"22");
           }
       }
    ui->textEdit_2->insertPlainText(str2);
}
