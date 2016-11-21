#include<iostream>
#include<string>

#define N 16000001
using namespace std;


bool Hash[N] = { false };
int id[500];
int value;

int main()
{
	value = 0;
	int n, nc;
	string data;
	cin >> n >> nc;
	cin >> data;

	for (int i = 0; i < 500; i++)id[i] = -1;
	



	for (int i = 0; i < data.size(); i++)
	{
		if (id[data[i]] < 0)id[data[i]] = value++;
	}

	int ans = 0;
	for (int i = 0; i <=data.size() - n; i++)
	{
		string sub = data.substr(i,n);
		int s = 0;
		for (int j = 0; j < sub.size(); j++)
		{
			s = s*nc+id[sub[j]];
		}
		if (!Hash[s])
		{
			ans++;
			Hash[s] = true;

		}
	}

	cout << ans;


	return 0;
}