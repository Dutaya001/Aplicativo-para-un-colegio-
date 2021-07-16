#include <iostream>
#include <fstream>
#include <string>
//#define NOMBRE "listado.csv"
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
void Usuario::eliminar(string code){
    ofstream escritura;
    escritura.open("listado.csv",ios::ate);
}
void Usuario::listarTodos(){
    ifstream lectura;
    string temp;
    lectura.open("final.csv",ios::in);
    lectura>>temp;
    int i=0;
    while (!lectura.eof()){
        for(int i=0;i<8;i++){   
            string *ptr;
            if(i==0){
                ptr = strtok(temp,",");
            }
        }
       //lectura.getline(temp,sizeof(temp));  
        i++;
        //getline(lectura,temp);
        //cout<<temp<<endl;
        //cout<< i<<endl;        
    }
    //int i=0;
    // while(lectura.good()){
    //     lectura>>password>>codigo>>nombre>>fono>>direccion>>sexo>>internet>>covid;
    //     cout<<i<<" "<<password<<" "<<nombre<<" "<<endl;
    //     i++;
    // }
    lectura.close();

}
