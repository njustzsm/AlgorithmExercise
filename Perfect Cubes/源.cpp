#include<iostream>


using namespace std;


int main()
{

	for (int a = 6; a <= 200; a++)
	{
		for (int b = 2; b < a; b++)
		{
			for (int c = b; c < a; c++)
			{
				for (int d = c; d < a; d++)
				{
					if (a*a*a == b*b*b + c*c*c + d*d*d)
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
					if (a*a*a < b*b*b + c*c*c + d*d*d)
					{
						break;
					}
				}
			}
		}
	}
	
	return 0;
}