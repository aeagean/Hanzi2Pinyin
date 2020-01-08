#include "Widget.h"
#include "ui_Widget.h"
#include "Hanzi2Pinyin.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString str = Hanzi2Pinyin().find(ui->lineEdit->text());
    ui->lineEdit_2->setText(str);
}
