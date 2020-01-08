#ifndef HANZI2PINYIN_H
#define HANZI2PINYIN_H

#include <QMap>
#include <QFile>

class Hanzi2Pinyin
{
public:
    Hanzi2Pinyin()
    {
        QFile file(":/pinyin.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
            return;

        while(!file.atEnd()) {
            QString content = QString::fromUtf8(file.readLine());
            m_map[content.split(" ").last().trimmed()] = content.split(" ").first().split(",");
        }
    }

    QString find(const QString &hanzi)
    {
        if (m_map.contains(hanzi))
            return m_map[hanzi].first();
        return "";
    }

private:
    QMap<QString, QStringList> m_map;
};

#endif // HANZI2PINYIN_H
