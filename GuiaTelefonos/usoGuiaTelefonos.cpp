
#include<iostream>
#include "guiaTelefonos.h"
using namespace std;

int main(){
	Guia_Tlf nuevo;
	cin>>nuevo;
	cout<<nuevo;
	string a;
	cout<< "";
	cin>>D;
	cout<<D;
	string a;

	cout<<"Introduce nombre"<<endl;
	cin>>a;
	cout<<"**************"<<endl<<"telefono:"<<a<<endl;
	vector<string> l=nuevo.get_InfoAsociada(a);
	if (l.size()>0)
		  nuevo.EscribeInformacion(l);

	}
	
}
