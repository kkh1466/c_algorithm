#include <iostream>
using namespace std;

int nj(int n){
    if (n==1) return 1;
    return n+nj(n-1);
}

int main(){
    cout<<nj(5);
}