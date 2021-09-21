//1로 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int d[100000];
int n;

int main(){
    cin>>n;
    d[1]=0;
    d[2]=1;
    d[3]=1;
    for(int i=4; i<=n; i++){
        d[i]=d[i-1]+1; //1뺀 경우
        if(i%3==0) d[i]=min(d[i],d[i/3]+1);  //2로 나눠지는 경우
        if(i%2==0) d[i]=min(d[i],d[i/2]+1);  //3으로 나눠지는 경우
    }
    cout << d[n] << endl;
    return 0;
}