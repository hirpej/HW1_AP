#include <vector>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>

using Matrix = std::vector<std::vector<double>>;

Matrix multiply(Matrix &a, Matrix &b); //Done
Matrix transpose(Matrix &a);           //Done
double det(Matrix &a);                 //Done
Matrix inv(Matrix &a);                 //Done
void show(Matrix &a);                  //  Shows the matrix in a beautiful way -> Done

// ***********************************

Matrix getData(char const *filename); //Done
Matrix getX(Matrix &);                //Done
Matrix gety(Matrix &data);            //Done

// ***********************************

Matrix solve(char const *filename);    //Done