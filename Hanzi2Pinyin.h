/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * QQ群: 732271126
 * Email: 2088201923@qq.com
 * Github: https://github.com/aeagean/Hanzi2Pinyin
 **********************************************************/
#ifndef HANZI2PINYIN_H
#define HANZI2PINYIN_H

#include <QMap>
#include <QFile>

class Hanzi2Pinyin
{
public:
    Hanzi2Pinyin()
    {
    }

    static QString find(const QString &hanzi)
    {
        static QMap<QString, QStringList> map = loadHanziTable(":/pinyin.txt");
        QString output;
        QStringList stringList = hanzi.split("");

        /* 遍历查找汉字-拼音对照表的内容并将汉字替换为拼音 */
        for (const QString &str : stringList) {
            if (map.contains(str))
                output += map[str].first();
            else
                output += str;
        }

        return output;
    }

private:
    /* 加载汉字对照表 */
    static QMap<QString, QStringList> loadHanziTable(const QString &fileName)
    {
        QMap<QString, QStringList> map;
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            qDebug("File: '%s' open failed!", file.fileName().toStdString().c_str());
            return map;
        }

        /* 读取汉字对照表文件并转换为QMap存储 */
        while(!file.atEnd()) {
            QString content = QString::fromUtf8(file.readLine());
            map[content.split(" ").last().trimmed()] = content.split(" ").first().split(",");
        }

        file.close();

        return map;
    }
};

#endif // HANZI2PINYIN_H
