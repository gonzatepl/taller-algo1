#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

//Agregamos los siguientes test cases al suite

TEST(vistaTrasladadaTEST, DiagonalVsTodoFalse){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false,false,false},
            {false,false,false},
            {false,false,false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, dosFilasTrueUnaFalse){
    toroide t1 = {
            {true,true,true},
            {true,true,true},
            {false,false,false}};
    toroide t2 = {
            {false,false,false},
            {true,true,true},
            {true,true,true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}



