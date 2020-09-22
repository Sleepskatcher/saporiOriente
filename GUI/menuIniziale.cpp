#include"menuIniziale.h"

MenuIniziale::MenuIniziale(QWidget* p):
    parent(p),
    file(new QMenu("File",p)),
    home(new QAction("Home",p)),
    carica(new QAction("Carica file",p)),
    salva(new QAction("Salva",p)),
    stampa(new QAction("Stampa Menu",p)),
    esci(new QAction("Esci",p)),
    listapiatti(new QMenu("Menu",p)),
    menuComp(new QAction("Menu Completo",p)),
    sushi(new QAction("Sushi",p)),
    udon(new QAction("Udon",p)),
    ramen(new QAction("Ramen",p)),
    gelatoFritto(new QAction("Gelato Fritto",p)),
    riso(new QAction("Riso Condito",p)),
    ricerca(new QAction("Ricerca",p)),
    inserisci(new QMenu("Inserisci",p)),
    datiMenu(new QMenu("Informazioni",p)),
    infoMenu(new QAction("Informazioni sul Menu",p)),
    info(new QAction("Assistenza",p)),
    dolce(new QAction("Inserisci dolce",p)),
    piatto(new QAction("Inserisci piatto principale",p)),
    m_sigmapper(new QSignalMapper(p))
{

    addMenu(file);

    file->addAction(home);
    file->addAction(carica);
    file->addAction(salva);
    file->addAction(stampa);
    file->addAction(esci);

    addMenu(listapiatti);

    listapiatti->addAction(menuComp);
    listapiatti->addAction(sushi);
    listapiatti->addAction(udon);
    listapiatti->addAction(ramen);
    listapiatti->addAction(riso);
    listapiatti->addAction(gelatoFritto);


    addAction(ricerca);
    addMenu(inserisci);

    inserisci->addAction(piatto);
    inserisci->addAction(dolce);

    addMenu(datiMenu);

    datiMenu->addAction(infoMenu);
    datiMenu->addAction(info);

    //1
    connect(menuComp,SIGNAL(triggered()),m_sigmapper,SLOT(map()));
    connect(ramen,SIGNAL(triggered()),m_sigmapper,SLOT(map()));
    connect(sushi,SIGNAL(triggered()),m_sigmapper,SLOT(map()));
    connect(udon,SIGNAL(triggered()),m_sigmapper,SLOT(map()));
    connect(riso,SIGNAL(triggered()),m_sigmapper,SLOT(map()));
    connect(gelatoFritto,SIGNAL(triggered()),m_sigmapper,SLOT(map()));

    //2
    m_sigmapper->setMapping(menuComp,"Menu Completo");
    m_sigmapper->setMapping(sushi,"Sushi");
    m_sigmapper->setMapping(udon,"Udon");
    m_sigmapper->setMapping(riso,"Riso Condito");
    m_sigmapper->setMapping(ramen,"Ramen");
    m_sigmapper->setMapping(gelatoFritto,"Gelato Fritto");

    //3
    connect(m_sigmapper,SIGNAL(mapped(QString)),parent,SLOT(setMenuSelezionato(const QString&)));

    connect(stampa,SIGNAL(triggered()),parent,SLOT(stampa()));
    connect(esci,SIGNAL(triggered()),parent,SLOT(esci()));
    connect(ricerca,SIGNAL(triggered()),parent,SLOT(vediRicerca()));
    connect(home,SIGNAL(triggered()),parent,SLOT(vediLayoutPrinc()));
    connect(carica,SIGNAL(triggered()),parent,SLOT(carica()));
    connect(menuComp,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(menuComp,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
    connect(sushi,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
    connect(sushi,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(ramen,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
    connect(ramen,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(udon,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
    connect(udon,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(riso,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
    connect(riso,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(piatto,SIGNAL(triggered()),parent,SLOT(vediInserisci()));
    connect(dolce,SIGNAL(triggered()),parent,SLOT(vediInserisciDolce()));
    connect(infoMenu,SIGNAL(triggered()),parent,SLOT(vediInformazioniMenu()));
    connect(info,SIGNAL(triggered()),parent,SLOT(vediInformazioniSviluppatore()));
    connect(gelatoFritto,SIGNAL(triggered()),parent,SLOT(vediMenuCompleto()));
    connect(gelatoFritto,SIGNAL(triggered()),parent,SLOT(caricaDatiSelezionato()));
}

QAction* MenuIniziale::getSalva() const {
    return salva;
}

QAction* MenuIniziale::getRicerca() const {
    return ricerca;
}

QMenu* MenuIniziale::getMenuComp() const {
    return listapiatti;
}

QMenu* MenuIniziale::getInserisci() const {
    return inserisci;
}

QAction* MenuIniziale::getStampa() const {
    return stampa;
}
