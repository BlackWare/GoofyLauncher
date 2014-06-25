#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
//#include "login.cpp"
#include "launch.cpp"



int main(int argc, char *argv[])
{

    FILE* fichier = NULL;
    fichier = fopen("libjava","r");
    char tocken[] = "";
    char user[] = "";
    char mcdir[] = "%appdata%\\.goofy";
    QString file = launch(fichier,tocken,user,mcdir);

    if (fichier == NULL) {
        file = "wut ?";
    }
    QApplication app(argc, argv);


//    MainWindow w;

    QString value = "<Voilà !> ";
    value += "3 ";
    value += "petits pains.";

//    QPushButton *bouton = new QPushButton("Salut, la forme ? ");
    QTextBrowser *text = new QTextBrowser();
    text->setText(file);
//    bouton->setText(value);
//    bouton->show();
    text->show();
    return app.exec();
}

