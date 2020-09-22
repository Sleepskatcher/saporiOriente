#ifndef MENUCOMPLETO_H
#define MENUCOMPLETO_H

#include<QWidget>
#include<QListWidget>
#include<QScrollBar>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>

#include"GUI/piattoWidget.h"

class menuPiatti: public QWidget {
private:
    QWidget* parent;
    piattoWidget* listaPiatti;
    QPushButton* modifica;
    QPushButton* rimuovi;
public:
    menuPiatti(QWidget* = nullptr);
    piattoWidget* getLista() const;
    QPushButton* getModifica() const;
    QPushButton* getRimuovi() const;
};

#endif // MENUCOMPLETO_H
