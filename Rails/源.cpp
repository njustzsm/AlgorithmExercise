#include<iostream>
#include<vector>
using namespace std;

int dst[1002];
int main()
{
	int n;
	
	while (cin >> n&&n)
	{
		while (cin>>dst[0]&&dst[0])
		{
			for (int i = 1; i < n; i++)
			{
				cin >> dst[i];
			}

			int cur = 0;
			vector<int>stack;
			stack.clear();
			for (int i = 1; i <= n; i++)
			{
				stack.push_back(i);
				while (cur<n&&stack.size()>0&&dst[cur]==stack[stack.size()-1])
				{
					cur++;
					stack.pop_back();
				}
			}
			if (stack.size() == 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;

	}
	
	return 0;
}