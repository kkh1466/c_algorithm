// 마법사 상어와 토네이도
#include <iostream>
#include <vector>
int N;

using namespace std;
vector<vector<int> > board;

//4방향
int dx[] = { -1, 0,1,0 };
int dy[] = { 0,1,0,-1 };

// 움직이는 모래의 정도
double per[9] = { 0.05, 0.1, 0.1, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01 };

int move_dx[4][10] = {
	{-2,-1,-1,0,0,0,0,1,1,-1},  // 서
	{0,-1,1, -2,2,-1,1,-1,1,0}, // 남
	{2,1,1,0,0,0,0,-1,-1,1},    // 동
	{0,-1,1, -2,2,-1,1,-1,1,0}  // 북
};
int move_dy[4][10] = {
	{0,-1,1, -2,2,-1,1,-1,1,0}, // 서
	{2,1,1,0,0,0,0,-1,-1,1},    // 남
	{0,-1,1, -2,2,-1,1,-1,1,0}, // 동
	{-2,-1,-1,0,0,0,0,1,1,-1}   // 북
};
int result = 0;
int cnt = 0;

void move() {
	int y = N / 2, x = N / 2; // 배열의 중간 좌표
	int a;
	int distance = 1;
	int direction = 0; // 방향 정보 ( 0 : 서, 1 : 남, 2 : 동, 3 : 북)
	int cnt = 0; // 두 번 이동 확인용 count 변수
	while (true) {
		cnt++;

		//distance만큼 direction방향으로 이동
		for (int m = 0; m < distance; m++) { 
            int nx = x + dx[direction];  // direction 방향으로 이동
			int ny = y + dy[direction];  // direction 방향으로 이동
			x = nx;
            y = ny;
			a = board[ny][nx]; // 이동한 위치의 모래의 양 
			for (int k = 0; k < 9; k++) {
                int scatter_nx = nx + move_dx[direction][k]; //흩날리는 모래 x 좌표
				int scatter_ny = ny + move_dy[direction][k]; //흩날리는 모래 y 좌표

				int sand = (int)(board[ny][nx] * per[k]); //흩날리는 모래 양
				a -= sand; // 현재위치의 모래에서 흩날린 모래의 양을 빼줌
				if (scatter_ny < 0 || scatter_ny >= N || scatter_nx < 0 || scatter_nx >= N)  // 격자 밖으로 이동한 경우 result에 흩날린 모래를 추가
					result += sand; 
				else   // 격자 안인 경우 해당 좌표에 흩날리는 모래 양 추가
					board[scatter_ny][scatter_nx] += sand; 
				
			}
			//나머지 모래 이동
            int m_nx = nx + move_dx[direction][9];
			int m_ny = ny + move_dy[direction][9]; 
			if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N) {
				result += a;
			}
			else
				board[m_ny][m_nx] += a;

			board[ny][nx] = 0; // 이동 후 모래 = 0으로 지정
			if (ny == 0 && nx == 0) //이동 후 좌표가 (0, 0)인 경우 종료
				return;
		}
		if (cnt == 2) {  
			//두 번 이동한 경우 dist+=1
			distance++;
			cnt = 0;
		}
		direction = (direction + 1) % 4; // 이동 방향을 바꿈
	}
}
int main(){
	//입력
	cin >> N;
	board = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//모래 이동
	move();

	//결과 출력
	cout << result;
}