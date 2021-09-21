// 지우개 
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<=n; i++) v.push_back(i);
    while(v.size()!=2){
        for(int i=v.size()-1; i>0; i--){
            if(i%2 == 1) v.erase(v.begin()+i);
        } 
    }
    cout << v[1];
}