#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
const int sz=5e3;
int n,arr[sz],idx,ans1,ans2,ans3;
ll temp,mn=3e9+1;
bool flag;
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    cin>>n;
    for(int i=0;i<n;++i)cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n-2;++i){
        for(int j=i+2;j<n;++j){
            temp=0-(arr[i]+arr[j]);
            idx=lower_bound(arr+i+1,arr+j-1,temp)-arr;
            if(idx>i+1 && abs(arr[idx-1]-temp)<abs(arr[idx]-temp))idx--;
            temp=arr[idx]-temp;
            if(abs(temp)<mn){
                mn=abs(temp);
                ans1=arr[i],ans2=arr[idx],ans3=arr[j];
            }
            if(!abs(temp)){
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    return 0;
}