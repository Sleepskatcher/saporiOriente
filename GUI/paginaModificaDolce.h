#ifndef PAGINAMODIFICADOLCE_H
#define PAGINAMODIFICADOLCE_H

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

class ModificaDolce: public QDialog {
private:
    piatto* dishMod;
    QWidget* parent;
    QLineEdit* nomeMod;
    QCheckBox* glassaMod;
    QCheckBox* pannaMod;
    QComboBox* ingFreddoMod;
    QComboBox* ingCaldoMod;
    QPushButton* salvaModDolce;
public:
    ModificaDolce(QWidget* = nullptr);
    QPushButton* getSalvaModDolce();
    void setPiattoDolce(piatto*);
    void compilaModDolce();
    void setNuoviCampiDolce();
};

#endif // PAGINAMODIFICADOLCE_H
