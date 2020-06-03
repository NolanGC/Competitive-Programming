// Shortest path dijikstras implemented from priority queue
// leverages non-negative edge weights to only visit each node once
// O(n + mlogm)
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100000];
const int INF = 999999;
int dist[100000];
int processed[100000];
int n;
void dijkstras(int s){
	for (int i = 0; i<= n; ++i) {
		dist[i] = INF;	
	}
	priority_queue<pair<int, int>> q;
	dist[s] = 0;
	q.push({0,s});
	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		if(processed[a]) continue;
		processed[a] = true;
		for(auto u : adj[a]){
			int b = u.first; int w = u.second;
			if(dist[a]+w < dist[b]){
				dist[b] = dist[a] + w;
				q.push({-dist[b], b});
			}
		}
	}
}
int main(int argc, char *argv[])
{
	// adj[a] contains (b,w)
	std::cout << "how many edges: "	<< std::endl;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, w; cin >> a; cin >> b; cin >> w;	
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}	
	std::cout << "enter s d : " << std::endl;
	int s, d; cin >> s; cin >> d;
	dijkstras(s);
	std::cout << dist[d] << std::endl;
	return 0;
}
