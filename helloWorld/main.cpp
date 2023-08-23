#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Hello World, my name is Maged Elesseily";

    return a.exec();
}
