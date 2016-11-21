#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>
#include<cmath>
using namespace std;

int n;
double a1, b1, c1, a2, b2, c2;

double max(double a,double b)
{
	if (a > b)return a;
	return b;
}
double f(double e)
{
	return max(a1*e*e+b1*e+c1,a2*e*e+b2*e+c2);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		cin >> a1 >> b1 >> c1;
		cin >> a2 >> b2 >> c2;

		double left = 0, right = 1000;
		while (right - left >= 1e-8)
		{
			double mid1 = left + (right - left) / 3;
			double mid2 = right - (right - left) / 3;

			if (f(mid1) < f(mid2))right = mid2;
			else
				left = mid1;
		}
		printf("%.4lf \n", f(left));
		//cout << fixed << setprecision(4) << f(left) << endl;

	}

	


	return 0;
}