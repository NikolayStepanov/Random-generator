#include <randomgenerators.h>
#include <iostream>

using namespace std;

double calculateVolumeBall(const int numberIter, const double radiusBall, int methodNumber = 0)
{
    double x = rgn_rand_initializ();
    double y = rgn_rand_initializ();
    double z = rgn_rand_initializ();
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    int numberPointsBelongBall = 0;
    for(int i=0; i < numberIter; ++i)
    {
        x1= rgn_rand(x1, methodNumber);
        y1= rgn_rand(y1, methodNumber);
        z1 = rgn_rand(z1, methodNumber);

        x = radiusBall * x1;
        y = radiusBall * y1;
        z = radiusBall * z1;
        if ((x*x + y*y + z*z) < (radiusBall*radiusBall))
        {
            numberPointsBelongBall++;
        };
    }
    double VolumeCube = radiusBall*radiusBall*radiusBall*8;
    double res = ((double)numberPointsBelongBall / numberIter) * VolumeCube;
    return res;
}

int main()
{
    int numberIterations = 0;
    int methodNumber = 0;
    double radiusBall = 0.0;
    double volumeBall = 0.0;

    /*cout<<volumeBall<<endl;
    cout<<"Enter the number of iterations:"<<endl;
    cin>>numberIterations;
    cout<<"Enter the generation method number:"<<endl;
    cin>>methodNumber;
    cout<<"Enter the radius of the ball:"<<endl;
    cin>>radiusBall;
    cout<<"Aproximate volume is: "<<endl;
    volumeBall = calculateVolumeBall(numberIterations,radiusBall,methodNumber);
    cout<<volumeBall<<endl;*/

    numberIterations =10000000;
    radiusBall = 1.0;

    for(methodNumber=0; methodNumber < 6; methodNumber++)
    {
        volumeBall = calculateVolumeBall(numberIterations,radiusBall, methodNumber);
        cout<<volumeBall<<endl;
    }

    return 0;
}
