#ifndef MENUINIZIALE_H
#define MENUINIZIALE_H

#include<QMenuBar>
#include<QAction>
#include<QWidgetAction>
#include<QSignalMapper>

class MenuIniziale: public QMenuBar {
    Q_OBJECT
private:
    QWidget* parent;
    QMenu* file;
    QAction* home;
    QAction* carica;
    QAction* salva;
    QAction* stampa;
    QAction* esci;
    QMenu* listapiatti;
    QAction* menuComp;
    QAction* sushi;
    QAction* udon;
    QAction* ramen;
    QAction* gelatoFritto;
    QAction* riso;
    QAction* ricerca;
    QMenu* inserisci;
    QMenu* datiMenu;
    QAction* infoMenu;
    QAction* info;
    QAction* dolce;
    QAction* piatto;
    QSignalMapper* m_sigmapper;
public:
    MenuIniziale(QWidget* = nullptr);
    QMenu* getMenuComp() const;
    QMenu* getInserisci() const;
    QAction* getRicerca() const;
    QAction* getSalva() const;
    QAction* getStampa() const;
};

#endif // MENUINIZIALE_H
