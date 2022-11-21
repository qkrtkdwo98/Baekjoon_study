#include <iostream>
#include <queue>
/*
BFS와 비슷한 방식구현 시도
queue를 이용해 로봇위 위치를 갱신하고 조건을 부여
왼쪽으로 돌아서 이동했을 시 조건에 주의( 3번조건과 겹치지 않게 할 것)
계산을 줄이기 위해 방향을 dx,dy와 일치시킴
*/

using namespace std;
int map[50][50];
int checkmap[50][50];
bool check[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
typedef struct {
    int x;
    int y;
    int z;
}xyz;
queue <xyz> q;

int main() {
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);
    int r = 0, c = 0, d = 0;
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                check[i][j] = true;
        }
    }
    q.push({ r,c,d });
    int ans = 0;
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        if (check[x][y] == false) {
            ans += 1;
            check[x][y] = true;
            checkmap[x][y] = 2;
        }
        
        int nd = z;
        for (int i = 0; i < 4; i++) {
            nd--;
            if (nd < 0)
                nd = 3;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (map[nx][ny] == 0 && check[nx][ny] == false) {
                cnt = 1;
                q.push({ nx, ny, nd });
                break;
            }
        }
        if (cnt != 1) {
            int nz = z;
            for (int j = 0; j < 2; j++) {
                nz++;
                if (nz > 3)
                    nz = 0;
            }
            if (map[x + dx[nz]][y + dy[nz]] == 0) {
                q.push({ x + dx[nz],y + dy[nz],z });
            }
        }
        else if (cnt == 1)
            cnt = 0;
    }

    printf("%d", ans);
    return 0;
}