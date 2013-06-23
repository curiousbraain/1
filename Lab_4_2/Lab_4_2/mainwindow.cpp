#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>
#include<QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStack<QString> stk;
    QString str = ui->textEdit->toPlainText(), str2=str;
    bool f=false;
    bool Pr=false, f2=true,f3=true;

    for(int i=0; i<str.count();i++)
        if ((str.at(i)=='0')||(str.at(i)=='1'))
              Pr= true;
    else
            Pr = false;


//        if(str.count("0")!=str.count("1"))
//            f3=false;

    if(str.isEmpty()||(Pr==false))//||(f3=false))
    {
        ui->textEdit_2->insertPlainText("Error");
    }
        else
        {
         for(int i=0;i<str.count();i++)
            {
             if (str.at(i)=='0')
             {
                 stk.push("0");
                 f=true;

             }
             if ((str.at(i)=='1'))
                 if(!stk.empty())
                 stk.pop();
                 else
                 {
                 ui->textEdit_2->insertPlainText("Error");
                 f2=false;
                 break;
                 }


       }
    }


    if ((f==true)&&(stk.isEmpty())&&(f2))
        ui->textEdit_2->insertPlainText("Right");
}


