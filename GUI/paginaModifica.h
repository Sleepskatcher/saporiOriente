#ifndef PAGINAMODIFICA_H
#define PAGINAMODIFICA_H

#include<QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QCheckBox>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QComboBox>
#include<QDebug>
#include<QLabel>

#include"GERARCHIA/gerarchia.h"
#include"GUI/piattoWidget.h"

class Modifica: public QDialog {
    Q_OBJECT
private:
    piatto* dish;
    QWidget* parent;
    QWidget* sushiMod;
    QWidget* primoIngF;
    QWidget* secondoIngF;
    QWidget* terzoIngF;
    QWidget* quartoIngF;
    QWidget* primoIngC;
    QWidget* secondoIngC;
    QWidget* terzoIngC;
    QWidget* quartoIngC;
    QLabel* modNome;
    QLineEdit* nome;
    QLabel* modPiccantezza;
    QCheckBox* piccante;
    QLabel* modIngredienti;
    QComboBox* ingFreddo0;
    QComboBox* ingFreddo1;
    QComboBox* ingFreddo2;
    QComboBox* ingFreddo3;
    QComboBox* ingCaldo0;
    QComboBox* ingCaldo1;
    QComboBox* ingCaldo2;
    QComboBox* ingCaldo3;
    QPushButton* ancora;
    QPushButton* rimuovi1F;
    QPushButton* rimuovi2F;
    QPushButton* rimuovi3F;
    QPushButton* rimuovi1C;
    QPushButton* rimuovi2C;
    QPushButton* rimuovi3C;
    QLabel* modSushi;
    QCheckBox* primaSceltaMod;
    QCheckBox* algaMod;
    QComboBox* pezziMod;
    QLabel* modCaldo;
    QCheckBox* fattoManoMod;
    QCheckBox* saltatoMod;
    QComboBox* baseBrodoMod;
    QPushButton* salvaModifiche;
public:
    Modifica(QWidget* = nullptr);
    void setPiatto(piatto*);
    void compilaModifica();
    void setNuoviCampi();
    QPushButton* getBottoneSalva() const;
public slots:
    void aggiungiIngredienteMod();
    void rimuoviIngredienteMod();
};

#endif // PAGINAMODIFICA_H
