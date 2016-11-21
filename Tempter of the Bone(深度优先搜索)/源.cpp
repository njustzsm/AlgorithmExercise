#include<iostream>

using namespace std;

char grid[8][8];
bool check[8][8];
int time[8][8];
int rt[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int row, col, requireTime;
bool ok = false;
int srcX, srcY, dstX, dstY;

void DFS(int x,int y,int curTime)
{
	if (ok)return;
	if (x == dstX&&y == dstY&&curTime==requireTime)
	{
		cout << "YES" << endl;
		ok = true;
		return;
	}
	else if (curTime >= requireTime)
		return;

	//注意：该行为剪枝函数，如果没有该行，提交时会提醒超时
	if (((int)abs(x - dstX) + (int)abs(y - dstY)) % 2 != (requireTime - curTime) % 2)
		return;

	for (int i = 0; i < 4; i++)
	{
		int xx = x+rt[i][0];
		int yy = y + rt[i][1];
		if (xx >= 1 && xx <= row&&yy >= 1 && yy <= col&&!check[xx][yy] && grid[xx][yy] != 'X') 
		{
			check[xx][yy] = true;
			DFS(xx,yy,curTime+1);
			check[xx][yy] = false;
		}
	}
}

int main()
{
	while (true)
	{
		ok = false;
		cin >> row >> col >> requireTime;
		if (row + col + requireTime == 0)break;

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				check[i][j] = false;
				time[i][j] = 0;
				cin >> grid[i][j];
				if (grid[i][j] == 'S')
				{
					srcX = i; srcY = j;
				}
				if (grid[i][j] == 'D')
				{
					dstX = i; dstY = j;
				}
			}
		}
		check[srcX][srcY] = true;
		DFS(srcX, srcY, 0);
		if (!ok)cout << "NO" << endl;

	}
	return 0;
}