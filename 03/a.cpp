#include <bits/stdc++.h>

using namespace std;
int main()
{
	vector<string> v;
	string t;
	while(cin >> t)
		v.push_back(t);
	const int n = v.size();
	const int m = v[0].size();
	vector<vector<bool>> h(n, vector<bool>(m, 0));
	int dx[] = {1,0,1,-1,-1,0,1,-1};
	int dy[] = {0,1,1,-1,0,-1,-1,1};
	auto inbounds = [&](int x, int y)
	{
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			if(isdigit(v[i][j]) || v[i][j]=='.')
				continue;
			for(int k=0; k<8; ++k)		
			{
				if(inbounds(i+dx[k], j+dy[k]))	
					h[i+dx[k]][j+dy[k]] = 1;			
			}
		}
	}
	int sum = 0;
	for(int i=0; i<n; ++i)
	{
		int cur = 0;
		bool ok = 0;
		int f = 1;
		for(int j=m-1; j>=0; --j)
		{
			if(!isdigit(v[i][j]))
			{
				cur = 0;
				ok = 0;
				f = 1;
			}
			else
			{
				cur += f * (v[i][j] - '0');	
				f *= 10;
				ok |= h[i][j];
				if(ok && (!inbounds(i, j-1) || !isdigit(v[i][j-1])))
					sum += cur;
			}
		}
	}
	cout << sum << endl;	
}
