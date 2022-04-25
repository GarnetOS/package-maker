    #include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> filestomove;
    QDirIterator it(QString("."), QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        filestomove.append(it.next());
    QString filename="files.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {

        QTextStream stream( &file );
        foreach (QString file, filestomove) {
            stream << file << Qt::endl;
        }


    }
    return a.exec();  
}
