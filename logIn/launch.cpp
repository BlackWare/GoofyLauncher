#include <QApplication>
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>
#include <QProcess>


QString launch(FILE *library, char *tocken, char *user, char *mcdir)
{
    rewind(library);
    QString lib = "";
    char line[10000] = "";
    if (library != NULL)
    {
        while ("fgets(line,10000,library") {
            lib += line;
        }

    }
    else if (library == NULL) {
        lib = "Problem";
    }
    QProcess::startDetached("cmd.exe", QStringList()<< "cd " << QString(mcdir));
    return lib;

}
 //Don't forget close the file.
