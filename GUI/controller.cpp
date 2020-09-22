#include"GUI/controller.h"

Controller::Controller(Modello* m,QWidget* p):
    parent(p),
    modello(m),
    menu(new MenuIniziale(this)),
    ricerca(new Ricerca(this)),
    menuComp(new menuPiatti(this)),
    home(new layoutPrinc(this)),
    inserisci(new Inserisci(this)),
    inserisciDolce(new InserisciDolce(this)),
    layoutModifica(new Modifica(this)),
    layoutModDolce(new ModificaDolce(this)),
    file(QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ProgettoP2/SALVATAGGIO","File XML(*.xml)"))
{
    QVBoxLayout* controller = new QVBoxLayout(this);

    setMinimumSize(800,800);
    setWindowTitle("Sapori d'Oriente");
    setWindowIcon(QPixmap(":/logo.jpg"));

    QRect screenGeometry = QGuiApplication::screens()[0]->geometry();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screenGeometry));

    controller->setMenuBar(menu);

    controller->addWidget(home);
    controller->addWidget(ricerca);
    controller->addWidget(menuComp);
    controller->addWidget(inserisci);
    controller->addWidget(inserisciDolce);

    home->show();
    ricerca->hide();
    menuComp->hide();
    inserisci->hide();
    inserisciDolce->hide();

    caricaDati();

    connect(menuComp->getModifica(),SIGNAL(clicked()),this,SLOT(mostraModifica()));
    connect(menuComp->getRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviPiatto()));
    connect(ricerca->getModificaRic(),SIGNAL(clicked()),this,SLOT(mostraModificaRic()));
    connect(ricerca->getRimuoviRic(),SIGNAL(clicked()),this,SLOT(rimuoviPiattoRic()));
    connect(layoutModDolce->getSalvaModDolce(),SIGNAL(clicked()),this,SLOT(salvaModDolce()));
    connect(layoutModifica->getBottoneSalva(),SIGNAL(clicked()),this,SLOT(salvaMod()));
    connect(inserisci->getBottoneInserisci(),SIGNAL(clicked()),this,SLOT(inserisciPiatto()));
    connect(inserisciDolce->getBottoneInserisciDolce(),SIGNAL(clicked()),this,SLOT(inserisciDolceNuovo()));
    connect(ricerca->getCercaBut(),SIGNAL(clicked()),this,SLOT(ricercaPiatti()));
}

Controller::~Controller() {}

void Controller::caricaDati() {
    if(file!="") {
        modello->setPercorso(file.toStdString());
        modello->Carica();
        abilita();
        if(contaPiatti()==0) {
            Avviso* avvisoCarica = new Avviso("Warning","Attenzione,non sono presenti piatti.");
            avvisoCarica->exec();
        } else {
            lista<piatto*>::iteratoreConst inizioLista = modello->inizioCIT();
            lista<piatto*>::iteratoreConst fineLista = modello->fineCIT();

            for(;inizioLista!=fineLista;++inizioLista) {
                menuComp->getLista()->aggiungiPiatto(*inizioLista);
            }
            modello->setSalvaMod(true);
        }
    } else {
        disabilita();
        modello->setPercorso(file.toStdString());
    }
}

