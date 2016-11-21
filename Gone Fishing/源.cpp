#include<iostream>
#include<queue>

using namespace std;
class Node
{
public:
	int num, name;
	Node(int a = 0, int b = 0)
	{
		name = a;
		num = b;
	}
	bool operator<(const Node n)const
	{
		if (num == n.num)return name>n.name;
		else return num < n.num;
	}
};
int fi[50] = { 0 }, di[50] = { 0 }, ti[50] = { 0 }, n, h, ans[50] = {0};
vector<int>result[50];

int fishing(int p)
{
	
	for (int i = 0; i < 50; i++)
	{
		ans[i] = 0;
	}
	int result = 0;
	int time = h * 12;
	for (int i = 0; i < p; i++)
	{
		time -= ti[i];
	}
	priority_queue<Node>que;

	for (int i = 0; i <= p; i++)
	{
		if (fi[i]>0)
		{
			Node nn = Node(i, fi[i]);
			que.push(nn);
		}
	}

	while (time>0&&!que.empty())
	{
		time--;
		Node maxNode = que.top();
		que.pop();
		result += maxNode.num;
		maxNode.num -= di[maxNode.name];
		if (maxNode.num > 0)
			que.push(maxNode);
		ans[maxNode.name] += 5;
	}
	return result;
}




int main()
{
	int curIndex = 0;
	while (cin >> n&&n)
	{
		cin >> h;
		for (int i = 0; i < n; i++)
		{
			cin >> fi[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> di[i];
		}
		for (int i = 0; i < n - 1; i++)
		{
			cin >> ti[i];
		}

		int maxNum = -1;
		int index;
		for (int i = 0; i < n; i++)
		{
			int curResult = fishing(i);
			if (curResult>maxNum)
			{
				maxNum = curResult;
				index = i;
			}
		}

		fishing(index);

		int sum = 0;
		for (int i = 0; i < n; i++)sum += ans[i];
		for (int i = 0; i < index; i++)sum += ti[i] * 5;
		sum = h * 60 - sum;


		/*vector<int>cur;
		cur.push_back(maxNum);
		cur.push_back(ans[0] + sum);
		for (int i = 1; i < n; i++)
		{
			cur.push_back(ans[i]);
		}

		result[curIndex++]=cur;*/
		
		cout << endl;
		cout << ans[0] + sum;
		for (int i = 1; i < n; i++)
		{
			cout << ", " << ans[i];
		}
		cout << endl;
		cout << "Number of fish expected: " << maxNum << endl;
		
	}
	
	


	return 0;
}