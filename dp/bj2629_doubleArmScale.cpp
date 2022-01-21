// 양팔저울
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, bead, x, weight[31];
bool dp[31][15001];

void solve(int i, int w){  // i는 주어진 추의 개수, w는 현재 무게
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	solve(i + 1, w + weight[i]);
	solve(i + 1, abs(w - weight[i]));
	solve(i + 1, w);
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) cin >> weight[i];

	solve(0, 0);

	cin >> bead;

	for (int i = 0; i < bead; i++){
		cin >> x;
		if(x > 15000) cout << "N ";
		else if (dp[n][x]) cout << "Y ";
		else cout << "N ";
	}	
}