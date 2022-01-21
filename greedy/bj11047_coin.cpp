// 동전 0
#include <iostream>
using namespace std;


int main(){
    int result=0, n, money, arr[11]{};
    cin>>n>>money;
    for(int i=1; i<=n; i++) cin>>arr[i];

    while(money>0){
        for (int i = n; i > 0 ; i--) {
	        result += money / arr[i];
	        money %= arr[i];
        }
    }
    cout<<result;
}


/*
int main(){
    int result=0, n, k, arr[11]{};
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>arr[i];

    while(k>0){
        for(int i=n; i>0; i--){
            if(arr[i]<=k){
                result++;
                k-=arr[i];
                break;
            }
        }
    }
    cout<<result;
}
*/