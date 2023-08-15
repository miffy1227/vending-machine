#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    updateDrinkButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    updateDrinkButtons();
}

void Widget::updateDrinkButtons()
{
    ui->pbCoffee->setEnabled(true);
    ui->pbTea->setEnabled(true);
    ui->pbMilk->setEnabled(true);


    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if (money < 150) {
        ui->pbTea->setEnabled(false);
    }
    if (money < 200) {
        ui->pbMilk->setEnabled(false);
    }
}


void Widget::on_pb10_clicked()
{
    money += 10;
    ui -> lcdNumber -> display(money);
    updateDrinkButtons();
}


void Widget::on_pb50_clicked()
{
    money += 50;
    ui -> lcdNumber -> display(money);
    updateDrinkButtons();
}


void Widget::on_pb100_clicked()
{
    money += 100;
    ui -> lcdNumber -> display(money);
    updateDrinkButtons();
}


void Widget::on_pb500_clicked()
{
    money += 500;
    ui -> lcdNumber -> display(money);
    updateDrinkButtons();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    updateDrinkButtons();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    updateDrinkButtons();
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    updateDrinkButtons();
}


void Widget::on_pbReset_clicked()
{
    int num500 = money / 500;
    int remainingMoney = money % 500;
    int num100 = remainingMoney / 100;
    remainingMoney %= 100;
    int num50 = remainingMoney / 50;
    remainingMoney %= 50;
    int num10 = remainingMoney / 10;

    QString changeInfo = QString("500: %1\n100: %2\n50: %3\n10: %4")
                         .arg(num500).arg(num100).arg(num50).arg(num10);

    QMessageBox mb;
    mb.information(nullptr, "Changes", changeInfo);

    money = 0;
    ui->lcdNumber->display(money);

    updateDrinkButtons();
}