void Controller::caricaDatiXML() {
    QString caricaAncora = QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ProgettoP2/SALVATAGGIO","File XML(*.xml)");
    if(caricaAncora!="") {
        modello->setPercorso(caricaAncora.toStdString());
        modello->Carica();
        abilita();
        if(contaPiatti()==0) {
            disabilita();
            Avviso* avvisoCarica = new Avviso("Warning","Attenzione,non sono presenti piatti. Prova a caricare un altro file!");
            avvisoCarica->exec();
        } else {
            lista<piatto*>::iteratoreConst inizioLista = modello->inizioCIT();
            lista<piatto*>::iteratoreConst fineLista = modello->fineCIT();

            if(menuSelezionato=="Menu Completo") {
                for(;inizioLista!=fineLista;++inizioLista) {
                    menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Sushi") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<sushi*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Udon") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<udon*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Ramen") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<ramen*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Riso Condito") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<risoCondito*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else {
                for(;inizioLista!=fineLista;++inizioLista) {
                    menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            }
            modello->setSalvaMod(true);
        }
    } else {
        modello->setPercorso(file.toStdString());
    }
}

int Controller::contaPiatti() const {
    return modello->contaPiatti();
}

Modello* Controller::getModello() const {
    return modello;
}

void Controller::disabilita() {
    home->show();
    ricerca->hide();
    menuComp->hide();
    inserisci->hide();
    menu->getSalva()->setEnabled(false);
    menu->getRicerca()->setEnabled(false);
    menu->getMenuComp()->setEnabled(false);
    menu->getInserisci()->setEnabled(false);
    home->getMenuBut()->setEnabled(false);
    menu->getStampa()->setEnabled(false);
}

void Controller::abilita() {
    home->show();
    ricerca->hide();
    menuComp->hide();
    inserisci->hide();
    menu->getSalva()->setEnabled(true);
    menu->getRicerca()->setEnabled(true);
    menu->getMenuComp()->setEnabled(true);
    menu->getInserisci()->setEnabled(true);
    home->getMenuBut()->setEnabled(true);
    menu->getStampa()->setEnabled(true);
}

bool Controller::controlloDoppione(piatto* p) const {
    bool controlloDoppio=false;
    lista<piatto*>* listaMenu = modello->getListaPiatti();
    for(lista<piatto*>::iteratore cit=listaMenu->inizio();cit!=listaMenu->fine();++cit) {
        if(*p==(**cit)) {
            controlloDoppio=true;
            return controlloDoppio;
        }
        else controlloDoppio=false;
    }
    return controlloDoppio;
}

void Controller::stampa() {
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;

    std::string listaCibo= "<!doctype html>"
                           "<html>"
                           "<body>"
                           "<h1 style=\"font:20px bold Arial, sans-serif;\" align='center'>MENU SAPORI D'ORIENTE</h1>";

    lista<piatto*>::iteratoreConst inizioLista = modello->inizioCIT();
    lista<piatto*>::iteratoreConst fineLista = modello->fineCIT();

    std::string path;
    std::string immagine;

    for(;inizioLista!=fineLista;++inizioLista) {
        if(dynamic_cast<sushi*>(*inizioLista)) path=":/IMMAGINI/sushi.jpg";
        if(dynamic_cast<udon*>(*inizioLista)) path=":/IMMAGINI/udon.jpg";
        if(dynamic_cast<risoCondito*>(*inizioLista)) path=":/IMMAGINI/riso.jpg";
        if(dynamic_cast<ramen*>(*inizioLista)) path=":/IMMAGINI/ramen.jpg";
        if(dynamic_cast<gelatoFritto*>(*inizioLista)) path=":IMMAGINI/dolce.jpg";
        immagine.append("<li><img width=\"90\" height:\"90\" src="+path+"></li>");
        listaCibo.append("<ul style=\"list-style-type:none; font:12px Arial, sans-serif;\" align='center'>"+immagine+(*inizioLista)->getInfoStampa()+"</ul>");
        immagine.clear();
    }

    std::string daStampare = listaCibo+"</body>"
                                       "</html>";
    doc.setTextWidth(-1);
    doc.setHtml(QString::fromStdString(daStampare));
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);

    if(doc.isEmpty()==false) {
        Avviso* avvisoStampa = new Avviso("Informazione","Salvataggio del file avvenuto correttamente!");
        avvisoStampa->exec();
    } else {
        Avviso* avvisoStampa = new Avviso("Warning","Salvataggio del file non avvenuto, contattare l'amministratore!");
        avvisoStampa->exec();
    }
}

void Controller::esci() {
    close();
}

void Controller::carica() {
    caricaDatiXML();
}

void Controller::vediRicerca() {
    home->hide();
    menuComp->hide();
    inserisci->hide();
    inserisciDolce->hide();
    ricerca->resetCampi();
    ricerca->show();
}

