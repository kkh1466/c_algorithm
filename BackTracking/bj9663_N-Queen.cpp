//N-Queen
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt = 0;
int queen_loc[15];

int possible_loc(int row){
    // 입력 받은 행까지 탐색하며
    // 이전에 찾은 퀸들의 열 위치와 같은 열에 위치해 있거나, 대각선에 위치해 있다면 불가능하다고 판단
    for(int i=0; i<row; i++){
        if ((queen_loc[i] == queen_loc[row]) || ( row - i == (abs(queen_loc[row] - queen_loc[i])))){
            return 0;
        }
    }
    return 1;
}


void nqueen(int row){
    if (row == n){  // n번째 행까지 n개의 퀸을 놓는 하나의 경우의 수를 찾았다면, 함수 종료
        cnt++;
        return;
    }
    else{   // 모든 경우의 수를 찾지 못한 경우
        for (int col=0; col<n; col++){ // 현재 행에서 모든 열 검사       
            queen_loc[row] = col;      // 행 위치에 열 값을 할당
            if (possible_loc(row)){    // 현재 행, 열 위치가 퀸의 위치로 문제 없다면, 다음 행 검사
                nqueen(row + 1);
            }
            // 현재 행, 열 위치가 퀸의 위치로 문제가 있다면, 이어서 반복문 진행
        }
    }
}

int main(){
    cin>>n;    // 입력
    nqueen(0);// nqueen 알고리즘 수행 (0번째 행부터 탐색)
    cout<<cnt; // nqueen 알고리즘 수행 후, 찾은 경우의 수 반환
    return 0;
}