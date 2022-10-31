#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int map[51][51];
int num[51][51];
bool check[51][51];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct {
    int x;
    int y;
}xy;

queue <xy> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    for (int c = 0; c < N; c++) {
        for(int r = 0; r< N;r++){
            cin >> map[r][c];
        }
    }
    int ans = 0;
    int point = 0;
    int s_point = 0;
    while (1) {
        memset(num, 0, sizeof(num));
        memset(check, false, sizeof(check));
        point = 0;
        
        for (int b = 0; b < N; b++) {
            for (int a = 0; a < N; a++) {
                if (check[a][b] == false) {
                    q.push({ a,b });
                    check[a][b] = true;
                }
                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    check[x][y] = true;
                    q.pop();					
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (L <= abs(map[nx][ny] - map[x][y]) && abs(map[nx][ny] - map[x][y]) <= R && check[nx][ny] == false && nx < N && nx >=0 && ny < N && ny >=0 && num[nx][ny] == 0 ) {
                            q.push({ nx, ny });
                            num[x][y] = 1;
                            num[nx][ny] = 1;
                            point = 1;
                            s_point = 1;
                        }
                    }
                }
                int result = 0;
                int cnt = 0;
                if (s_point == 1) {
                    for (int c = 0; c < N; c++) {
                        for (int r = 0; r < N; r++) {
                            if (num[r][c] == 1) {
                                result += map[r][c];
                                num[r][c] = 2;
                                cnt++;
                            }
                        }
                    }
                    if (point == 1 && cnt > 0) {
                        int people = result / cnt;
                        for (int c = 0; c < N; c++) {
                            for (int r = 0; r < N; r++) {
                                if (num[r][c] == 2) {
                                    map[r][c] = people;
                                    num[r][c] = 3;
                                }
                            }
                        }
                    }
                    s_point = 0;
                }
            }
        }
        if (point == 1) {
            ans++;
            point = 0;
        }
        else
            break;
    }
    cout << ans;
    return 0;
}