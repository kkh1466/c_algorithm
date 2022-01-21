// 합분해
// DP[K][N] = K개를 더해서 합이 N일 경우
// DP[K][N] = Σ(DP[K-1][N-L]), L을 더해지는 마지막 수로 생각 (0<=L<=N)
#include <iostream>
using namespace std;

int main(){
    int n,k;
    long long dp[201][201]{};
    cin>>n>>k;

    for(int i=0; i<=200; i++) dp[1][i]=1; // 숫자 1개를 더해서 숫자 n을 만드는 경우의 수는 1
    
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                dp[i][j]+=dp[i-1][l];
                dp[i][j]%=1000000000;
            }
        }
    }
    cout<<dp[k][n];
}


/* 파스칼 삼각형 이용
int main() {
    long long pascal[500][500];

    for (int i = 0; i <= 399; i++) {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % 1000000000;
        }
    }

    int N, K;
    std::cin >> N >> K;

    std::cout << pascal[N + K - 1][N];
}
*/
