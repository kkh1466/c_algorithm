// 신입 사원
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    int a;
    int b;
    person(int _a, int _b){
        a=_a;
        b=_b;
    }
};

bool cmp(person p1, person p2){
    return p1.a<p2.a;
}

int main(){
    cin.tie(0);
	cin.sync_with_stdio(false);
    int testcase;
    vector<person> v;
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        v.clear();
        int n;
        cin>>n;
        for(int j=0; j<n; j++){
            int a,b;
            cin>>a>>b;
            v.push_back(person(a,b));
        }

        sort(v.begin(),v.end(),cmp);
        int result=1;
        int _min=v[0].b;
        for(int k=1; k<n; k++){
            if(v[k].b<_min){
                result++;
                _min=v[k].b;
            }
        }
        cout<<result<<'\n';
    }
}