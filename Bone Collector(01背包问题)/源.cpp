#include<iostream>
#include<algorithm>
using namespace std;

int requireweight, num;

int value[1001], weight[1001],dp[1001];
int grid[1001][1001] = { 0 };



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> num >> requireweight;
		for (int i = 1; i <= num; i++)
		{
			cin >> value[i];
		}
		for (int i = 1; i <= num; i++)
		{
			cin >> weight[i];
		}

		/*for (int i = 0; i <= 1000; i++)
		{
			dp[i] = 0;
		}*/

		for (int i = 0; i <= num; i++)
		{
			for (int j = 0; j <= requireweight; j++)
			{
				grid[i][j] = 0;
			}
		}
		

		
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= requireweight; j++)
			{
				if (j >= weight[i])
					grid[i][j] = max(grid[i - 1][j], grid[i - 1][j - weight[i]] + value[i]);
				else
					grid[i][j] = grid[i-1][j];
			}
		}
		cout << grid[num][requireweight] << endl;
		/*for (int i = 1; i <= num; i++)
		{
			for (int j = requireweight; j >= weight[i]; j--)
			{
				dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
			}
		}
		cout << dp[requireweight] << endl;*/
		

	}
	return 0;
}