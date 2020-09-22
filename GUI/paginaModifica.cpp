#include"GUI/paginaModifica.h"

Modifica::Modifica(QWidget* p):
    parent(p),
    sushiMod(new QWidget(this)),
    primoIngF(new QWidget(this)),
    secondoIngF(new QWidget(this)),
    terzoIngF(new QWidget(this)),
    quartoIngF(new QWidget(this)),
    primoIngC(new QWidget(this)),
    secondoIngC(new QWidget(this)),
    terzoIngC(new QWidget(this)),
    quartoIngC(new QWidget(this)),
    modNome(new QLabel(this)),
    nome(new QLineEdit(this)),
    modPiccantezza(new QLabel(this)),
    piccante(new QCheckBox(this)),
    modIngredienti(new QLabel(this)),
    ingFreddo0(new QComboBox(this)),
    ingFreddo1(new QComboBox(this)),
    ingFreddo2(new QComboBox(this)),
    ingFreddo3(new QComboBox(this)),
    ingCaldo0(new QComboBox(this)),
    ingCaldo1(new QComboBox(this)),
    ingCaldo2(new QComboBox(this)),
    ingCaldo3(new QComboBox(this)),
    ancora(new QPushButton(this)),
    rimuovi1F(new QPushButton(this)),
    rimuovi2F(new QPushButton(this)),
    rimuovi3F(new QPushButton(this)),
    rimuovi1C(new QPushButton(this)),
    rimuovi2C(new QPushButton(this)),
    rimuovi3C(new QPushButton(this)),
    modSushi(new QLabel(this)),
    primaSceltaMod(new QCheckBox(this)),
    algaMod(new QCheckBox(this)),
    pezziMod(new QComboBox(this)),
    modCaldo(new QLabel(this)),
    fattoManoMod(new QCheckBox(this)),
    saltatoMod(new QCheckBox(this)),
    baseBrodoMod(new QComboBox(this)),
    salvaModifiche(new QPushButton(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* N = new QHBoxLayout();
    QHBoxLayout* P = new QHBoxLayout();
    QVBoxLayout* APS = new QVBoxLayout(sushiMod);
    QVBoxLayout* caldoInfo = new QVBoxLayout();
    QVBoxLayout* tieniTutto = new QVBoxLayout();
    QHBoxLayout* ING = new QHBoxLayout();
    QVBoxLayout* ing1F = new QVBoxLayout(primoIngF);
    QVBoxLayout* ing2F = new QVBoxLayout(secondoIngF);
    QVBoxLayout* ing3F = new QVBoxLayout(terzoIngF);
    QVBoxLayout* ing4F = new QVBoxLayout(quartoIngF);
    QVBoxLayout* ing1C = new QVBoxLayout(primoIngC);
    QVBoxLayout* ing2C = new QVBoxLayout(secondoIngC);
    QVBoxLayout* ing3C = new QVBoxLayout(terzoIngC);
    QVBoxLayout* ing4C = new QVBoxLayout(quartoIngC);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowIcon(QPixmap(":/logo.jpg"));
    setMinimumSize(900,400);

    modPiccantezza->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    modPiccantezza->setWordWrap(true);
    modIngredienti->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    modIngredienti->setWordWrap(true);
    modSushi->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    modSushi->setWordWrap(true);
    modCaldo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    modCaldo->setWordWrap(true);


    salvaModifiche->setText("Salva modifiche");
    setWindowTitle("Pagina modifica piatto");
    modNome->setText("Modifica il nome del piatto");
    modPiccantezza->setText("Modifica la piccantezza del piatto");
    modIngredienti->setText("Modifica gli ingredienti: puoi modificare quelli già presenti, aggiungerne di nuovi"
                            " o toglierne di presenti. Se vengono selezionati "
                            "degli ingredienti doppioni essi verranno inseriti solamente una volta.");
    piccante->setText("Piccante");
    modSushi->setText("Modifica se vuoi il pesce di prima scelta, l'alga e il numero di pezzi.");
    modCaldo->setText("Per modificare gli Udon selezionare se si vogliono fatti a mano, per il ramen selezionare il tipo del brodo e per il riso "
                      "selezionare se si vuole che sia saltato nel Wok.");
    algaMod->setText("Alga");
    primaSceltaMod->setText("Pesce di prima di scelta");
    ancora->setText("Aggiungi un altro ingrediente");
    fattoManoMod->setText("Fatti a mano");
    saltatoMod->setText("Saltato nel wok");
    rimuovi1F->setText("Rimuovi ingrediente");
    rimuovi2F->setText("Rimuovi ingrediente");
    rimuovi3F->setText("Rimuovi ingrediente");
    rimuovi1C->setText("Rimuovi ingrediente");
    rimuovi2C->setText("Rimuovi ingrediente");
    rimuovi3C->setText("Rimuovi ingrediente");

    salvaModifiche->setObjectName("salvaMod");
    ancora->setObjectName("ancora");
    rimuovi1F->setObjectName("rimuoviF");
    rimuovi2F->setObjectName("rimuoviF");
    rimuovi3F->setObjectName("rimuoviF");
    rimuovi1C->setObjectName("rimuoviC");
    rimuovi2C->setObjectName("rimuoviC");
    rimuovi3C->setObjectName("rimuoviC");

    QList<QString> numeri = {"1","2","3","4","5","6","7","8"};

    for(int i=0;i<numeri.length();++i) pezziMod->addItem(numeri[i]);

    QList<QString> baseBrodo = {"Pesce","Manzo","Pollo"};

    for(int i=0;i<baseBrodo.length();++i) baseBrodoMod->addItem(baseBrodo[i]);

    QList<QString> ingFreddi= {"Salmone crudo","Salmone scottato","Tonno crudo","Tonno scottato","Avocado","Wasabi","Gambero crudo","Gambero fritto"
                             ,"Branzino crudo","Gamberone crudo","Branzino scottato","Surimi","Philadelphia"};

    std::sort(ingFreddi.begin(), ingFreddi.end());

    ingFreddo0->addItems(ingFreddi);

    for(int i=0;i<ingFreddi.length();++i) {
        ingFreddo0->addItem(ingFreddi[i]);
        ingFreddo1->addItem(ingFreddi[i]);
        ingFreddo2->addItem(ingFreddi[i]);
        ingFreddo3->addItem(ingFreddi[i]);
    }

    QList<QString> ingCaldi= {"Manzo saltato","Pollo saltato","Pollo fritto","Prosciutto","Salsa di soia","Germogli di soia","Gamberetti saltati",
                            "Gamberetti lessati","Salmone saltato","Seppie saltate","Calamari saltati","Bamboo","Carote","Mandorle","Piselli",
                            "Funghi","Uovo sodo","Uovo saltato"};

    std::sort(ingCaldi.begin(), ingCaldi.end());

    for(int i=0;i<ingCaldi.length();++i) {
        ingCaldo0->addItem(ingCaldi[i]);
        ingCaldo1->addItem(ingCaldi[i]);
        ingCaldo2->addItem(ingCaldi[i]);
        ingCaldo3->addItem(ingCaldi[i]);
    }

    ingFreddo0->hide();
    ingFreddo1->hide();
    ingFreddo2->hide();
    ingFreddo3->hide();

    ingCaldo0->hide();
    ingCaldo1->hide();
    ingCaldo2->hide();
    ingCaldo3->hide();

    N->addWidget(modNome);
    N->addWidget(nome);
    P->addWidget(modPiccantezza);
    P->addWidget(piccante);

    ing1F->addWidget(ingFreddo0);

    ing2F->addWidget(ingFreddo1);
    ing2F->addWidget(rimuovi1F);

    ing3F->addWidget(ingFreddo2);
    ing3F->addWidget(rimuovi2F);

    ing4F->addWidget(ingFreddo3);
    ing4F->addWidget(rimuovi3F);

    ing1C->addWidget(ingCaldo0);

    ing2C->addWidget(ingCaldo1);
    ing2C->addWidget(rimuovi1C);

    ing3C->addWidget(ingCaldo2);
    ing3C->addWidget(rimuovi2C);

    ing4C->addWidget(ingCaldo3);
    ing4C->addWidget(rimuovi3C);

    ING->addWidget(primoIngC);
    ING->addWidget(secondoIngC);
    ING->addWidget(terzoIngC);
    ING->addWidget(quartoIngC);

    ING->addWidget(primoIngF);
    ING->addWidget(secondoIngF);
    ING->addWidget(terzoIngF);
    ING->addWidget(quartoIngF);
    ING->addWidget(ancora);

    APS->addWidget(modSushi);
    APS->addWidget(algaMod);
    APS->addWidget(primaSceltaMod);
    APS->addWidget(pezziMod);

    caldoInfo->addWidget(modCaldo);
    caldoInfo->addWidget(fattoManoMod);
    caldoInfo->addWidget(saltatoMod);
    caldoInfo->addWidget(baseBrodoMod);

    tieniTutto->addWidget(modIngredienti);
    tieniTutto->addLayout(ING);

    layout->addLayout(N);
    layout->addLayout(P);
    layout->addWidget(sushiMod);
    layout->addLayout(caldoInfo);
    layout->addLayout(tieniTutto);
    layout->addWidget(salvaModifiche);

    sushiMod->hide();
    fattoManoMod->hide();
    saltatoMod->hide();
    baseBrodoMod->hide();
    ancora->hide();
    primoIngF->hide();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->hide();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();

    connect(ancora,SIGNAL(clicked()),this,SLOT(aggiungiIngredienteMod()));
    connect(rimuovi1F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
    connect(rimuovi2F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
    connect(rimuovi3F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
    connect(rimuovi1C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
    connect(rimuovi2C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
    connect(rimuovi3C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienteMod()));
}

void Modifica::setPiatto(piatto *p) {
    dish=p;
}

void Modifica::compilaModifica() {
    //setto il nome
    nome->setText(QString::fromStdString(dish->getNomePiatto()));
    //setto la piccantezza
    if(dish->getPiccante()) piccante->setCheckState(Qt::Checked);
    else piccante->setCheckState(Qt::Unchecked);
    //controllo se è un piatto caldo o freddo e mostro gli ingredienti
    piattoFreddo* pf = dynamic_cast<piattoFreddo*>(dish);
    piattoCaldo* pc = dynamic_cast<piattoCaldo*>(dish);
    if(pf!=nullptr) { //qua il piatto è freddo
        sushiMod->show();
        modSushi->show();
        modCaldo->hide();
        primoIngF->hide();
        secondoIngF->hide();
        terzoIngF->hide();
        quartoIngF->hide();
        primoIngC->hide();
        secondoIngC->hide();
        terzoIngC->hide();
        quartoIngC->hide();
        fattoManoMod->hide();
        saltatoMod->hide();
        baseBrodoMod->hide();
        //setto prima scelta
        if(pf->getPescePrimaScelta()) primaSceltaMod->setCheckState(Qt::Checked);
        //setto caratteristiche del sushi
        sushi* s = dynamic_cast<sushi*>(pf);
        //setto alga
        if(s->getAlga()) algaMod->setCheckState(Qt::Checked);
        //setto numero dei pezzi
        QString pezziCorrenti = QString("%1").arg(s->getPezzi());
        pezziMod->setCurrentIndex(pezziMod->findText(pezziCorrenti));
        //sistemo gli ingredienti
        std::vector<std::string> ing = pf->getIngredientiFreddi();
        int conto = 0;
        for(std::vector<std::string>::const_iterator cit=ing.cbegin();cit!=ing.cend();++cit) {
            QString corrente = QString::fromStdString(*cit);
            if(conto==0) {
            ingFreddo0->setCurrentIndex(ingFreddo0->findText(corrente));
            primoIngF->show();
            ingFreddo0->show();
            ancora->show();
            } else if(conto==1) {
                ingFreddo1->setCurrentIndex(ingFreddo1->findText(corrente));
                secondoIngF->show();
                ingFreddo1->show();
            } else if(conto==2) {
                ingFreddo2->setCurrentIndex(ingFreddo2->findText(corrente));
                terzoIngF->show();
                ingFreddo2->show();
            } else if(conto==3) {
                ingFreddo3->setCurrentIndex(ingFreddo3->findText(corrente));
                quartoIngF->show();
                ingFreddo3->show();
                ancora->hide();
            }
            conto++;
        }
    } else if(pc!=nullptr) { //qua il piatto è caldo
        sushiMod->hide();
        primoIngF->hide();
        secondoIngF->hide();
        terzoIngF->hide();
        quartoIngF->hide();
        primoIngC->hide();
        secondoIngC->hide();
        terzoIngC->hide();
        quartoIngC->hide();
        modSushi->hide();
        modCaldo->show();
        std::vector<std::string> ing = pc->getIngredientiCaldi();
        int conto = 0;
        for(std::vector<std::string>::const_iterator cit=ing.cbegin();cit!=ing.cend();++cit) {
            QString corrente = QString::fromStdString(*cit);
            if(conto==0) {
            ingCaldo0->setCurrentIndex(ingCaldo0->findText(corrente));
            ingCaldo0->show();
            primoIngC->show();
            ancora->show();
            } else if(conto==1) {
                ingCaldo1->setCurrentIndex(ingCaldo1->findText(corrente));
                ingCaldo1->show();
                secondoIngC->show();
            } else if(conto==2) {
                ingCaldo2->setCurrentIndex(ingCaldo2->findText(corrente));
                ingCaldo2->show();
                terzoIngC->show();
            } else if(conto==3) {
                ingCaldo3->setCurrentIndex(ingCaldo3->findText(corrente));
                ingCaldo3->show();
                quartoIngC->show();
                ancora->hide();
            }
            conto++;
        }
        udon* u = dynamic_cast<udon*>(pc);
        if(u!=nullptr) {
            fattoManoMod->show();
            saltatoMod->hide();
            baseBrodoMod->hide();
        }
        risoCondito* rc = dynamic_cast<risoCondito*>(pc);
        if(rc!=nullptr) {
            saltatoMod->show();
            fattoManoMod->hide();
            baseBrodoMod->hide();
        }
        ramen* r = dynamic_cast<ramen*>(pc);
        if(r!=nullptr) {
            baseBrodoMod->show();
            fattoManoMod->hide();
            saltatoMod->hide();
        }
    }
}

void Modifica::setNuoviCampi() {
    //generico
    dish->setNome(nome->text().toStdString());
    dish->setPiccante(piccante->isChecked()==true ? true : false);
    //piatto freddo
    piattoFreddo* pf = dynamic_cast<piattoFreddo*>(dish);
    if(pf!=nullptr) {
    pf->svuotaIngredientiFreddi();
    if(ingFreddo0->isVisible()) pf->setIngredientiFreddi(ingFreddo0->currentText().toStdString());
    if(ingFreddo1->isVisible()) pf->setIngredientiFreddi(ingFreddo1->currentText().toStdString());
    if(ingFreddo2->isVisible()) pf->setIngredientiFreddi(ingFreddo2->currentText().toStdString());
    if(ingFreddo3->isVisible()) pf->setIngredientiFreddi(ingFreddo3->currentText().toStdString());
    pf->setPescePrimaScelta(primaSceltaMod->isChecked()==true ? true : false);
    //sushi
    sushi* s = dynamic_cast<sushi*>(pf);
        if(s!=nullptr) {
            s->setPescePrimaScelta(primaSceltaMod->isChecked()==true ? true : false);
            s->setAlga(algaMod->isChecked()==true ? true : false);
            s->setPezzi(pezziMod->currentText().toUInt());
        }
    }
    //piatto caldo
    piattoCaldo* pc = dynamic_cast<piattoCaldo*>(dish);
    if(pc!=nullptr) {
    pc->svuotaIngredientiCaldi();
    if(ingCaldo0->isVisible()) pc->setIngredientiCaldi(ingCaldo0->currentText().toStdString());
    if(ingCaldo1->isVisible()) pc->setIngredientiCaldi(ingCaldo1->currentText().toStdString());
    if(ingCaldo2->isVisible()) pc->setIngredientiCaldi(ingCaldo2->currentText().toStdString());
    if(ingCaldo3->isVisible()) pc->setIngredientiCaldi(ingCaldo3->currentText().toStdString());
    //udon
    udon* u = dynamic_cast<udon*>(pc);
    if(u!=nullptr) u->setFattiMano(fattoManoMod->isChecked()==true ? true : false);
    //riso condito
    risoCondito* rc = dynamic_cast<risoCondito*>(pc);
    if(rc!=nullptr) rc->setSaltato(saltatoMod->isChecked()==true ? true : false);
    //ramen
    ramen* r = dynamic_cast<ramen*>(pc);
    int baseBrodoModificato=0;
    if(baseBrodoMod->currentText()=="Pollo") baseBrodoModificato=3;
    else if(baseBrodoMod->currentText()=="Manzo") baseBrodoModificato=2;
    else if(baseBrodoMod->currentText()=="Pesce") baseBrodoModificato=1;
    else baseBrodoModificato=1;
    if(r!=nullptr) r->setBaseBrodo(baseBrodoModificato);
    }
}

QPushButton* Modifica::getBottoneSalva() const {
    return salvaModifiche;
}

void Modifica::aggiungiIngredienteMod() {
    if(dynamic_cast<piattoFreddo*>(dish)) {
        if (primoIngF->isVisible() == true && secondoIngF->isVisible() == false ) {
            ingFreddo1->show();
            secondoIngF->show();
            return;
        }
        if (secondoIngF->isVisible() == true && terzoIngF->isVisible() == false) {
            ingFreddo2->show();
            terzoIngF->show();
            return;
        }
        if (terzoIngF->isVisible() == true && quartoIngF->isVisible() == false) {
            ingFreddo3->show();
            quartoIngF->show();
            ancora->hide();
            if (quartoIngF->isVisible() == true) ancora->hide();
            return;
        }
    } else if(dynamic_cast<piattoCaldo*>(dish)) {
        if (primoIngC->isVisible() == true && secondoIngC->isVisible() == false ) {
            ingCaldo1->show();
            secondoIngC->show();
            return;
        }
        if (secondoIngC->isVisible() == true && terzoIngC->isVisible() == false) {
            ingCaldo2->show();
            terzoIngC->show();
            return;
        }
        if (terzoIngC->isVisible() == true && quartoIngC->isVisible() == false) {
            ingCaldo3->show();
            quartoIngC->show();
            if (quartoIngC->isVisible() == true) ancora->hide();
            return;
        }
    }
}

void Modifica::rimuoviIngredienteMod() {
    int contaIng = 1;
    if(dynamic_cast<piattoFreddo*>(dish)) {
        if (secondoIngF->isVisible() == true) {
            ingFreddo1->hide();
            secondoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (terzoIngF->isVisible() == true) {
            ingFreddo2->hide();
            terzoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }

        if (quartoIngF->isVisible() == true) {
            ingFreddo3->hide();
            quartoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
    } else if(dynamic_cast<piattoCaldo*>(dish)) {
        if (secondoIngC->isVisible() == true) {
            ingCaldo1->hide();
            secondoIngC->hide();
            contaIng=1;
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (terzoIngC->isVisible() == true) {
            ingCaldo2->hide();
            terzoIngC->hide();
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (quartoIngC->isVisible() == true) {
            ingCaldo3->hide();
            quartoIngC->hide();
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
    }
}
