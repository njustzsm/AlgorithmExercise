#include<iostream>

using namespace std;


int f(int m,int n)
{
	if (n == 1)return 1;
	if (m == 0)return 1;

	if (n > m)
	{
		return f(m, m);
	}
	else
		return f(m, n - 1) + f(m - n, n);
}

int main()
{
	
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << f(a, b) << endl;
	}
	return 0;
}