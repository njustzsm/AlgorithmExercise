#include<iostream>
#include<string>
#include<vector>
using namespace std;


int input[100001];


int h1[100001],h2[100001];
int cur1, cur2;

void shiftdown1(int v)
{
	int t;
	while (v*2<=cur1)
	{
		t = v;
		if (h1[v * 2] < h1[v])
		{
			t = v * 2;
		}
		if (v * 2 + 1 <= cur1)
		{
			if (h1[v * 2 + 1] < h1[t])
			{
				t = v * 2 + 1;
			}
		}
		if (t != v)
		{
			int va = h1[v];
			h1[v] = h1[t];
			h1[t] = va;
			v = t;
		}
		else
			break;
	}
}
void shiftdown2(int v)
{
	int t;
	while (v * 2 <= cur2)
	{
		t = v;
		if (h2[v * 2]> h2[v])
		{
			t = v * 2;
		}
		if (v * 2 + 1 <= cur2)
		{
			if (h2[v * 2 + 1] > h2[t])
			{
				t = v * 2 + 1;
			}
		}
		if (t != v)
		{
			int va = h2[v];
			h2[v] = h2[t];
			h2[t] = va;
			v = t;
		}
		else
			break;
	}
}

void shiftup1(int v)
{
	if (v == 1)return;
	while (v!=1)
	{
		if (h1[v] < h1[v / 2])
		{
			int va = h1[v];
			h1[v] = h1[v / 2];
			h1[v / 2] = va;
			v /= 2;
		}
		else
			break;
	}
}

void shiftup2(int v)
{
	if (v == 1)return;
	while (v != 1)
	{
		if (h2[v] > h2[v / 2])
		{
			int va = h2[v];
			h2[v] = h2[v / 2];
			h2[v / 2] = va;
			v /= 2;
		}
		else
			break;
	}
}


void Insert1(int v)
{
	cur1++;
	h1[cur1] = v;
	shiftup1(cur1);
}

void Insert2(int v)
{
	cur2++;
	h2[cur2] = v;
	shiftup2(cur2);
}

int delete1()
{
	int cur = h1[1];
	h1[1] = h1[cur1];
	shiftdown1(1);
	cur1--;
	return cur;
}
int delete2()
{
	int cur = h2[1];
	h2[1] = h2[cur2];
	shiftdown2(1);
	cur2--;
	return cur;
}


void addAnum(int value)
{
	if (cur1 == 0)
		Insert1(value);
	else if (cur2 == 0)
		Insert2(value);
	else
	{
		if (value > h1[1])
		{
			Insert1(value);
		}
		else
		{
			Insert2(value);
		}
	}
	if (cur1 - cur2 >= 2)
	{
		Insert2(h1[1]);
		delete1();
	}
	else if (cur2 - cur1 >= 2)
	{
		Insert1(h2[1]);
		delete2();
	}
}
int main()
{
	vector<int>result;
	result.clear();
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cur1 = 0;
		cur2 = 0;

		int n;
		cin >> n;

		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			addAnum(a);

		}

		int m;
		string command;
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> command;
			if (command == "add")
			{
				int addnum;
				cin >> addnum;
				addAnum(addnum);
			}
			else
			{
				if (cur1 > cur2)
				{
					int tmp = h1[1];
					cout << tmp << endl;
				}
				else if (cur2 > cur1)
				{
					int tmp = h2[1];
					cout << tmp << endl;
					
				}
				else
				{
					if (h1[1] > h2[1])
					{
						cout << h2[1];
						
					}
						
					else
					{
						
						cout << h1[1];
					}
						
				}

			}
		}

		
		
	}
	return 0;
}