#include "Widget.h"
#include "ui_Widget.h"
#include "Hanzi2Pinyin.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_2->setReadOnly(true);

    this->setWindowTitle("汉字转拼音 by Qt君");
    this->setFixedSize(800, 360);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    QString str = Hanzi2Pinyin::find(ui->lineEdit->text());
    ui->lineEdit_2->setText(str);
}
