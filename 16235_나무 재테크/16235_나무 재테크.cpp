/*
힘들게 꼬아서 풀지말고 직관적으로 풀자
괜히 어렵게 하려다가 이상해지고 엉킨다.
봄, 여름, 가을, 예비봄 의 큐를 만들어서 좌표를 저장하였고 배열을 vector로 선언하여 뒤에 계속적으로 넣게 하였다.
vector erase를 할때는 상항 범위를 조심하고 최대값과 현재값을 하나씩 줄이는 방향으로 큰 무리없이 처리가 가능하다.
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
    int x;
    int y;
}xy;
typedef struct {
    int a;
    int b;
    int c;
}abc;
vector<int> map[11][11];
int food[11][11] = {5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5 };
int a[11][11];
bool check[11][11];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int N, M, K;
queue <xy> sp;
queue <xy> spn;
queue <abc> su;
queue <abc> at;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        int xf = 0;
        int yf = 0;
        int agef = 0;
        scanf("%d %d %d", &xf, &yf, &agef);
        if (map[xf][yf].size() == 0)
            sp.push({ xf,yf });
        map[xf][yf].push_back(agef);
    }

    while (K--) {
        memset(check, false, sizeof(check));
        while (!sp.empty()) {
            int x = sp.front().x;
            int y = sp.front().y;
            sp.pop();
            sort(map[x][y].begin(),map[x][y].end());
            int cnt = map[x][y].size();
            for (int i = 0; i < cnt; i++) {
                if (food[x][y] >= map[x][y][i]) {
                    food[x][y] -= map[x][y][i];
                    map[x][y][i]++;
                    if (map[x][y][i] % 5 == 0) {
                        at.push({ x,y,map[x][y][i]});
                        if (check[x][y] == false) {
                            check[x][y] = true;
                            spn.push({ x,y });
                        }
                    }
                    else if (check[x][y] == false) {
                        spn.push({ x,y });
                        check[x][y] = true;
                    }
                }
                else {
                    su.push({ x,y,map[x][y][i] });
                    map[x][y].erase(map[x][y].begin() + i);
                    cnt--;
                    i--;
                }
            }
        }

        while (!su.empty()) {
            int x = su.front().a;
            int y = su.front().b;
            int z = su.front().c;
            food[x][y] += z / 2;
            su.pop();
        }

        while (!at.empty()) {
            int x = at.front().a;
            int y = at.front().b;
            int z = at.front().c;
            at.pop();
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    map[nx][ny].push_back(1);
                    if (check[nx][ny] == false) {
                        sp.push({ nx,ny });
                        check[nx][ny] = true;
                    }
                }
            }
        }

        while (!spn.empty()) {
            sp.push({ spn.front().x,spn.front().y });
            spn.pop();
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                food[i][j] += a[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += map[i][j].size();
        }
    }
    printf("%d", ans);
    
    return 0;
}