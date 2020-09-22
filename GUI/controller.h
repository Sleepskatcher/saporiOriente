
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QWidget>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QFileDialog>
#include<QScrollBar>
#include<QDesktopWidget>
#include<QGuiApplication>
#include<QApplication>
#include<QScreen>
#include<QPrinter>
#include<QTextDocument>

#include"GUI/menuIniziale.h"
#include"modello.h"
#include"GUI/ricerca.h"
#include"GUI/menuCompleto.h"
#include"GUI/layoutPrinc.h"
#include"GUI/inserisci.h"
#include"GUI/avviso.h"
#include"GUI/paginaModifica.h"
#include"GUI/inserisciDolce.h"
#include"GUI/paginaModificaDolce.h"

class Controller: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    Modello* modello;
    MenuIniziale* menu;
    Ricerca* ricerca;
    menuPiatti* menuComp;
    layoutPrinc* home;
    Inserisci* inserisci;
    InserisciDolce* inserisciDolce;
    Modifica* layoutModifica;
    ModificaDolce* layoutModDolce;
    QString file;
    QString menuSelezionato;
public:
    Controller(Modello*, QWidget* = nullptr);
    ~Controller();
    void caricaDati();
    void caricaDatiXML();
    int contaPiatti() const;
    Modello* getModello() const;
    void disabilita();
    void abilita();
    bool controlloDoppione(piatto*) const;
public slots:
    void stampa();
    void esci();
    void carica();
    void vediRicerca();
    void vediMenuCompleto();
    void setMenuSelezionato(const QString&);
    void vediLayoutPrinc();
    void vediInserisci();
    void vediInserisciDolce();
    void vediInformazioniSviluppatore();
    void vediInformazioniMenu();
    void mostraModifica();
    void mostraModificaRic();
    void salvaMod();
    void salvaModDolce();
    void inserisciPiatto();
    void inserisciDolceNuovo();
    void caricaDatiSelezionato();
    void rimuoviPiatto();
    void rimuoviPiattoRic();
    void ricercaPiatti();
};

#endif // CONTROLLER_H
