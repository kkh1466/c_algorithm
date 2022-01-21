// 회전초밥
// 1. 첫 번째 스시부터 K개의 스시를 덱에 집어넣고 종류를 샘
// 2. N - 1번 반복문을 돌리면서 맨 앞에 있는 스시를 빼고 다음 스시를 덱에 집어넣음
//  2.1 뺀 스시의 종류가 덱에 더 이상 없을 경우 cnt를 뺌.
//  2.2 집어 넣은 스시의 종류가 기존 덱에 존재하지 않았을 경우 cnt를 더해줌
//  2.3 덱에 쿠폰으로 제공되는 스시의 종류가 없을 경우 cnt를 하나 더해줌
// 3. 1, 2번에서 구한 값들 중 최대를 출력
// 회전초밥집이기 때문에 더해주는 스시 인덱스를 (i+K)%N으로 해주는 것이 핵심
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX = 3000000;

int N, D, K, C;
int result;
int sushi[MAX];
int sushiKind[3000 + 1] = { 0 };

deque<int> dq;

int main(void){
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        cin >> N >> D >> K >> C;

        for (int i = 0; i < N; i++)
                 cin >> sushi[i];

        int cnt = 0;
        //첫 번째 스시부터 K개 덱에 넣고 종류 센다
        for (int i = 0; i < K; i++){
            dq.push_back(sushi[i]);
            sushiKind[sushi[i]]++;
            if (!sushiKind[sushi[i]]) cnt++;
            result = max(result, cnt);
        }

        for(int i=0; i<50; i++){
            cout<<i<<" : "<<sushiKind[i]<<endl;
        }

        //슬라이딩 윈도우 기법
        for (int i = 0; i < N - 1; i++){
            //맨 앞 스시를 빼고
            dq.pop_front();
            //해당 스시의 종류가 덱에 없을 경우 cnt를 뺀다
            if (!(--sushiKind[sushi[i]]))
                cnt--;
            //다음 스시를 덱에 넣는다
            dq.push_back(sushi[(i + K) % N]);

            //새로운 종류라면 cnt를 더해준다
            if (!(sushiKind[sushi[(i + K) % N]])++)
                cnt++;

            //덱에 쿠폰 스시가 없다면
            if (!sushiKind[C])
                result = max(result, cnt + 1);

            //덱에 쿠폰 스시가 있다면
            else
                result = max(result, cnt);
        }

        cout << result << "\n";
        return 0;
}



