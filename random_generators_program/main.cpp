#include <randomgenerators.h>
#include <iostream>
#include <time.h>

using namespace std;

typedef double(*func_rand)();

func_rand funcGenerators[] =
{
	rgn_one, rgn_two, rgn_three, rgn_four, rgn_five
};

double calculateVolumeBall(const int numberIter, const double radiusBall, double (*rgn_rand)())
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	int numberPointsBelongBall = 0;

	for (int i = 0; i < numberIter; ++i)
	{
		x = radiusBall * rgn_rand();
		y = radiusBall * rgn_rand();
		z = radiusBall * rgn_rand();

		if ((x * x + y * y + z * z) < (radiusBall * radiusBall))
		{
			numberPointsBelongBall++;
		};
	}

	double volumeCube = radiusBall * radiusBall * radiusBall * 8;
	double resVolumeBall = ((double)numberPointsBelongBall / numberIter) * volumeCube;

	return resVolumeBall;
}

void resultsGeneratorsOutputConsole(int numberIterations, double radiusBall, int methodNumber = -1)
{
	double volumeBall = 0.0;
	double volumeBallReal = 0.0;

	volumeBallReal = (4.0 / 3) * PI * radiusBall * radiusBall * radiusBall;

	cout << "-------------------------------------------------" << endl;

	if (methodNumber == -1)
	{
		for (int methodNumber = 0; methodNumber < 5; methodNumber++)
		{
			cout << endl;
			cout << "Iterations:" << numberIterations << "  Ball radius:" << radiusBall <<
				"  Method number:" << methodNumber << endl;

			volumeBall = calculateVolumeBall(numberIterations, radiusBall, funcGenerators[methodNumber]);

			cout << " Aproximate ball volume:" << volumeBall <<
				" Discrepancy:" << abs(volumeBallReal - volumeBall) << endl;
		}

	}
	else {
		cout << endl;
		cout << "Iterations:" << numberIterations << "  Ball radius:" << radiusBall <<
			"  Method number:" << methodNumber << endl;

		volumeBall = calculateVolumeBall(numberIterations, radiusBall, funcGenerators[methodNumber]);

		cout << " Aproximate ball volume:" << volumeBall <<
			" Discrepancy:" << abs(volumeBallReal - volumeBall) << endl;
	}
}



int main()
{
	int numberIterations = 0;
	int methodNumber = 0;

	double radiusBall = 0.0;
	double volumeBall = 0.0;
	double volumeBallReal = 0.0;

	char key_exit = 'y';

	rgn_srand(time(NULL));

	numberIterations = 10000000;
	radiusBall = 1.0;
	resultsGeneratorsOutputConsole(numberIterations, radiusBall);

	numberIterations = 1000000;
	radiusBall = 1.0;
	resultsGeneratorsOutputConsole(numberIterations, radiusBall);

	numberIterations = 1000000;
	radiusBall = 4.7;
	resultsGeneratorsOutputConsole(numberIterations, radiusBall);

	while (key_exit == 'y')
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Enter the number of iterations:" << endl;
		cin >> numberIterations;
		cout << endl;
		cout << "Enter the radius of the ball:" << endl;
		cin >> radiusBall;
		cout << endl;
		cout << "Enter the generation method number:" << endl;
		cin >> methodNumber;
		cout << endl;

		resultsGeneratorsOutputConsole(numberIterations, radiusBall, methodNumber);

		cout << "Continue calculation? yes-y" << endl;
		cin >> key_exit;
	}

	system("pause");
	return 0;
}
