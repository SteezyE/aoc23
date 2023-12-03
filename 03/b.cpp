#include <bits/stdc++.h>

using namespace std;
int main()
{
	// 1*1 *** ***
	// *** 1*1 ***
	// *** *** 1*1
	// 
	// not 1*1
	// but numbers in two rows
	// or 1*1 exactly ones
	// 
	// c1 := count of rows containing numbers
	// c2 := count of 1*1 patterns
	// 
	// c2 == 0 && c1 == 2 || c2 == 1 && c1 == 1
	vector<string> v;
	v.push_back("placeholder");
	string t;
	while(cin >> t)
		v.push_back("."+t+".");
	v.push_back(string(v[1].size(), '.'));	
	const int n = v.size()-2;
	const int m = v[1].size()-2;
	v[0] = v[int(v.size()-1)];
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(v[i][j]!='*')
				continue;
			int c1 = 0, c2 = 0;	
			vector<pair<int,int>> start;
			for(int dx=-1; dx<=1; ++dx)
			{
				if(isdigit(v[i+dx][j-1]) && !isdigit(v[i+dx][j]) && isdigit(v[i+dx][j+1]))
				{
					c2 += 1;
					start.push_back({i+dx, j+1});
				}	
				for(int dy=-1; dy<=1; ++dy)
				{
					if(isdigit(v[i+dx][j+dy]))
					{
						c1 += 1;
						start.push_back({i+dx, j+dy});
						break;
					}
				}
			}
			if(c2 == 0 && c1 == 2 || c2 == 1 && c1 == 1)
			{
				for(int k=0; k<=1; ++k)
				{
					while(isdigit(v[start[k].first][start[k].second+1]))
						start[k].second += 1;
				}
				int f = 1, cur = 0;
				vector<int> t;
				for(int k=0; k<=1; ++k)
				{
					while(isdigit(v[start[k].first][start[k].second]))
					{
						cur += f * (v[start[k].first][start[k].second] - '0');
						f *= 10;
						start[k].second -= 1;
					}
					t.push_back(cur);	
					cur = 0;
					f = 1;
				}
				sum += t[0] * t[1];
			}	
		}
	}
	cout << sum << endl;
}
