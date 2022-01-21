#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

long long result=0,x=1;

int main(){
    string cipher;
    int a=0;
    cin>>cipher;
    stack <long long> reverse;
    vector <int> cipher1;
    vector <int> aski;
    for(int i=0;i<cipher.size();i+=7)
    {
        for(int p=i;p<i+7;p++)
        {
            reverse.push(cipher[p]-'0');
        }
        while(!reverse.empty()){
            cout<<reverse.top();
            reverse.pop();
        }

        // for(int p=0;p<7;p++)  // 굳이 p를 어렵게 할 필요 없음
        // {
        //     cipher1.push_back(reverse.top());
        //     reverse.pop();
        // }
    }

    // for(auto &i : cipher1) cout<<i;

    /*
    for(int i=0;i<cipher.size();i+=7)
    {
        aski.push_back(cipher1[i]);
    }
    for(int i=0;i<cipher.size();i+=7)
    {
        for(int p=i+6;p>=i;p++)
        {
            if(aski[p]==1)
            {
                result+=x;
            }
            x=x*2;
        }
        cout<<(char)result;
        result=0;
        x=1;
    }
    */
}