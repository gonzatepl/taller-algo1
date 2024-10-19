#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;

//Aquí ubicamos todas las funciones auxiliares de soporte para la resolución de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}


//FUNCIONES AUXILIARES (LAS BOOLEANAS EQUIVALENTES A PREDICADOS) IMPLEMENTADAS

//A PARTIR DEL EJERCICIO 1: toroideValido
bool esToroide(vector<vector<bool>> const &t){
    return esRectangulo(t) && (cantFilas(t)>=3) && (cantColumnas(t)>=3);
}

bool esRectangulo(vector<vector<bool>> const &t){
    return cantFilas(t)>0 && cantColumnas(t)>0 && columnasMismaCantElementos(t);
}

int cantFilas(vector<vector<bool>> const &t){
    return t.size();
}

int cantColumnas(vector<vector<bool>> const &t){
    int columnas = 0;
    if (cantFilas(t)>0)
        columnas = t[0].size();
    return columnas;
}

bool columnasMismaCantElementos(vector<vector<bool>> posibleToroide){
    bool cumple = true;
    int i = 0;
    while (i<posibleToroide.size()){
        cumple = cumple && (posibleToroide[0].size() == posibleToroide[i].size());
        i++;
    }
    return cumple;
}



//A PARTIR DEL EJERCICIO 2: toroideMuerto

bool enRangoToroide(int f, int c, vector<vector<bool>> t){
    return enRangoFila(f, t) && enRangoColumna(c,t[f]);
}

bool enRangoFila(int i, vector<vector<bool>> t){
    return (0<=i && i<t.size());
}

bool enRangoColumna(int i, vector<bool> s){
    return (0<=i && i<s.size());
}


//A PARTIR DEL EJERCICIO 4: densidadPoblacion
float superficieTotal(toroide const &t){
    return cantFilas(t) * cantColumnas(t);
}


//A PARTIR DEL EJERCICIO 5: cantidadVecinosVivos

bool vecinaViva(toroide const &t, int f, int c, int i, int j){
    return vivaToroide(f+i,c+j,t);
}

bool vivaToroide(int f, int c, toroide const &t){
    bool res = estaViva(filaToroide(f,t), columnaToroide(c,t),t);
    return res;
}

bool estaViva(int f, int c, toroide const &t){
    bool res = enRangoToroide(f,c,t) && t[f][c];
    return res;
}

int filaToroide(int f, toroide const &t){
    int filas = cantFilas(t);
    return restoPositivo(f % filas, filas);
}

int columnaToroide(int c, toroide const &t){
    int col = cantColumnas(t);
    return restoPositivo(c % col, col);
}

int restoPositivo (int resto, int divisor){
    //Función que armamos ya que el % de c++ no es suficiente para llegar a la 'congruencia' positiva
    int res = resto;
    while (res<0)
        res+=divisor;
    return res;
}

//A PARTIR DEL EJERCICIO 6: evolucionDePosicion

bool debeVivir(toroide const &t, int f, int c){
    int vecinosVivos = cantidadVecinosVivos(t,f,c);
    bool casoViva = estaViva(f,c,t) && (2<=vecinosVivos &&  vecinosVivos<=3);
    bool casoMuerta = estaMuerta(f,c,t) && vecinosVivos==3;
    return casoViva || casoMuerta;

}

bool estaMuerta(int f, int c, toroide const &t){
    return enRangoToroide(f,c,t) && !t[f][c];
}

//A PARTIR DEL EJERCICIO 10: primosLejanos

bool sonPrimosLejanos(toroide const &t1, toroide const &t2){ //T1: toroide final y T2:toroide inicial
    int k=1;
    bool resp=false;
    //En los casos en los que hay toroides iguales (muertos o no), o que hay muerto y periódico, no entrara a ninguna
    //condición y se mantendrá en el resp inicial.

    //Primero nos fijamos si hay alguno muerto y el otro finito, porque si no es muerto ni periódico, es finito.
    if((toroideMuerto(t1) || toroideMuerto(t2)) && !(esPeriodico(t1, k) || esPeriodico(t2, k))){
        //Como t1 es toroide final y t2 es toroide inicial, verificamos que el muerto es el T1, el final, al cual
        //si o si evoluciona el finito, que cumple con la especificación de eventualmenteMuere(t)
        if(toroideMuerto(t1) && !toroideMuerto(t2)){
            resp=true;
        }
    //Como t2 es el inicial y el que se evoluciona en pos de ver si es primo lejano de t1, solo nos importaría ver
    //que si es periódico, visualizar con la función propuesta si t1 está en alguna de las evoluciones de t2
    //previas a volver a si mismo.
    } else if(esPeriodico(t2,k)){
        resp= primosLejanosSegundoPeriodico(t2,t1);
    }
    //Por último, si es que son distintos y no pasó nada de lo anterior, solo resta ver si t2 en algún momento pasa
    //por t1 en sus evoluciones, mirando mientras que éste siga vivo.
    else if(t1!=t2){
        while(!(t1==evolucionMultiple(t2,k)) && !(toroideMuerto(evolucionMultiple(t2,k)))){
            k++;
        }
    }
    return resp;
}


