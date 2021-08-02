#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Usuario{
    int tam=6;
    string password;
    string codigo;
    string  nombre;
    int fono;
    string direccion;
    char sexo;
    string internet;
    string covid;
    
    public:
        //Usuario(string,string,string);
        void agregar();
        int buscar(string _password,string _codigo);
        void eliminar(string);
        void listarTodos();
        //void verificar();
};
void Usuario::agregar(){
    ofstream escritura; //escribir  fichero(entrada)
    //ifstream verificador;   //leer    ficheros(salida)
    escritura.open("final.csv",ios::app);
    //verificador.open("users.csv",ios::app);
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
    cout<<"\n\t\tDatos agregados :\n";
    cout<<"contraseña : "<<password<<"codigo : "<<codigo<<"\nnombre : "<<nombre<<"\ntelefono : "<<fono<<"\ndireccion : "<<direccion<<"\nsexo : "<<sexo<<"\nPresenta internet : "<<internet<<"\nPresenta covid : "<<covid<<"\nContraseña : "<<password<<"\n";
}
int Usuario::buscar(string _password, string _codigo){
    ifstream leer;
    string linea;
    int busq_linea=1;
    char coma = ',';
    leer.open("final.csv",ios::in);
    getline(leer,linea);

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
        if(i==_password.size()+1){
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
void Usuario::eliminar(string linea){    //incompleto
    ifstream eliminar;
    ofstream copiar;
    string linea;
    eliminar.open("listado.csv");
    while(getline(eliminar,linea)){
        

    }
    
    eliminar.close();
}
void Usuario::listarTodos(){
    ifstream lectura;
    string temp;
    lectura.open("final.csv",ios::in);
    lectura>>temp;
    int i=0;
    while (!lectura.eof()){
        getline(lectura,temp);
        cout<<temp<<endl;
        i++;
        }
    lectura.close();
}
