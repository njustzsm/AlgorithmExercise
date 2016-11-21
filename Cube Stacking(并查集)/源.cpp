#include<iostream>

#define N 30001
using namespace std;

int n,fa[N],mx[N],r[N];
//fa��ʾ�ڵ�ĸ��ڵ㣬mx��ʾ�ڵ����ڼ��ϵĽڵ���� r��ʾ�ڵ㵽���ڵ�ľ���

int find(int n)
{
	int ff = fa[n];
	if (ff == n)return ff;

	int root = find(ff);
	fa[n] = root;

	r[n] += r[ff];  //ͬʱ���µ�ǰ�ڵ㵽���ڵ�ľ���

	return root;
}


/*
int find(int x)
{
int fx = fa[x];
if (fa[x] != x)
{
fx = find(fa[x]);
r[x] += r[fa[x]];
}
return fa[x] = fx;
}
*/



void U(int x, int y)
{
	int rx = find(x);
	int ry = find(y);

	fa[ry] = rx;
	r[ry] += mx[rx];
	mx[rx] += mx[ry];

}


int main()
{
	for (int i = 1; i < N; i++)
		{
			fa[i] = i;
			mx[i] = 1;
			r[i] = 0;
		}


	cin >> n;
		char a;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == 'M')
			{
				int src, dst;
				cin >> src >> dst;
				U(src, dst);
			}
			else
			{
				int nn;
				cin >> nn;
				int curRoot = find(nn);
				cout << mx[curRoot] - r[nn] - 1 << endl;
			}
		}

	


	

	


	return 0;
}