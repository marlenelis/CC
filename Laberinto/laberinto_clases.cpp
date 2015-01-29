#include <iostream>  // Para usar cin y cout
#include <vector>    // Para usar el tipo vector de STL

using namespace std;
class Posicion
{
    private:
        int posFila;
        int posColumna;
    public:
        Posicion(){};
        Posicion(int f,int c){posFila=f,posColumna=c;};
        int posicionFila(){return posFila;};
        int posicionColumna(){return posColumna;};
};

class Laberinto {
  private:
    int filas,columnas;
    vector< vector<char> > datos;
    // Método privado que crea e inicializa una matriz nueva
    void Crear(int f, int c, char v=' ');

  public:
    // Constructores
    Laberinto()           {filas=columnas=0; }
    Laberinto(int f, int c,char v=' ');

    // Modificar elemento de la matriz
    void Set(int f, int c, char val);

    // Obtener elemento de la matriz
    char Get(int f, int c);

    // Obtener tamaño de la matriz
    int Filas() const     { return datos.size(); }
    int Columnas() const  { return datos.empty() ? 0 : datos.at(0).size(); }

   // Operaciones de E/S por dispositivo estándar
    void LeeLaberinto();
    bool solucionLaberinto();
};
void Laberinto::Crear(int f, int c, char v)
{
    datos.clear();
    vector<vector<char> > aux(f);

    for (int i=0; i<f; i++)
        for (int j=0; j<c; j++)
         aux.at(i).push_back(v);
    datos=aux;
  // Alternativa al código anterior:
   //datos = vector< vector<char> >(f,vector<char>(c,v));

}

Laberinto::Laberinto(int f, int c,char v)
{
    Crear(f,c,v);
}

char Laberinto::Get(int f, int c)
{
    return datos.at(f).at(c);
}

void Laberinto::Set(int f, int c, char dat)
{
    datos.at(f).at(c) = dat;
}
void Laberinto::LeeLaberinto()
{
    int f,c;
    cin >> f >> c;
    while(f<=0 || c <=0)
        cin >> f >> c;

    Crear(f,c);
    char dat;
    for (int i=0;i<Filas();++i)
    {
        for (int j=0;j< Columnas(); ++j)
        {
            cin >> dat;
            Set(i,j,dat);
        }
    }
}
bool buscarCaracter(Laberinto lab, Posicion &enc,char m)
{
    bool existe= false;
    for (int i=0; i< lab.Filas(); ++i)
            for (int j=0; j<lab.Columnas();++j)
                if (lab.Get(i,j)== m)
                {
                    existe=true;
                    Posicion e(i,j);
                    enc=e;
                }

    return existe;
}
bool solucionLaberinto(Laberinto lab,vector<Posicion> &sol)
{
    bool ok = false;
    vector<vector<bool> > visitado(lab.Filas());

    for (int i=0;i<lab.Filas(); i++)
        for(int j=0;j<lab.Columnas();j++)
           visitado.at(i).push_back(false);//inicialición de la matriz  visitada a false.

    Posicion posinicial(0,0);
    Posicion posfinal(0,0);

    char entrada='e', salida= 's';
    bool existeEntrada,existeSalida;
    existeEntrada=buscarCaracter(lab,posinicial,entrada);/** Busca la coordenada de entrada */
    if(existeEntrada)
    {/** añade la coordenada de entrada */
        sol.push_back(posinicial);/* vector para almacenar la solucion*/

        existeSalida = buscarCaracter(lab,posfinal,salida);/** Busca la coordenada de salida*/

        Posicion m = sol.at(sol.size()-1);
        //inicialización de i y j con la posición de entrada que tenemos almacenada en la solucion */
        int i=m.posicionFila(),j=m.posicionColumna();

        visitado[i][j]=true;// y marcamos como visitada.

        while( !sol.empty() &&(i!= posfinal.posicionFila()||j!=posfinal.posicionColumna() ))
        {
            // Ultima posición de la solución
            m=sol.at(sol.size()-1);
            i=m.posicionFila();
            j=m.posicionColumna();

            if (lab.Get(i,j-1)!='p'&& visitado[i][j-1]==false)   /** Intento a la izquierda */
            {
                Posicion aux(i,j-1);
                sol.push_back(aux);
                visitado[i][j-1] = true;
            }else
            {
                if (lab.Get(i,j+1)!='p'  && visitado[i][j+1]==false)   /** Intento a la derecha */
                {
                    Posicion aux(i,j+1);
                    sol.push_back(aux);
                    visitado[i][j+1]=true;
                }
                else
                {
                    if (lab.Get(i-1,j)!='p' && visitado[i-1][j]==false)   /** Intento hacia arriba */
                    {
                        Posicion aux(i-1,j);
                        sol.push_back(aux);
                        visitado[i-1][j]=true;
                    }
                    else
                    {
                        if (lab.Get(i+1,j)!='p' && visitado[i+1][j]==false)   /** Intento hacia abajo */
                        {
                            Posicion aux(i+1,j);
                            sol.push_back(aux);
                            visitado[i+1][j]=true;
                        }
                        else
                        {
                            sol.pop_back(); /** eliminamos la última posición de la solución*/

                        }
                    }
                }
            }
         }
        /** si los vectores que contiene la solución no esta vacío el laberinto tiene solución*/
        if(!sol.empty())
        ok = true;
    }
    else
        ok=false;

    return ok;

}
bool BuscarPosicion(vector<Posicion> sol, int i, int j)
{
    bool listo = false;
    int z = sol.size()-1;
    for(int x=0 ; x < z; ++x)
    {
        Posicion aux = sol.at(x);

        if(i==aux.posicionFila() && j==aux.posicionColumna())
            listo=true;
    }
    return listo;
}
void imprimirlaberinto(Laberinto lab, vector <Posicion> sol)
{

    for (int i=0;i<lab.Filas(); i++)
    {
        for(int j=0;j<lab.Columnas();j++)
        {
            if(lab.Get(i,j)== 'p')
                cout << "#";
            else
            if(lab.Get(i,j)== 'l')
            {
                bool listo = BuscarPosicion(sol,i,j);
                if(listo)
                    cout << ".";
                else
                    cout << " ";
            }
            else
                cout << lab.Get(i,j);
        }
        cout << endl;
    }
}


int main() {

    Laberinto lab;
    vector <Posicion> caminoSolucion;
    bool ok;

    lab.LeeLaberinto();

    ok = solucionLaberinto(lab,caminoSolucion);

    if(!ok)
        cout << "El laberinto no tiene solución "<< endl;
    else
    {
         cout << "La solución al laberinto : " << endl;
            imprimirlaberinto(lab,caminoSolucion);
    }

}
