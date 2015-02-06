#include "arbolbinario.h"
#include <string>
#include <sstream>
#include <cstdlib>



/*Otra forma de dar el recorrido en preorden mediante un nodo*/

void RecorridoPreOrden (ostream & os,ArbolBinario<int>::nodo n){
	  if (!n.nulo()){
		    os<<" " <<(*n);
		    RecorridoPreOrden(os,n.hi());
		    RecorridoPreOrden(os,n.hd());
	  }	    
		    
	 
}	  




/*Otra forma de dar el recorrido en preorden mediante un iterador preorden_iterador*/
template <class T>
void RecorridoPreorden (ostream & os,const ArbolBinario<T> &a1){
	  typename ArbolBinario<T>::preorden_iterador pre;
	  //os<<endl<<"Preorden: ";
	  for (pre=a1.beginpreorden();pre!=a1.endpreorden(); ++pre){
	      os<<(*pre)<<" ";
	      
	  }   
	 
}
/*Otra forma de dar el recorrido en inorden mediante un iterador inorden_iterador*/
template <class T>
void RecorridoInorden (ostream & os,const ArbolBinario<T> &a1){
	  typename ArbolBinario<T>::inorden_iterador in;
	  //os<<endl<<"Inorden: ";
	  for (in=a1.begininorden();in!=a1.endinorden(); ++in){
	      os<<(*in)<<" ";
	        
	  }		  
}	  

/*Otra forma de dar el recorrido en postorden mediante un iterador postorden_iterador*/
template <class T>
void RecorridoPostorden (ostream & os,const ArbolBinario<T> &a1){
	  typename ArbolBinario<T>::postorden_iterador post;
	  //os<<endl<<"Postorden: ";
	  for (post=a1.beginpostorden();post!=a1.endpostorden(); ++post){
	      os<<(*post)<<" ";      
	  }   
}	  

/*Construye el arbol reflejado */
template <class T>
void ReflejaArbol(ArbolBinario<T> &ab,typename ArbolBinario<T>::nodo pos){
	  if (!pos.nulo() )
	     if( ! (pos.hi().nulo() && pos.hd().nulo()) ){
		    
		    ArbolBinario<T> ramai=ab.PodarHi_GetSubtree(pos);
		    ArbolBinario<T> ramad=ab.PodarHd_GetSubtree(pos);
		    
		    ab.Insertar_Hd(pos,ramai);
		    ab.Insertar_Hi(pos,ramad);
		    
		    
		    typename ArbolBinario<T>::nodo pi=pos.hi();
		    typename ArbolBinario<T>::nodo pd=pos.hd();
		    ReflejaArbol(ab,pi);
		    ReflejaArbol(ab,pd);
	  }
}
template <class T>
bool SonReflejados (ArbolBinario<T> &a1,ArbolBinario<T>&a2){
	  typename ArbolBinario<T>::preorden_iterador pre=a1.beginpreorden();
	  typename ArbolBinario<T>::postorden_iterador post=a2.beginpostorden();
	  string s1="",s2="";
	  for (;pre!=a1.endpreorden() && post!=a2.endpostorden(); ++pre,++post){
		    std::stringstream out;
		    out <<(*pre);
		    s1+=out.str();
		    out.str("");
		    out<<(*post);
		    s2+=out.str();
		    
			
	  }
	  for (int i=0,j=s2.size()-1;i<s1.size(),j>=0;i++,j--)
		    if (s1[i]!=s2[j]) return false;
	  return true;
}	  

