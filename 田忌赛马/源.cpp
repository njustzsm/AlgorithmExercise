#include<iostream>
#include<vector>

using namespace std;



int tianji[1001];
int king[1001];
vector<int>result;

void quickSorttianji(int src, int dst)
{
	if (src >= dst)return;

	int p = src, q = dst;
	int cur = tianji[src];


	while (p<q)
	{
		while (tianji[q] <= cur&&p<q)
		{
			q--;
		}
		while (tianji[p] >= cur&&p<q)
		{
			p++;
		}
		if (p < q)
		{
			int tmp = tianji[p];
			tianji[p] = tianji[q];
			tianji[q] = tmp;
		}
	}
	
	int tmp = tianji[p];
	tianji[p] = cur;

	tianji[src] = tmp;

	quickSorttianji(src, p - 1);
	quickSorttianji(p + 1, dst);
}

void quickSortking(int src, int dst)
{
	if (src >= dst)return;

	int p = src, q = dst;
	int cur = king[src];


	while (p<q)
	{
		while (king[q] <= cur&&p<q)
		{
			q--;
		}
		while (king[p] >= cur&&p<q)
		{
			p++;
		}
		if (p < q)
		{
			int tmp = king[p];
			king[p] = king[q];
			king[q] = tmp;
		}
	}

	int tmp = king[p];
	king[p] = cur;

	king[src] = tmp;

	quickSortking(src, p - 1);
	quickSortking(p + 1, dst);
}

int main()
{

	
	int num;
	while (cin >> num&&num)
	{
		
		for (int i = 1; i <= num; i++)
			cin >> tianji[i];
		for (int i = 1; i <= num; i++)
			cin >> king[i];

		quickSorttianji(1,num);
		quickSortking(1,num);

		int l1 = 1, l2 = 1, r1 = num, r2 = num;
		int curResult = 0;

		while (l1<=r1)
		{
			if (tianji[l1] > king[l2])
			{
				curResult+=200;
				l1++;
				l2++;
			}
			else if (tianji[l1] < king[l2])
			{
				curResult -= 200;
				l2++;
				r1--; 
			}
			else if (tianji[l1] == king[l2] && tianji[r1]>king[r2])
			{
				curResult += 200;
				r1--;
				r2--;
			}
			else if (tianji[l1] == king[l2] && tianji[r1]<=king[r2])
			{
				if (tianji[r1] < king[l2])curResult -= 200;
				r1--;
				l2++;
			}
		}
		result.push_back(curResult);
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
}