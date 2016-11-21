#include<iostream>
#include<algorithm>

using namespace std;




int time1[101];
int value[101];
int dp[1001];
int requreTime, num;

int grid[101][1001] = {0};




int main()
{
	cin >> requreTime >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> time1[i] >> value[i];
	}
	/*for (int i = 1; i <= 1000; i++)
	{
		dp[i] = 0;
	}*/
	
	
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= requreTime; j++)
		{
			if (j>=time1[i])
				grid[i][j] = max(grid[i-1][j],grid[i-1][j-time1[i]]+value[i]);
			else
			{
				grid[i][j] =grid[i-1][j];
			}
		}
	}
	cout << grid[num][requreTime];
	/*
	for (int i = 1; i <= requreTime; i++)
	{
	for (int j = 1; j <= num; j++)
	{
	if (time[j] > i)continue;
	dp[i] = max(dp[i],dp[i-time[j]]+value[j]);
	}
	}
	*/
	
	/*for (int i = 1; i <= num; i++)
	{
		for (int j = requreTime; j >= time1[i]; j--)
		{
			dp[j] = max(dp[j],dp[j- time1[i]]+value[i]);
		}
	}
	cout << dp[requreTime];*/
	

	return 0;
}