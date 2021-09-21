// 카드
#include<iostream>
#include<algorithm>
using namespace std;
long long card[1000000];
int main()
{
	int n;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);
	//세기위한 변수, 갯수를 비교하기위한변수
	int cnt = 1, max = 0, index = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (card[i] == card[i + 1])
		{
			cnt++;
			if (cnt > max)
			{
				max = cnt;
				index = i;
			}
		}
		else
			//0이아닌 1로초기화!
			cnt = 1;
	}
	cout << card[index] << '\n';
	
}