// 상자 넣기
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, arr[1001]{}, dp[1001]{},result=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    fill(dp,dp+1001,1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
        }
        result=max(result,dp[i]);
    }
    cout<<result;
}