void Controller::vediMenuCompleto() {
    home->hide();
    ricerca->hide();
    inserisci->hide();
    inserisciDolce->hide();
    menuComp->show();
}

void Controller::setMenuSelezionato(const QString& s) {
    menuSelezionato=s;
}

void Controller::vediLayoutPrinc() {
    ricerca->hide();
    menuComp->hide();
    inserisci->hide();
    inserisciDolce->hide();
    home->show();
}

void Controller::vediInserisci() {
    ricerca->hide();
    menuComp->hide();
    home->hide();
    inserisciDolce->hide();
    inserisci->resetTutto();
    inserisci->show();
}

void Controller::vediInserisciDolce() {
    ricerca->hide();
    menuComp->hide();
    home->hide();
    inserisciDolce->resetCampi();
    inserisci->hide();
    inserisciDolce->show();
}

void Controller::vediInformazioniSviluppatore() {
    Avviso* informazioni = new Avviso("Informazione","Progetto realizzato da: Margherita Mitillo con numero di matricola 1098971.\n Per qualsiasi necessità"
                                                     " contattarla tramite la seguente email: \n margherita.mitillo@studenti.unipd.it");
    informazioni->exec();
}

void Controller::vediInformazioniMenu() {
    int totale = modello->contaPiatti();
    int riso = modello->contaRiso();
    int udon = modello->contaUdon();
    int ramen = modello->contaRamen();
    int sushi = modello->contaSushi();
    int gelato = modello->contaGelato();
    QString info = "Il numero totale dei piatti è ";
    info.append(QString::number(totale));
    info.append("\n Il numero dei piatti di riso è ");
    info.append(QString::number(riso));
    info.append("\n Il numero dei piatti di udon è ");
    info.append(QString::number(udon));
    info.append("\n Il numero dei piatti di ramen è ");
    info.append(QString::number(ramen));
    info.append("\n Il numero dei piatti di sushi è ");
    info.append(QString::number(sushi));
    info.append("\n Il numero dei piatti di gelato fritto è ");
    info.append(QString::number(gelato));
    Avviso* informazioni = new Avviso("Informazione",info);
    informazioni->exec();
}

void Controller::mostraModifica() {
    if(menuComp->getLista()->currentItem()==nullptr) {
        Avviso* nessunPiattoSelezionato = new Avviso("Warning","Nessun piatto selezionato, seleziona un piatto da modificare!");
        nessunPiattoSelezionato->exec();
    } else {
        if(menuComp->getLista()->currentItem()->getSelezionato()->getBase()==3) {
            layoutModDolce->setPiattoDolce(menuComp->getLista()->currentItem()->getSelezionato());
            layoutModDolce->compilaModDolce();
            layoutModDolce->exec();
        } else {
            layoutModifica->setPiatto(menuComp->getLista()->currentItem()->getSelezionato());
            layoutModifica->compilaModifica();
            layoutModifica->exec();
        }
    }
}

void Controller::mostraModificaRic() {
    if(ricerca->getListaRic()->currentItem()==nullptr) {
        Avviso* nessunPiattoSelezionato = new Avviso("Warning","Nessun piatto selezionato, seleziona un piatto da modificare!");
        nessunPiattoSelezionato->exec();
    } else {
        if(ricerca->getListaRic()->currentItem()->getSelezionato()->getBase()==3) {
            layoutModDolce->setPiattoDolce(ricerca->getListaRic()->currentItem()->getSelezionato());
            layoutModDolce->compilaModDolce();
            layoutModDolce->exec();
        } else {
             layoutModifica->setPiatto(ricerca->getListaRic()->currentItem()->getSelezionato());
             layoutModifica->compilaModifica();
             layoutModifica->exec();
        }
    }
}

void Controller::salvaMod() {
    layoutModifica->setNuoviCampi();
    modello->Salva();
    menuComp->getLista()->clear();
    caricaDati();
    home->hide();
    ricerca->hide();
    inserisci->hide();
    inserisciDolce->hide();
    menuComp->show();
    layoutModifica->close();
    Avviso* avvisoModifica = new Avviso("Informazione","Modifica avvenuta con successo!");
    avvisoModifica->exec();
}

