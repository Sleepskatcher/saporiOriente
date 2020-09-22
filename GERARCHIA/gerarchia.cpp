#include "gerarchia.h"
#include<QDebug>

//PIATTO

piatto::piatto(std::string nome,int base, bool picc): nomePiatto(nome), basePiatto(base), piccante(picc){}

bool piatto::getPiccante() const {
    return piccante;
}

int piatto::getBase() const {
    return basePiatto;
}

std::string piatto::getNomePiatto() const {
    return nomePiatto;
}

std::string piatto::getInfo() const {
    std::string frase;
    std::string base = getBase()==1 ? "Riso" : "Spaghetti";
    return frase.append("\n Nome: "+getNomePiatto())
           .append("\n Base del piatto: "+base)
           .append("\n Piccante: ").append((getPiccante() ? "Si" : "No"));
}

std::string piatto::getInfoStampa() const {
    std::string frase;
    std::string base = getBase()==1 ? "Riso" : "Spaghetti";
    frase=("<li> Nome: "+getNomePiatto()+"</li>");
    return frase.append("<li> Base del piatto: "+base+"</li>")
           .append("<li> Piccante: ").append((getPiccante() ? "Si" : "No"))+"</li>";
}

void piatto::setPiccante(bool piccantezza) {
    piccante = piccantezza;
}

void piatto::setNome(std::string nuovoNome) {
    nomePiatto = nuovoNome;
}

void piatto::setBasePiatto(int nuovoTipo) {
    basePiatto = nuovoTipo;
}

bool piatto::operator==(const piatto& p) const {
    return nomePiatto==p.nomePiatto && basePiatto==p.basePiatto;
}

double piatto::ricavo() const {
    return guadagno()-costo();
}

//PIATTO FREDDO

piattoFreddo::piattoFreddo(std::string nome,bool pregiato, std::vector<std::string> ingredienti,int base, bool picc):
    piatto(nome,base,picc), ingredientiFreddi(ingredienti), pescePrimaScelta(pregiato){}

std::vector<std::string> piattoFreddo::getIngredientiFreddi() const {
    return ingredientiFreddi;
}

bool piattoFreddo::getPescePrimaScelta() const {
    return pescePrimaScelta;
}

std::string piattoFreddo::getInfo() const {
    std::string frase = piatto::getInfo();
    std::string ingredienti="";
    std::vector<std::string> vettore=getIngredientiFreddi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredienti.append(*cit+",");
        else ingredienti.append(*cit);
    }
    return frase.append("\n Ingredienti: "+ingredienti)
           .append("\n Pesce di prima scelta: ").append(getPescePrimaScelta() ? "Si" : "No");
}

std::string piattoFreddo::getInfoStampa() const {
    std::string frase = piatto::getInfoStampa();
    std::string ingredienti="";
    std::vector<std::string> vettore=getIngredientiFreddi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredienti.append(*cit+",");
        else ingredienti.append(*cit);
    }
    frase.append("<li> Ingredienti: "+ingredienti+"</li>");
    return frase.append("<li> Pesce di prima scelta: ").append(getPescePrimaScelta() ? "Si" : "No")+"</li>";
}

void piattoFreddo::setIngredientiFreddi(std::string ingrediente) {
    for(unsigned int i=0;i<ingredientiFreddi.size();++i) {
        if(ingrediente==ingredientiFreddi[i]) return;
    }
    ingredientiFreddi.push_back(ingrediente);
    return;
}

void piattoFreddo::setPescePrimaScelta(bool pregiato) {
    pescePrimaScelta = pregiato;
}

bool piattoFreddo::operator==(const piatto &pf) const {
    return piatto::operator==(pf);
}

void piattoFreddo::svuotaIngredientiFreddi() {
    ingredientiFreddi.clear();
}

//SUSHI

sushi::sushi(std::string nome, std::vector<std::string> ingredienti,bool nori, int numero, bool pregiato, int base, bool picc):
    piatto(nome,base,picc), piattoFreddo(nome,pregiato,ingredienti,base,picc), alga(nori), pezzi(numero) {}

bool sushi::getAlga() const {
    return alga;
}

int sushi::getPezzi() const {
    return pezzi;
}

std::string sushi::getInfo() const {
    std::string frase = piattoFreddo::getInfo();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    return frase.append("\n Alga: ").append(getAlga() ? "Si" : "No")
           .append("\n Numero dei pezzi: "+std::to_string(getPezzi()))
            .append("\n Costo: "+cifraCosto.str()+("€"))
            .append("\n Guadagno: "+cifraGuadagno.str()+("€"))
            .append("\n Ricavo: "+cifraRicavo.str()+("€"));
}

