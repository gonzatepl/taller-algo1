#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };

    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}


//Agregamos los siguientes test cases al suite

TEST(evolucionMultipleTEST, tresPorTresDosPasos){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };

    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false} };

    toroide res = evolucionMultiple(t, 2);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, cuatroPorCinco){
    toroide t = { {true, false, true, true,true},
                  {false, false, true, false,true},
                  {true, false, false, true,true},
                  {false, true, true, true,false}};

    toroide evo_t = { {true, false, false, false,false},
                      {false, false, true, false,false},
                      {true, false, false, false,false},
                      {false, false, false, false,false}};

    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

