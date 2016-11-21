#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int grid[10][10];
vector<int>stack;
vector<int>result;
vector<int>test;
bool ok = false;
bool check(int x,int y,int value)
{
	
	for (int i = 1; i <= 9; i++)
	{
		if (grid[x][i] ==value)return false;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (grid[i][y] == value )return false;
	}




	return true;
}


void dfs(int index)
{
	if (ok)return;
	if (index < stack.size())
	{
		int x = stack[index];
		int y = stack[index+1];
		
		for (int i = 1; i <= 9; i++)
		{
			if (check(x, y, i))
			{
				grid[x][y] = i;
				result.push_back(i);
				dfs(index+2);
				grid[x][y] = 0;
				result.pop_back();
			}
				
		}
	}
	else if (index ==stack.size())
	{
		ok = true;
		//test = result;
		cout << endl;
		int cur = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (grid[i][j] != 0)
					cout << grid[i][j] << " ";
				else
					cout << result[cur++] << " ";
			}
			cout << endl;
		}
	}
	

		
		
	
}


//注意，该题答案提交提示为超时 
int main()
{
	char s;
	while (cin >> s)
	{
		stack.clear();
		ok = false;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (i == 1 && j == 1)
				{
					if (s == '?')
						grid[i][j] = 0;
					else
						grid[i][j] =s-'0';
				
					if (grid[i][j] == 0)
					{
						stack.push_back(i);
						stack.push_back(j);
					}

					continue;
				}

				cin >> s;
				if (s == '?')
					grid[i][j] = 0;
				else
					grid[i][j] = s - '0';

				if (grid[i][j] == 0)
				{
					stack.push_back(i);
					stack.push_back(j);
				}
			}
		}

		dfs(0);
	}
	

	
	


	return 0;
}