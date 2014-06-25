#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
//#include "login.cpp"
#include "launch.cpp"



int main(int argc, char *argv[])
{

    int RAM = 1000; // En MegaOctets
    FILE* fichier = NULL;
    fichier = fopen("libjava.set","r");
    char tocken[] = "";
    char user[] = "";
    QString mcdir[] = "%appdata%\\.goofy";
    QString file = launch(fichier,tocken,user,mcdir,RAM);

    QApplication app(argc, argv);
    QTextBrowser *text = new QTextBrowser();
    text->setText(file);
    text->show();
    return app.exec();
}

