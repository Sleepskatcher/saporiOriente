#include<QApplication>
#include"modello.h"
#include"GUI/controller.h"
#include"GUI/menuIniziale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/style.qss");
    qss.open(QFile::ReadOnly | QFile::Text);
    a.setStyleSheet(qss.readAll());
    qss.close();

    Controller w(new Modello());
    w.show();
    return a.exec();
}
