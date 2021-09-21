// 종이 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,num;
    cin>>n>>m>>num;
    vector<int> hor;
    vector<int> ver;
    for(int i=0; i<num; i++){
        int a,b;
        cin>>a>>b;
        if(a==0) hor.push_back(b);
        else ver.push_back(b);
    }
    hor.push_back(m);
    ver.push_back(n);
    sort(hor.begin(),hor.end());
    sort(ver.begin(),ver.end());

    vector<int> horlen;
    vector<int> verlen;
    horlen.push_back(hor[0]);
    verlen.push_back(ver[0]);
    for(int i=1; i<hor.size(); i++) horlen.push_back(hor[i]-hor[i-1]);
    for(int i=1; i<ver.size(); i++) verlen.push_back(ver[i]-ver[i-1]);

    sort(horlen.begin(),horlen.end());
    sort(verlen.begin(),verlen.end());
    cout << horlen[horlen.size()-1]*verlen[verlen.size()-1];
}