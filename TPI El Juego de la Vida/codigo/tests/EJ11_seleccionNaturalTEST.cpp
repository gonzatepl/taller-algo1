#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

//No cumple la precondición, saltearnos este test
/*
TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
    toroide t1 = {
                  {false, false, false, false, false},
                  {false, false, false, false, false},
                  {false, true, true, true, false},
                  {false, false, false, false, false},
                  {false, false,false, false, false} };
    toroide t2 = {
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}
 */

//Agregamos los siguientes test cases al suite

TEST(seleccionNaturalTEST, dosMuerenIgualQuieroPrimero){
    toroide t1 = {
            {true, false, true},
            {false, true, false},
            {false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t1);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, viveMasAnteUltimo){
    toroide t1 = {
            {false, false, true},
            {false, false, true},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);
}



