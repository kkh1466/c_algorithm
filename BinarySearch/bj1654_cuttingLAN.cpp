#include <iostream>
using namespace std;
long long lan[10001];
int K,N;

int main(){
    cin>>K>>N;
    long long high=0;
    for(int i=0; i<K; i++) {
        cin >> lan[i];
        high=max(high,lan[i]);
    }

    long long result=0;
    long long low=1;
    
    while(low<=high){
        long long mid = (low+high)/2;

        int count=0;
        for(int i=0; i<K;i++) count+=lan[i]/mid;

        if(count>=N){
            if(result<mid)
                result=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<result;
}