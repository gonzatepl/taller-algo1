#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
//PRE: True
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    resp=esToroide(t);
    return resp;
}

// EJERCICIO 2
//PRE: esToroide(t)
bool toroideMuerto(toroide const &t) {
    bool resp = false;
    for (int i=0; i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            //Asumimos que los booleanos son, efectivamente, valores de verdad.
            resp = resp || t[i][j];
        }
    }
    return !resp;
}

// EJERCICIO 3
//PRE: esToroide(t)
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    for (int i=0; i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            //Nuevamente, aprovechamos que las celdas devuelven valores de verdad
            if(t[i][j])
                vivos.push_back({i,j});
        }
    }
    return vivos;
}

// EJERCICIO 4
//PRE: esToroide(t)
float densidadPoblacion(toroide const &t) {
    float resp = -1;
    float cantVivas = posicionesVivas(t).size();
    resp =  cantVivas/superficieTotal(t);
    return resp;
}

// EJERCICIO 5
//PRE: esToroide(t) ∧ enRangoToroide(f,c,t)
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    float resp = 0;
    for (int i=-1; i<2;i++){
        for(int j=-1;j<2;j++){
            if ((i!=0 || j!=0) && vecinaViva(t,f,c,i,j))
                resp++;
        }
    }
    return resp;
}

// EJERCICIO 6
//PRE: esToroide(t) ∧ enRangoToroide(x_1,x_2,t)
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = false;
    resp = debeVivir(t, x.first,x.second);
    return resp;
}

// EJERCICIO 7
//PRE: esToroide(t)
void evolucionToroide(toroide &t){
    const toroide t0 = t;
    for (int i=0; i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            t[i][j] = debeVivir(t0,i,j);
        }
    }
}

// EJERCICIO 8
//PRE: esToroide(t) ∧ k>=1
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    for (int i=K;i>0;i--){
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 9
//PRE: esToroide(t) ∧ p = P0 ∧ (cumpleEvolucionCiclica(t) ∨ eventualmenteMuere(t))
bool esPeriodico(toroide const &t, int &p) {
    int p0=1;
    toroide t0=t;
    bool resp = false;
    evolucionToroide(t0);
    while(t0!=t && !toroideMuerto(t0)){
        evolucionToroide(t0);
        p0++;
    }
    if(!toroideMuerto(t0)){
        resp=true;
        p=p0;
    }
    return resp;
}

// EJERCICIO 10
//PRE esToroide(t1) ∧ esToroide(t2) ∧L mismaDimension(t1, t2) ∧ sonPeriodicosOMueren(t1, t2)
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
    resp=sonPrimosLejanos(t,u);
    return resp;
}

// EJERCICIO 11
//PRE |ts| > 0 ∧L todosValidos(ts) ∧ todosVivos(ts) ∧ todosSeExtinguen(ts)
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
    int cantMaxTicksAntesDeMorir=0;
    for (int i = 0; i<ts.size(); i++){
        if(ticksAntesDeMorir(ts[i])>cantMaxTicksAntesDeMorir){
            resp = i;
            cantMaxTicksAntesDeMorir = ticksAntesDeMorir(ts[i]);
        }
    }
    return resp;
}


// EJERCICIO 12
//PRE:esToroide(t1) ∧ esToroide(t2) ∧ mismaDimension(t1, t2)
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    for(int i=0;i<t.size();i++){
        vector<bool> fila;
        for(int j=0;j<t[0].size();j++){
            if(t[i][j] && u[i][j])
                fila.push_back(true);
            else
                fila.push_back(false);
        }
        out.push_back(fila);
    }
    return out;
}

// EJERCICIO 13
//PRE:esToroide(t1) ∧ esToroide(t2) ∧L mismaDimension(t1; t2)
bool vistaTrasladada(toroide const &t, toroide const &u){
    bool resp = false;
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            if(t==rotar(u,i+1,j+1))
                resp = resp || true;
        }
    }
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
    int resp = t.size() * t[0].size();
    //Comparamos el área mínima en cada una de los traslados posibles empezando desde la vista original dado por el
    //toroide ingresado.
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            int areaMinimaVistaParticular = 0;
            areaMinimaVistaParticular = menorSuperficieVivaToroideVistaParticular(rotar(t,i+1,j+1));
            if (areaMinimaVistaParticular<resp)
                resp=areaMinimaVistaParticular;
        }
    }
    return resp;
}