void ConstruyeArbol(ArbolBinario<int>&a,ArbolBinario<int>::nodo n,string &spreorden, string sinorden) {
	  
	  
	  if (spreorden.size()>0 && sinorden.size()>0){
			istringstream si (spreorden);      
			string aux ;
			si>>aux; // hasta que encontremos un espacio
			size_t pos=sinorden.find(aux);
		        
			(*n)=atoi(aux.c_str());//convertimos a entero   
			
			string sizq=sinorden.substr(0,pos); // subcadena que pertenece al subarbo izquierdo
			if (pos!=string::npos){
                               // eliminamos el nodo creado				  
			      spreorden = spreorden.substr(aux.size()+1,spreorden.size()-aux.size()-1);
			      
			      //insertamos el subarbol izquierdo
			      if (sizq.size()>0){
					a.Insertar_Hi(n,0);//creamos un nuevo nodo
					ConstruyeArbol(a,n.hi(),spreorden,sizq);
			      }
			      string sder = sinorden.substr(pos+1+aux.size());
			      if (sder.size()>0){
			       a.Insertar_Hd(n,0);
			       ConstruyeArbol(a,n.hd(),spreorden,sder);
			     } 
			}      
		 
	  }	 
}
int main(){
 ArbolBinario<int> a;
 
 // ej:n1n2n4xxn5xxn3n6xxn7xx se corresponde con el arbol
 // 1
 // |_2
 // | |_4
 // | |_5	  
 // |_3
 //   |_6
 //   |_7
 cout<<"Introduce un arbol:";
 
 cin>>a;
 cout<<endl<<"El arbol insertado: "<<endl;
 cout<<a<<endl;
 
 
//Funciones de arbolbinario: recorridos implementados de forma recursiva
/* cout<<"El recorrido en Preorden"<<endl;
 a.RecorridoPreOrden(cout);cout<<endl;
 cout <<"El recorrido en Inorden"<<endl;
 a.RecorridoInOrden(cout);cout<<endl;
 cout <<"El recorrido en Postorden"<<endl;
 a.RecorridoPostOrden(cout);cout<<endl;
 */
 
 //recorrido en preorden haciendo uso de nodo
 cout<<endl<<"Recorrido en preorden usando un iterador nodo:";
 RecorridoPreOrden(cout,a.getRaiz());
 
 cout<<endl<<"El recorrido por niveles:"<<endl;
 a.RecorridoNiveles(cout);cout<<endl;
 //Recorrido usando iteradores preorden_iterador, inorden_iterador y postorden_iterador
 ostringstream spre,sin;
 RecorridoPreorden(spre,a); //obtenemos el listado en un flujo ostringstream
 cout<<"Recorrido Preorden:"<<spre.str()<<endl;
 RecorridoInorden(sin,a);
 cout<<"Recorrido Inorden:"<<sin.str()<<endl;
 cout<<"Recorrido Postorden:";
 RecorridoPostorden(cout,a);//obtenemos el listado solamente en el cout
 
 
 //A partir del recorrido preorden e inorden creamos el arbol
 if (spre.str().size()>0){
	  ArbolBinario<int>ab(0); // tiene que tener un nodo al menos
	  string pre=spre.str();
	  ConstruyeArbol(ab,ab.getRaiz(),pre,sin.str());
 	  cout<<endl<<"Arbol construido a partir del recorrido preorden e inorden: "<<ab<<endl;
 }
 else cout<<" El arbol es vacío"<<endl;

 ArbolBinario<int>a2,acopia(a);
 ArbolBinario<int>::nodo pos=acopia.getRaiz();
 
 //Contruimos el arbol reflejado
 ReflejaArbol(acopia,pos);
 
 
 // Vemos si dos arboles son uno el reflejo del otro usando sus recorridos preorden y postorden
 if (SonReflejados(a,acopia)){
	 cout<<"Los arboles "<<a << "y "<<acopia<<" son arboles reflejados"<<endl;
 }
 else cout<<"No son reflejados"<<endl;
	 
//Eliminamos el hijo a la izquierda
 cout<<"Podamos hijo a la izquierda de "; RecorridoPreorden(cout,acopia);
 
 acopia.Podar_Hi(acopia.getRaiz());
 cout<<"Resultado :";
 RecorridoPreorden(cout,acopia);
 if (!acopia.getRaiz().hd().nulo()){
	  cout<<endl<<"Podando el nieto a la derecha :";
	  acopia.Podar_Hd(acopia.getRaiz().hd());
	  RecorridoPreorden(cout,acopia);
 }	  
 
 if (acopia==a){
	   cout<<endl<<acopia<<" y "<<a<<" son iguales"<<endl;
 }
 else if (acopia!=a){
	   cout<<endl<<acopia<<" y "<<a<<" son distintos"<<endl;
 }	   
 
 
}