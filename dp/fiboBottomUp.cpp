#include <iostream>
using namespace std;
int d[100];

int main(){
    d[1]=1;
    d[2]=1;
    int n=40;
    for(int i=3;i<n+1;i++){
        d[i]=d[i-1]+d[i-2];
    }
    cout << d[n];
}