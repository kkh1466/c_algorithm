//2*n 타일링
#include <iostream>
#include <algorithm>
using namespace std;

int d[1000];
int n;

int main(){
    cin >> n;
    d[1]=1;
    d[2]=2;
    for(int i=3; i<=n; i++){
        d[i]=d[i-1]+d[i-2];
    }
    cout << d[n] << endl;
    return 0;
}