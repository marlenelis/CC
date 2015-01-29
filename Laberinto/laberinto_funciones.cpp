# include <iostream>
# include <vector>

using namespace std;
/********************************************
 * función para lectura del laberinto       *
 ********************************************/
vector <vector< char> > leerlaberinto(int &fila, int &columna)
{
    cin >> fila >> columna;
    while(fila<=0 || columna <=0)
        cin >> fila >> columna;
    vector<vector< char> > laberinto(fila);
    char dato;
    for (int f=0;f<fila;++f)
    {
        for (int c=0;c< columna; ++c)
        {
            cin >> dato;
            laberinto.at(f).push_back(dato);
        }
    }
    return laberinto;
}
/********************************************
 * función para buscar un caracter          *
 ********************************************/

bool buscarCaracter(vector<vector< char> > laberinto, int fila, int columna,int &x,int &y,char m)
{
    bool existe= false;
    for (int i=0; i<fila; ++i)
            for (int j=0; j<columna;++j)
                if (laberinto.at(i).at(j)==m)
                {
                    existe=true;
                    x=i;
                    y=j;
                }

    return existe;
}

/********************************************************************
 * función para comprobar si la posición dada como parámetro esta   *
 * en los vectores de la solución                                   *
 ********************************************************************/

bool BuscarPosicion(vector<int> fil, vector<int> col, int i, int j)
{
    bool listo = false;
    //for(int x=0 ; x < fil.size()-1; ++x) // al compilar sale 0 errors, 1 warnings
    int z = fil.size()-1;
    for(int x=0 ; x < z; ++x)
    {
        if(i==fil.at(x) && j==col.at(x))
            listo=true;
    }
    return listo;
}
/********************************************************
 * función para imprimir el laberinto con la solución   *
 ********************************************************/
void imprimirlaberinto(vector<vector <char> > lab, int fila, int columna,vector <int> fil,vector <int> col)
{

    for (int i=0;i<fila; i++)
    {
        for(int j=0;j<columna;j++)
        {
            if(lab.at(i).at(j)== 'p')
                cout << "#";
            else
            if(lab.at(i).at(j)== 'l')
            {
                bool listo = BuscarPosicion(fil,col,i,j);
                if(listo)
                    cout << ".";
                else
                    cout << " ";
            }
            else
                cout << lab.at(i).at(j);
        }
        cout << endl;
    }
}

bool solucionLaberinto(vector<vector< char> > laberinto,int fila, int columna, vector<int> &fil, vector<int> &col )
{
    bool ok = false;
    vector<vector<bool> > visitado(fila);

    for (int i=0;i<fila; i++)
        for(int j=0;j<columna;j++)
           visitado.at(i).push_back(false);//inicialición de la matriz  visitada a false.

    int xo=0, yo=0, xf=0,yf=0;

    char entrada='e',salida = 's';
    bool existeEntrada,existeSalida;
    existeEntrada=buscarCaracter(laberinto,fila,columna,xo,yo,entrada);/** Busca la coordenada de entrada */
    if(existeEntrada)
    {/** añade la coordenada de entrada a los vectores (filas,columnas)*/
        fil.push_back(xo);/* vector para almacenar las filas*/
        col.push_back(yo);/* vector para almacenar las columnas*/

        existeSalida=buscarCaracter(laberinto,fila,columna,xf,yf,salida);/** Busca la coordenada de salida*/

        int i=fil.at(fil.size()-1), j=col.at(col.size()-1); //inicialización de i y j con la posición de entrada que tenemos almacenada en la solucion(vectores(fila,columna) en */
        visitado[i][j]=true;// y marcamos como visitada.

        while( !fil.empty() && !col.empty() && (fil.at(fil.size()-1 )!= xf || col.at(col.size()-1) != yf))
        {
            i=fil.at(fil.size()-1);
            j=col.at(col.size()-1);// Ultima posición de la solución

            if (laberinto[i][j-1]!='p'&& visitado[i][j-1]==false)   /** Intento a la izquierda */
            {
                fil.push_back(i);
                col.push_back(j-1);
                visitado[i][j-1]=true;
            }else
            {
                if (laberinto[i][j+1]!='p'  && visitado[i][j+1]==false)   /** Intento a la derecha */
                {
                    fil.push_back(i);
                    col.push_back(j+1);
                    visitado[i][j+1]=true;
                }
                else
                {
                    if (laberinto[i-1][j]!='p' && visitado[i-1][j]==false)   /** Intento hacia arriba */
                    {
                        fil.push_back(i-1);
                        col.push_back(j);
                        visitado[i-1][j]=true;
                    }
                    else
                    {
                        if (laberinto[i+1][j]!='p' && visitado[i+1][j]==false)   /** Intento hacia abajo */
                        {
                            fil.push_back(i+1);
                            col.push_back(j);
                            visitado[i+1][j]=true;
                        }
                        else
                        {
                            fil.pop_back(); /** eliminamos la última posición de la solución*/
                            col.pop_back();
                        }
                    }
                }
            }
         }
        /** si los vectores que contiene la solución no esta vacío el laberinto tiene solución*/
        if(!col.empty() && !fil.empty())
        ok = true;
    }
    else
        ok=false;
    return ok;

}
int main()
{
    int filas=0, columnas=0;
    vector<vector< char> > laberinto(filas);
    vector <int>col;
    vector <int>fil;
    bool ok;

    laberinto=leerlaberinto(filas,columnas);

    ok = solucionLaberinto(laberinto,filas,columnas,fil,col);

    if(!ok)
        cout << "El laberinto no tiene solución "<< endl;
    else
    {
         cout << "La solución al laberinto : " << endl;
         imprimirlaberinto(laberinto,filas,columnas,fil,col);
    }
}
