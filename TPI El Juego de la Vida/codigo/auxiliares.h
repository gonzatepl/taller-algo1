#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// Definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);


//FUNCIONES AUXILIARES (Y EQUIVALENTES A PREDICADOS) IMPLEMENTADAS

//A PARTIR DEL EJERCICIO 1: toroideValido
bool esToroide(vector<vector<bool>> const &t);
bool esRectangulo(vector<vector<bool>> const &t);
int cantFilas(vector<vector<bool>> const &t);
int cantColumnas(vector<vector<bool>> const &t);
bool columnasMismaCantElementos(vector<vector<bool>> posibleToroide);

//A PARTIR DEL EJERCICIO 2: toroideMuerto
bool enRangoToroide(int f, int c, vector<vector<bool>> t);
bool enRangoFila(int i, vector<vector<bool>> seq);
bool enRangoColumna(int i, vector<bool> seq);

//A PARTIR DEL EJERCICIO 4: densidadPoblacion
float superficieTotal(toroide const &t);

//A PARTIR DEL EJERCICIO 5: cantidadVecinosVivos
bool vecinaViva(toroide const &t, int f, int c, int i, int j);
bool vivaToroide(int f, int c, toroide const &t);
bool estaViva(int f, int c, toroide const &t);
int filaToroide(int f, toroide const &t);
int columnaToroide(int c, toroide const &t);
int restoPositivo (int resto, int divisor);

//A PARTIR DEL EJERCICIO 6: evolucionDePosicion
bool debeVivir(toroide const &t, int f, int c);
bool estaMuerta(int f, int c, toroide const &t);

//A PARTIR DEL EJERCICIO 10: primosLejanos
bool sonPrimosLejanos(toroide const &t1, toroide const &t2);
bool primosLejanosSegundoPeriodico(toroide const &t1, toroide const &t2);

//A PARTIR DEL EJERCICIO 11: seleccionNatural
int ticksAntesDeMorir(toroide const &t);

//A PARTIR DEL EJERCICIO 13: vistaTrasladada
toroide rotar(toroide t, int a, int d);

//A PARTIR DEL EJERCICIO 14: menorSuperficieViva
int menorSuperficieVivaToroideVistaParticular (toroide const &t);
vector<bool> obtenerKColumna(vector<vector<bool>> toroide, int c);
vector<bool> obtenerKFila(vector<vector<bool>> toroide, int f);
bool noContieneVivas(vector<bool> sec);


#endif //REUNIONESREMOTAS_AUXILIARES_H