void Controller::salvaModDolce() {
    layoutModDolce->setNuoviCampiDolce();
    modello->Salva();
    menuComp->getLista()->clear();
    caricaDati();
    home->hide();
    ricerca->hide();
    inserisci->hide();
    inserisciDolce->hide();
    menuComp->show();
    layoutModDolce->close();
    Avviso* avvisoModifica = new Avviso("Informazione","Modifica avvenuta con successo!");
    avvisoModifica->exec();
}

void Controller::inserisciPiatto() {
    piatto* daInserire = inserisci->dimmiNuovo();
    if(inserisci->controlloInserimento()==false) {
        Avviso* inserimentoSbagliato = new Avviso("Critical","Inserimento scorreto,ricontrolla i campi!");
        inserimentoSbagliato->exec();
    } else if(daInserire==nullptr) {
        Avviso* piattoNonEsiste = new Avviso("Critical","Piatto non creato,hai compilato in modo scorretto!");
        piattoNonEsiste->exec();
    } else if(controlloDoppione(daInserire)) {
        Avviso* piattoDoppione = new Avviso("Warning","Piatto doppione,hai già creato un piatto così!");
        piattoDoppione->exec();
    } else {
    modello->inserisci(daInserire);
    modello->Salva();
    menuComp->getLista()->clear();
    caricaDati();
    home->hide();
    inserisci->resetTutto();
    inserisci->hide();
    inserisciDolce->resetCampi();
    inserisciDolce->hide();
    menuComp->show();
    }
}

void Controller::inserisciDolceNuovo() {
    piatto* daInserire = inserisciDolce->nuovoDolce();
    if(inserisciDolce->controllo()==false) {
        Avviso* inserimentoSbagliato = new Avviso("Critical","Inserimento scorreto,ricontrolla i campi!");
        inserimentoSbagliato->exec();
    } else if (daInserire==nullptr) {
        Avviso* piattoNonEsiste = new Avviso("Critical","Piatto non creato,hai compilato in modo scorretto!");
        piattoNonEsiste->exec();
    } else if (controlloDoppione(daInserire)) {
        Avviso* piattoDoppione = new Avviso("Warning","Piatto doppione,hai già creato un piatto così!");
        piattoDoppione->exec();
    } else {
        modello->inserisci(daInserire);
        modello->Salva();
        menuComp->getLista()->clear();
        caricaDati();
        home->hide();
        inserisci->resetTutto();
        inserisci->hide();
        inserisciDolce->resetCampi();
        inserisciDolce->hide();
        menuComp->show();
    }
}

