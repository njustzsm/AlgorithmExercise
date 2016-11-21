#include<iostream>
#include<algorithm>
using namespace std;

int data[21] = {0};
bool check[21];
int m;
int length;
int result ;

int dfs(int index,int curLength,int count)
{
	if (count == 3)
	{
		return 1;
	}

	for (int i = index; i >= 1; i--)
	{
		if (!check[i])
		{
			check[i] = true;
			if (data[i] + curLength < length)
			{
				if (dfs(i - 1, data[i] + curLength, count))//如果有解的话，证明data[i]加入该边是对的
				{
					return 1;
				}
			}
			else if (data[i] + curLength == length)
			{
				if (dfs(m, 0, count + 1))
					return 1;
				
			}
			check[i] = false;
		}
	}

	return 0;
	
}

int main()
{ 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		cin >> m;
		int sum = 0;
		result = 0;
		for (int j = 1; j <= m; j++)
		{
			check[j] = false;
			cin >> data[j];
			sum += data[j];
		}
		length = sum / 4;
		sort(data + 1, data + m + 1);


		if (sum % 4 != 0||m<4||length<data[m])
		{
			cout << "no" << endl;
			continue;
		}

		if (dfs(m, 0, 0))
		{
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;
	}
	return 0;
}