std::string sushi::getInfoStampa() const {
    std::string frase = piattoFreddo::getInfoStampa();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    frase.append("<li> Alga: ").append((getAlga() ? "Si" : "No"))+"</li>";
    return frase.append("<li> Numero dei pezzi: "+std::to_string(getPezzi())+"</li>")
            .append("<li> Costo: "+cifraCosto.str()+("€")+"</li>")
            .append("<li> Guadagno: "+cifraGuadagno.str()+("€")+"</li>")
            .append("<li> Ricavo: "+cifraRicavo.str()+("€"))+"</li>";
}

void sushi::setAlga(bool a) {
    alga=a;
}

void sushi::setPezzi(int p) {
    pezzi=p;
}

bool sushi::operator==(const piatto &s) const {
    return ricavo()==s.ricavo() && piattoFreddo::operator==(s);
}

double sushi::costo() const {
    double costoFinale = (pezzi*0.75)+4;
    if(getPiccante()) costoFinale = costoFinale + 0.25;
    if(alga) costoFinale = costoFinale + 0.25;
    if(getPescePrimaScelta()) costoFinale = costoFinale + 0.50;
    costoFinale = costoFinale + (0.05*getIngredientiFreddi().size());
    return costoFinale;
}

double sushi::guadagno() const {
    int guadagno = costo();
    int percentuale = (costo()/100)*40;
    return guadagno+percentuale;
}

std::string sushi::tipoPiatto() const {
    return "sushi";
}

//PIATTO CALDO

piattoCaldo::piattoCaldo(std::string nome,std::vector<std::string> ingredienti, int base, bool piccantezza):
    piatto(nome,base,piccantezza), ingredientiCaldi(ingredienti) {}

std::vector<std::string> piattoCaldo::getIngredientiCaldi() const {
    return ingredientiCaldi;
}

std::string piattoCaldo::getInfo() const {
    std::string frase = piatto::getInfo();
    std::string ingredienti="";
    std::vector<std::string> vettore=getIngredientiCaldi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredienti.append(*cit+",");
        else ingredienti.append(*cit);
    }
    return frase.append("\n Ingredienti: "+ingredienti);
}

std::string piattoCaldo::getInfoStampa() const {
    std::string frase = piatto::getInfoStampa();
    std::string ingredienti="";
    std::vector<std::string> vettore=getIngredientiCaldi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredienti.append(*cit+",");
        else ingredienti.append(*cit);
    }
    return frase.append("<li> Ingredienti: "+ingredienti+"</li>");
}

void piattoCaldo::setIngredientiCaldi(std::string ingrediente) {
    for(unsigned int i=0;i<ingredientiCaldi.size();++i) {
        if(ingrediente==ingredientiCaldi[i]) return;
    }
    ingredientiCaldi.push_back(ingrediente);
    return;
}

bool piattoCaldo::operator==(const piatto& pc) const {
    return piatto::operator==(pc);
}

void piattoCaldo::svuotaIngredientiCaldi() {
    ingredientiCaldi.clear();
}

//GELATO FRITTO

gelatoFritto::gelatoFritto(std::string nome,std::vector<std::string> iF,std::vector<std::string> iC,int base,bool primaS,bool picc,bool c,bool pan):
    piatto(nome,base,picc), piattoCaldo(nome,iC,base,picc), piattoFreddo(nome,picc,iF,base,primaS), glassaCioccolato(c), panna(pan) {}

bool gelatoFritto::getCioccolato() const {
    return glassaCioccolato;
}

bool gelatoFritto::getPanna() const {
    return panna;
}

std::string gelatoFritto::getInfo() const {
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::string frase = "Nome: "+getNomePiatto();
    std::string ingredientiC="";
    std::vector<std::string> vettore=getIngredientiCaldi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredientiC.append(*cit+",");
        else ingredientiC.append(*cit);
    }
    frase.append("\n Ingredienti Caldi: "+ingredientiC);
    std::string ingredientiF="";
    vettore=getIngredientiFreddi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredientiF.append(*cit+",");
        else ingredientiF.append(*cit);
    }
    frase.append("\n Ingredienti Freddi: "+ingredientiF);
    return frase.append("\n Costo: "+cifraCosto.str()+("€"))
                .append("\n Guadagno: "+cifraGuadagno.str()+("€"))
                .append("\n Ricavo: "+cifraRicavo.str()+("€"));
}

