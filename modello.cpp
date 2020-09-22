#include "modello.h"

Modello::Modello(std::string p): percorso(p), menuCompleto(new lista<piatto*>), salvaMod(true){}

Modello::~Modello() {
    delete  menuCompleto;
}

std::string Modello::getPercorso() const {
    return percorso;
}

void Modello::setPercorso(std::string s) {
    percorso = s;
    delete menuCompleto;
    salvaMod = false;
    menuCompleto = new lista<piatto*>();
}

bool Modello::getSalvaMod() const {
    return salvaMod;
}

lista<piatto*>* Modello::getListaPiatti() const {
    return menuCompleto;
}

void Modello::setSalvaMod(bool s) {
    salvaMod = s;
}

lista<piatto*>::iteratore Modello::inizioIT() const {
    return menuCompleto->inizio();
}

lista<piatto*>::iteratore Modello::fineIT() const {
    return menuCompleto->fine();
}

lista<piatto*>::iteratoreConst Modello::inizioCIT() const {
    return menuCompleto->inizioC();
}

lista<piatto*>::iteratoreConst Modello::fineCIT() const {
    return menuCompleto->fineC();
}

void Modello::Salva() {
    QSaveFile fileSalva(QString::fromStdString(percorso));

    if(!fileSalva.open(QIODevice::WriteOnly)) qWarning() <<"Problemi di salvataggio";

    QXmlStreamWriter scrivi(&fileSalva);

    scrivi.setAutoFormatting(true);
    scrivi.writeStartDocument();

    scrivi.writeStartElement("root");

    auto cit = inizioCIT();
    while(cit!=fineCIT()) {
        const piatto* nuovoPiatto = *cit;
        const QString tipoPiatto = QString::fromStdString(nuovoPiatto->tipoPiatto());
        int baseP=0;
        scrivi.writeEmptyElement(tipoPiatto);

        scrivi.writeAttribute("nomePiatto",QString::fromStdString(nuovoPiatto->getNomePiatto()));
        if(tipoPiatto=="sushi") baseP=1;
        else if(tipoPiatto=="udon") baseP=2;
        else if(tipoPiatto=="ramen") baseP=2;
        else if(tipoPiatto=="risoCondito") baseP=1;
        else baseP=3;

        scrivi.writeAttribute("basePiatto",QString("%1").arg((baseP)));
        scrivi.writeAttribute("piccante",nuovoPiatto->getPiccante()==true ? "Si" : "No");

        if(tipoPiatto=="sushi") {
            QString ing;
            const sushi* Sushi = dynamic_cast<const sushi*>(nuovoPiatto);
            std::vector<std::string> ingredienti = Sushi->getIngredientiFreddi();
            for(std::vector<std::string>::iterator scorri=ingredienti.begin(); scorri!=ingredienti.end();++scorri){
                if(scorri!=ingredienti.cend()-1) ing.append(QString::fromStdString(*scorri)).append(",");
                else ing.append(QString::fromStdString(*scorri));
            }
            scrivi.writeAttribute("ingredientiFreddi",ing);
            scrivi.writeAttribute("alga",Sushi->getAlga()==true ? "Si" : "No");
            scrivi.writeAttribute("pregiato",Sushi->getPescePrimaScelta()==true ? "Si" : "No");
            scrivi.writeAttribute("pezzi",QString("%1").arg((Sushi->getPezzi())));
        }
        if(tipoPiatto=="udon") {
            QString ing;
            const udon* Udon = dynamic_cast<const udon*>(nuovoPiatto);
            std::vector<std::string> ingredienti = Udon->getIngredientiCaldi();
            for(std::vector<std::string>::iterator scorri=ingredienti.begin(); scorri!=ingredienti.end();++scorri){
                if(scorri!=ingredienti.cend()-1) ing.append(QString::fromStdString(*scorri)).append(",");
                else ing.append(QString::fromStdString(*scorri));
            }
            scrivi.writeAttribute("ingredientiCaldi",ing);
            scrivi.writeAttribute("fattiMano",Udon->getFattiMano()==true ? "Si" : "No");
        }
        if(tipoPiatto=="ramen") {
            QString ing;
            const ramen* Ramen = dynamic_cast<const ramen*>(nuovoPiatto);
            std::vector<std::string> ingredienti = Ramen->getIngredientiCaldi();
            for(std::vector<std::string>::iterator scorri=ingredienti.begin(); scorri!=ingredienti.end();++scorri){
                if(scorri!=ingredienti.cend()-1) ing.append(QString::fromStdString(*scorri)).append(",");
                else ing.append(QString::fromStdString(*scorri));
            }
            scrivi.writeAttribute("ingredientiCaldi",ing);
            scrivi.writeAttribute("baseBrodo",QString("%1").arg((Ramen->getBaseBrodo())));
        }
        if(tipoPiatto=="risoCondito") {
            QString ing;
            const risoCondito* Riso = dynamic_cast<const risoCondito*>(nuovoPiatto);
            std::vector<std::string> ingredienti = Riso->getIngredientiCaldi();
            for(std::vector<std::string>::iterator scorri=ingredienti.begin(); scorri!=ingredienti.end();++scorri){
                if(scorri!=ingredienti.cend()-1) ing.append(QString::fromStdString(*scorri)).append(",");
                else ing.append(QString::fromStdString(*scorri));
            }
            scrivi.writeAttribute("ingredientiCaldi",ing);
            scrivi.writeAttribute("saltato",Riso->getSaltato()==true ? "Si" : "No");
        }

        if(tipoPiatto=="gelatoFritto") {
            QString ingF;
            QString ingC;
            const gelatoFritto* Gelato = dynamic_cast<const gelatoFritto*>(nuovoPiatto);
            std::vector<std::string> ingredientiC = Gelato->getIngredientiCaldi();
            for(std::vector<std::string>::iterator scorri=ingredientiC.begin(); scorri!=ingredientiC.end();++scorri){
                if(scorri!=ingredientiC.cend()-1) ingC.append(QString::fromStdString(*scorri)).append(",");
                else ingC.append(QString::fromStdString(*scorri));
            }
            std::vector<std::string> ingredientiF = Gelato->getIngredientiFreddi();
            for(std::vector<std::string>::iterator scorri=ingredientiF.begin(); scorri!=ingredientiF.end();++scorri){
                if(scorri!=ingredientiF.cend()-1) ingC.append(QString::fromStdString(*scorri)).append(",");
                else ingF.append(QString::fromStdString(*scorri));
            }
            scrivi.writeAttribute("ingredientiCaldi",ingC);
            scrivi.writeAttribute("ingredientiFreddi",ingF);
            scrivi.writeAttribute("GlassaAlCioccolato",Gelato->getCioccolato()==true ? "Si" : "No");
            scrivi.writeAttribute("Panna",Gelato->getPanna()==true ? "Si" : "No");
        }

        delete *cit;
        ++cit;
    }
    scrivi.writeEndElement();
    scrivi.writeEndDocument();
    salvaMod = true;
    fileSalva.commit();
}

