#include"ricerca.h"

Ricerca::Ricerca(QWidget* p):
    QWidget(p),
    piccante(new QCheckBox(this)),
    freddo(new QCheckBox(this)),
    caldo(new QCheckBox(this)),
    riso(new QCheckBox(this)),
    spaghetti(new QCheckBox(this)),
    dolce(new QCheckBox(this)),
    cerca(new QPushButton(this)),
    reset(new QPushButton(this)),
    listaPiatti(new piattoWidget(this)),
    modifica(new QPushButton(this)),
    rimuovi(new QPushButton(this)),
    istruzioni(new QLabel(this))
{
    QVBoxLayout* layoutRic = new QVBoxLayout(this);
    QHBoxLayout* layoutTemp = new QHBoxLayout();
    QHBoxLayout* layoutBase = new QHBoxLayout();
    QHBoxLayout* layoutBott = new QHBoxLayout();
    QVBoxLayout* layoutRisultati = new QVBoxLayout();
    QHBoxLayout* bottoni = new QHBoxLayout();

    istruzioni->setText("Spuntare le caratterisiche del piatto che si vuole cercare. "
                        "Dopo aver spuntato il necessario premere sul pulsante 'Cerca',"
                        "se si vuole annullare le selezioni fatte premere sul pulsante 'Resetta i campi'.");

    listaPiatti->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    istruzioni->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    istruzioni->setWordWrap(true);

    modifica->setText("Modifica il piatto");
    rimuovi->setText("Rimuovi il piatto");

    bottoni->addWidget(modifica);
    bottoni->addWidget(rimuovi);

    piccante->setText("Piccante");
    freddo->setText("Piatto freddo");
    caldo->setText("Piatto caldo");
    riso->setText("Riso");
    spaghetti->setText("Spaghetti");
    cerca->setText("Cerca");
    reset->setText("Resetta i campi");
    dolce->setText("Dolce");

    piccante->setEnabled(true);
    freddo->setEnabled(true);
    caldo->setEnabled(true);
    riso->setEnabled(true);
    spaghetti->setEnabled(true);

    layoutTemp->addWidget(freddo);
    layoutTemp->addWidget(caldo);

    layoutBase->addWidget(riso);
    layoutBase->addWidget(spaghetti);

    layoutBott->addWidget(cerca);
    layoutBott->addWidget(reset);

    layoutRisultati->addWidget(listaPiatti);

    layoutRic->addWidget(istruzioni);
    layoutRic->addWidget(piccante);
    layoutRic->addLayout(layoutTemp);
    layoutRic->addLayout(layoutBase);
    layoutRic->addWidget(dolce);
    layoutRic->addLayout(layoutBott);
    layoutRic->addLayout(layoutRisultati);
    layoutRic->addLayout(bottoni);

    connect(reset,SIGNAL(clicked()),this,SLOT(resetCampi()));
    connect(freddo,SIGNAL(toggled(bool)),this,SLOT(freddoSi()));
    connect(caldo,SIGNAL(toggled(bool)),this,SLOT(caldoSi()));
    connect(riso,SIGNAL(toggled(bool)),this,SLOT(risoSi()));
    connect(spaghetti,SIGNAL(toggled(bool)),this,SLOT(spaghettiSi()));
    connect(riso,SIGNAL(stateChanged(int)),this,SLOT(resetRS()));
    connect(spaghetti,SIGNAL(stateChanged(int)),this,SLOT(resetRS()));
    connect(freddo,SIGNAL(stateChanged(int)),this,SLOT(resetCF()));
    connect(caldo,SIGNAL(stateChanged(int)),this,SLOT(resetCF()));
}

QPushButton* Ricerca::getCercaBut() const {
    return  cerca;
}

QPushButton* Ricerca::getModificaRic() const {
    return modifica;
}

QPushButton* Ricerca::getRimuoviRic() const {
    return rimuovi;
}

piattoWidget* Ricerca::getListaRic() const {
    return listaPiatti;
}

bool Ricerca::getPiccante() const {
    if(piccante->isChecked()==true) return true;
    else return false;
}

int Ricerca::getRiso() const {
    if(riso->isChecked()==true) return 1;
    else return 4;
}

int Ricerca::getSpaghetti() const {
    if(spaghetti->isChecked()==true) return 2;
    else return 4;
}

int Ricerca::getDolce() const {
    if(dolce->isChecked()==true) return 3;
    else return 4;
}

std::string Ricerca::getCaldo() const {
    if(caldo->isChecked()==true) return "piattoCaldo";
    else return "niente";
}

std::string Ricerca::getFreddo() const {
    if(freddo->isChecked()==true) return "piattoFreddo";
    else return "niente";
}

void Ricerca::resetCampi() {
    piccante->setChecked(false);
    freddo->setChecked(false);
    caldo->setChecked(false);
    riso->setChecked(false);
    spaghetti->setChecked(false);
    piccante->setEnabled(true);
    caldo->setEnabled(true);
    freddo->setEnabled(true);
    spaghetti->setEnabled(true);
    riso->setEnabled(true);
    dolce->setChecked(false);
    listaPiatti->clear();
}

void Ricerca::freddoSi() {
    if(freddo->isChecked()==true) {
        caldo->setEnabled(false);
        spaghetti->setEnabled(false);
    }
}

void Ricerca::caldoSi() {
    if(caldo->isChecked()==true) {
        freddo->setEnabled(false);
    }
}

void Ricerca::risoSi() {
    if(riso->isChecked()==true) spaghetti->setEnabled(false);
}

void Ricerca::spaghettiSi() {
    if(spaghetti->isChecked()==true) riso->setEnabled(false);
}

void Ricerca::resetRS() {
    if(riso->checkState()==false && spaghetti->isEnabled()==false) spaghetti->setEnabled(true);
    if(spaghetti->checkState()==false && riso->isEnabled()==false) riso->setEnabled(true);
}

void Ricerca::resetCF() {
    if(freddo->checkState()==false && caldo->isEnabled()==false) {
        caldo->setEnabled(true);
        spaghetti->setEnabled(true);
    }
    if(caldo->checkState()==false && freddo->isEnabled()==false) freddo->setEnabled(true);
}
