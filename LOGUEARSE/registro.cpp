#include "registro.h"
#include "ui_registro.h"
#include "QDebug"
#include "QString"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include <iostream>
#include <fstream>
using namespace std;
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
void Registro::agregar(){
    ofstream escritura; //escribir  fichero(entrada)
    escritura.open("final.csv",ios::app);
    tam++;
    cout<<"elija contraseña password ";
    getline(cin,password);
    cout<<"ingrese codigo :";
    getline(cin,codigo);
    cout<<"ingrese nombre :";
    getline(cin,nombre);
    cout<<"ingrese telefono : ";
    cin>>fono;
    cin.ignore();
    cout<<"ingrese direccion : ";
    getline(cin,direccion);
    cout<<"ingrese sexo :";
    cin>>sexo;
    cin.ignore();
    cout<<"tiene conexion a internet? :";
    getline(cin,internet);
    cout<<"presenta covid? :";
    getline(cin,covid);

    escritura<<password<<","<<codigo<<","<<nombre<<","<<fono<<","<<direccion<<","<<sexo<<","<<internet<<","<<covid<<"\n";
    escritura.close();
        //mostrar datos agregados
    cout<<"\n\t\tDatos agregados :\n";
    cout<<"contraseña : "<<password<<"codigo : "<<codigo<<"\nnombre : "<<nombre<<"\ntelefono : "<<fono<<"\ndireccion : "<<direccion<<"\nsexo : "<<sexo<<"\nPresenta internet : "<<internet<<"\nPresenta covid : "<<covid<<"\nContraseña : "<<password<<"\n";
}
int Registro::buscar(string _password, string _codigo){
    ifstream leer;
    string linea;
    int busq_linea=1;
    char coma = ',';
    leer.open("final.csv",ios::in);
    getline(leer,linea); // paso de linea

    while (getline(leer,linea)){
        int i=0;
        int j=0;
        while(linea[i] != coma){
            if(linea[i] != _password[i]){
                break;
            }
            i++;
            }
        i++;
        if(i == _password.size()+1){
            while (linea[i] != coma){
                if(linea[i] != _codigo[j]){
                    break;
                }
                i++;
                j++;
            }
            if(j==_codigo.size()){
                return busq_linea;
            }
        }
        busq_linea++;
    }
    leer.close();
    return 0;
}
void Registro::eliminar(int line){
    ifstream leer;  //leer
    ofstream temp;    //modificar
    string linea;
    leer.open("final.csv",ios::in);
    temp.open("temp.csv",ios::out);
    for(int i=0;i<tam;i++){
        if(i==line){
            cout<<"eliminado = ";
            getline(leer,linea);
            cout<<linea<<endl;
        }
        getline(leer,linea);
        temp<<linea;

    }
    temp.close();
    leer.close();
    remove("final.csv");
    rename("temp.csv","final.csv");
}
void Registro::listarTodos(){
    ifstream leer;
    string linea;
    leer.open("listado.csv",ios::in);
    getline(leer,linea);
    while(getline(leer,linea)){
        cout<<linea<<"\n";
    }
    leer.close();
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

