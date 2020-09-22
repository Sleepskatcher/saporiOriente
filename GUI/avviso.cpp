#include"avviso.h"

Avviso::Avviso(QString n,QString t):
    nomeFinestra(n),
    testo(t)
{
    this->setWindowTitle(nomeFinestra);
    this->setText(testo);
    if(n == "Informazione") {
        setIcon(QMessageBox::Information);
        setWindowIcon(QIcon(":/IMMAGINI/information.png"));
    } else if(n== "Warning") {
        setIcon(QMessageBox::Warning);
        setWindowIcon(QIcon(":/IMMAGINI/warning.png"));
    } else {
        setIcon(QMessageBox::Critical);
        setWindowIcon(QIcon(":/IMMAGINI/critical.png"));
    }
}
