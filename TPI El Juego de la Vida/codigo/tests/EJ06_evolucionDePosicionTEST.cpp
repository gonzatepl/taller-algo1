#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true},
                  {false, true, false},
                  {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}


//Agregamos los siguientes test cases al suite

TEST(cantidadVecinosVivosTEST, cuatroPorCincoMuertaVive){
    toroide t = {
            {true, false, false, true,true},
            {false, false, true, false,true},
            {true, false, false, true,true},
            {false, false, true, true,false}};

    EXPECT_TRUE(evolucionDePosicion(t, make_pair(3,1)));
}

TEST(cantidadVecinosVivosTEST, cuatroPorCincoVivaMuere){
    toroide t = {
            {true, false, true, true,true},
            {false, false, true, false,true},
            {true, false, false, true,true},
            {false, true, true, true,false}};

    EXPECT_FALSE(evolucionDePosicion(t, make_pair(3,1)));
}
