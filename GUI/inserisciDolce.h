#ifndef INSERISCIDOLCE_H
#define INSERISCIDOLCE_H

#include<QWidget>
#include<QLabel>
#include<algorithm>
#include<QList>
#include<QLineEdit>
#include<QCheckBox>
#include<QComboBox>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QtDebug>

#include"GERARCHIA/gerarchia.h"

class InserisciDolce: public QWidget {
    Q_OBJECT
private:
    QLabel* inizioInserisci;
    QLabel* labelNome;
    QLineEdit* nomeDolce;
    QLabel* glassaPanna;
    QCheckBox* glassa;
    QCheckBox* panna;
    QLabel* ingredientiL;
    QComboBox* ingFreddo;
    QComboBox* ingCaldo;
    QPushButton* inserisci;
    QPushButton* reset;
public:
    InserisciDolce(QWidget* = nullptr);
    piatto* nuovoDolce();
    bool controllo();
    QPushButton* getBottoneInserisciDolce();
public slots:
    void resetCampi();
};

#endif // INSERISCIDOLCE_H
