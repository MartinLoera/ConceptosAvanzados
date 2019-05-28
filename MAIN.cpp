#include <iostream>
#include "libxd.h"
#include <stdlib.h>
#include <thread> 

using namespace std;

int main(){
	
	FullScreen();
	thread hilo(reloj);
	
	conteo = INTENTOS;
	
	while(activo){
		
		if(conteo<=INTENTOS & conteo > 0){
			
			ConsultaDB();
			
		}else{
			
			thread Musica(NavidadMusic);
			
			cout<<endl<<endl<<"\t\t\t\tLimite de intentos exedidos\n\n\t\t\t\tVuelva a intentarlo m"<<char(160)<<"s tarde..."<<endl<<endl;
			cout<<"\t\t\t\t\t";
			for(int i = 30; i > 0; i--){
				
				cout<<i<<" ";
				Sleep(500);
			}
			
			conteo = INTENTOS;
			Musica.detach();
		}
		
		system("cls");
	}
	
	hilo.detach();
	
	return 0;
}
