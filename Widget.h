/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * QQ群: 732271126
 * Email: 2088201923@qq.com
 * Github: https://github.com/aeagean/Hanzi2Pinyin
 **********************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
