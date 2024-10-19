#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(cantidadVecinosVivosTEST, seisVivos){
    toroide t = {
            {true, false, false, false},
            {false, false, true, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 6);
}


//Agregamos los siguientes test cases al suite

TEST(cantidadVecinosVivosTEST, ningunoVivo){
    toroide t = {
            {true, false, false, false,true},
            {true, false, true, false,true},
            {true, false, false, false,true},
            {true, true, true, true,true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 1, 2), 0);
}

TEST(cantidadVecinosVivosTEST, todosVivos){
    toroide t = {
            {true, false, false, true,true},
            {false, false, true, false,true},
            {true, false, false, true,true},
            {true, false, true, true,false}};

    EXPECT_EQ(cantidadVecinosVivos(t, 3, 4), 8);
}

TEST(cantidadVecinosVivosTEST, unSoloVecinoVivo){
    toroide t = {
            {true, false, false, false,false},
            {false, false, true, false,true},
            {false, false, false, false,false},
            {false, false, true, false,false}};

    EXPECT_EQ(cantidadVecinosVivos(t, 3, 4), 1);
}

