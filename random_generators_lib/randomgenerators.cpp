#include "randomgenerators.h"


inline double fractional_part_number(double value)
{
    return value - (int)value;
}

double rgn_rand_initializ()
{
    srand(time(NULL));
    return double(rand()) / RAND_MAX;
}

double rgn_one(double r)
{
    r = fractional_part_number(11 * r + PI);

    return r;
}

double rgn_two(double r)
{
    static double z = 0.011;

    r = fractional_part_number(r/z + PI);
    z = z + 0.00000001;

    return r;
}

double rgn_three(double r)
{

    r = 0.318309887 * acos(cos(100000000*r+1));

    return r;
}

double rgn_four(double r)
{
    r = fractional_part_number(exp(PI+r));

    return r;
}

double rgn_five(double r)
{
    r+=1.14159265;
    r = fractional_part_number(r*=r);

    return r;
}

double rgn_rand(double r, int method_number)
{
    double value_rgn = 0.0;

    if(method_number == 0)
    {
        method_number = rand()%NUMBER_OF_GENERATION_METHODS+1;
    }

    switch (method_number) {
    case 1:
        value_rgn = rgn_one(r);
        break;
    case 2:
        value_rgn = rgn_two(r);
        break;
    case 3:
        value_rgn = rgn_three(r);
        break;
    case 4:
        value_rgn = rgn_four(r);
        break;
    case 5:
        value_rgn = rgn_five(r);
        break;
    default:
        value_rgn = rgn_rand_initializ();
        break;
    }
    return value_rgn;
}


