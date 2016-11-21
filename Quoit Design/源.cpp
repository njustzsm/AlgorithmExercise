#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

struct Node
{
	double x, y;
};


Node data[100005];
int n;

double getDis(Node a,Node b)
{
	return sqrt(pow(a.x-b.x,2)+pow(b.y-a.y,2));
}

double min(double a,double b)
{
	if (a > b)return b;
	return a;
}

bool cmpx(Node a, Node b)
{
	return a.x < b.x;
}

bool cmpy(Node a, Node b)
{
	return a.y < b.y;
}

double cal(int s, int e)
{
	if (s == e)return 1e10;

	int mid = (s + e) / 2;

	double d = min(cal(s,mid),cal(mid+1,e));

	vector<Node>rest;
	
	int lineValue = data[mid].x;

	for (int i = mid; i >=s; i--)
	{
		if (lineValue - data[i].x < d)
			rest.push_back(data[i]);
		else
			break;
	}
	for (int i = mid + 1; i <= e; i++)
	{
		if (data[i].x - lineValue < d)
			rest.push_back(data[i]);
		else
			break;
	}

	sort(rest.begin(), rest.end(), cmpy);
	

	for (int i = 0; i < rest.size(); i++)
	{
		for (int j = i + 1; j < rest.size(); j++)
		{
			if (abs(rest[i].y - rest[j].y)>=d)break;

			double dis = getDis(rest[i],rest[j]);
			if (dis < d)
				d = dis;
		}
	}
	return d;

}

int main()
{
	
	while (cin>>n&&n)
	{
		
		for (int i = 0; i <n; i++)
		{
			cin>>data[i].x>>data[i].y;
		}
		sort(data, data + n, cmpx);
		double d = cal(0, n - 1) / 2.0;
		printf("%.2lf\n",d);
	}
	return 0;
}