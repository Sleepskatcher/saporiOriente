#ifndef CONTAINER_H
#define CONTAINER_H

#include<iostream>
#include<QDebug>

template<class T>

class lista {
private:
    class nodo;

    class smartP {
    public:
        nodo* punt;
        smartP(nodo* p = 0); //costruttore
        smartP(const smartP&); //costruttre di copia profondo
        ~smartP(); //distruttore profondo
        //operatori
        smartP& operator=(const smartP&); //assegnazione profonda
        nodo& operator*() const;
        nodo* operator->() const;
        bool operator==(const smartP&) const;
        bool operator!=(const smartP&) const;
    };

    class nodo {
    public:
        T info;
        smartP prev;
        smartP next;
        unsigned int riferimenti;
        nodo();
        nodo(const T&, const smartP&, const smartP&);
    };

    smartP primo;
    smartP ultimo;

public:

    class iteratore {
    private:
        smartP* it;
        bool fine;
    public:
        iteratore();
        iteratore(smartP* = nullptr, bool = false);
        iteratore(const iteratore&);
        iteratore& operator++();
        iteratore& operator--();
        T operator*() const;
        T operator->() const;
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
    };

    class iteratoreConst {
    private:
        const smartP* constIt;
        bool fineConst;
    public:
        iteratoreConst();
        iteratoreConst(const smartP* = nullptr, bool = false);
        iteratoreConst(const iteratoreConst&);
        iteratoreConst& operator++();
        iteratoreConst& operator--();
        bool operator==(const iteratoreConst&) const;
        bool operator!=(const iteratoreConst&) const;
        const T& operator*() const;
        const T* operator->() const;
    };

    void aggiungiTesta(const T&);
    void aggiungiCoda(const T&);
    bool vuoto();
    void togliUno(const T&); //da fare

    iteratore inizio();
    iteratore fine();
    iteratoreConst inizioC() const;
    iteratoreConst fineC() const;
};

//SMARTP

template <class T>
typename lista<T>::smartP& lista<T>::smartP::operator=(const smartP& p) {
    if (this != &p) {
        nodo* t = punt;
        punt = p.punt;
        if(punt) punt->riferimenti++;
        if(t) {
            t->riferimenti--;
            if(t->riferimenti == 0) delete t;
        }
    }
    return  *this;
}

template <class T>
lista<T>::smartP::smartP(nodo* p): punt(p) {
    if(punt) punt->riferimenti++;
}

template <class T>
lista<T>::smartP::smartP(const smartP& c): punt(c.punt) {
    if(punt) punt->riferimenti++;
}

template <class T>
lista<T>::smartP::~smartP() {
    if(punt) {
        punt->riferimenti--;
        if (punt->riferimenti == 0) delete punt;
    }
}

template <class T>
typename lista<T>::nodo& lista<T>::smartP::operator*() const {
    return *punt;
}

template <class T>
typename lista<T>::nodo* lista<T>::smartP::operator->() const {
    return punt;
}

template <class T>
bool lista<T>::smartP::operator==(const smartP& p) const {
    return punt == p.punt;
}

template <class T>
bool lista<T>::smartP::operator!=(const smartP& p) const {
    return punt != p.punt;
}

//NODO

template <class T>
lista<T>::nodo::nodo(): riferimenti(0) {}

template <class T>
lista<T>::nodo::nodo(const T& i, const smartP& p, const smartP& n): info(i), prev(p), next(n), riferimenti(0) {}

//LISTA

template<class T>
void lista<T>::aggiungiTesta(const T& n) {
    if(primo == nullptr){
        primo = new nodo(n,nullptr,nullptr);
        ultimo = primo;
    } else {
        nodo* aux = new nodo(n,nullptr,primo);
        primo = aux;
    }
}

template<class T>
void lista<T>::aggiungiCoda(const T& n) {
    if(primo == nullptr){
        primo = new nodo(n,nullptr,nullptr);
        ultimo = primo;
    } else {
        nodo* aux = new nodo(n,ultimo,nullptr);
        ultimo->next = aux;
        ultimo = aux;
    }
}

template<class T>
bool lista<T>::vuoto() {
    if(primo == nullptr) return true;
    else return false;
}

