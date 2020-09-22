#include"GUI/piattoWidget.h"

piattoWidget::piattoWidget(QWidget* p): parent(p) {
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent),Qt::AlignRight);
    setIconSize(QSize(150,150));
}

void piattoWidget::aggiungiPiatto(piatto* nuovoPiatto) {
    piattiLista* mettiNuovo = new piattiLista(parent,nuovoPiatto);
    addItem(mettiNuovo);
}

piattiLista* piattoWidget::currentItem() const {
    return static_cast<piattiLista*>(QListWidget::currentItem());
}
