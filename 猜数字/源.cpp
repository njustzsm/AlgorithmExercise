#include<iostream>
#include<vector>
using namespace std;

struct point
{
	int data;
	int b;
	int c;
	point(int u, int v, int w)
	{
		data = u;
		b = v;
		c = w;
	}
};

vector<point*>input;


bool test0(int starddata, point* testdata)
{
	int stardnum[4];
	int testnum [4];

	int tmp1 = starddata, tmp2 = testdata->data;

	for (int i = 3; i >= 0; i--)
	{
		stardnum[i] = tmp1 % 10;
		tmp1 /= 10;
		testnum[i] = tmp2 % 10;
		tmp2 /= 10;
	}

	int tt = 0;
	for (int i = 0; i < 4; i++)
	{
		if (stardnum[i] == testnum[i])
			tt++;
	}
	if (tt != testdata->c)return false;


	tt = 0;
	bool ischeck[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++)
	{
		int aa = testnum[i];
		for (int j = 0; j < 4; j++)
		{
			if (aa == stardnum[j] && !ischeck[j])
			{
				tt++;
				ischeck[j] = true;
				break;
			}
		}
	}
	if (tt != testdata->b)return false;
	return true;
}

bool test(int number)
{
	for (int i = 0; i < input.size(); i++)
	{
		point*cur = input[i];
		if (!test0(number, cur))return false;
	}
	return true;
}




int main()
{
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)break;
		input.clear();

		for (int i = 0; i < num; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			point*pt = new point(a, b, c);
			input.push_back(pt);
		}
		int countNum = 0;
		int index = 0;
		for (int i = 1000; i <= 9999; i++)
		{
			if (i == 3585)
			{
				int a = 1;
			}
			if (test(i))
			{
				countNum++;
				index = i;
			}
		}
		if (countNum == 1)
		{
			cout << index << endl;
		}
		else
			cout << "Not sure" << endl;
	}
	

	/*
	6
	4815 2 1
	5716 1 0
	7842 1 0
	4901 0 0
	8585 3 3
	8555 3 2

	*/
}