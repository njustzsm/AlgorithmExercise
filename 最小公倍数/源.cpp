#include<iostream>

using namespace std;



//辗转相除法求最大公约数
int gcd(int a, int b)
{
	if (a < b)
	{
		int tt = a;
		int a = b;
		int b = a;
	}
	if (a%b == 0)return b;

	int c = a%b;
	return gcd(b,c);
}


int main()
{
	int a, b;
	while (cin>>a>>b)
	{
		cout << a*b / gcd(a, b) << endl;
		return 0;
	}
}