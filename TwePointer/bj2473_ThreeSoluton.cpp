// 세용액
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define inf 9000000000
#define fast_io std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

long long absnum(long long X){
    return X > 0 ? X : -X;
}

int main(){
    fast_io

    long long n, a;
    long long resa = inf, resb = inf, resc = inf;
    long long v[5001];

    cin>>n;
    for(int i = 0; i < n; i++) cin>>v[i];

    sort(v, v+n);
    long long least = inf;

    for(int i = 0; i < n; i++){
        long long fst = i+1;
        long long end = n-1;

        while(fst < end){
            long long sum = v[i]+v[fst]+v[end];
            if(absnum(sum) < least){
                resa = v[i];
                resb = v[fst];
                resc = v[end];
                least = absnum(sum);
            }
            if (sum > 0)
                end--;
            else if (sum < 0)
                fst++;
            else {
                std::cout << resa << " " << resb << " " << resc;
                return 0;
            }
        }
    }
    cout<<resa<<" "<<resb<<" "<<resc;
    return 0;
}