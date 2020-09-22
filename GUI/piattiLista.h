#ifndef PIATTILISTA_H
#define PIATTILISTA_H

#include<QListWidgetItem>

#include"../GERARCHIA/gerarchia.h"

class piattiLista: public QListWidgetItem {
private:
    QWidget* parent;
    piatto* piatti;
public:
    piattiLista(QWidget* = nullptr, piatto* = nullptr);
    void aggiornaPiatto();
    piatto* getSelezionato() const;
};

#endif // PIATTILISTA_H
