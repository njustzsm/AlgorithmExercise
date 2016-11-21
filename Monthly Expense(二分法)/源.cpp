#include<iostream>

using namespace std;


int n, m;
int maxValue = -1, sum = 0;
int data[100002];

bool isFit(int value)
{
	/*int curNum = 0;
	int curIndex = 1;
	int cursum = 0;
	
	while (curIndex<=n&&curNum<m)
	{
		if (cursum + data[curIndex] <= value)
		{
			cursum += data[curIndex];
			curIndex++;
		}
		else
		{
			cursum = 0;
			curNum++;
			if (curNum >= 5)return false;
		}
	}
	return true;*/

	int num = 1;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur + data[i] <= value)cur +=data[i];
		else
		{
			num++;
			cur = data[i];
		}
	}
	return num <= m;
}

int main()
{
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> data[i];
		sum += data[i];
		if (maxValue < data[i])
			maxValue = data[i];
	} 

	
	int low = maxValue;
	int height = sum;
	int result;

	while (true)
	{
		if (low == height)
		{
			result = low;
			break;
		}

		int mid = (low + height) / 2;
		if (isFit(mid))
		{
			height = mid;
		}
		else
		{
			low = mid + 1;
		}

	}
	cout << result << endl;
}