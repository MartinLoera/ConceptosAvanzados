#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define INTENTOS 3 //Numero limite de intentos para validar un input.

using namespace std;

ifstream archivo;

bool activo = true; //Variable para saber cuando termina el programa
static int conteo; //Variable para contar el numero de intentos al validar un input.

void buscar();
void barra();
void bye();

//Función para acceder y buscar una cadena.
void ConsultaDB(){
system("color A");
int opcion;

barra();

string *texto = new string[4];

texto[0] = "\t\t\t0) Apagar sistema";
texto[1] = "\t\t\t1) Laboratorio: LC5";
texto[2] = "\t\t\t2) Laboratorio: LC7";
texto[3] = "\t\t\t3) Salon: 63";

try{
	cout<<"\t\t\t<< Men"<<char(163)<<" de opciones >>"<<endl<<endl;
	cout<<texto[0]<<endl<<endl;
	cout<<texto[1]<<endl<<endl;
	cout<<texto[2]<<endl<<endl;
	cout<<texto[3]<<endl<<endl<<endl;
	cout<<"\t\t\tA que sal"<<char(162)<<"n desea ingresar, escribe el numero del salon: ";
	cin>> opcion;
	cin.ignore();
	
	delete []texto;
	
	switch(opcion){
		case 0:
			system("cls");
			activo = false;
			cout<< endl << endl <<endl;
			bye();
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t";
			for(int i = 10; i > 0; i--){
				cout<<i<<"..\t";
				Sleep(400);
			}
			
			cout<<endl<<endl;
			exit(0);
		case 1:
		    archivo.open("lc5.txt");
	    	if(archivo.fail()) throw "No esta disponible la base de datos del laboratorio 5.";
			else{
				buscar();
			}
			break;
		case 2:
		    archivo.open("lc7.txt");
	    	if(archivo.fail()) throw "No esta disponible la base de datos del laboratorio 7.";
			else{
				buscar();
			}
			break;
		case 3:
		    archivo.open("sa-63.txt");
	    	if(archivo.fail()) throw "No esta disponible la base de datos del salon 63";
	    	else{
	    		buscar();
			}
			break;
		default:
			system("cls");
			cout<<endl<<endl<<"\t\t\tNo existe el salon al que intentas acceder."<<endl<<endl<<"\t\t\tPor favor intente de nuevo...";
			system("pause>nul");
			break;
	}
}catch(const char * mensaje){
	cout<<">>Error: "<<mensaje;
	system("pause>nul");
	exit(0);
}catch(...){
	system("color 4");
	cout<<"Error: excepcion inesperada";
	system("pause>nul");
	}
}

void buscar(){
	
	string matricula;
	string nombre;
	int n;
	string dato;
	
	system("cls");
	cout<<endl<<endl<<"\t\t\tIngrese su nombre o matricula: ";
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
		conteo = INTENTOS;
	    cout<<endl<<endl<<"\t\t\tAccedio con exito al salon."<<endl<<endl;
	    cout<<"\t\t\tMatricula: "<<matricula<<endl<<"\t\t\tNombre: "<<nombre;
	    system("pause>nul");
	}
	else{
		conteo--;
		Beep(2000, 500);
	    cout<<endl<<endl<<"\tNo Existe";
	    system("pause>nul");
	    //exit(0);
	}
	
	archivo.close();
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);	
}

void reloj()
{

time_t now = time(0);

tm * time = localtime(&now);

string dia_semana[7]={"domingo","lunes","martes","miercoles","jueves","viernes","sabado"};

string meses[12]={"Enero","Febrero","marzo","abril","mayo", "junio","julio","agosto","septiembre","noviembre","diciembre"};

int year = 1900 + time->tm_year;

while(activo==true){
	for(int h=time->tm_hour; h<23; h++){
		for(int m=time->tm_min; m<60; m++){
				gotoxy(56,2);
				cout << "Hoy es " << dia_semana[time->tm_wday] << ", " << time->tm_mday << " de " << meses[time->tm_mon] << " del " << year << " Hora: ";
				
				if(h<10){
					cout << "0";
				}
				
				cout << h << ":";
				
				if(m<10){
					cout<<"0";
				}
				cout << m  << endl;
				Sleep(60000);	
			}
		}
	}
}

//Función para mostrar el programa en panatalla completa.
void FullScreen(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

//Función que imprime una barra de titulo.
void barra(){
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********                        ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********   <  Consulta UACH  >  ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********                        ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<endl;
}

//Función para imprimir una despedida.
void bye(){
	cout<<"\t\t\t\t\t\t _____                                      _____"<<endl;
    cout<<"\t\t\t\t\t\t( ___ )------------------------------------( ___ )"<<endl;
    cout<<"\t\t\t\t\t\t | / |                                      | \\ |"<<endl;
	cout<<"\t\t\t\t\t\t | / |               Good Bye               | \\ |"<<endl;
    cout<<"\t\t\t\t\t\t |___|                                      |___|"<<endl;
    cout<<"\t\t\t\t\t\t(_____)------------------------------------(_____)"<<endl;
}

//Musica de espera, supuestamente navideña.
void NavidadMusic(){
Beep(3290,200);Beep(4930,200);Beep(6980,200);Beep(6590,300);Beep(7830,150);Beep(6980,150);Beep(6590,300);Beep(3290,50);
Beep(4930,150);Beep(6980,150);Beep(6590,300);Beep(3920,200);Beep(4400,100); Beep(5870,150);Beep(3490,150);Beep(5870,250);
Beep(3290,150);Beep(4930,150);Beep(6980,1500);Beep(6590,300);Beep(7830,150);Beep(6980,150);Beep(6590,300);Beep(3290,50);
Beep(4930,150);Beep(6980,150);Beep(6590,300);Beep(3920,200);Beep(4400,100); Beep(5870,150);Beep(3490,200);Beep(5870,200);
}
