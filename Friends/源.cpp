#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

string Calc(string a,string b,char type)
{
	int check[26] = {0};
	if (type == '+')
	{
		for (int i = 0; i < a.size(); i++)
		{
			int n = a[i] - 'A';
			check[n] = 1;
		}
		for (int i = 0; i < b.size(); i++)
		{
			int n = b[i] - 'A';
			check[n] = 1;
		}

		string result;
		for (int i = 0; i < 26; i++)
		{
			if (check[i])
			{
				result += 'A' + i;
			}
		}
		return result;
	}
	if (type == '-')
	{
		for (int i = 0; i < a.size(); i++)
		{
			int n = a[i] - 'A';
			check[n] = 1;
		}
		for (int i = 0; i < b.size(); i++)
		{
			int n = b[i] - 'A';
			check[n] = 0;
		}
		string result;
		for (int i = 0; i < 26; i++)
		{
			if (check[i])
			{
				result += 'A' + i;
			}
		}
		return result;
	}
	if (type == '*')
	{
		for (int i = 0; i < a.size(); i++)
		{
			int n = a[i] - 'A';
			check[n] += 1;
		}
		for (int i = 0; i < b.size(); i++)
		{
			int n = b[i] - 'A';
			check[n] += 1;
		}
		string result;
		for (int i = 0; i < 26; i++)
		{
			if (check[i]==2)
			{
				result += 'A' + i;
			}
		}
		return result;
	}
}

string func(vector<string>data)
{
	int num = data.size();
	if (num == 0)return "";
	if (num == 1)return data[0];

	vector<string> rt;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == "*")
		{
			string left = rt[rt.size() - 1];
			string right = data[i + 1];
			i += 1;
			rt.pop_back();
			left = Calc(left, right, '*');
			rt.push_back(left);
		}
		else
			rt.push_back(data[i]);
	}
	
	if (rt.size() == 1)return rt[0];
	string result = rt[0];

	for (int i = 1; i < rt.size() - 1; i += 2)
	{
		if (rt[i] == "+")
		{
			result = Calc(result,rt[i+1],'+');
		}
		if (rt[i] == "-")
		{
			result = Calc(result, rt[i + 1], '-');
		}
	}

	return result;

}
int main()
{
	vector<string>data;
	
	string t;

	//while (cin >> t)
	//{
	cin >> t;
		int num = t.size();
		queue<string>input;

		for (int i = 0; i < num; i++)
		{
			if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '(' || t[i] == ')')
			{
				string rr;
				rr += t[i];
				input.push(rr);
			}
			else if (t[i] == '{')
			{
				int p = i;
				int q = p + 1;
				while (t[q] != '}')
					q++;
				if (q - p > 1)
				{
					string tt = t.substr(p + 1, q - p - 1);
					i = q;
					input.push(tt);
				}
				else
				{
					string tt = "";
					i = q;
					input.push(tt);
				}
			}
		}

		vector<string> output;

		while (!input.empty())
		{
			string curstring = input.front();
			input.pop();
			if (curstring != ")")
			{
				output.push_back(curstring);
			}
			else
			{
				int p = output.size() - 1;
				while (output[p] != "(")
				{
					p--;
				}
				vector<string>tmp;
				for (int i = p + 1; i < output.size(); i++)
				{
					tmp.push_back(output[i]);
				}
				string cur = func(tmp);
				while (output.size() != p)
				{
					output.pop_back();
				}
				output.push_back(cur);
			}
		}



		
			vector<string>mul;
			mul.push_back(output[0]);
			for (int i = 1; i < output.size(); i++)
			{
				if (output[i] == "*")
				{
					string left = mul[mul.size() - 1];
					string right = output[i + 1];
					i++;
					left = Calc(left, right, '*');
					mul.pop_back();
					mul.push_back(left);

				}
				else
					mul.push_back(output[i]);
			}

			string result = mul[0];

			for (int i = 1; i < mul.size() - 1; i+=2)
			{
				if (mul[i] == "+")
				{
					result = Calc(result,mul[i+1],'+');
				}
				else
				{
					result = Calc(result, mul[i + 1], '-');
				}
			}
			data.push_back(result);

		


	//}
		
		
	
	return 0;
}