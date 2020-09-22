#ifndef LAYOUTPRINC_H
#define LAYOUTPRINC_H

#include<QWidget>
#include<QPixmap>
#include<QLabel>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QPushButton>

class layoutPrinc: public QWidget {
    Q_OBJECT
private:
    QPixmap* immagine;
    QLabel* layoutPrincipaleTesto;
    QLabel* layoutPrincipaleImmagine;
    QPushButton* menuBut;
public:
    layoutPrinc(QWidget* = nullptr);
    QPushButton* getMenuBut() const;
};

#endif // LAYOUTPRINC_H
