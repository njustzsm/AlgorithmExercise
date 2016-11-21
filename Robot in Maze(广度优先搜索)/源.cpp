#include<iostream>
#include<queue>

using namespace std;


char grad[101][101];
bool check[101][101];
int dis[101][1010] = {0};
int direction[101][101];

int rt[5][2] = { {0,0}, { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };


int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int m, n;
		int srcX, srcY, dstX, dstY;
		queue<int>que;
		
		cin >> m >> n;
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				check[j][k]=false;

				cin >> grad[j][k];
				if (grad[j][k] == 'S')
				{
					srcX = j;
					srcY = k;
				}
				if (grad[j][k] == 'T')
				{
					dstX = j;
					dstY = k;
				}
			}
		}

		que.push(srcX);
		que.push(srcY);
		direction[srcX][srcY] = 1;
		check[srcX][srcY] = true;

		
		bool found = false;
		
		while (!que.empty())
		{
			 int curX = que.front(); que.pop();
			 int curY = que.front(); que.pop();

			 
			 if (curX == dstX&&curY == dstY)
			 {
				cout << dis[curX][curY]<< endl;
				 found = true;
				 break;
			 }
			 
			

			int newdir;
			
			
			for (int j = 1; j <= 4; j++)
			{
				if (j == direction[curX][curY])continue;
				if (j == 1)newdir = 3;
				if (j == 2)newdir = 4;
				if (j == 3)newdir = 1;
				if (j == 4)newdir = 2;

				int xx = curX + rt[j][0];
				int yy = curY + rt[j][1];
				if (xx >= 1 && xx <= m&&yy >= 1 && yy <= n&&grad[xx][yy] != '#'&&grad[xx][yy] != 'S'&&!check[xx][yy])
				{
					
						
					check[xx][yy] = true;
					que.push(xx);
					que.push(yy);
					direction[xx][yy] = newdir;
					dis[xx][yy] = dis[curX][curY]+1;
					if (newdir != direction[curX][curY])
						dis[xx][yy] += 1;
				}
			}
			
		}
		if (!found)
			cout << -1 << endl;
	}


	return 0;
}