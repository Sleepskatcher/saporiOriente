#include"layoutPrinc.h"

layoutPrinc::layoutPrinc(QWidget* p):
    QWidget(p),
    layoutPrincipaleTesto(new QLabel(this)),
    layoutPrincipaleImmagine(new QLabel(this)),
    menuBut(new QPushButton(this))
{
     QVBoxLayout* homeP = new QVBoxLayout(this);

     menuBut->setText("Vai al menu completo");

     layoutPrincipaleTesto->setText("SAPORI D'ORIENTE");
     layoutPrincipaleTesto->setStyleSheet("font-size: 28px");
     layoutPrincipaleTesto->setAlignment(Qt::AlignCenter);

     QPixmap pesci = QPixmap(":/logo.jpg");
     layoutPrincipaleImmagine->setPixmap(pesci);
     layoutPrincipaleImmagine->setAlignment(Qt::AlignCenter);

     homeP->addWidget(layoutPrincipaleTesto);
     homeP->addWidget(layoutPrincipaleImmagine);
     homeP->addWidget(menuBut);

     connect(menuBut,SIGNAL(clicked()),p,SLOT(vediMenuCompleto()));
}

QPushButton* layoutPrinc::getMenuBut() const {
    return menuBut;
}