void Controller::caricaDatiSelezionato() {

    menuComp->getLista()->clear();

    lista<piatto*>::iteratoreConst inizioLista = modello->inizioCIT();
    lista<piatto*>::iteratoreConst fineLista = modello->fineCIT();

    if(menuSelezionato=="Menu Completo") {
        for(;inizioLista!=fineLista;++inizioLista) {
            menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    } else if(menuSelezionato=="Sushi") {
        for(;inizioLista!=fineLista;++inizioLista) {
           if(dynamic_cast<sushi*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    } else if(menuSelezionato=="Udon") {
        for(;inizioLista!=fineLista;++inizioLista) {
           if(dynamic_cast<udon*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    } else if(menuSelezionato=="Ramen") {
        for(;inizioLista!=fineLista;++inizioLista) {
           if(dynamic_cast<ramen*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    } else if (menuSelezionato=="Riso Condito"){
        for(;inizioLista!=fineLista;++inizioLista) {
           if(dynamic_cast<risoCondito*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    } else {
        for(;inizioLista!=fineLista;++inizioLista) {
           if(dynamic_cast<gelatoFritto*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
        }
    }
}

void Controller::rimuoviPiatto() {
    if(menuComp->getLista()->currentItem()==nullptr) {
        Avviso* nessunPiattoSelezionatoElimina = new Avviso("Warning","Nessun piatto selezionato, seleziona un piatto da eliminare!");
        nessunPiattoSelezionatoElimina->exec();
    } else {
    modello->rimuovi(menuComp->getLista()->currentItem()->getSelezionato());
    modello->Salva();
    menuComp->getLista()->clear();
    caricaDati();
    vediMenuCompleto();
    if(contaPiatti()!=0) {
    Avviso* eliminatoCorrettamente = new Avviso("Informazione","Piatto eliminato correttamente!");
    eliminatoCorrettamente->exec();
    } else {
        home->show();
        menuComp->hide();
    }
    }
}

void Controller::rimuoviPiattoRic() {
    if(ricerca->getListaRic()->currentItem()==nullptr) {
        Avviso* nessunPiattoSelezionatoElimina = new Avviso("Warning","Nessun piatto selezionato, seleziona un piatto da eliminare!");
        nessunPiattoSelezionatoElimina->exec();
    } else {
    modello->rimuovi(ricerca->getListaRic()->currentItem()->getSelezionato());
    modello->Salva();
    menuComp->getLista()->clear();
    caricaDati();
    if(contaPiatti()!=0) {
    Avviso* eliminatoCorrettamente = new Avviso("Informazione","Piatto eliminato correttamente!");
    eliminatoCorrettamente->exec();
    } else {
        home->show();
        menuComp->hide();
    }
    }
}

void Controller::ricercaPiatti() {

    ricerca->getListaRic()->clear();

    if(ricerca->getPiccante()==false && ricerca->getRiso()==4 && ricerca->getSpaghetti()==4 && ricerca->getCaldo()=="niente" && ricerca->getFreddo()=="niente" && ricerca->getDolce()==4) {
        Avviso* ricercaNonEffettuata = new Avviso("Critical","Ricerca non effettuata, non hai selezionato alcun campo!");
        ricercaNonEffettuata->exec();
        ricerca->getListaRic()->clear();
        return;
    }

    lista<piatto*>::iteratoreConst inizioLista = modello->inizioCIT();
    lista<piatto*>::iteratoreConst fineLista = modello->fineCIT();

    for(;inizioLista!=fineLista;++inizioLista) {
        //solo piccante
        if(ricerca->getPiccante()==true && ricerca->getRiso()==4 && ricerca->getSpaghetti()==4 && ricerca->getDolce()==4) {
            if((*inizioLista)->getPiccante()==true) {
                 ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //piccante e riso
        if(ricerca->getPiccante()==true && ricerca->getRiso()==1 && ricerca->getSpaghetti()==4 && ricerca->getDolce()==4) {
            if((*inizioLista)->getPiccante()==true && (*inizioLista)->getBase()==1) {
                ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //solo riso
        if(ricerca->getRiso()==1 && ricerca->getSpaghetti()==4 && ricerca->getPiccante()==false && ricerca->getDolce()==4) {
            if((*inizioLista)->getBase()==1) {
                 ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //solo spaghetti
        if(ricerca->getSpaghetti()==2 && ricerca->getRiso()==4 && ricerca->getPiccante()==false && ricerca->getDolce()==4) {
            if((*inizioLista)->getBase()==2) {
                 ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //piccante e spaghetti
        if(ricerca->getPiccante()==true && ricerca->getSpaghetti()==2 && ricerca->getRiso()==3 && ricerca->getDolce()==4) {
            if((*inizioLista)->getPiccante()==true && (*inizioLista)->getBase()==2) {
                ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //caldo
        if(ricerca->getCaldo()=="piattoCaldo") {
            if(dynamic_cast<piattoCaldo*>(*inizioLista) && (*inizioLista)->getBase()!=3) {
                ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //freddo
        if(ricerca->getFreddo()=="piattoFreddo") {
            if(dynamic_cast<piattoFreddo*>(*inizioLista) && (*inizioLista)->getBase()!=3) {
                ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
        //dolce
        if(ricerca->getDolce()==3) {
            if((*inizioLista)->getBase()==3) {
                ricerca->getListaRic()->aggiungiPiatto(*inizioLista);
            }
        }
    }
}
