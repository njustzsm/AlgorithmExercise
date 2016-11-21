#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<string>

using namespace std;
typedef unsigned long long ull;

const int N = 100001;

int ls1, ls2;

string s1, s2;
ull pow1[N],h1[N],h2[N],a[N];

int max(int a, int b)
{
	if (a > b)return a;
	return b;
}

ull getHash(ull h[], int i, int j)
{
	return h[j] - h[i] * pow1[j - i];
}


bool haveSolution(int t)
{
	int n = 0;
	for (int i = t; i <= ls1; i++)
	{
		a[n++] = getHash(h1,i-t,i);
	}
	sort(a,a+n);
	for (int i = t; i <= ls2; i++)
	{
		ull h = getHash(h2,i-t,i);
		if (binary_search(a, a + n, h))
			return true;
	}
	return false;
}


int main()
{
	
	cin>>s1>>s2;

	ls1 =s1.size();
	ls2 = s2.size();

	pow1[0] = 1;

	int l = 0;
	int r = max(ls1, ls2);

	for (int i = 1; i < r; i++)
	{
		pow1[i] = 27 * pow1[i - 1];
	}

	h1[0] = 0;
	for (int i = 0; i < ls1; i++)
	{
		h1[i + 1] = h1[i] * 27 + (s1[i]-'a');
	}
	h2[0] = 0;
	for (int i = 0; i < ls2; i++)
	{
		h2[i + 1] = h2[i] * 27 + (s2[i]-'a');
	}

	while (l != r)
	{
		int t = (l + r) / 2;
		if (haveSolution(t + 1))l = t + 1;
		else
			r = t;
	}
	cout << l;


	return 0;
}


