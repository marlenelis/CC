#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H

#include <iostream>
#include "diccionario.h"

using namespace std;

class Guia_Tlf{
	  private:
	  Diccionario<string,string> buffer;
					     
	  public:
		    Guia_Tlf(){
				Diccionario<string,string> nuevo;
				nuevo=0;
				buffer=nuevo;
				
			}
			Guia_Tlf(const Diccionario<string,string> &m){
				buffer=m;
			}
		    Guia_Tlf(const Guia_Tlf & gt){
				if(this!=gt){
					Diccionario<string,string> aux;
					aux.data=gt.data;
					buffer=aux;	
				}
				else
				buffer=0;						
			}
			
		    ~Guia_Tlf(){}
		    Guia_Tlf & operator=(const Guia_Tlf & gt){
				if(this!=gt){
					buffer=gt.buffer;			
				}
				return *this;
			}
		    /**
		      @brief Devuelve si el elemento con un determinada clave.
		      @param clave:clave del elemento a berificar
		      @return 
		    */
		    bool esta_enLaGuia( const string &clave ){
				 Diccionario<string,string> ::iterator it;
				 bool esta= buffer.Esta_Clave(clave,it);
				 return esta;
			}		    
		     
		    /**
		     @brief Insert un nuevo telefono 
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return 
		    */
			void Insertar(const string &nombre ,string &telf){
					buffer.Insertar(nombre,tlf);
		    }
		    
			void SetTelf(const string &nombre,const string &tlf){
					buffer.AddSignificado_Palabra(tlf ,nombre);
		    }
		    
		    vector<string>  getTelf(const string & p) {
			   vector<string>aux =  getInfo_Asoc(p) ;
			   return aux;			   
			}		
		 	
		    /**
		      @brief  Numero de telefonos 
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			      return buffer.size();
		    }	

/**************************************************************************************/			
class const_iterator;
		 class iterator{
			   private:
				Diccionario <string,string>:: iterator punt;
			   public:
				     iterator(){}
				     iterator & operator ++(){
					       punt++;
					       return *this;
				     }	       
				     iterator & operator --(){
					       punt--;
					       return *this;
				     }	       
				     bool operator ==(const iterator & it){
					       return it.punt==punt;
				     }
				     bool operator !=(const iterator & it){
					       return it.punt!=punt;
				     }
				     //pair<t1,vector<t2> > & operator *(){
					 //      return *punt;
				     //}
				     friend class Guia_Tlf;
				     friend class const_iterator;
		 };
		 class const_iterator{
			   private:
				Diccionario <string,string>:: const_iterator punt;
			   public:
				     const_iterator(){}
				     const_iterator(const iterator &it){
					       punt = it.punt;
				     }	       
				     const_iterator & operator ++(){
					       punt++;
					       return *this;
				     }	       
				     const_iterator & operator --(){
					       punt--;
					       return *this;
				     }	       
				     bool operator ==(const const_iterator & it){
					       return it.punt==punt;
				     }
				     bool operator !=(const const_iterator & it){
					       return it.punt!=punt;
				     }
				     //const pair<t1,vector<t2> > & operator *()const{
					//       return *punt;
				    // }
				     friend class Guia_Tlf;
				     
		 };
		 iterator begin(){
			iterator it;
			it.punt=  buffer.begin();
			return it
		 }
		 iterator end(){
			   iterator it;
			   it.punt=buffer.end();
			return it;
			
		 }	 
		 
		 const_iterator begin()const{
			   const_iterator it;
			   it.punt = buffer.begin();
			   return it;
		 }
		 const_iterator end()const {
			   const_iterator it;
			   it.punt = buffer.end();
			   return it;
		 }
		 
/**************************************************************************************/			
	ostream & operator<<(ostream & os, const Guia_Tlf & D){
	  Diccionario<string,string> aux=D.buffer;
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
/********************************************************************/
istream & operator >>(istream & is,Guia_Tlf &D){
	  int np;
	  is>>np;
	  is.ignore();
	  
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
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);
		    
	  }
	 
	  D.buffer=Daux;
	  return is;
	}
	void EscribeInformacion(const vector<string>&l){		 
	  vector<string>::const_iterator it_s;
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}
};	

#endif

