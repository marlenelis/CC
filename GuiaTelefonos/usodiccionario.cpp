#include <iostream>

#include "diccionario.h"
		 
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
	  Diccionario<string,string> ::const_iterator it;
	  for (it=D.begin(); it!=D.end(); ++it){
	  
		    vector<string>::const_iterator it_s;
		    os<<endl<<(*it).first<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).second.begin();it_s!=(*it).second.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }
	  
	  return os;
}
//EL formato de la entrada es:
//   numero de claves en la primera linea
//   clave-iseima retorno de carro
//   numero de informaciones asociadas en la siguiente linea
//   en cada linea informacion asociada

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    vector<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);
		    
	  }
	  D=Daux;
	  return is;
}
void EscribeSigni(const vector<string>&l){		 
	  vector<string>::const_iterator it_s;
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	  
int main(){
 Diccionario<string,string > D;

	cin>>D;
	cout<<D;
	string a;

	cout<<"Introduce una palabra"<<endl;
	cin>>a;
	cout<<"**************"<<endl<<"Los significados de :"<<a<<" son:"<<endl;
	vector<string> l=D.getInfo_Asoc(a);
	if (l.size()>0)
		  EscribeSigni(l);

	}