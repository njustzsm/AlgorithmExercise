#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<char>result;


int find(string a,char target)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (target == a[i])
			return i;
	}
	return -1;
}

void solve(string a, string b)
{
	if (a.size() == 0)return;
	if (a.size() == 1)
	{
		result.push_back(a[0]);
		return;
	}

	char root = a[0];
	int index = find(b,root);

	string leftTreeMid = b.substr(0,index);
	string rightTreeMid = b.substr(index+1);

	string leftTreeFir = a.substr(1,index);
	string rightTreeFir = a.substr(index+1);

	solve(leftTreeFir, leftTreeMid);  //����������
	solve(rightTreeFir,rightTreeMid);  //����������
	result.push_back(root);      //��������
	
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		result.clear();   //ע�⣬û��Ӹ���ʱ������
		solve(s1, s2);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		cout << endl;
		
		
	}
	
	return 0;
}