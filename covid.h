#include <iostream>
#include <fstream>
#include <string>
//#define NOMBRE "listado.csv"
using namespace std;
class Usuario{
    string codigo;
    string  nombre;
    string fono;
    string direccion;
    string sexo;
    string internet;
    string covid;
    string password;
    public:
        //Usuario(string,string,string);
        void agregar();
        void verificar();
};
void Usuario::agregar(){
    ofstream escritura; //escribir 
    ifstream verificador;   //leer
    escritura.open("users.csv",ios::out);
    verificador.open("users.csv",ios::app);

    cout<<"password "; 
    getline(cin,password);   
    cout<<"ingrese codigo";
    getline(cin,codigo);
    cout<<"ingrese nombre :";
    getline(cin,nombre);
    cout<<"ingrese telefono";
    getline(cin,fono);
    cout<<"ingrese direccion";
    getline(cin,direccion);
    cout<<"ingrese sexo";
    getline(cin,sexo);
    cout<<"tiene conexion a internet?";
    getline(cin,internet);
    cout<<"presenta covid?";
    getline(cin,covid);
    cout<<"\n\t\tDatos agregados :\n";
    cout<<"nombre : "<<nombre<<"\ntelefono : "<<fono<<"\ncodigo : "<<codigo<<endl;
    escritura<<nombre<<"\t"<<fono<<"\t"<<codigo<<"\n"; 
}
//incompleto
void Usuario::verificar(){
    ifstream verificador;   //leer
    verificador.open("users.csv",ios::app);
    //verificador.seekg(0);
    while (!verificador.eof())
    {   getline(verificador,nombre);
        getline(verificador,fono);
        getline(verificador,direccion);
        getline(verificador,sexo);
        getline(verificador,internet);
        getline(verificador,covid);
    }
    cout<<nombre<<"\n"<<fono<<"\n"<<direccion<<"\n"<<sexo<<"\n"<<internet<<"\n"<<covid;
    verificador.close();

}
