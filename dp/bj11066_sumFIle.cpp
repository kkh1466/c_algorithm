// 파일 합치기
#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 2e8
using namespace std;
 
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;
 
int dpf(int tx, int ty) {
    if (dp[tx][ty] != INF)
        return dp[tx][ty];
 
    if (tx == ty)
        return dp[tx][ty] = 0;
 
    if (tx + 1 == ty)
        return dp[tx][ty] = cost[tx] + cost[ty];
 
    for (int mid = tx; mid < ty; mid++) {
        int left = dpf(tx, mid);
        int right = dpf(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right);
    }
 
    return dp[tx][ty] += sum[ty] - sum[tx - 1];
}
 
int main() {
    cin >> t;
    while (t--) {
        fill(&dp[0][0], &dp[500][501], INF);
        cin >> k;
        for (i = 1; i <= k; i++) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        cout << dpf(1, k) << "\n";
    }
    return 0;
}