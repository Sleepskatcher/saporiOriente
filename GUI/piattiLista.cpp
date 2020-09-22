#include"GUI/piattiLista.h"

piattiLista::piattiLista(QWidget* p,piatto* c): parent(p), piatti(c) {
    aggiornaPiatto();
}

void piattiLista::aggiornaPiatto() {
    QString path;
    if(dynamic_cast<sushi*>(piatti)) path=QString::fromStdString(":/IMMAGINI/sushi.jpg");
    if(dynamic_cast<udon*>(piatti)) path=QString::fromStdString(":/IMMAGINI/udon.jpg");
    if(dynamic_cast<risoCondito*>(piatti)) path=QString::fromStdString(":/IMMAGINI/riso.jpg");
    if(dynamic_cast<ramen*>(piatti)) path=QString::fromStdString(":/IMMAGINI/ramen.jpg");
    if(dynamic_cast<gelatoFritto*>(piatti)) path=QString::fromStdString(":/IMMAGINI/dolce.jpg");
    QPixmap p(path);
    setIcon(p.scaled(400,400,Qt::AspectRatioMode::KeepAspectRatio));
    setText(QString::fromStdString(piatti->getInfo()));
}

piatto* piattiLista::getSelezionato() const {
    return piatti;
}
