#include <iostream>
#include <iomanip>
using namespace std;

/*
	f(1) = 1.0
	f(x) - f(1) = Sigma(k)[(1 - x) / (k * (k + x) * (k + 1))]
	f(x) =  Sigma(k)[(1 - x) / (k * (k + x) * (k + 1))] + 1.0

	Sigma(k)[k ^ -3] < Integrate (x ^ -3) from (n - 1) to infinite =  1 / 2 * (n - 1)^2
	Sigma(k)[(1 - x) / (k * (k + x) * (k + 1))] < (1 - x) * Sigma(k)[k ^ -3] 
	(1 - x) * Sigma(k)[k ^ -3] < (1 - x) / 2 * (n - 1)^2
*/
int main()
{
	double Epsilon = 1.0 / (2.0 * (1e4 - 1.0) * (1e4 - 1.0));

	for (double x = 0.0; x <= 2.0; x += 0.001)
	{
		double Result = 0.0;

		//题目精度要求为12位，而f(x)是k的三次式，故这里只用累加到10^4即可
		for (int k = 1; k <= 1e4; k++)
		{
			Result += (1.0 - x) / (k * (k + x) * (k + 1.0));
		}

		Result += 1.0;
		Result += (1.0 - x) * Epsilon;

		cout.setf(ios::fixed);
		cout << fixed << setprecision(3) << x << " " << setprecision(12) << Result << endl;
	}

	return 0;
}