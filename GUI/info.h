#ifndef INFO_H
#define INFO_H

#include<QWidget>
#include<QMessageBox>
#include<QVBoxLayout>

class Info: public QMessageBox {
    Q_OBJECT
private:
    QMessageBox* messaggio;
public:
    Info(QWidget* = nullptr);
};

#endif // INFO_H
