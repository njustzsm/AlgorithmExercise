#include<iostream>

using namespace std;

long long mod(int a, int b)
{
	if (b == 1)return a;
	long long s = mod(a, b / 2);
	if (b % 2 == 0)return (s*s) % 10;
	else return (s*s*a) % 10;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int a = m % 10;
		cout << mod(a, m) << endl;
	}
	return 0;
}