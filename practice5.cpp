#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
 * dir = 0 => 왼쪽
 * dir = 1 => 아래
 * dir = 2 => 오른쪽
 * dir = 3 => 위쪽
 */

const int START = 1000;
const int ALPHA = -1;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

struct Tornado {
    int x, y;
    int dir;

    Tornado(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};

std::tuple<int, int, int> arr[4][9] = {
        {
                {0,  1, 1},
                {0, -1, 1},
                {-1, 1,  7},
                {-1, 2,  2},
                {-2, 1,  10},
                {-3, 0,  5},
                {-2, -1, 10},
                {-1, -1, 7},
                {-1, -2, 2}
        },
        {
                {-1, 0, 1},
                {1, 0,  1},
                {-2, 1,  2},
                {-1, 1,  7},
                {1,  1,  7},
                {2,  1,  2},
                {-1, 2,  10},
                {1,  2,  10},
                {0,  3,  5}
        },
        {
                {0,  1, 1},
                {0, -1, 1},
                {1,  1,  7},
                {1,  2,  2},
                {2,  1,  10},
                {3,  0,  5},
                {2,  -1, 10},
                {1,  -1, 7},
                {1,  -2, 2}
        },
        {
                {-1, 0, 1},
                {1, 0,  1},
                {-2, -1, 2},
                {-1, -1, 7},
                {1,  -1, 7},
                {2,  -1, 2},
                {-1, -2, 10},
                {1,  -2, 10},
                {0,  -3, 5}
        }
};

std::tuple<int, int> offset[4]{
        {0,  -1},
        {1, 0},
        {0,  1},
        {-1,  0}
};


int main() {
    int N;
    std::cin >> N;

    int sand[500][500];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> sand[i][j];

    Tornado pos = *new Tornado(N / 2, N / 2, 0);

    int cnt = 1;
    int ans = 0;

    while (pos.x != 0 && pos.y != 0) {

        for (int repeat = 0; repeat < (cnt + 1) / 2; repeat++) {
            int x = pos.x, y = pos.y;

            int tot = 0;

            auto &[xoff, yoff] = offset[pos.dir];

            for (int i = 0; i < 9; i++) {
                auto &[b, a, c] = arr[pos.dir][i];

                a = y + a, b = x + b;

				if (a < 0 || a >= N || b < 0 || b >= N) {
                    ans += sand[x + xoff][y + yoff] * c / 100;
                    tot += sand[x + xoff][y + yoff] * c / 100;
                    continue;
                }

                sand[a][b] += sand[x + xoff][y + yoff] * c / 100;
                tot += sand[x + xoff][y + yoff] * c / 100;
            }

            if (x + xoff * 2 >= 0 && x + xoff * 2 < N && y + yoff * 2 >= 0 && y + yoff * 2 < N)
                sand[x + xoff * 2][y + yoff * 2] += sand[x + xoff][y + yoff] - tot;
            else ans += sand[x + xoff][y + yoff] - tot;

            sand[x + xoff][y + yoff] = 0;

            switch (pos.dir) {
                case 0:
                    pos.x--;
                    break;
                case 1:
                    pos.y++;
                    break;
                case 2:
                    pos.x++;
                    break;
                case 3:
                    pos.y--;
                    break;
            }
        }

        cnt++;
        pos.dir = (pos.dir + 1) % 4;
    }

    std::cout << ans;
}