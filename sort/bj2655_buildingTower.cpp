// 가장 높은 탑 쌓기
// 답과 밀접하게 관련있는 주 변위는 높이이지만 비교해야 하는 변위는 넓이와 무게이므로 변수가 많아서 어렵게 느껴지는 문제
// 답에 영향을 주는 변수가 많은 경우 우리가 활용할 수 있는 가장 좋은 무기는 정렬과 변수 고정
// 이 문제의 핵심은 무게또는 넓이 중 어느 한 변수에 대해 정렬시킨 뒤 다른 변수를 통해 조건 세우는 것
// 본 코드에서는 무게에 대해 정렬시킨 뒤 넓이에 대해 조건을 세웠다. 
// 우리가 메모할 사항은 i번째 벽돌을 맨 아래에 놨을 때 세울 수 있는 최대 높이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
   int s;                     //넓이
   int h;                     //높이
   int w;                     //무게
   int idx;                   //벽돌의 번호
}Block;

int cmp(Block &a, Block &b)         
{
   return a.w < b.w;
}

int main()
{
   int n;                     //벽돌 수
   int height = 0;               //최대 높이 저장
   int dp[101] = { 0, };         //최대 누적 높이를 저장
   vector<int> ans;            //누적 높이가 가장 높은 경우의 블록의 번호 저장

   cin >> n;

   vector<Block> block(n + 1);      //벽돌에 관한 구조체

   for (int i = 1; i <= n; i++)
   {
      cin >> block[i].s >> block[i].h >> block[i].w;

      block[i].idx = i;         //벽돌 번호 저장
   }

   sort(block.begin(), block.end(), cmp);         //무게 순으로 오름차순 -> 이제 넓이, 높이만 신경쓰면 됨.

   for (int i = 1; i <= n; i++)
   {
      for (int j = 0; j < i; j++)
         if (block[i].s > block[j].s)         //무게가 무거운 블록의 넓이 > 무게가 가벼운 블록의 넓이
            dp[i] = max(dp[i], dp[j] + block[i].h);   //dp[i]에 블록 최대 누적 높이 저장

      height = max(height, dp[i]);            //최대 누적 높이 저장
   }

   while (n)
   {
      if (height == dp[n])
      {
         ans.push_back(block[n].idx);         //block[n]의 번호를 저장

         height -= block[n].h;               //block[n]의 높이만큼 뺌
      }

      n--;
   }

   cout << ans.size() << endl;

   for (int i = ans.size() - 1; i >= 0; i--)
      cout << ans[i] << endl;

   return 0;
}