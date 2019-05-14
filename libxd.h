#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

#define intentos 3

using namespace std;

void ConsultaDB(){

system("color a");
ifstream archivo;

try{
    archivo.open("lc5.txt");
    if(archivo.fail()) throw "No esta disponible la base de datos.";
}catch(const char * mensaje){
    cout<<">>Error: "<<mensaje;
    system("pause>nul");
    exit(0);
}catch(...){}

string matricula;
string nombre;
int n;

string dato;

system("cls");

cout<<"Ingrese su nombre o matricula: ";
getline(cin,dato);

for(int i = 0; i<dato.size(); i++){
    dato[i] = toupper(dato[i]);
}

while(!archivo.eof()){

    getline(archivo,matricula);
    nombre = matricula;

    string aux;

    for(int i=0; i<6; i++){
        aux+=matricula[i];
    }
    matricula=aux;
    aux.clear();

    for(int i=7; i<nombre.size(); i++){
        aux+=nombre[i];
    }
    nombre=aux;
   // cout<<nombre;system("pause");

    if(dato==matricula) break;
    if(dato==nombre) break;
}

system("cls");

if(dato==nombre || dato==matricula){
    cout<<"Existe"<<endl;
    cout<<"Matricula: "<<matricula<<endl<<"Nombre: "<<nombre<<endl;
}else{
    cout<<"No Existe"<<endl;
    system("pause");
    //exit(0);
}

archivo.close();
}
