#include"menuCompleto.h"

menuPiatti::menuPiatti(QWidget* p):
    QWidget(p),
    listaPiatti(new piattoWidget(this)),
    modifica(new QPushButton(this)),
    rimuovi(new QPushButton(this))
{    
    QVBoxLayout* menuPiatti = new QVBoxLayout(this);
    QHBoxLayout* bottoni = new QHBoxLayout();

    listaPiatti->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    modifica->setText("Modifica il piatto");
    rimuovi->setText("Rimuovi il piatto");

    bottoni->addWidget(modifica);
    bottoni->addWidget(rimuovi);

    menuPiatti->addWidget(listaPiatti);
    menuPiatti->addLayout(bottoni);
}

piattoWidget* menuPiatti::getLista() const {
    return listaPiatti;
}

QPushButton* menuPiatti::getModifica() const {
    return modifica;
}

QPushButton* menuPiatti::getRimuovi() const {
    return rimuovi;
}
