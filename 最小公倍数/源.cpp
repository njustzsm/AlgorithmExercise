#include<iostream>

using namespace std;



//շת����������Լ��
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