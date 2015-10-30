#ifndef RED_H
#define RED_H

#include <QMainWindow>

namespace Ui {
class Red;
}

class Red : public QMainWindow
{
    Q_OBJECT

public:
    explicit Red(QWidget *parent = 0);
    ~Red();

private slots:
    void on_btnCalcular_clicked();

private:
    Ui::Red *ui;
};

#endif // RED_H
