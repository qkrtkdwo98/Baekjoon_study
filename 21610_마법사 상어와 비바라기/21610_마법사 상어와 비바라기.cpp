#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int map[51][51];
bool check[51][51];
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int N, M;

typedef struct {
    int x;
    int y;
}xy;

vector <xy> m;
queue <xy> cloud;
queue <xy> w;

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        m.push_back({ a,b });
    }
    

    cloud.push({N,1});
    cloud.push({N,2});
    cloud.push({ N - 1,1 });
    cloud.push({ N - 1,2 });

    while (M--) {
        memset(check, false, sizeof(check));
        while (!cloud.empty()) {
            int x = cloud.front().x;
            int y = cloud.front().y;
            cloud.pop();
            int nx = x + m.front().y*dx[(m.front().x)-1];
            int ny = y + m.front().y*dy[(m.front().x)-1];
            if (nx <= 0) {
                nx = N - ((-nx) % N);
            }
            else if (nx > N) {
                nx = nx%N;
                if (nx == 0)
                    nx = N;
            }
            if (ny <= 0) {
                ny = N - ((-ny)%N);
            }
            else if (ny > N) {
                ny = ny%N;
                if (ny == 0) {
                    ny = N;
                }
            }
            map[nx][ny] += 1;
            w.push({ nx,ny });
            check[nx][ny] = true;
        }
        while (!w.empty()) {
            int x = w.front().x;
            int y = w.front().y;
            w.pop();
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i*2 + 1];
                int ny = y + dy[i*2 + 1];
                if (map[nx][ny] > 0 && nx <= N && nx > 0 && ny <= N && ny > 0) {
                    cnt++;
                }
            }
            map[x][y] += cnt;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++ ) {
                if (map[i][j] >= 2 && check[i][j] == false) {
                    map[i][j] -= 2;
                    cloud.push({ i,j });
                }
            }
        }
        m.erase(m.begin());
    }
    long long int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += map[i][j];
        }
    }
    printf("%lld", ans);
    return 0;
} 