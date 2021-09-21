#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int n;                     //장소의 수
   int arr[100001];            //장소
   int arr2[100001];            //arr을 오름차순 정렬 -> 크기 구분
   int sum[100001];            //누적합
   int ans = 0;               //최대의 꿀의 양

   cin >> n;

   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];

      arr2[i] = arr[i];

      if (i == 0)
         sum[i] = arr[i];
      else
         sum[i] = sum[i - 1] + arr[i];
   }

   sort(arr2, arr2 + n);               //오름차순


   for (int i = 0; i < n; i++)
   {
      if (i >= 1 && i <= n - 2)         //벌꿀이 벌 사이에 있는 경우
      {
         if (arr2[n - 1] == arr[i])      //벌꿀은 가장 큰 값
         {
            ans = max(ans, sum[n - 2] - sum[0] + arr[i]);
         }
      }
   }

   int b = n - 1;
   int a = n - 2;
   int i = 0;

   while (i < a)         //벌꿀이 왼쪽에 있는 경우
   {
      ans = max(ans, sum[b - 1] - arr[a] + sum[a - 1]);
      //ans = max(ans, sum[b - 1] - sum[i] + arr[i] - arr[a] + sum[a - 1] - sum[i] + arr[i]);
      a--;
   }

   int c = 0;
   int d = 1;

   i = n - 1;

   while (d < i)         //벌꿀이 오른쪽에 있는 경우
   {
      //ans = max(ans, sum[i] - sum[c] + sum[i] - sum[d]);
      ans = max(ans, sum[i] - sum[c] + sum[i] - sum[d] - arr[d]);
      d++;
   }

   cout << ans << endl;
   return 0;
}