#include "registro.h"
#include "ui_registro.h"
#include "QDebug"
#include "QString"
#include "QSqlQuery"
#include "QtSql/QSqlError"
Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    CrearTabla();
}

Registro::~Registro()
{
    delete ui;
}
void Registro::CrearTabla(){
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXITS usuario("
                    "id INTEGER AUTOINCREMENT,"
                    "nombre VARCHAR(25),"
                    "pass VARCHAR(25),"
                    "nick VARCHAR(25)PRYMARY KEY,");
}

void Registro::on_pushButton_clicked()
{
    QString nom=ui->nom->text();
    QString contra=ui->contra->text();
    QString telefono=ui->contra->text();
    QString direccion=ui->contra->text();
    qDebug()<<nom;
    qDebug()<<contra;
    qDebug()<<telefono;
    qDebug()<<direccion;

    QString insertar;
    insertar.append("INSER INTO usuario(nombre,pass,nick)"
                    "values(:nombre,:pass,:nick)");
    QSqlQuery insertar_db;
    insertar_db.prepare(insertar);
    insertar_db.bindValue(":nombre",nom);
    insertar_db.bindValue(":pass",contra);
    insertar_db.bindValue(":nick",telefono);
    if(insertar_db.exec()){
        qDebug()<<"Datos ingresados ala tabla";
    }
    else{
        qDebug()<<"Error al ingresar los datos"<<insertar_db.lastError();
    }
}

