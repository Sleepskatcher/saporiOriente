#include"GUI/inserisciDolce.h"

InserisciDolce::InserisciDolce(QWidget* p):
    QWidget(p),
    inizioInserisci(new QLabel(this)),
    labelNome(new QLabel(this)),
    nomeDolce(new QLineEdit(this)),
    glassaPanna(new QLabel(this)),
    glassa(new QCheckBox(this)),
    panna(new QCheckBox(this)),
    ingredientiL(new QLabel(this)),
    ingFreddo(new QComboBox(this)),
    ingCaldo(new QComboBox(this)),
    inserisci(new QPushButton(this)),
    reset(new QPushButton(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* layoutNome = new QHBoxLayout();
    QVBoxLayout* layoutGP = new QVBoxLayout();
    QHBoxLayout* gp = new QHBoxLayout();
    QHBoxLayout* bottoni = new QHBoxLayout();
    QVBoxLayout* INGLabel = new QVBoxLayout();
    QHBoxLayout* ingredienti = new QHBoxLayout();

    labelNome->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    labelNome->setWordWrap(true);
    ingredientiL->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ingredientiL->setWordWrap(true);
    glassaPanna->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    glassaPanna->setWordWrap(true);
    inizioInserisci->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    inizioInserisci->setWordWrap(true);

    inizioInserisci->setText("ATTENZIONE! I campi con l'asterisco sono obbligatori.");
    labelNome->setText("Inserisci il nome del dolce*");
    inserisci->setText("Inserisci Dolce");
    reset->setText("Resetta i campi");
    glassa->setText("Glassa al cioccolato");
    panna->setText("Panna Montata");
    glassaPanna->setText("Spuntare le checkbox se si vuole la glassa al cioccolato e/o la panna montata.");
    ingredientiL->setText("Selezionare gli ingredienti, se non viene selezionato alcun ingrediente verrà creato "
                          "il piatto con il primo ingrediente delle liste.");

    QList<QString> ingFreddi = {"Gelato al cioccolato","Gelato alla fragola","Gelato alla panna","Gelato stracciatella"};

    std::sort(ingFreddi.begin(), ingFreddi.end());

    for(int i=0;i<ingFreddi.length();++i) ingFreddo->addItem(ingFreddi[i]);

    QList<QString> ingCaldi = {"Pane di riso","Pane bianco","Pane al mais","Pane integrale"};

    std::sort(ingCaldi.begin(), ingCaldi.end());

    for(int i=0;i<ingCaldi.length();++i) ingCaldo->addItem(ingCaldi[i]);

    INGLabel->addWidget(ingredientiL);
    INGLabel->addLayout(ingredienti);

    ingredienti->addWidget(ingFreddo);
    ingredienti->addWidget(ingCaldo);

    layoutNome->addWidget(labelNome);
    layoutNome->addWidget(nomeDolce);

    bottoni->addWidget(inserisci);
    bottoni->addWidget(reset);

    layoutGP->addWidget(glassaPanna);
    layoutGP->addLayout(gp);

    gp->addWidget(glassa);
    gp->addWidget(panna);

    layout->addWidget(inizioInserisci);
    layout->addLayout(layoutNome);
    layout->addLayout(INGLabel);
    layout->addLayout(layoutGP);
    layout->addLayout(bottoni);

    connect(reset,SIGNAL(clicked()),this,SLOT(resetCampi()));
}

void InserisciDolce::resetCampi() {
    nomeDolce->setText("");
    glassa->setCheckState(Qt::Unchecked);
    panna->setCheckState(Qt::Unchecked);
    ingCaldo->setCurrentIndex(0);
    ingFreddo->setCurrentIndex(0);
}

piatto* InserisciDolce::nuovoDolce() {
    piatto* ritorno = nullptr;
    //nome
    std::string nuovoNome=nomeDolce->text().toStdString();
    //ingrediente freddo
    std::vector<std::string> nuovoFreddo;
    nuovoFreddo.push_back(ingFreddo->currentText().toStdString());
    //ingrediente caldo
    std::vector<std::string> nuovoCaldo;
    nuovoCaldo.push_back(ingCaldo->currentText().toStdString());
    //glassa
    bool glassaNova=glassa->isChecked()==true ? true : false;
    //panna
    bool pannaNuova=panna->isChecked()==true ? true : false;
    ritorno = new gelatoFritto(nuovoNome,nuovoFreddo,nuovoCaldo,3,false,false,glassaNova,pannaNuova);
    return ritorno;
}

QPushButton* InserisciDolce::getBottoneInserisciDolce() {
    return inserisci;
}

bool InserisciDolce::controllo() {
    bool ritorno=false;
    if(nomeDolce->text()=="") return ritorno=false;
    else ritorno=true;
    return ritorno;
}