bool primosLejanosSegundoPeriodico(toroide const &t1, toroide const &t2){
    bool res = false;
    toroide t1_0 = t1;
    evolucionToroide(t1_0);
    while(t1_0!=t1){
        res = (t2==t1_0);
        evolucionToroide(t1_0);
    }
    return res;
}

//A PARTIR DEL EJERCICIO 11: seleccionNatural

int ticksAntesDeMorir(toroide const &t){
    int resp=0;
    toroide t0 = t;
    while(!toroideMuerto(t0)){
        evolucionToroide(t0);
        resp++;
    }
    return resp;
}

//A PARTIR DEL EJERCICIO 13: vistaTrasladada

toroide rotar(toroide t, int a, int d){
    int n = t.size();
    int m = t[0].size();
    toroide res(n,vector<bool>(m));
    int i = 0;
    while(i < n) {
        int j = 0;
        while(j < m) {
            res[i][j] = t[restoPositivo((i-a) % n, n)][restoPositivo((j-d) % m,m)];
            j++;
        }
        i++;
    }
    return res;
}

//A PARTIR DEL EJERCICIO 14: menorSuperficieViva

int menorSuperficieVivaToroideVistaParticular (toroide const &t){
    //Inicializamos el área mínima, con el área total del toroide.
    int res = t.size() * t[0].size();
    //Para mantener el concepto de que el área mínima es un rectángulo.
    rectangulo r = t;
    //i representa a la primera fila, f a la última fila, j a la primera columna, c a la última columna.
    int i=0, j=0, f=t.size()-1, c=t[0].size()-1;

    //La idea es ir recorriendo a partir de las filas y las columnas que componen el rectángulo que representa
    // el área minima del toroide.

    //Decimos que va a entrar cuando no se cumpla que las cuatro esquinas forman el rectángulo,


    while (noContieneVivas(obtenerKColumna(r,j)) || noContieneVivas(obtenerKColumna(r,c)) || noContieneVivas(obtenerKFila(r,i)) || noContieneVivas(obtenerKFila(r,f))){
        //Caso 1: en la columna j no hay ninguna viva: aumenta en una unidad j
        if(noContieneVivas(obtenerKColumna(r,j))){
            j++;
        }
        //Caso 2: en la columna c no hay ninguna viva: disminuye en unidad c
        if(noContieneVivas(obtenerKColumna(r,c))){
            c--;
        }
        //Caso 3: en la fila i no hay ninguna viva: aumenta en una unidad i
        if(noContieneVivas(obtenerKFila(r,i))){
            i++;
        }
        //Caso 3: en la fila f no hay ninguna viva: disminuye en unidad f
        if(noContieneVivas(obtenerKFila(r,f))){
            f--;
        }
        // La formula final: a partir de la definicion de "base * altura", y los corrimientos propios de
        // la implementación computacional:
        // base = cant filas totales del rectángulo (f+1), - filas que le quitaron (i);
        // altura = cant columnas totales del rectángulo (c+1) - columnas que le quitaron (j)
        res = (f+1-i) * (c+1-j);
    }
    return res;
}

bool noContieneVivas(vector<bool> sec){
    bool res = true;
    for (int i=0; i<sec.size();i++){
        if(sec[i])
            res = res && false;
    }
    return res;
}

vector<bool> obtenerKColumna(vector<vector<bool>> toroide, int c){
    vector<bool> kColumna;
    for (int i=0; i<toroide.size();i++)
        kColumna.push_back(toroide[i][c]);
    return kColumna;
}

vector<bool> obtenerKFila(vector<vector<bool>> toroide, int f){
    vector<bool> kFila;
    for (int j=0; j<toroide[0].size();j++)
        kFila.push_back(toroide[f][j]);
    return kFila;
}

