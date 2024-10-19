#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

//Agregamos los siguientes test cases al suite

TEST(menorSuperficieVivaTEST, tresEnSegundaFila){
    toroide t = {
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}

TEST(menorSuperficieVivaTEST, dosEnPrimeraColumna){
    toroide t = {
            {false, false, false, false, false},
            {true, false, false, false, false},
            {true, false, false, false, false},
            {false, false, false, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 2);
}

TEST(menorSuperficieVivaTEST, doceSeparados1){
    toroide t = {
            {false, false, true, false, false},
            {true, false, false, false, true},
            {true, false, false, false, true},
            {false, false, false, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 12);
}


TEST(menorSuperficieVivaTEST, doceSeparados2){
    toroide t = {
            {false, false, true, false, false},
            {true, false, false, false, false},
            {false, false, false, true, false},
            {false, false, false, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 12);
}

TEST(menorSuperficieVivaTEST, cuatroAbajoDerecha){
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true, false,false , false, true},
            {false, false, false, false, true}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, seisEnElMedio){
    toroide t = {
            {false, false, false, true, false},
            {false, false, true, false, false},
            {false, false, false, false, false},
            {false, false, true, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, esquinas){
    toroide t = {
            {true, false, false, false, true},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true, false, false, false, true}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, tresPorTresMedio){
    toroide t = {
            {false, false, false},
            {false, true, false},
            {false, false, false}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, extremosSeJuntan){
    toroide t = {
            {true, false, false},
            {false, false, false},
            {false, false, true}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, areaMinEsMax){
    toroide t = {
            {true, true, true, true, true},
            {true, true, true, true, true},
            {true, true, true, true, true},
            {true, true, true, true, true}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 20);
}