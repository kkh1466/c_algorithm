// 효율적인 화폐 구성
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    vector<int> v;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    int d[10001]{};
    for(int i=1; i<=10000; i++) d[i]=10001;

    for(int i=0; i<n; i++){
        for(int j=v[i]; j<=m; j++){
            if(d[j-v[i]]!=10001) d[j]=min(d[j], d[j-v[i]]+1);
        }
    }

    if(d[m]==10001) cout<<-1<<endl;
    else cout<<d[m]<<endl; 
}