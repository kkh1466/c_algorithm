//1. 증가하는 부분 수열일 경우, LIS 배열의 가장 끝에 추가한다.
//2. 증가하는 부분 수열이 아닐 경우, LIS배열을 이분 탐색하여 들어갈 위치를 찾아 값을 대체한다.
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int ans=0,n,arr[10001]{};
    vector<int> v;
    v.push_back(-1000000);
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if (v.back() < arr[i]){
            v.push_back(arr[i]);
            ans++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
        }
    }

    cout<<ans<<endl;
    // for(int i=1; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
}