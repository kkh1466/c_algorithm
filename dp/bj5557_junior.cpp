// 1학년
// dp[i][j]=j번 계산했을 때 숫자 i값이 나올 수 있는 경우의 수
// j-arr[i]>=0인 경우 dp[i][j-arr[i]]+=dp[i-1][j]
// j-arr[i]<=20인 경우 dp[i][j+arr[i]]+=dp[i-1][j]
#include <iostream> 
using namespace std; 
long long int dp[110][30] = { 0, }; 
int n; int arr[110] = { 0, }; 

int main() { 
    cin.tie(NULL); 
    ios::sync_with_stdio(false); 
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i+1]; 
    } 
    dp[1][arr[1]] = 1; 
    for (int i = 2; i <= n; i++) { //row 
        for (int j = 0; j <= 20; j++) { //col 
            if (dp[i - 1][j] >= 0) { 
                if( j - arr[i] >= 0) // j == 8 
                    dp[i][j - arr[i]] += dp[i - 1][j]; 
                if (j + arr[i] <= 20)  
                    dp[i][j + arr[i]] += dp[i - 1][j]; 
            } 
        } 
    } 
    cout << dp[n-1][arr[n]] << endl; 
    return 0; 
}

