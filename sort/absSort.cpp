// 절대값 정렬
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int i, int j){
    if(i<0) i=-i;
    if(j<0) j=-j;
    return i<j;
}

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
}