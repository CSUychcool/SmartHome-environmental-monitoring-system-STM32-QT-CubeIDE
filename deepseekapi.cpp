#include "deepseekapi.h"

deepseekapi::deepseekapi(QObject *parent)
    : QObject{parent}
{
    My_manager=new QNetworkAccessManager(this);
    connect(My_manager,&QNetworkAccessManager::finished,this,&deepseekapi::onSloveReply);

}

void deepseekapi::Set_apikey(const QString apikey)
{
    m_apikey=apikey;
}

void deepseekapi::SendChatRequest(const QString Chatnews)
{
    QNetworkRequest My_Requset=QNetworkRequest(QUrl("https://api.deepseek.com/v1/chat/completions"));
    My_Requset.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    My_Requset.setRawHeader("Authorization", QString("Bearer %1").arg(m_apikey).toUtf8());

    QJsonArray My_JsonArr;
    QJsonObject tem_JsonObj;
    tem_JsonObj["role"]="user";
    tem_JsonObj["content"]=Chatnews;
    My_JsonArr.append(tem_JsonObj);

    QJsonObject My_JsonObj;
    My_JsonObj["model"]="deepseek-chat";
    My_JsonObj["messages"]=My_JsonArr;
    My_JsonObj["temperature"]=1;
    My_JsonObj["max_tokens"]=1024;

    QJsonDocument My_JsonDoc(My_JsonObj);

    My_manager->post(My_Requset,My_JsonDoc.toJson());
}

void deepseekapi::onSloveReply(QNetworkReply *reply)
{
    QByteArray Reply_ByteArray=reply->readAll();
    if(reply->error()==QNetworkReply::NoError&&!Reply_ByteArray.isEmpty()){
        reply->deleteLater();
        QJsonDocument Reply_JsonDoc = QJsonDocument::fromJson(Reply_ByteArray);
        if(!Reply_JsonDoc.isEmpty()){
            if(Reply_JsonDoc.isObject()){
                QJsonObject Reply_JsonObj=Reply_JsonDoc.object();
                QJsonArray choices=Reply_JsonObj["choices"].toArray();
                QJsonObject choice = choices[0].toObject();
                QJsonObject message = choice["message"].toObject();
                QString content = message["content"].toString();
                emit requestFinished(content);
            }
            else
                qDebug()<<"JsonObject对象不存在";
        }
        else
            qDebug()<<"JsonDoc文件不存在";
    }
    else{
        qDebug()<<reply->errorString();
        reply->deleteLater();}

}
