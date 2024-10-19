#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}


//Agregamos los siguientes test cases al suite

TEST(evolucionToroideTEST, toroideTodasVivas){
    toroide t = {{true, true, true},
                 {true, true, true},
                 {true, true, true}};

    toroide evo_t = {{false, false, false},
                     {false, false, false},
                     {false, false, false}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMuerto){
    toroide t = {{false, false, false},
                 {false, false, false},
                 {false, false, false}};


    toroide evo_t = {{false, false, false},
                     {false, false, false},
                     {false, false, false}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideCuatroPorCinco){
    toroide t = { {true, false, true, true,true},
                  {false, false, true, false,true},
                  {true, false, false, true,true},
                  {false, true, true, true,false}};

    toroide evo_t = { {true, false, false, false,false},
                      {false, false, true, false,false},
                      {true, false, false, false,false},
                      {false, false, false, false,false}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}




