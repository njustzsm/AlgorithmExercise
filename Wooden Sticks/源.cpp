#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct  node
{
	int length;
	int weight;
	node(int a, int b)
	{
		length = a;
		weight = b;
	}
};

bool cmp(node*a, node*b)
{
	if (a->length == b->length)return a->weight < b->weight;
	else
		return a->length < b->length;

}

vector<node*>data;
vector<int>result;
int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		data.clear();
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int a, b;
			cin >> a >> b;
			node*cur = new node(a,b);
			data.push_back(cur);
		}
		bool check[5000] = { false };

		sort(data.begin(),data.end(),cmp);

		int curResult = 0;
		int curWeight = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (!check[j])
			{
				node*curNode = data[j];
				curWeight = curNode->weight;
				check[j] = true;

				for (int k = j; k >= 0; k--)
				{
					if (!check[k] && data[k]->weight <= curWeight)
					{
						check[k] = true;
						curWeight = data[k]->weight;
					}
				}
				curResult++;
			}
		}

		result.push_back(curResult);

	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] <<endl;
	}
}