void Modello::Carica() {
    QFile fileSalva(QString::fromStdString(percorso));

    if(!fileSalva.open(QIODevice::ReadOnly)) {
        qWarning() <<"Errore nell'apertura del file "<<fileSalva.errorString();
        return;
    }
    QXmlStreamReader lettore(&fileSalva);
    if(lettore.readNextStartElement()) {
        if(lettore.name()=="root") {
            while(lettore.readNextStartElement()) {
                const QXmlStreamAttributes campo = lettore.attributes();

                std::string Nome = campo.value("nomePiatto").toString().toStdString();
                int Base = campo.value("basePiatto").toUInt();
                bool Piccantezza = campo.value("piccante").toString()=="Si" ? true : false;

                piatto* inserisci = nullptr;

                if(lettore.name()=="udon") {
                std::string ingredienti = campo.value("ingredientiCaldi").toString().toStdString();
                std::vector<std::string> ingredientiFinali;
                const char* v=",";
                std::string ing="";
                int lung=ingredienti.length();
                for(int i=0;i<lung;++i) {
                    while(ingredienti[i]!=*v && i<lung) {
                        std::string lettera=toString(ingredienti[i]);
                        ing.append(lettera);
                        ++i;
                    }
                ingredientiFinali.push_back(ing);
                ing.clear();
                }
                 bool FattiAMano = campo.value("fattiMano").toString()=="Si" ? true : false;

                 if(Base!=2) Base=2;
                 inserisci = new udon(Nome,ingredientiFinali,Base,Piccantezza,FattiAMano);
                 }

                 if(lettore.name()=="risoCondito") {
                 std::string ingredienti = campo.value("ingredientiCaldi").toString().toStdString();
                 std::vector<std::string> ingredientiFinali;
                 const char* v=",";
                 std::string ing="";
                 int lung=ingredienti.length();
                 for(int i=0;i<lung;++i) {
                    while(ingredienti[i]!=*v && i<lung) {
                        std::string lettera=toString(ingredienti[i]);
                        ing.append(lettera);
                        ++i;
                    }
                 ingredientiFinali.push_back(ing);
                 ing.clear();
                 }
                 bool Saltato = campo.value("saltato").toString()=="Si" ? true : false;

                 if(Base!=1) Base=1;
                 inserisci = new risoCondito(Nome,ingredientiFinali,Base,Piccantezza,Saltato);
                 }

                 if(lettore.name()=="ramen") {
                 std::string ingredienti = campo.value("ingredientiCaldi").toString().toStdString();
                 std::vector<std::string> ingredientiFinali;
                 const char* v=",";
                 std::string ing="";
                 int lung=ingredienti.length();
                 for(int i=0;i<lung;++i) {
                    while(ingredienti[i]!=*v && i<lung) {
                        std::string lettera=toString(ingredienti[i]);
                        ing.append(lettera);
                        ++i;
                    }
                    ingredientiFinali.push_back(ing);
                    ing.clear();
                 }
                 int Brodo = campo.value("baseBrodo").toUInt();

                 if(Base!=2) Base=2;
                 inserisci = new ramen(Nome,ingredientiFinali,Base,Piccantezza,Brodo);
                 }

                if(lettore.name()=="sushi") {
                std::string ingredienti = campo.value("ingredientiFreddi").toString().toStdString();
                std::vector<std::string> ingredientiFinali;
                const char* v=",";
                std::string ing="";
                int lung=ingredienti.length();
                for(int i=0;i<lung;++i) {
                    while(ingredienti[i]!=*v && i<lung) {
                        std::string lettera=toString(ingredienti[i]);
                        ing.append(lettera);
                        ++i;
                    }
                ingredientiFinali.push_back(ing);
                ing.clear();
                }
                bool Alga = campo.value("alga").toString()=="Si" ? true : false;
                int Pezzi = campo.value("pezzi").toUInt();
                bool Pregiato = campo.value("pregiato").toString()=="Si" ? true : false;

                if(Base!=1) Base=1;
                inserisci = new sushi(Nome,ingredientiFinali,Alga,Pezzi,Pregiato,Base,Piccantezza);
                }

                if(lettore.name()=="gelatoFritto") {
                    std::string ingredientiF = campo.value("ingredientiFreddi").toString().toStdString();
                    std::vector<std::string> ingredientiFinaliF;
                    const char* v=",";
                    std::string ing="";
                    int lung=ingredientiF.length();
                    for(int i=0;i<lung;++i) {
                        while(ingredientiF[i]!=*v && i<lung) {
                            std::string letteraF=toString(ingredientiF[i]);
                            ing.append(letteraF);
                            ++i;
                        }
                    ingredientiFinaliF.push_back(ing);
                    ing.clear();
                    }
                    std::string ingredientiC = campo.value("ingredientiCaldi").toString().toStdString();
                    std::vector<std::string> ingredientiFinaliC;
                    lung=ingredientiC.length();
                    for(int i=0;i<lung;++i) {
                        while(ingredientiC[i]!=*v && i<lung) {
                            std::string lettera=toString(ingredientiC[i]);
                            ing.append(lettera);
                            ++i;
                        }
                    ingredientiFinaliC.push_back(ing);
                    ing.clear();
                    }
                    bool Pregiato = campo.value("pregiato").toString()=="Si" ? true : false;
                    bool GlassaCioc = campo.value("GlassaAlCioccolato").toString()=="Si" ? true : false;
                    bool Panna = campo.value("Panna").toString()=="Si" ? true : false;
                    if(Base!=3) Base=3;
                    inserisci = new gelatoFritto(Nome,ingredientiFinaliF,ingredientiFinaliC,Base,Pregiato,Piccantezza,GlassaCioc,Panna);
                }

                if(inserisci!=nullptr) menuCompleto->aggiungiCoda(inserisci);

                if(!lettore.isEndDocument()) lettore.skipCurrentElement();
            }
        }
    }
    fileSalva.close();
    salvaMod=true;
}

std::string Modello::toString(char x) {
    std::string s(1, x);
    return s;
}

void Modello::inserisci(piatto* p) {
    menuCompleto->aggiungiTesta(p);
}

void Modello::rimuovi(piatto* p) {
    menuCompleto->togliUno(p);
}

int Modello::contaPiatti() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) conta++;
    return conta;
}

int Modello::contaSushi() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) {
        if(dynamic_cast<sushi*>(*it)) conta++;
    }
    return conta;
}

int Modello::contaUdon() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) {
        if(dynamic_cast<udon*>(*it)) conta++;
    }
    return conta;
}

int Modello::contaRamen() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) {
        if(dynamic_cast<ramen*>(*it)) conta++;
    }
    return conta;
}

int Modello::contaRiso() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) {
        if(dynamic_cast<risoCondito*>(*it)) conta++;
    }
    return conta;
}

int Modello::contaGelato() {
    int conta=0;
    for(lista<piatto*>::iteratore it=menuCompleto->inizio(); it!=menuCompleto->fine();++it) {
        if(dynamic_cast<gelatoFritto*>(*it)) conta++;
    }
    return conta;
}
