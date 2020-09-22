#ifndef MODELLO_H
#define MODELLO_H

#include"GERARCHIA/gerarchia.h"
#include"container.h"

#include<QFile>
#include<QSaveFile>
#include<QXmlStreamReader>
#include<QDebug>
#include<iostream>

class Modello {
private:
    std::string percorso;
    lista<piatto*>* menuCompleto;
    bool salvaMod;
public:
    Modello(std::string = ":/SALVATAGGIO DATI/listaPiatti.xml");
    ~Modello();

    std::string getPercorso() const;
    bool getSalvaMod() const;
    lista<piatto*>* getListaPiatti() const;
    void setSalvaMod(bool);
    void setPercorso(std::string = "");

    lista<piatto*>::iteratore inizioIT() const;
    lista<piatto*>::iteratore fineIT() const;
    lista<piatto*>::iteratoreConst inizioCIT() const;
    lista<piatto*>::iteratoreConst fineCIT() const;

    void Salva();
    void Carica();

    std::string toString(char);

    void inserisci(piatto*);
    void rimuovi(piatto*);
    int contaPiatti();
    int contaSushi();
    int contaUdon();
    int contaRamen();
    int contaRiso();
    int contaGelato();
};

#endif // MODELLO_H
