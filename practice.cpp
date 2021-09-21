#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

struct town{
    int population;
    int pos;
    town(int a, int b){
        population=a;
        pos=b;
    }
};

bool custom(town a, town b){
    return a.pos<b.pos;
}

vector<town> t;
vector<int> question;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;

    for(int i=0; i<n; i++){
        int a,b;
        cin >>a>>b;
        t.push_back(town(a,b));
    }

    for(int i=0; i<q; i++){
        int q;
        cin>>q;
        question.push_back(q);
        t.push_back(town(0,q));
    }

    sort(t.begin(), t.end(), custom);


    //cout<<"\n";
    for(int i=0; i<question.size();i++){
        int x=0, sum=0, result=0;
        while(1){
            if(question[i]==t[x].pos) break;
            sum+=t[x].population;
            result+=sum*(t[x+1].pos-t[x].pos);
            x++;
        }   


        int y=n+q-1;
        sum=0;
        while(1){
            if(question[i]==t[y].pos) break;
            sum+=t[y].population;
            result+=sum*(t[y].pos-t[y-1].pos);
            y--;
        } 
        cout<<result<<"\n";
    }  
}