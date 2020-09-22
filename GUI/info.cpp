#include"info.h"

Info::Info(QWidget* p):
    messaggio(new QMessageBox(this))
{
   QVBoxLayout* popUpInfo = new QVBoxLayout(this);

   messaggio->setText("kjshgf");

   popUpInfo->addWidget(messaggio);

}
