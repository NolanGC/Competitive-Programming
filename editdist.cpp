// Levenshtein Distance
// first time implementing DP algo
// 1) define process in terms of recursive function
// 2) define base case
// 3) # of inputs to function = dimension of DP array
// 4) memoize values and recall whenever possible
// 5) easy 

#include <bits/stdc++.h>
using namespace std;

string x; string y;
int dp[1000][1000];
bool ready[1000][1000] = {0};

int cost(int a, int b){
	if(x[a-1] == y[b-1]) return 0;
	return 1;
}
int distance(int a, int b){
	if(a==0&&b==0) return 0;
	else if(a == 0) return b;
	else if(b==0) return a;
	else if(ready[a][b]) return dp[a][b];
	else{
		int appendX = 0; int truncateX = 0; int matchLast = 0;
		appendX = distance(a, b-1)+1;
		truncateX = distance(a-1, b)+1;
		matchLast = distance(a-1,b-1)+cost(a,b);
		int mn = min(min(appendX, truncateX), matchLast);
		ready[a][b] = true;
		dp[a][b] = mn;
		return mn;
	}
}

int main(int argc, char *argv[])
{
	std::cout << "Enter two strings: " << std::endl;
	cin >> x; cin >> y;
	int n; int m; 
	n = x.size(); m = y.size();
	std::cout << distance(n-1, m-1) << std::endl;
    	
	return 0;
}
