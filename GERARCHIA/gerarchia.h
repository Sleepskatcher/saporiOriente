#ifndef GERARCHIA_H
#define GERARCHIA_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>

enum tipo{riso=1,spaghetti=2,dolce=3}; //1=riso,2=spaghetti
enum brodo{pesce=1,manzo=2,pollo=3};//1=pesce,2=manzo,3=pollo

class piatto {
private:
    std::string nomePiatto;
    int basePiatto = tipo{}; //{riso,spaghetti};
    bool piccante;
public:
    piatto(std::string,int, bool);
    virtual ~piatto() = default;
    //GET
    bool getPiccante() const;
    int getBase() const;
    std::string getNomePiatto() const;
    virtual std::string getInfo() const;
    virtual std::string getInfoStampa() const;
    //SET
    void setPiccante(bool);
    void setNome(std::string);
    void setBasePiatto(int);
    //OPERATORI
    virtual bool operator==(const piatto&) const;
    //METODI
    virtual double costo() const = 0; //dipende da tipo della base, dagli ingredienti scelti, dalle varie booleane specifiche e dalla quantità per il sushi
    virtual double guadagno() const = 0;
    double ricavo() const;
    virtual std::string tipoPiatto() const = 0;
};

class piattoFreddo: virtual public piatto {
private:
    std::vector<std::string> ingredientiFreddi;
    bool pescePrimaScelta;
public:
    piattoFreddo(std::string, bool, std::vector<std::string>, int, bool);
    //GET
    std::vector<std::string> getIngredientiFreddi() const;
    bool getPescePrimaScelta() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setIngredientiFreddi(std::string);
    void setPescePrimaScelta(bool);
    //OPERATORI
    virtual bool operator==(const piatto&) const override;
    //METODI
    ///virtual double costo() const;
    //virtual double guadagno() const;
    //virtual std::string tipoPiatto() const = 0;
    void svuotaIngredientiFreddi();
};

class piattoCaldo: virtual public piatto {
private:
    std::vector<std::string> ingredientiCaldi;
public:
    piattoCaldo(std::string,std::vector<std::string>,int,bool);
    //GET
    std::vector<std::string> getIngredientiCaldi() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setIngredientiCaldi(std::string);
    //OPERATORI
    virtual bool operator==(const piatto&) const override;
    //METODI
    //virtual double costo() const = 0;
    //virtual double guadagno() const = 0;
    //virtual std::string tipoPiatto() const = 0;
    void svuotaIngredientiCaldi();
};

class gelatoFritto: public piattoCaldo, public piattoFreddo {
private:
    bool glassaCioccolato;
    bool panna;
public:
    gelatoFritto(std::string,std::vector<std::string>,std::vector<std::string>,int,bool,bool,bool,bool);
    //GET
    bool getCioccolato() const;
    bool getPanna() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setCioccolato(bool);
    void setPanna(bool);
    //OPERATORI
    bool operator==(const piatto&) const override;
    //METODI
    virtual double costo() const override;
    virtual double guadagno() const override;
    virtual std::string tipoPiatto() const override;
};

class udon: public piattoCaldo {
private:
    bool fattiMano;
public:
    udon(std::string,std::vector<std::string>,int,bool, bool);
    //GET
    bool getFattiMano() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setFattiMano(bool);
    //OPERATORI
    bool operator==(const piatto&) const override;
    //METODI
    virtual double costo() const override;
    virtual double guadagno() const override;
    virtual std::string tipoPiatto() const override;
};

class risoCondito: public piattoCaldo {
private:
    bool saltato;
public:
    risoCondito(std::string,std::vector<std::string>,int, bool, bool);
    //GET
    bool getSaltato() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setSaltato(bool);
    //OPERATORI
    bool operator==(const piatto&) const override;
    //METODI
    virtual double costo() const override;
    virtual double guadagno() const override;
    virtual std::string tipoPiatto() const override;
};

class ramen: public piattoCaldo {
private:
    int baseBrodo = brodo{};
public:
    ramen(std::string,std::vector<std::string>,int, bool, int);
    //GET
    int getBaseBrodo() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setBaseBrodo(int);
    //OPERATORI
    bool operator==(const piatto&) const override;
    //METODI
    virtual double costo() const override;
    virtual double guadagno() const override;
    virtual std::string tipoPiatto() const override;
};

class sushi: public piattoFreddo {
private:
    bool alga;
    int pezzi;
public:
    sushi(std::string,std::vector<std::string>,bool, int, bool,int, bool);
    //GET
    bool getAlga() const;
    int getPezzi() const;
    virtual std::string getInfo() const override;
    virtual std::string getInfoStampa() const override;
    //SET
    void setAlga(bool);
    void setPezzi(int);
    //OPERATORI
    virtual bool operator==(const piatto&) const override;
    //METODI
    virtual double costo() const override;
    virtual double guadagno() const override;
    virtual std::string tipoPiatto() const override;
};

#endif // GERARCHIA_H
