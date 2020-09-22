#ifndef AVVISO_H
#define AVVISO_H

#include<QMessageBox>
#include<QIcon>

class Avviso: public QMessageBox {
private:
    QString nomeFinestra;
    QString testo;
public:
    Avviso(QString,QString);
};

#endif // AVVISO_H
