// 수 이어가기
#include <iostream>
using namespace std;
int main() 
{
  int a[10000]={0},b[100000]={0},n,i,j,max=0,w;
  cin>>n;
  for(i=n/2;i<=n;i++)
  {
    j=2;
    b[1]=n;
    b[2]=i;
    while(b[j]>=0)
    {
      j++;
      b[j]=b[j-2]-b[j-1];
      if(b[j]<0)
      {
        j=j-1;
        break;
      }
    }
    if(max<j)
    {
      max=j;
      for(j=1;j<=max;j++)
      {
        a[j]=b[j];
      }
    }
  }
  cout<<max<<"\n";
  for(i=1;i<=max;i++)
  {
    cout<<a[i]<<" ";
  }
}