#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(toroideMuertoTEST, toroideDiagonalVivas){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    EXPECT_FALSE(toroideMuerto(t));
}


//Agregamos los siguientes test cases al suite

TEST(toroideMuertoTEST, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    EXPECT_TRUE(toroideMuerto(t));
}

TEST(toroideMuertoTEST, toroideCasiMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, true}};

    EXPECT_FALSE(toroideMuerto(t));
}

TEST(toroideMuertoTEST, toroideTodasVivas){
    toroide t = {
            {true, true,true, true},
            {true, true,true, true},
            {true, true,true, true},
            {true, true,true, true},
            {true, true,true, true}};

    EXPECT_FALSE(toroideMuerto(t));
}




