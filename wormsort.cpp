#include <bits/stdc++.h>
using namespace std;

int n; int m;
int p[100001];
int visited[100001];
vector<pair<int, int>> adj[100001];
int group = 1; 

void dfs_visit(int s, int k){
	if(visited[s] != 0) return;
	visited[s] = group;
	for(auto u : adj[s]){
		if(u.second >= k){
			dfs_visit(u.first, k);
		}
	}
}
void dfs(int k){
	for (int i = 1; i <= n; ++i) {
		if(visited[i] == 0)	
		{
			dfs_visit(i, k);
			group++;
		}
	}
}
bool valid(int k){
	for (int i = 1; i <= n; ++i) {
		visited[i] = 0;		
	}
	dfs(k);
	for (int i = 1; i <= n; ++i) {
		if(visited[i] != visited[p[i]]) return false;	
	}	
	return true;
}
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(int argc, char *argv[])
{
	setIO("wormsort");
	cin >> n; cin >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];	
	}	
	for (int i = 0; i < m; ++i) {
		int a;int b; int w;
		cin >> a; cin >> b; cin >> w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	int l = 1; int r = 999999999;
	int best = -1;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(valid(mid)){
			best = mid;
			l = mid +1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << best;

	return 0;
}
