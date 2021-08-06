#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>

namespace Ui {
class Registro;
}

class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();
    void CrearTabla();
    void agregar();
    int buscar(std::string _password,std::string _codigo);
    void eliminar(int);
    void listarTodos();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Registro *ui;
    int tam=5;
    std::string password;
    std::string codigo;
    std::string  nombre;
    int fono;
    std::string direccion;
    char sexo;
    std::string internet;
    std::string covid;
};

#endif // REGISTRO_H
