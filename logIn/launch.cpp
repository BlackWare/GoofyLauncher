#include <QApplication>
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>
#include <QProcess>
#include <QDebug>


QString launch(FILE *library, char *tocken, char *user, QString *mcdir, int RAM)
{
    rewind(library);
    QString lib = "";
    char line[150] = "";
    if (library != NULL)
    {
        while (fgets(line,150,library) != NULL ) {
            lib += line;
            qDebug() << "check : REad line !";
        }

    }
    else if (library == NULL) {
        qDebug() << "Problem , File not found !";
    }
    QProcess::setWorkingDirectory(mcdir);
    QProcess::startDetached("shutdown -i",QStringList()<< " " << "set MCDIR=" << QString(mcdir));

    return lib;

}
 //Don't forget close the file.