std::string gelatoFritto::getInfoStampa() const {
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::string frase = "<li> Nome: "+getNomePiatto()+"</li>";
    std::string ingredientiC="";
    std::vector<std::string> vettore=getIngredientiCaldi();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredientiC.append(*cit+",");
        else ingredientiC.append(*cit);
    }
    frase.append("<li> Ingredienti Caldi: "+ingredientiC)+"</li>";
    std::string ingredientiF="";
    std::vector<std::string> vettoreF=getIngredientiFreddi();
    for(std::vector<std::string>::const_iterator cit=vettoreF.cbegin();cit!=vettoreF.cend();++cit) {
        if(cit!=vettoreF.cend()-1) ingredientiF.append(*cit+",");
        else ingredientiF.append(*cit);
    }
    frase.append("<li> Ingredienti Freddi: "+ingredientiF)+"</li>";
    return frase.append("<li> Costo: "+cifraCosto.str()+("€")+"</li>")
                .append("<li> Guadagno: "+cifraGuadagno.str()+("€")+"</li>")
                .append("<li> Ricavo: "+cifraRicavo.str()+("€")+"</li>");
}

void gelatoFritto::setCioccolato(bool c) {
    glassaCioccolato=c;
}

void gelatoFritto::setPanna(bool p) {
    panna=p;
}

bool gelatoFritto::operator==(const piatto & g) const {
    return piatto::ricavo()==g.ricavo() && piattoFreddo::operator==(g);
}

double gelatoFritto::costo() const {
    double costo = 0.75;
    if(glassaCioccolato) costo=costo+0.25;
    if(panna) costo=costo+0.50;
    costo = costo + (0.50*getIngredientiFreddi().size());
    costo = costo + (0.50*getIngredientiFreddi().size());
    return costo;
}

double gelatoFritto::guadagno() const {
    int guadagno = costo();
    int percentuale = (costo()/100)*60;
    return guadagno+percentuale;
}

std::string gelatoFritto::tipoPiatto() const {
    return "gelatoFritto";
}

//UDON

udon::udon(std::string nome,std::vector<std::string> ingredienti,int base,bool piccantezza, bool mano):
    piatto(nome,base,piccantezza), piattoCaldo(nome,ingredienti,base,piccantezza), fattiMano(mano) {}

bool udon::getFattiMano() const {
    return fattiMano;
}

std::string udon::getInfo() const {
    std::string frase = piattoCaldo::getInfo();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    return frase.append("\n Fatti a mano: ").append(getFattiMano() ? "Si" : "No")
            .append("\n Costo: "+cifraCosto.str()+("€"))
            .append("\n Guadagno: "+cifraGuadagno.str()+("€"))
            .append("\n Ricavo: "+cifraRicavo.str()+("€"));
}

std::string udon::getInfoStampa() const {
    std::string frase = piattoCaldo::getInfoStampa();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    frase.append("<li> Fatti a mano: ").append(getFattiMano() ? "Si" : "No")+"</li>";
    return frase.append("<li> Costo: "+cifraCosto.str()+("€")+"</li>")
            .append("<li> Guadagno: "+cifraGuadagno.str()+("€")+"</li>")
            .append("<li> Ricavo: "+cifraRicavo.str()+("€")+"</li>");
}

void udon::setFattiMano(bool mano) {
    fattiMano = mano;
}

bool udon::operator==(const piatto &u) const {
    return ricavo()==u.ricavo() && piattoCaldo::operator==(u);
}

double udon::costo() const {
    double prezzoFinale = 5;
    if(fattiMano) prezzoFinale = prezzoFinale + 0.50;
    prezzoFinale = prezzoFinale + (0.40*getIngredientiCaldi().size());
    return prezzoFinale;
}

double udon::guadagno() const {
    int guadagno = costo();
    int percentuale = (costo()/100)*30;
    return guadagno+percentuale;
}

std::string udon::tipoPiatto() const {
    return "udon";
}

//RISO CONDITO

risoCondito::risoCondito(std::string nome,std::vector<std::string> ingredienti,int base,bool piccantezza, bool wok):
    piatto(nome,base,piccantezza), piattoCaldo(nome,ingredienti,base,piccantezza), saltato(wok) {}

bool risoCondito::getSaltato() const {
    return saltato;
}

void risoCondito::setSaltato(bool padella) {
    saltato = padella;
}

