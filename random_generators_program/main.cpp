#include <randomgenerators.h>
#include <iostream>
#include <time.h>

using namespace std;

double calculateVolumeBall(const int numberIter, const double radiusBall, int methodNumber = 0)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	int numberPointsBelongBall = 0;

	for (int i = 0; i < numberIter; ++i)
	{
		x = radiusBall * rgn_rand(methodNumber);
		y = radiusBall * rgn_rand(methodNumber);
		z = radiusBall * rgn_rand(methodNumber);

		if ((x * x + y * y + z * z) < (radiusBall * radiusBall))
		{
			numberPointsBelongBall++;
		};
	}

	double volumeCube = radiusBall * radiusBall * radiusBall * 8;
	double resVolumeBall = ((double)numberPointsBelongBall / numberIter) * volumeCube;

	return resVolumeBall;
}

int main()
{
	int numberIterations = 0;
	int methodNumber = 0;

	double radiusBall = 0.0;
	double volumeBall = 0.0;
	double volumeBallReal = 0.0;

	numberIterations = 10000000;
	radiusBall = 1.0;

	volumeBallReal = (4.0 / 3) * PI * radiusBall * radiusBall * radiusBall;

	cout << "-------------------------------------------------" << endl;
	for (methodNumber = 1; methodNumber < 6; methodNumber++)
	{
		cout << "Iterations:" << numberIterations << "  Ball radius:" << radiusBall <<
			"  Method number:" << methodNumber << endl;

		volumeBall = calculateVolumeBall(numberIterations, radiusBall, methodNumber);

		cout << " Aproximate ball volume:" << volumeBall <<
			" Discrepancy:" << abs(volumeBallReal - volumeBall) << endl;
	}

	numberIterations = 1000000;
	radiusBall = 1.0;

	volumeBallReal = (4.0 / 3) * PI * radiusBall * radiusBall * radiusBall;

	cout << "-------------------------------------------------" << endl;
	for (methodNumber = 1; methodNumber < 6; methodNumber++)
	{
		cout << "Iterations:" << numberIterations << "  Ball radius:" << radiusBall <<
			"  Method number:" << methodNumber << endl;

		volumeBall = calculateVolumeBall(numberIterations, radiusBall, methodNumber);

		cout << " Aproximate ball volume:" << volumeBall <<
			" Discrepancy:" << abs(volumeBallReal - volumeBall) << endl;
	}


	numberIterations = 1000000;
	radiusBall = 4.7;

	volumeBallReal = (4.0 / 3) * PI * radiusBall * radiusBall * radiusBall;

	cout << "-------------------------------------------------" << endl;
	for (methodNumber = 1; methodNumber < 6; methodNumber++)
	{
		cout << "Iterations:" << numberIterations << "  Ball radius:" << radiusBall <<
			"  Method number:" << methodNumber << endl;

		volumeBall = calculateVolumeBall(numberIterations, radiusBall, methodNumber);

		cout << " Aproximate ball volume:" << volumeBall <<
			" Discrepancy:" << abs(volumeBallReal - volumeBall) << endl;
	}

	return 0;
}
