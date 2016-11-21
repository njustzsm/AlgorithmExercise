#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;


int data[100][100] = {0};

void show(int num)
{
	data[1][1] = 1;
	for (int i = 0; i < num-1; i++)
		cout << " ";
	cout << 1 << endl;
	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
		}

		for (int j = 0; j < num - i; j++)
			cout << " ";
		for (int j = 1; j <= i; j++)
		{
			cout << data[i][j] <<" ";
		}
		cout << endl;
	}

}

void main()
{
	show(10);
}