#include"inserisci.h"

Inserisci::Inserisci(QWidget* p):
    QWidget(p),
    inizioInserisci(new QLabel(this)),
    nomePiatto(new QLabel(this)),
    nome(new QLineEdit(this)),
    piccanteLabel(new QLabel(this)),
    piccante(new QCheckBox(this)),
    tipologia(new QLabel(this)),
    freddo(new QCheckBox(this)),
    caldo(new QCheckBox(this)),
    primaScelta(new QCheckBox(this)),
    base(new QLabel(this)),
    riso(new QCheckBox(this)),
    spaghetti(new QCheckBox(this)),
    avviso(new QLabel),
    infoSushi(new QLabel(this)),
    alga(new QCheckBox(this)),
    pezzi(new QComboBox(this)),
    wSushi(new QWidget(this)),
    infoCaldo(new QLabel(this)),
    wCaldo(new QWidget(this)),
    udonN(new QCheckBox(this)),
    ramenN(new QCheckBox(this)),
    risoCondN(new QCheckBox(this)),
    saltato(new QCheckBox(this)),
    fattoMano(new QCheckBox(this)),
    baseBrodoN(new QComboBox(this)),
    ingredienti(new QLabel(this)),
    ingredienteFreddo0(new QComboBox(this)),
    ingredienteFreddo1(new QComboBox(this)),
    ingredienteFreddo2(new QComboBox(this)),
    ingredienteFreddo3(new QComboBox(this)),
    ingredienteCaldo0(new QComboBox(this)),
    ingredienteCaldo1(new QComboBox(this)),
    ingredienteCaldo2(new QComboBox(this)),
    ingredienteCaldo3(new QComboBox(this)),
    rimuovi1F(new QPushButton(this)),
    rimuovi2F(new QPushButton(this)),
    rimuovi3F(new QPushButton(this)),
    rimuovi1C(new QPushButton(this)),
    rimuovi2C(new QPushButton(this)),
    rimuovi3C(new QPushButton(this)),
    primoIngF(new QWidget(this)),
    secondoIngF(new QWidget(this)),
    terzoIngF(new QWidget(this)),
    quartoIngF(new QWidget(this)),
    primoIngC(new QWidget(this)),
    secondoIngC(new QWidget(this)),
    terzoIngC(new QWidget(this)),
    quartoIngC(new QWidget(this)),
    ancora(new QPushButton(this)),
    inserisci(new QPushButton(this)),
    reset(new QPushButton(this))
{
    QVBoxLayout* layoutInserisci = new QVBoxLayout(this);
    QHBoxLayout* layoutN = new QHBoxLayout();
    QHBoxLayout* layoutP = new QHBoxLayout();
    QHBoxLayout* layoutFC = new QHBoxLayout();
    QHBoxLayout* layoutCheckBase = new QHBoxLayout();
    QHBoxLayout* layoutBottoniSotto = new QHBoxLayout();
    QVBoxLayout* layoutSushi = new QVBoxLayout(wSushi);
    QVBoxLayout* layoutCaldo = new QVBoxLayout(wCaldo);
    QHBoxLayout* infoEurr = new QHBoxLayout();
    QVBoxLayout* URR = new QVBoxLayout();
    QVBoxLayout* infoURR = new QVBoxLayout();
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

    inizioInserisci->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    inizioInserisci->setWordWrap(true);

    nomePiatto->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    nomePiatto->setWordWrap(true);

    piccanteLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    piccanteLabel->setWordWrap(true);

    tipologia->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    tipologia->setWordWrap(true);

    base->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    base->setWordWrap(true);

    avviso->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    avviso->setWordWrap(true);

    infoSushi->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    infoSushi->setWordWrap(true);

    infoCaldo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    infoCaldo->setWordWrap(true);

    ingredienti->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ingredienti->setWordWrap(true);

    inizioInserisci->setText("ATTENZIONE! I campi con l'asterisco sono obbligatori.");
    nomePiatto->setText("Inserisci il nome del piatto *");
    piccanteLabel->setText("Selezionare se si vuole il piatto piccante.");
    piccante->setText("Piccante");
    tipologia->setText("Seleziona la tipologia del piatto *");
    freddo->setText("Piatto Freddo");
    caldo->setText("Piatto Caldo");
    primaScelta->setText("Pesce di prima scelta");
    base->setText("Seleziona l'ingrediente base *");
    riso->setText("Riso");
    spaghetti->setText("Spaghetti");
    avviso->setText("ATTENZIONE! Dopo aver selezionato la tipoloiga e la base del piatto questi campi non sono più modificabili dalla pagina di modifica!");
    infoCaldo->setText("Per creare un piatto di Udon selezionare se si vogliono fatti a mano, per il ramen selezionare il tipo del brodo e per il riso "
                       "selezionare se si vuole che sia saltato nel Wok.");
    infoSushi->setText("Seleziona se vuoi il pesce di prima scelta, l'alga e il numero di pezzi.");
    alga->setText("Alga");
    ramenN->setText("Ramen");
    risoCondN->setText("Riso Condito");
    udonN->setText("Udon");
    fattoMano->setText("Fatto a mano");
    saltato->setText("Saltato nel Wok");
    ancora->setText("Aggiungi ingrediente");
    rimuovi1F->setText("Rimuovi ingrediente");
    rimuovi2F->setText("Rimuovi ingrediente");
    rimuovi3F->setText("Rimuovi ingrediente");
    rimuovi1C->setText("Rimuovi ingrediente");
    rimuovi2C->setText("Rimuovi ingrediente");
    rimuovi3C->setText("Rimuovi ingrediente");
    inserisci->setText("Inserisci Piatto");
    reset->setText("Reset Compilazione");
    ingredienti->setText("Selezionare gli ingredienti da inserire nel piatto."
                         "Il numero minimo di ingredienti è 1 e il massimo è 4."
                         "Dopo aver selezionato un ingrediente premere il "
                         "pulsante accanto per poterne aggiungere un altro."
                         "In automatico, se non viene selezionato alcun ingrediente,"
                         "verrà creato il piatto con il primo ingrediente della lista. Se vengono selezionati "
                         "degli ingredienti doppioni essi verranno inseriti solamente una volta.");
    QStringList numeri = {"1","2","3","4","5","6","7","8"};
    QList<QString> baseBrodo = {"Pesce","Manzo","Pollo"};

    for(int i=0;i<baseBrodo.length();++i) baseBrodoN->addItem(baseBrodo[i]);

    ancora->setObjectName("ancora");
    rimuovi1F->setObjectName("rimuoviF");
    rimuovi2F->setObjectName("rimuoviF");
    rimuovi3F->setObjectName("rimuoviF");
    rimuovi1C->setObjectName("rimuoviC");
    rimuovi2C->setObjectName("rimuoviC");
    rimuovi3C->setObjectName("rimuoviC");

    freddo->setEnabled(true);
    caldo->setEnabled(true);
    riso->setEnabled(true);
    spaghetti->setEnabled(true);

    pezzi->addItems(numeri);

    QList<QString> ingFreddi= {"Salmone crudo","Salmone scottato","Tonno crudo","Tonno scottato","Avocado","Wasabi","Gambero crudo","Gambero fritto"
                             ,"Branzino crudo","Gamberone crudo","Branzino scottato","Surimi","Philadelphia"};

    std::sort(ingFreddi.begin(), ingFreddi.end());

    for(int i=0;i<ingFreddi.length();++i) {
        ingredienteFreddo0->addItem(ingFreddi[i]);
        ingredienteFreddo1->addItem(ingFreddi[i]);
        ingredienteFreddo2->addItem(ingFreddi[i]);
        ingredienteFreddo3->addItem(ingFreddi[i]);
    }

    QList<QString> ingCaldi= {"Manzo saltato","Pollo saltato","Pollo fritto","Prosciutto","Salsa di soia","Germogli di soia","Gamberetti saltati",
                            "Gamberetti lessati","Salmone saltato","Seppie saltate","Calamari saltati","Bamboo","Carote","Mandorle","Piselli",
                            "Funghi","Uovo sodo","Uovo saltato"};

    std::sort(ingCaldi.begin(), ingCaldi.end());

    for(int i=0;i<ingCaldi.length();++i) {
        ingredienteCaldo0->addItem(ingCaldi[i]);
        ingredienteCaldo1->addItem(ingCaldi[i]);
        ingredienteCaldo2->addItem(ingCaldi[i]);
        ingredienteCaldo3->addItem(ingCaldi[i]);
    }

    ingredienteCaldo0->show();
    ingredienteCaldo1->hide();
    ingredienteCaldo2->hide();
    ingredienteCaldo3->hide();

    ingredienteFreddo0->show();
    ingredienteFreddo1->hide();
    ingredienteFreddo2->hide();
    ingredienteFreddo3->hide();

    primoIngF->hide();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->hide();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();
    ancora->hide();

    ing1F->addWidget(ingredienteFreddo0);

    ing2F->addWidget(ingredienteFreddo1);
    ing2F->addWidget(rimuovi1F);

    ing3F->addWidget(ingredienteFreddo2);
    ing3F->addWidget(rimuovi2F);

    ing4F->addWidget(ingredienteFreddo3);
    ing4F->addWidget(rimuovi3F);

    ing1C->addWidget(ingredienteCaldo0);

    ing2C->addWidget(ingredienteCaldo1);
    ing2C->addWidget(rimuovi1C);

    ing3C->addWidget(ingredienteCaldo2);
    ing3C->addWidget(rimuovi2C);

    ing4C->addWidget(ingredienteCaldo3);
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

    tieniTutto->addWidget(ingredienti);
    tieniTutto->addLayout(ING);

    layoutN->addWidget(nomePiatto);
    layoutN->addWidget(nome);

    layoutP->addWidget(piccanteLabel);
    layoutP->addWidget(piccante);

    layoutFC->addWidget(tipologia);
    layoutFC->addWidget(freddo);
    layoutFC->addWidget(caldo);

    primaScelta->hide();

    layoutCheckBase->addWidget(base);
    layoutCheckBase->addWidget(riso);
    layoutCheckBase->addWidget(spaghetti);

    layoutSushi->addWidget(infoSushi);
    layoutSushi->addWidget(primaScelta);
    layoutSushi->addWidget(alga);
    layoutSushi->addWidget(pezzi);

    wSushi->hide();

    layoutCaldo->addWidget(infoCaldo);
    layoutCaldo->addLayout(infoEurr);
    URR->addWidget(udonN);
    URR->addWidget(ramenN);
    URR->addWidget(risoCondN);
    infoURR->addWidget(saltato);
    infoURR->addWidget(fattoMano);
    infoURR->addWidget(baseBrodoN);
    infoEurr->addLayout(URR);
    infoEurr->addLayout(infoURR);

    wCaldo->hide();

    layoutBottoniSotto->addWidget(inserisci);
    layoutBottoniSotto->addWidget(reset);

    layoutInserisci->addWidget(inizioInserisci);
    layoutInserisci->addLayout(layoutN);
    layoutInserisci->addLayout(layoutP);
    layoutInserisci->addLayout(layoutFC);
    layoutInserisci->addLayout(layoutCheckBase);
    layoutInserisci->addWidget(avviso);
    layoutInserisci->addWidget(wSushi);
    layoutInserisci->addWidget(wCaldo);
    layoutInserisci->addLayout(tieniTutto);
    layoutInserisci->addLayout(layoutBottoniSotto);

    connect(freddo,SIGNAL(toggled(bool)),this,SLOT(checkFreddo(bool)));
    connect(caldo,SIGNAL(toggled(bool)),this,SLOT(checkCaldo(bool)));
    connect(riso,SIGNAL(toggled(bool)),this,SLOT(checkRiso(bool)));
    connect(spaghetti,SIGNAL(toggled(bool)),this,SLOT(checkSpaghetti(bool)));
    connect(ramenN,SIGNAL(toggled(bool)),this,SLOT(checkRamen(bool)));
    connect(udonN,SIGNAL(toggled(bool)),this,SLOT(checkUdon(bool)));
    connect(risoCondN,SIGNAL(toggled(bool)),this,SLOT(checkRisoCond(bool)));
    connect(ancora,SIGNAL(clicked()),this,SLOT(aggiungiIngredienti()));
    connect(reset,SIGNAL(clicked()),this,SLOT(resetTutto()));
    connect(freddo,SIGNAL(stateChanged(int)),this,SLOT(resetCaldoFreddo()));
    connect(caldo,SIGNAL(stateChanged(int)),this,SLOT(resetCaldoFreddo()));
    connect(riso,SIGNAL(stateChanged(int)),this,SLOT(resetBase()));
    connect(spaghetti,SIGNAL(stateChanged(int)),this,SLOT(resetBase()));
    connect(rimuovi1F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
    connect(rimuovi2F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
    connect(rimuovi3F,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
    connect(rimuovi1C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
    connect(rimuovi2C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
    connect(rimuovi3C,SIGNAL(clicked()),this,SLOT(rimuoviIngredienti()));
}

QPushButton* Inserisci::getBottoneInserisci() const {
    return inserisci;
}

piatto* Inserisci::dimmiNuovo() {
    piatto* ritorno = nullptr;
    //nome
    std::string nomeNuovo=nome->text().toStdString();
    //ingredienti
    std::vector<std::string> nuoviIng;
    std::string primoIng;
    std::string secondoIng;
    std::string terzoIng;
    std::string quartoIng;
    bool controllodoppio=true;
    if(freddo->isChecked()==true) {
        //primo ingrediente
        if(ingredienteFreddo0->isVisible()) primoIng = ingredienteFreddo0->currentText().toStdString();
        if(primoIng!="") nuoviIng.push_back(primoIng);
        //secondo ingrediente
        if(ingredienteFreddo1->isVisible()) secondoIng = ingredienteFreddo1->currentText().toStdString();
        if(secondoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(secondoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(secondoIng);
        }
        //terzo ingrediente
        if(ingredienteFreddo2->isVisible()) terzoIng = ingredienteFreddo2->currentText().toStdString();
        if(terzoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(terzoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(terzoIng);
        }
        //quarto ingrediente
        if(ingredienteFreddo3->isVisible()) quartoIng = ingredienteFreddo3->currentText().toStdString();
        if(quartoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(quartoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(quartoIng);
        }
    }
    if(caldo->isChecked()==true) {
        //primo ingrediente
        if(ingredienteCaldo0->isVisible()) primoIng = ingredienteCaldo0->currentText().toStdString();
        if(primoIng!="") nuoviIng.push_back(primoIng);
        //secondo ingrediente
        if(ingredienteCaldo1->isVisible()) secondoIng = ingredienteCaldo1->currentText().toStdString();
        if(secondoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(secondoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(secondoIng);
        }
        //terzo ingrediente
        if(ingredienteCaldo2->isVisible()) terzoIng = ingredienteCaldo2->currentText().toStdString();
        if(terzoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(terzoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(terzoIng);
        }
        //quarto ingrediente
        if(ingredienteCaldo3->isVisible()) quartoIng = ingredienteCaldo3->currentText().toStdString();
        if(quartoIng!="") {
            for(unsigned int i=0;controllodoppio==true && i<nuoviIng.size();++i) {
                if(quartoIng==nuoviIng[i]) controllodoppio=false;
                else controllodoppio=true;
            }
            if(controllodoppio)nuoviIng.push_back(quartoIng);
        }
    }
    //piccante
    bool piccanteNuovo=piccante->isChecked()==true ? true : false;
    //base piatto
    int baseNuovo=riso->isChecked()==true ? 1 : 2;
    //alga
    bool algaNuovo=alga->isChecked()==true ? true : false;
    //numero sushi
    int pezziNuovo=pezzi->currentText().toInt();
    //prima scelta
    bool primaSceltaNuovo=primaScelta->isChecked()==true ? true : false;
    //saltato
    bool saltatoNuovo=saltato->isChecked()==true ? true : false;
    //base brodo
    int baseBrodoNuovo = 0;
    if(baseBrodoN->currentText()=="Pollo") baseBrodoNuovo=3;
    else if(baseBrodoN->currentText()=="Manzo") baseBrodoNuovo=2;
    else if(baseBrodoN->currentText()=="Pesce") baseBrodoNuovo=1;
    else baseBrodoNuovo=1;
    //fatti a mano
    bool fattiManoNuovo = fattoMano->isChecked()==true ? true : false;
    if(udonN->isChecked()==true) ritorno = new udon(nomeNuovo,nuoviIng,baseNuovo,piccanteNuovo,fattiManoNuovo);
    else if(freddo->isChecked()==true) ritorno = new sushi(nomeNuovo,nuoviIng,algaNuovo,pezziNuovo,primaSceltaNuovo,baseNuovo,piccanteNuovo);
    else if(risoCondN->isChecked()==true) ritorno = new risoCondito(nomeNuovo,nuoviIng,piccanteNuovo,baseNuovo,saltatoNuovo);
    else if(ramenN->isChecked()==true) ritorno = new ramen(nomeNuovo,nuoviIng,baseNuovo,piccanteNuovo,baseBrodoNuovo);
    return ritorno;
}

bool Inserisci::controlloInserimento() {
    //Controllo che abbia inserito il nome
    bool controllo=false;
    if(nome->text()=="") return controllo=false;
    else controllo=true;
    //controllo che abbia scelto se il piatto è caldo o freddo
    if(caldo->isChecked() || freddo->isChecked()) controllo=true;
    else controllo=false;
    //controllo che abbia scelto la base del piatto
    if(riso->isChecked() || spaghetti->isChecked()) controllo=true;
    else controllo=false;
    //se ha spuntato freddo posso smettere di fare i controlli
    if(freddo->isChecked()==true) return controllo;
    //controllo che selezioni almeno uno dei tre tra riso,udon e ramen
    if(caldo->isChecked() && (ramenN->isChecked() || udonN->isChecked() || risoCondN->isChecked())) controllo=true;
    else controllo=false;
    //se ho selezionato riso o udon posso smettere di fare i controlli
    if(udonN->isChecked()==true) return controllo;
    if(risoCondN->isChecked()==true) return controllo;
    return controllo;
}

void Inserisci::checkFreddo(bool f) {
    if(f) {
        caldo->setEnabled(false);
        spaghetti->setEnabled(false);
        riso->setCheckState(Qt::Checked);
    } else {
        caldo->setEnabled(true);
        riso->setCheckState(Qt::Unchecked);
    }
    primoIngF->show();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->hide();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();
    primaScelta->show();
    ancora->show();
    wSushi->show();
    ingredienteCaldo0->setCurrentIndex(0);
    ingredienteCaldo1->setCurrentIndex(0);
    ingredienteCaldo2->setCurrentIndex(0);
    ingredienteCaldo3->setCurrentIndex(0);
    ingredienteFreddo0->setCurrentIndex(0);
    ingredienteFreddo1->setCurrentIndex(0);
    ingredienteFreddo2->setCurrentIndex(0);
    ingredienteFreddo3->setCurrentIndex(0);
}

void Inserisci::checkCaldo(bool c) {
    if(c) freddo->setEnabled(false);
    else freddo->setEnabled(true);
    primoIngF->hide();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->show();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();
    ancora->show();
    wCaldo->show();
    fattoMano->hide();
    saltato->hide();
    baseBrodoN->hide();
    ingredienteCaldo0->setCurrentIndex(0);
    ingredienteCaldo1->setCurrentIndex(0);
    ingredienteCaldo2->setCurrentIndex(0);
    ingredienteCaldo3->setCurrentIndex(0);
    ingredienteFreddo0->setCurrentIndex(0);
    ingredienteFreddo1->setCurrentIndex(0);
    ingredienteFreddo2->setCurrentIndex(0);
    ingredienteFreddo3->setCurrentIndex(0);
}

void Inserisci::checkRiso(bool r) {
    if(r) {
        spaghetti->setEnabled(false);
        udonN->setEnabled(false);
        ramenN->setEnabled(false);
        risoCondN->setCheckState(Qt::Checked);
    } else {
        spaghetti->setEnabled(true);
        udonN->setEnabled(true);
        ramenN->setEnabled(true);
    }
}

void Inserisci::checkSpaghetti(bool s) {
    if(s) {
        riso->setEnabled(false);
        risoCondN->setEnabled(false);
    } else {
        riso->setEnabled(true);
        risoCondN->setEnabled(true);
    }
}

void Inserisci::checkRamen(bool r) {
    if(r) {
        risoCondN->setEnabled(false);
        udonN->setEnabled(false);
        baseBrodoN->show();
        spaghetti->setCheckState(Qt::Checked);
    } else {
        risoCondN->setEnabled(true);
        udonN->setEnabled(true);
        baseBrodoN->hide();
        riso->setEnabled(true);
        spaghetti->setCheckState(Qt::Unchecked);
    }
}

void Inserisci::checkUdon(bool u) {
    if(u) {
        ramenN->setEnabled(false);
        risoCondN->setEnabled(false);
        fattoMano->show();
        spaghetti->setCheckState(Qt::Checked);
    } else {
        ramenN->setEnabled(true);
        risoCondN->setEnabled(true);
        fattoMano->hide();
        riso->setEnabled(true);
        spaghetti->setCheckState(Qt::Unchecked);
    }
}

void Inserisci::checkRisoCond(bool rc) {
    if(rc) {
        ramenN->setEnabled(false);
        udonN->setEnabled(false);
        saltato->show();
        riso->setCheckState(Qt::Checked);
    } else {
        ramenN->setEnabled(true);
        udonN->setEnabled(true);
        saltato->hide();
        spaghetti->setEnabled(true);
        riso->setCheckState(Qt::Unchecked);
    }
}

void Inserisci::aggiungiIngredienti() {
    if(freddo->isChecked()) {
        if (primoIngF->isVisible() == true && secondoIngF->isVisible() == false ) {
            ingredienteFreddo1->show();
            secondoIngF->show();
            return;
        }
        if (secondoIngF->isVisible() == true && terzoIngF->isVisible() == false) {
            ingredienteFreddo2->show();
            terzoIngF->show();
            return;
        }
        if (terzoIngF->isVisible() == true && quartoIngF->isVisible() == false) {
            ingredienteFreddo3->show();
            quartoIngF->show();
            ancora->hide();
            if(quartoIngF->isVisible() == true) ancora->hide();
            return;
        }
    }
    if(caldo->isChecked()) {
        if (primoIngC->isVisible() == true && secondoIngC->isVisible() == false ) {
            ingredienteCaldo1->show();
            secondoIngC->show();
            return;
        }
        if (secondoIngC->isVisible() == true && terzoIngC->isVisible() == false) {
            ingredienteCaldo2->show();
            terzoIngC->show();
            return;
        }
        if (terzoIngC->isVisible() == true && quartoIngC->isVisible() == false) {
            ingredienteCaldo3->show();
            quartoIngC->show();
            ancora->hide();
            if(quartoIngC->isVisible()==true) ancora->hide();
            return;
        }
    }
}

void Inserisci::rimuoviIngredienti() {
    int contaIng = 1;
    if(freddo->isChecked()) {
        if (secondoIngF->isVisible() == true) {
            ingredienteFreddo1->hide();
            secondoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (terzoIngF->isVisible() == true) {
            ingredienteFreddo2->hide();
            terzoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }

        if (quartoIngF->isVisible() == true) {
            ingredienteFreddo2->hide();
            quartoIngF->hide();
            contaIng=1;
            if (secondoIngF->isVisible() == true) contaIng++;
            if (terzoIngF->isVisible() == true) contaIng++;
            if (quartoIngF->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
    } else if(caldo->isChecked()) {
        if (secondoIngC->isVisible() == true) {
            ingredienteCaldo1->hide();
            secondoIngC->hide();
            contaIng=1;
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (terzoIngC->isVisible() == true) {
            ingredienteCaldo2->hide();
            terzoIngC->hide();
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
        if (quartoIngC->isVisible() == true) {
            ingredienteCaldo3->hide();
            quartoIngC->hide();
            if (secondoIngC->isVisible() == true) contaIng++;
            if (terzoIngC->isVisible() == true) contaIng++;
            if (quartoIngC->isVisible() == true) contaIng++;
            if(contaIng<4) ancora->show();
            return;
        }
    }
}

void Inserisci::resetTutto() {
    nome->setText("");
    piccante->setChecked(false);
    freddo->setEnabled(true);
    freddo->setChecked(false);
    caldo->setEnabled(true);
    caldo->setChecked(false);
    ancora->hide();
    riso->setEnabled(true);
    riso->setChecked(false);
    spaghetti->setEnabled(true);
    spaghetti->setChecked(false);
    wSushi->hide();
    primaScelta->setChecked(false);
    alga->setChecked(false);
    wCaldo->hide();
    ramenN->setChecked(false);
    udonN->setChecked(false);
    baseBrodoN->setCurrentText("Pesce");
    risoCondN->setChecked(false);
    fattoMano->setChecked(false);
    saltato->setChecked(false);
    primoIngF->hide();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->hide();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();
}

void Inserisci::resetCaldoFreddo() {
    if(caldo->isEnabled()==true && freddo->isEnabled()==true) {
    primaScelta->hide();
    spaghetti->setEnabled(true);
    riso->setEnabled(true);
    riso->setCheckState(Qt::Unchecked);
    spaghetti->setCheckState(Qt::Unchecked);
    ancora->hide();
    primoIngF->hide();
    secondoIngF->hide();
    terzoIngF->hide();
    quartoIngF->hide();
    primoIngC->hide();
    secondoIngC->hide();
    terzoIngC->hide();
    quartoIngC->hide();
    wSushi->hide();
    wCaldo->hide();
    ramenN->setChecked(false);
    udonN->setChecked(false);
    risoCondN->setChecked(false);
    baseBrodoN->setCurrentText("Pesce");
    fattoMano->setChecked(false);
    saltato->setChecked(false);
    primaScelta->setChecked(false);
    alga->setChecked(false);
    }
}

void Inserisci::resetBase() {
    if(riso->isEnabled()==true && spaghetti->isEnabled()==true) {
    ramenN->setCheckState(Qt::Unchecked);
    risoCondN->setCheckState(Qt::Unchecked);
    udonN->setCheckState(Qt::Unchecked);
    }
}
