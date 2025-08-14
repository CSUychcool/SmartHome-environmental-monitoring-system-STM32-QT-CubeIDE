#ifndef DEEPSEEKAPI_H
#define DEEPSEEKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QByteArray>

class deepseekapi : public QObject
{
    Q_OBJECT
public:
    explicit deepseekapi(QObject *parent = nullptr);
    void SendChatRequest(const QString Chatnews);
    void Set_apikey(const QString apikey);

public slots:
    void onSloveReply(QNetworkReply *reply);
signals:
   void requestFinished(const QString &response);
private:
    QNetworkAccessManager *My_manager;
    QString m_apikey;
    deepseekapi *m_deepseek;
};

#endif // DEEPSEEKAPI_H
