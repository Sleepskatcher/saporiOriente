#include"GUI/paginaModificaDolce.h"

ModificaDolce::ModificaDolce(QWidget* p):
    parent(p),
    nomeMod(new QLineEdit(this)),
    glassaMod(new QCheckBox(this)),
    pannaMod(new QCheckBox(this)),
    ingFreddoMod(new QComboBox(this)),
    ingCaldoMod(new QComboBox(this)),
    salvaModDolce(new QPushButton(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* layoutNome = new QHBoxLayout();
    QHBoxLayout* layoutGP = new QHBoxLayout();
    QHBoxLayout* bottone = new QHBoxLayout();
    QHBoxLayout* ingredienti = new QHBoxLayout();

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowIcon(QPixmap(":/logo.jpg"));
    setMinimumSize(700,400);

    glassaMod->setText("Glassa al cioccolato");
    pannaMod->setText("Panna Montata");
    salvaModDolce->setText("Salva Modifiche");

    QList<QString> ingFreddi = {"Gelato al cioccolato","Gelato alla fragola","Gelato alla panna","Gelato stracciatella"};

    std::sort(ingFreddi.begin(), ingFreddi.end());

    for(int i=0;i<ingFreddi.length();++i) ingFreddoMod->addItem(ingFreddi[i]);

    QList<QString> ingCaldi = {"Pane di riso","Pane bianco","Pane al mais","Pane integrale"};

    std::sort(ingCaldi.begin(), ingCaldi.end());

    for(int i=0;i<ingCaldi.length();++i) ingCaldoMod->addItem(ingCaldi[i]);

    ingredienti->addWidget(ingFreddoMod);
    ingredienti->addWidget(ingCaldoMod);

    layoutNome->addWidget(nomeMod);

    bottone->addWidget(salvaModDolce);

    layoutGP->addWidget(glassaMod);
    layoutGP->addWidget(pannaMod);

    layout->addLayout(layoutNome);
    layout->addLayout(layoutGP);
    layout->addLayout(ingredienti);
    layout->addLayout(bottone);

}

QPushButton* ModificaDolce::getSalvaModDolce() {
    return salvaModDolce;
}

void ModificaDolce::setPiattoDolce(piatto *p) {
    dishMod=p;
}

void ModificaDolce::compilaModDolce() {
    nomeMod->setText(QString::fromStdString(dishMod->getNomePiatto()));
    gelatoFritto* g = dynamic_cast<gelatoFritto*>(dishMod);
    if(g->getCioccolato()) glassaMod->setCheckState(Qt::Checked);
    else glassaMod->setCheckState(Qt::Unchecked);
    if(g->getPanna()) pannaMod->setCheckState(Qt::Checked);
    else pannaMod->setCheckState(Qt::Unchecked);
    std::string giustoF = *((g->getIngredientiFreddi()).begin());
    ingFreddoMod->setCurrentIndex(ingFreddoMod->findText(QString::fromStdString(giustoF)));
    std::string giustoC = *((g->getIngredientiCaldi()).begin());
    ingCaldoMod->setCurrentIndex(ingCaldoMod->findText(QString::fromStdString(giustoC)));
}

void ModificaDolce::setNuoviCampiDolce() {
    dishMod->setNome(nomeMod->text().toStdString());
    gelatoFritto* g = dynamic_cast<gelatoFritto*>(dishMod);
    g->svuotaIngredientiFreddi();
    g->setIngredientiFreddi(ingFreddoMod->currentText().toStdString());
    g->svuotaIngredientiCaldi();
    g->setIngredientiCaldi(ingCaldoMod->currentText().toStdString());
}
