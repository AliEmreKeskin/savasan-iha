#ifndef UTILS_H
#define UTILS_H
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

static auto RESOURCE_PREFIX = QStringLiteral(":/json/");

QJsonObject ReadJSONFile(QString fileName){
    QString content;
    QFile file;
    QString values[8];

    file.setFileName(RESOURCE_PREFIX + fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    content = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject obj = doc.object();

    return obj;
}

#endif // UTILS_H
