#ifndef PIATTOWIDGET_H
#define PIATTOWIDGET_H

#include"GUI/piattiLista.h"

#include<QListWidget>
#include<QPushButton>
#include<QScrollBar>

class piattoWidget: public QListWidget {
private:
    QWidget* parent;
public:
    piattoWidget(QWidget* = nullptr);
    void aggiungiPiatto(piatto*);
    piattiLista* currentItem() const;
};

#endif // PIATTOWIDGET_H
