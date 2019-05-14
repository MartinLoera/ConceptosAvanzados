#include <iostream>
#include "libxd.h"
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	
	for(int i = 1; i<=intentos; i++){
		ConsultaDB();
	}
	system("cls");
	cout<<"Limite de intentos exedidos, me muero."<<endl;
	
	return 0;
}
