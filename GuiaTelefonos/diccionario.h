#ifndef DICCION__H
#define DICCION__H
#include <utility> // para pair
#include <vector>
using namespace std;
template <class t1,class t2>
class Diccionario{
	  private:
	    vector<pair<t1,vector<t2> > > data;

	  
	     void Copiar(const Diccionario<t1,t2> &D){
			  data = D.data;	
	     }
	     void Borrar(){
			   data.erase(data.begin(),data.end());
	     }
	  public:	
	     /*Contructor por defecto*/	    
	     Diccionario():data(vector<pair<t1,vector<t2> > >()){}
	     Diccionario(const Diccionario &D){
		    Copiar(D);
	     }
	     /*Destructor*/
	     ~Diccionario(){}
	     /*Operador de asignacion*/
	     Diccionario<t1,t2> & operator=(const Diccionario<t1,t2> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
	    }
	    /*Devuelve si el elemento con un determinada clave (p) está en el diccionario.
	    Si está devuelve true y un iterador apuntando a donde está
	    En caso contrario devuelve false y un iterador indicando donde debe ser insertado
	    */
	    bool Esta_Clave(const t1 &p, typename  vector<pair<t1,vector<t2> > >::iterator &it_out){
			  
			  if (data.size()>0){
				    
			      typename vector <pair <t1,vector<t2> > >::iterator it;
			      
			      for (it=data.begin(); it!=data.end() ;++it){
					if ((*it).first==p) {
						  it_out=it;
						  return true;
					}
					else if ((*it).first>p){
						  it_out=it;
						  return false;
					}	  
					   
			      }
			      
			      it_out=it;
			      return false;
			  }
			  else {
				    
				    it_out=data.end();
				    return false;
			  }	    
		 }
		 
		 /*Inserta un nuevo elemento en el diccionario, si no existe la clave.*/
		 
		 void Insertar(const t1 & clave,const vector<t2> &info){
			   
		     typename vector <pair <t1,vector<t2> > >::iterator it;
		     
		     if (!Esta_Clave(clave,it)){
			       pair <t1,vector<t2> > p;
			       p.first = clave;
			       p.second=info;
			 
			       /*Usamos el metodo insertar de vector*/
			       data.insert(it,p);
			       
			       
			      	 
		     }
		     
		 }
		 
		 void AddSignificado_Palabra(const t2 & s ,const t1 &p){
			   typename vector<pair<t1,vector<t2> > >::iterator it;
			   pair<t1,vector<t2> > aux;
			   aux.first=p;
			   if (!Esta_Clave(p,it)){
				    data.insert(it,aux);
			   }	    
			   
			    //Insertamos el siginificado al final
		           (*it).second.insert(s);
		 }
		  vector<t2>  getInfo_Asoc(const t1 & p) {
			   typename vector<pair<t1,vector<t2> > >::iterator it;
			   if (!Esta_Clave(p,it)){
				return vector<t2>();
			   }
			   else{
				return (*it).second;
			   }
		 }			   
				
			   
		 
		// data<T,U> & operator[](int pos){ return datos.at(pos);}
		 
		 //const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		 int size()const{
			   return data.size();
		 }
		 class const_iterator;
		 class iterator{
			   private:
				pair<t1,vector<t2> > * punt;
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
				     pair<t1,vector<t2> > & operator *(){
					       return *punt;
				     }
				     friend class Diccionario;
				     friend class const_iterator;
		 };
		 class const_iterator{
			   private:
				const pair<t1,vector<t2> > * punt;
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
				     const pair<t1,vector<t2> > & operator *()const{
					       return *punt;
				     }
				     friend class Diccionario;
				     
		 };
		 iterator begin(){
			   iterator it;
			   it.punt = &(data[0]);
			   return it;
		 }
		 iterator end(){
			   iterator it;
			   it.punt = &(data[data.size()]);
			   return it;
		 }
		 
		 
		 const_iterator begin()const{
			   const_iterator it;
			   it.punt = &(data[0]);
			   return it;
		 }
		 const_iterator end()const {
			   const_iterator it;
			   it.punt = &(data[data.size()]);
			   return it;
		 }
		 
};
#endif
		      