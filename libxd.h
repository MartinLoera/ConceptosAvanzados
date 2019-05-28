#include <iostream> /** Libreria para usar cout y cin */
#include <stdlib.h> /** Libreria para usar los comandos del sistema operativo. */
#include <fstream> /**Libreria para manejar ficheros de entrada y salida. */
#include <string.h> /** Libreria para usar cadenas de texto. */
#include <windows.h>
#include <cstdlib>
#include <ctime> /** Libreria para obtener la hora. */

#define INTENTOS 3 /** Numero limite de intentos para validar un input. */

using namespace std;

ifstream archivo;

bool activo = true; /** Variable para saber cuando termina el programa */
static int conteo; /** Variable para contar el numero de intentos al validar un input. */

void buscar(); /** Protocolo de función que busca al alumno en la base de datos. */
void barra(); /** Protocolo de función que imprime una barra de titulo.*/
void bye(); /** Protocolo de función para imprimir una despedida. */

/** Se declara un nuevo tipo de variable llamado T*/
template<typename T>
	
/**
 * Una función de tipo void
 * @param horaLocal es una variable tipo T en la que se alojara la hora según el sistema
 * @param minutoLocal es una variable tipo T en la que se alojara el minuto según el sistema
*/
void Retraso(T&horaLocal, T&minutoLocal){
		if(minutoLocal!= 0){
			cout<<"\n\t\t\tTu clase de las "<<horaLocal<<" horas ya empezo"<<endl;
		}
}

/** Una funcion de tipo void.
 * Función para acceder y buscar una cadena.
*/
void ConsultaDB(){
system("color A");
int opcion;

barra();

string *texto = new string[4]; /** Arreglo de memoria dinamica para seleccion de opciones. */

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
	cin.ignore(); /** Este comando sirve para borrar el buffer del cin. */
	
	delete []texto; /** Se libera la memoria dinamica. */
	
	/** Switch para cada opcion del menú mostrado. */
	switch(opcion){
		case 0:
			system("cls");
			activo = false;
			cout<< endl << endl <<endl;
			bye();
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t";
			
			/**
			 * Ciclo que imprime una cuenta regresiva para salir del programa.
			*/
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
/** Una funcion de tipo void.
 * Declaración de función que busca al alumno en la base de datos.
*/
void buscar(){
	
	/**
	 * Variables para la busqueda de alumno.
	*/
	int n;
	string matricula;
	string nombre;
	string dato;
	
	time_t now = time(0); /** time_t es un tipo de variable capaz de representar los tiempos segun devuelto por la funcion time */
	tm * time = localtime(&now);  /** tm es una estructura de tiempo que contiene una fecha y hora de calendario desglosada en sus componentes */
	
	system("cls");
	cout<<endl<<endl<<"\t\t\tIngrese su nombre o matricula: ";
	getline(cin,dato);
	
	/**
	 * Ciclo para convertir de minusculas a mayusculas.
	*/
	for(int i = 0; i<dato.size(); i++){ 
	    dato[i] = toupper(dato[i]);
	}
	
	/**
	 * Ciclo para guardar lo leido por la consola en una cada variable.
	*/
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
		Retraso(time->tm_hour, time->tm_min); /** Se invoca a la función Retraso se pasan parametros por valor */
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

/** 
 * Una funcion de tipo void.
 * Declaración de función que nos permite manipular la posición en la pantalla de lo que nuestra aplicación imprima, pueden ser variables tipo char, int, etc.
 * @param x es una variable de tipo entero que será la coordenada en x de la consola de Windows.
 * @param y es una variable de tipo entero que será la coordenada en y de la consola de Windows.
 * HANDLE es un identificador de un objeto o recurso unico 
 * COORD es una estructura definida de la libreria windows.h
 * SetConsoleCursorPosition Situa el cursor en una posicion de la cosola tomando como primer parametro el identificador de consola y el segundo la estructura de datos 
*/
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos; 
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);	 
}

/** 
 * Una funcion de tipo void.
 * Declaración de función que muestra la hora y el dia actual tomado directamente del sistema.
 * time_t es un tipo de variable capaz de representar los tiempos segun devuelto por la funcion time
 * tm es una estructura de tiempo que contiene una fecha y hora de calendario desglosada en sus componentes
 * La estructura tm contiene nueve miemnros de tipo entero, entre ellos los que usamos tm_year(años desde 1900), tm_hour(horas desde la medianoche), 
   tm_min(minutos después de la hora), tm_wday(días desde el domingo),tm_mday(día del mes), tm_mom(meses desde enero).
 * El operador -> sirve para apuntar a un espaacio de memoria.
 * dia_semana es un string con caracteres de los dias de la semana
 * meses es un string con caracteres de los meses del año
 * Sleep hara que la funcion se duerma durante un minuto.
*/
void reloj(){

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

/** Una funcion de tipo void.
 * Función para mostrar el programa en pantalla completa.
*/
void FullScreen(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

/** Una funcion de tipo void.
 * Declaración de la funcion que imprime una barra de titulo.
*/
void barra(){
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********                        ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********   <  Consulta UACH  >  ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********                        ************"<<endl;
	cout<<"\t\t\t\t\t\t\t**********************************************"<<endl;
	cout<<endl;
}

/**  Una funcion de tipo void.
 * Declaración de la función para imprimir una despedida.
*/
void bye(){
	cout<<"\t\t\t\t\t\t _____                                      _____"<<endl;
    cout<<"\t\t\t\t\t\t( ___ )------------------------------------( ___ )"<<endl;
    cout<<"\t\t\t\t\t\t | / |                                      | \\ |"<<endl;
	cout<<"\t\t\t\t\t\t | / |               Good Bye               | \\ |"<<endl;
    cout<<"\t\t\t\t\t\t |___|                                      |___|"<<endl;
    cout<<"\t\t\t\t\t\t(_____)------------------------------------(_____)"<<endl;
}

/** Una funcion de tipo void.
 * Funcion para la musica de espera, supuestamente navideña.
*/
void NavidadMusic(){
Beep(3290,200);Beep(4930,200);Beep(6980,200);Beep(6590,300);Beep(7830,150);Beep(6980,150);Beep(6590,300);Beep(3290,50);
Beep(4930,150);Beep(6980,150);Beep(6590,300);Beep(3920,200);Beep(4400,100); Beep(5870,150);Beep(3490,150);Beep(5870,250);
Beep(3290,150);Beep(4930,150);Beep(6980,1500);Beep(6590,300);Beep(7830,150);Beep(6980,150);Beep(6590,300);Beep(3290,50);
Beep(4930,150);Beep(6980,150);Beep(6590,300);Beep(3920,200);Beep(4400,100); Beep(5870,150);Beep(3490,200);Beep(5870,200);
}
