// 비슷한 단어
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int visited1[30]{}, visited2[30]{};
    int n, cnt=0;
    cin>>n>>s;
    for(int i=0; i<s.length(); i++) visited1[s[i]-65]++;

    for(int i=0; i<n-1; i++){
        int a=0, b=0, sw=0;
        s.clear();
        fill_n(visited2,30,0);
        cin>>s;
        for(int i=0; i<s.length(); i++) visited2[s[i]-65]++;

        for(int i=0; i<30; i++){
            if(visited1[i]==visited2[i]) continue;
            else if(visited1[i]-visited2[i]==1) a++;
            else if(visited2[i]-visited1[i]==1) b++;
            else{
                sw=1;
                break;
            }
            if(a>1 || b>1){
                sw=1;
                break;
            }
        }
        
        if(sw==1) continue;
        cnt++;
    }
    std::cout<<cnt;
}