#ifndef RICERCA_H
#define RICERCA_H

#include<QWidget>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QCheckBox>
#include<QListWidget>
#include<QLabel>
#include<QScrollBar>

#include"GUI/piattoWidget.h"

class Ricerca: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QCheckBox* piccante;
    QCheckBox* freddo;
    QCheckBox* caldo;
    QCheckBox* riso;
    QCheckBox* spaghetti;
    QCheckBox* dolce;
    QPushButton* cerca;
    QPushButton* reset;
    piattoWidget* listaPiatti;
    QPushButton* modifica;
    QPushButton* rimuovi;
    QLabel* istruzioni;
public:
    Ricerca(QWidget* = nullptr);
    QPushButton* getCercaBut() const;
    QPushButton* getModificaRic() const;
    QPushButton* getRimuoviRic() const;
    bool getPiccante() const;
    int getRiso() const;
    int getSpaghetti() const;
    int getDolce() const;
    std::string getCaldo() const;
    std::string getFreddo() const;
    piattoWidget* getListaRic() const;
public slots:
    void resetCampi();
    void freddoSi();
    void caldoSi();
    void risoSi();
    void spaghettiSi();
    void resetRS();
    void resetCF();
};

#endif // RICERCA_H
