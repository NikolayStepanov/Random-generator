#include "randomgenerators.h"

static double rgn_next = 0.1;

inline double fractional_part_number(double value)
{
    return value - (int)value;
}

double rgn_rand(int method_number=1)
{
    double value_rgn = 0.0;

    switch (method_number) {
    case 1:
        value_rgn = rgn_one();
        break;
    case 2:
        value_rgn = rgn_two();
        break;
    case 3:
        value_rgn = rgn_three();
        break;
    case 4:
        value_rgn = rgn_four();
        break;
    case 5:
        value_rgn = rgn_five();
        break;
    default:
        value_rgn = rgn_one();
        break;
    }

    return value_rgn;
}

double rgn_srand(unsigned int seed)
{
    seed = seed * 1103515245 + 12345;
    rgn_next = (double)((unsigned int)(seed / 65536) % 32768) / 32767;
    return rgn_next;
}

double rgn_one()
{
    rgn_next = fractional_part_number(11 * rgn_next + PI);

    return rgn_next;
}

double rgn_two()
{
    static double z = 0.011;

    rgn_next = fractional_part_number(rgn_next /z + PI);
    z = z + 0.00000001;

    return rgn_next;
}

double rgn_three()
{
    rgn_next = 0.318309887 * acos(cos(100000000* rgn_next +1));

    return rgn_next;
}

double rgn_four()
{
    rgn_next = fractional_part_number(exp(PI+ rgn_next));

    return rgn_next;
}

double rgn_five()
{
    rgn_next +=1.14159265;
    rgn_next = fractional_part_number(rgn_next *= rgn_next);

    return rgn_next;
}


