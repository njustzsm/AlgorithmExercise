#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;


int main()
{
	int n;
	string name = "sheep";
	string cur;
	cin >> n;
	int *result = new int[n];

	for (int i = 0; i < n; i++)
	{
		result[i] = 0;
		int m;
		cin >> m;
		
		for (int j = 0; j < m; j++)
		{
			cin >> cur;
			if (cur == name)
				result[i]+=1;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << "Case " << i + 1 << ": This list contains " << result[i] << " sheep." << endl;
		if (i != n - 1)
			cout << endl;
	}
	return 0;
}