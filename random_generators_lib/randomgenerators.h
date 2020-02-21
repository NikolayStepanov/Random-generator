#ifndef RANDOMGENERATORS_H
#define RANDOMGENERATORS_H
#include <cstdlib>
#include <ctime>
#include <cmath>

const int  NUMBER_OF_GENERATION_METHODS = 5;
const double PI = 3.14159265;

double rgn_rand_initializ();
double rgn_rand(double r,int m = 0);
double rgn_one(double r);
double rgn_two(double r);
double rgn_three(double r);
double rgn_four(double r);
double rgn_five(double r);

#endif // RANDOMGENERATORS_H
