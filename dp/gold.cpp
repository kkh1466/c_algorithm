// 금광
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int testcase, n, m;
int arr[20][20];
int dp[20][20];

int main(){
    cin>>testcase;
    for(int tc=0; tc<testcase; tc++){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
                dp[i][j]=arr[i][j];
            }
        }

        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                int left, leftdown, leftup;
                if(i==0) leftup=0; //왼쪽 위에서 오는 경우
                else leftup=dp[i-1][j-1];

                left=dp[i][j-1]; //왼쪽에서 오는 경우

                if(i==n-1) leftdown=0; //왼쪽 아래에서 오는 경우
                else leftup=dp[i+1][j-1];

                dp[i][j]=dp[i][j]+max({left, leftup, leftdown});
            }
        }

        int result=0;
        for(int i=0; i<n; i++) result=max(result, dp[i][m-1]);
        cout << result << endl;
    }
}