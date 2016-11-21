#include<iostream>
#include<queue>
using namespace std;

int n,length;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		queue<int>data;
		cin >> length;
		for (int j = 1; j <= length; j++)
		{
			data.push(j);
		}

		
		int num = 0;
		int curnum = 0;

		while (num<length-3)
		{
			curnum = length - num;
			for (int j = 1; j <=curnum; j++)
			{
				if (j%2!=0)
				{
					int tt = data.front();
					data.pop();
					data.push(tt);
				}
				else
				{
					data.pop();
					num++;
				}	
			}

			if (num >= length - 3)break;

			curnum = length - num;

			for (int j = 1; j <= curnum; j++)
			{
				if (j%3!=0)
				{
					int tt = data.front();
					data.pop();
					data.push(tt);
					
				}
				else
				{
					data.pop();
					num++;
				}
			}
		}
		while (!data.empty())
		{
			cout << data.front() << " ";
			data.pop();
		}
		cout << endl;



	}
}