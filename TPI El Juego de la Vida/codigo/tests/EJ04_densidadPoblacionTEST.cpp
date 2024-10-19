#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

//Antes se llamaba "toroideDiagonal", le cambiamos el nombre
//porque en realidad expresa otra cosa
TEST(densidadPoblacionTEST, todasVivas){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}


//Agregamos los siguientes test cases al suite

TEST(densidadPoblacionTEST, toroideMuerto){
    vector<bool> a = { false, false, false, false};
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.0, 0.01);
}

TEST(densidadPoblacionTEST, ochentaPorcientoVivo){
    vector<bool> a = { true, true, true, false};
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.75, 0.01);
}

TEST(densidadPoblacionTEST, cincuentaYCincoPorciento){
    toroide t = {
            {true, false, false, true,true},
            {false, false, true, false,true},
            {true, false, false, true,true},
            {true, false, true, true,false}};
    EXPECT_NEAR(densidadPoblacion(t), 0.55, 0.01);
}




