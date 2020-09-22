#ifndef INSERISCI_H
#define INSERISCI_H

#include<QWidget>
#include<QLineEdit>
#include<QCheckBox>
#include<QComboBox>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<algorithm>
#include<QList>
#include<QDebug>

#include"GERARCHIA/gerarchia.h"

class Inserisci: public QWidget {
    Q_OBJECT
private:
    QLabel* inizioInserisci;
    QLabel* nomePiatto;
    QLineEdit* nome;
    QLabel* piccanteLabel;
    QCheckBox* piccante;
    QLabel* tipologia;
    QCheckBox* freddo;
    QCheckBox* caldo;
    QCheckBox* primaScelta;
    QLabel* base;
    QCheckBox* riso;
    QCheckBox* spaghetti;
    QLabel* avviso;
    QLabel* infoSushi;
    QCheckBox* alga;
    QComboBox* pezzi;
    QWidget* wSushi;
    QLabel* infoCaldo;
    QWidget* wCaldo;
    QCheckBox* udonN;
    QCheckBox* ramenN;
    QCheckBox* risoCondN;
    QCheckBox* saltato;
    QCheckBox* fattoMano;
    QComboBox* baseBrodoN;
    QLabel* ingredienti;
    QComboBox* ingredienteFreddo0;
    QComboBox* ingredienteFreddo1;
    QComboBox* ingredienteFreddo2;
    QComboBox* ingredienteFreddo3;
    QComboBox* ingredienteCaldo0;
    QComboBox* ingredienteCaldo1;
    QComboBox* ingredienteCaldo2;
    QComboBox* ingredienteCaldo3;
    QPushButton* rimuovi1F;
    QPushButton* rimuovi2F;
    QPushButton* rimuovi3F;
    QPushButton* rimuovi1C;
    QPushButton* rimuovi2C;
    QPushButton* rimuovi3C;
    QWidget* primoIngF;
    QWidget* secondoIngF;
    QWidget* terzoIngF;
    QWidget* quartoIngF;
    QWidget* primoIngC;
    QWidget* secondoIngC;
    QWidget* terzoIngC;
    QWidget* quartoIngC;
    QPushButton* ancora;
    QPushButton* inserisci;
    QPushButton* reset;
    piatto* nuovo;
public:
    Inserisci(QWidget* = nullptr);
    QPushButton* getBottoneInserisci() const;
    piatto* dimmiNuovo();
    bool controlloInserimento();
public slots:
    void checkFreddo(bool);
    void checkCaldo(bool);
    void checkRiso(bool);
    void checkSpaghetti(bool);
    void checkRamen(bool);
    void checkUdon(bool);
    void checkRisoCond(bool);
    void aggiungiIngredienti();
    void rimuoviIngredienti();
    void resetTutto();
    void resetCaldoFreddo();
    void resetBase();
};

#endif // INSERISCI_H