template<class T>
void lista<T>::togliUno(const T& t) {
    //PAGINA 117-118
    smartP p = primo;
       smartP prec = nullptr/*, q = nullptr*/;
       //smartP inizio = primo;
       //primo = nullptr;
       while(p != nullptr && !(p->info == t)) {
           //q = new nodo(p->info, p->prev, p->next);
           prec = p;
           p = p->next;
           /*if(p->prev == nullptr) {
               primo = q;
               std::cout<<"qua?"<<std::endl;
           } else {
               prec->next = q;
               q->prev = prec;
           }*/

           //prec = q;
           //p = p->next;
       }
       /*if(p == nullptr){
           primo = inizio;
       } else {*/
       if(p != nullptr) {
           if (prec == nullptr && p->next == nullptr) {
               primo = p->next;
               ultimo = primo;
           } else {
           if(prec == nullptr) {
               primo = p->next;
               primo->prev = nullptr;
           } else {
               if(p->next != nullptr) {
                   prec->next = p->next;
                   (p->next)->prev = prec;
               } else {
                   prec->next = p->next;
                   ultimo = prec;
                   }
               }
           }
       }
}

//ITERATORE

template<class T>
lista<T>::iteratore::iteratore(): it(nullptr), fine(false) {}

template<class T>
lista<T>::iteratore::iteratore(smartP* iter,bool pastTheEnd): it(iter), fine(pastTheEnd) {}

template<class T>
lista<T>::iteratore::iteratore(const iteratore& iter): it(iter.it), fine(iter.fine) {}

template<class T>
typename lista<T>::iteratore lista<T>::inizio() {
    if(primo == nullptr) return iteratore(nullptr);
    else return iteratore(&primo);
}

template<class T>
typename lista<T>::iteratore lista<T>::fine() {
    if(ultimo == nullptr) return iteratore(nullptr);
    else return iteratore(&(ultimo->next),true);
}

template<class T>
bool lista<T>::iteratore::operator==(const iteratore& i) const{
    return it = i.it;
}

template<class T>
bool lista<T>::iteratore::operator!=(const iteratore& i) const {
    return it != i.it;
}

template<class T>
T lista<T>::iteratore::operator*() const{
    return (*(*it)).info;
}

template<class T>
T lista<T>::iteratore::operator->() const{
    return &(*(*(*it)).info);
}

template<class T>
typename lista<T>::iteratore& lista<T>::iteratore::operator++() {
    if(!fine && it != nullptr) {
        if((*it)->next == nullptr) {
            it = &((*it)->next);
            fine = true;
        } else {
            it = &((*it)->next);
        }
    }
    return *this;
}

template<class T>
typename lista<T>::iteratore& lista<T>::iteratore::operator--() {
    if(fine) {
        it = &(*(it)->prev);
        fine = false;
    } else {
        if(fine) &(*(it)->next);
    }
    return *this;
}

//ITERATORE CONST

template<class T>
lista<T>::iteratoreConst::iteratoreConst(): constIt(nullptr), fineConst(false) {}

template <class T>
lista<T>::iteratoreConst::iteratoreConst(const smartP* p, bool f): constIt(p), fineConst(f) {}

template <class T>
lista<T>::iteratoreConst::iteratoreConst(const iteratoreConst& ic): constIt(ic.constIt), fineConst(ic.fineConst) {}

template <class T>
typename lista<T>::iteratoreConst lista<T>::inizioC() const {
    if(primo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&(primo));
}

template <class T>
typename lista<T>::iteratoreConst lista<T>::fineC() const {
    if(primo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&(ultimo->next),true);
}

template <class T>
typename lista<T>::iteratoreConst& lista<T>::iteratoreConst::operator++() {
    if(!fineConst && constIt!=nullptr) {
        if((*constIt)->next == nullptr) {
            constIt = &((*constIt)->next);
            fineConst = true;
        } else {
            constIt = &((*constIt)->next);
        }
    }
    return *this;
}

template <class T>
typename lista<T>::iteratoreConst& lista<T>::iteratoreConst::operator--() {
    if(fineConst) {
        constIt = &(*(constIt)->prev);
        fineConst = false;
    } else {
        if(fineConst) &(*(constIt)->next);
    }
    return *this;
}

template <class T>
bool lista<T>::iteratoreConst::operator==(const iteratoreConst& c) const {
    return constIt==c.constIt;
}

template <class T>
bool lista<T>::iteratoreConst::operator!=(const iteratoreConst& c) const {
    return constIt!=c.constIt;
}

template <class T>
const T& lista<T>::iteratoreConst::operator*() const {
    return ((*constIt)->info);
}

template <class T>
const T* lista<T>::iteratoreConst::operator->() const {
    return &((*constIt)->info);
}

#endif // CONTAINER_H
