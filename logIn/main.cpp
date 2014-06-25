#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
#include "login.cpp"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    MainWindow w;
    //QString retour = request();

    QString value = "<Voilà !> ";
    value += "3 ";
    value += "petits pains.";

//    QPushButton *bouton = new QPushButton("Salut, la forme ? ");
    QTextBrowser *text = new QTextBrowser();
    text->setText(value);
//    bouton->setText(value);
//    bouton->show();
    text->show();
    return app.exec();
}

