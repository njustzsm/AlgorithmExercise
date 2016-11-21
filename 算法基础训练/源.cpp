#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;

int M, N,S;
int first[100001], next1[200002],u[100001],v[100001];
int result[100001];
void bfs(int s)
{
	queue<int>stack;
	stack.push(s);
	result[s] = -1;

	while (!stack.empty())
	{
		int cur = stack.front();
		stack.pop();

		int k = first[cur];
		while (k!=-1)
		{
			int dst = v[k];
			if (result[dst] == -2)
			{
				result[dst] = cur;
				stack.push(dst);
			}
			k = next1[k];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
	cout <<endl;
}


int main()
{
	int n;
	char tt=' ';
	while (cin >>tt&&tt!='t')
	{
		int a = 0;
	}
	return 0;
}