std::string risoCondito::getInfo() const {
    std::string frase=piattoCaldo::getInfo();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    return frase.append("\n Piatto saltato: ").append(getSaltato() ? "Si" : "No")
            .append("\n Costo: "+cifraCosto.str()+("€"))
            .append("\n Guadagno: "+cifraGuadagno.str()+("€"))
            .append("\n Ricavo: "+cifraRicavo.str()+("€"));
}

std::string risoCondito::getInfoStampa() const {
    std::string frase=piattoCaldo::getInfoStampa();
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    frase.append("<li> Piatto saltato: ").append(getSaltato() ? "Si" : "No")+"</li>";
    return frase.append("<li> Costo: "+cifraCosto.str()+("€")+"</li>")
            .append("<li> Guadagno: "+cifraGuadagno.str()+("€")+"</li>")
            .append("<li> Ricavo: "+cifraRicavo.str()+("€")+"</li>");
}

bool risoCondito::operator==(const piatto & r) const {
    return ricavo()==r.ricavo() && piattoCaldo::operator==(r);
}

double risoCondito::costo() const {
    double prezzoFinale = 4;
    if(getPiccante()) prezzoFinale = prezzoFinale + 0.25;
    if(saltato) prezzoFinale = prezzoFinale + 0.40;
    prezzoFinale = prezzoFinale +(0.30*getIngredientiCaldi().size());
    return prezzoFinale;
}

double risoCondito::guadagno() const {
    int guadagno = costo();
    int percentuale = (costo()/100)*35;
    return guadagno+percentuale;
}

std::string risoCondito::tipoPiatto() const {
    return "risoCondito";
}

//RAMEN

ramen::ramen(std::string nome,std::vector<std::string> ingredienti,int base,bool piccantezza, int brodo):
   piatto(nome,base,piccantezza), piattoCaldo(nome,ingredienti,base,piccantezza), baseBrodo(brodo){}

int ramen::getBaseBrodo() const {
    return baseBrodo;
}

void ramen::setBaseBrodo(int brodoNuovo) {
    baseBrodo = brodoNuovo;
}

std::string ramen::getInfo() const {
    std::string frase = piattoCaldo::getInfo();
    std::string brodo;
    if(getBaseBrodo()==1) brodo="Pesce";
    else if(getBaseBrodo()==2) brodo="Manzo";
    else brodo="Pollo";
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    return  frase.append("\n Base del brodo: "+brodo)
            .append("\n Costo: "+cifraCosto.str()+("€"))
            .append("\n Guadagno: "+cifraGuadagno.str()+("€"))
            .append("\n Ricavo: "+cifraRicavo.str()+("€"));
}

std::string ramen::getInfoStampa() const {
    std::string frase = piattoCaldo::getInfoStampa();
    std::string brodo;
    if(getBaseBrodo()==1) brodo="Pesce";
    else if(getBaseBrodo()==2) brodo="Manzo";
    else brodo="Pollo";
    std::stringstream cifraCosto;
    std::stringstream cifraGuadagno;
    std::stringstream cifraRicavo;
    cifraCosto<<std::fixed<<std::setprecision(2)<<costo();
    cifraGuadagno<<std::fixed<<std::setprecision(2)<<guadagno();
    cifraRicavo<<std::fixed<<std::setprecision(2)<<ricavo();
    return  frase.append("<li> Base del brodo: "+brodo+"</li>")
            .append("<li> Costo: "+cifraCosto.str()+("€")+"</li>")
            .append("<li> Guadagno: "+cifraGuadagno.str()+("€")+"</li>")
            .append("<li style=\"border-bottom: 1px solid #000000;\"> Ricavo: "+cifraRicavo.str()+("€")+"</li>");
}

bool ramen::operator==(const piatto & r) const {
    return ricavo()==r.ricavo() && piattoCaldo::operator==(r);
}

double ramen::costo() const {
    double costoFinale = 5;
    if(getPiccante()) costoFinale = costoFinale + 0.50;
    if(getBaseBrodo() == 1) costoFinale = costoFinale + 1.5;
    if(getBaseBrodo() == 2) costoFinale = costoFinale + 1;
    if(getBaseBrodo() == 3) costoFinale = costoFinale + 0.75;
    costoFinale = costoFinale + (0.40*getIngredientiCaldi().size());
    return costoFinale;
}

double ramen::guadagno() const {
    int guadagno = costo();
    int percentuale = (costo()/100)*30;
    return guadagno+percentuale;
}

std::string ramen::tipoPiatto() const {
    return "ramen";
}
