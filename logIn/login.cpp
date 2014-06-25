#include <QApplication>
#include <QtNetwork>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QMainWindow>
#include


class QNetworkReply;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
explicit MainWindow(QWidget *parent = 0);
~MainWindow();

protected slots:
void replyFinished(QNetworkReply *reply);
};

/*QString request()
{
    QNetworkAccessManager *nwam = new QNetworkAccessManager;

    QNetworkRequest request(QUrl("https://authserver.mojang.com/authenticate"));

    QByteArray data;
    QUrlQuery params;

    char user[] = "Jambo";
    char pass[] = "no";
    QString userString(user);
    QString passString(pass);

    params.addQueryItem("user", userString );
    params.addQueryItem("pass", passString );
    data.append(params.toString());
    data.remove(0,1);

    QNetworkReply *reply = nwam->post(request,data);

        return reply;
} */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
QUrl url("https://authserver.mojang.com/authenticate");
QNetworkRequest request(url);

request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

QNetworkAccessManager *manager = new QNetworkAccessManager(this);

QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(syncRequestFinished(QNetworkReply*)));

  QByteArray data = QtJson::Json::serialize(collectSyncData());
// FIXME for debug
//qDebug() << "Sync" << QString::fromUtf8(data.data(), data.size());

manager->post(request, data);
}

MainWindow::~MainWindow()
{
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
qDebug() << "ok!";
}
