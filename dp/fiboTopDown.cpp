#include <iostream>
using namespace std;
long long cache[100];

int fibo(int x){
    if(x==1||x==2) return 1;
    if(cache[x]!=0) return cache[x];
    cache[x]=fibo(x-1)+fibo(x-2);
    return cache[x];
}

int main(){
    cout << fibo(40);
}