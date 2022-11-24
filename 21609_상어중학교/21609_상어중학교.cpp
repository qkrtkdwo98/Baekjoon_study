#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[21][21];
int area[21][21][401];
bool check[21][21];
int rainbow[401];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

typedef struct {
    int x;
    int y;
}xy;

queue <xy> q;
int N = 0, M = 0;

void gravity() {
    int cnt = 0;
    while (1) {
        cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] >= 0) {
                    int nx = i + dx[2];
                    int ny = j + dy[2];
                    if (nx <= N && nx > 0 && ny <= N && ny > 0 && map[nx][ny] == -2) {
                        map[nx][ny] = map[i][j];
                        map[i][j] = -2;
                        cnt++;
                    } 
                }
            }
        }
        if (cnt == 0) {
            break;
        }
    }
}

void turn_left() {
    int change_map[21][21];
    memset(change_map, 0, sizeof(change_map));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            change_map[i][j] = map[j][N - i + 1];
        }
    }
    memcpy(map, change_map, sizeof(map));
}

int main() {
    
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int cnt = 0; // 지역구분
    int count = 0; // 지역인자수
    int max_count = 0;
    int max_cnt = 0;
    int color = 0;
    int point = 0;
    int rainbow_cnt = 0;
    
    while (1) {
        cnt = 0;
        max_count = 0;
        max_cnt = 0;
        
        memset(check, false, sizeof(check));
        memset(area, 0, sizeof(area));
        memset(rainbow, 0, sizeof(rainbow));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (check[i][j] == false && map[i][j] > 0) {
                    cnt += 1;
                    rainbow_cnt = 0;
                    q.push({i,j});
                    color = map[i][j];
                    check[i][j] = true;
                }
                count = 0;
                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();
                    area[x][y][cnt] = cnt;
                    count += 1;

                    for (int l = 0; l < 4; l++) {
                        int nx = x + dx[l];
                        int ny = y + dy[l];
                        if (nx <= N && nx > 0 && ny <= N && ny > 0 &&
                            check[nx][ny] == false && (map[nx][ny] == color || map[nx][ny] == 0)) {
                            q.push({ nx, ny });
                            check[nx][ny] = true;
                            if (map[nx][ny] == 0) {
                                rainbow_cnt += 1;
                            }
                        }
                    }
                }
                rainbow[cnt] = rainbow_cnt;
                for (int a = 1; a <= N; a++) {
                    for (int b = 1; b <= N; b++) {
                        if (map[a][b] == 0) {
                            check[a][b] = false;
                        }
                    }
                }
                if (count >= max_count) {
                    if (count == max_count) {
                        if (rainbow[cnt] >= rainbow[max_cnt]) {
                            max_count = count;
                            max_cnt = cnt;
                        }
                    }
                    else {
                        max_count = count;
                        max_cnt = cnt;
                    }
                }
            }
        }
        if (max_count == 1) {
            break;
        }
        point += max_count * max_count;
        int check_count = 0;
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if (area[a][b][max_cnt] == max_cnt) {
                    map[a][b] = -2;
                    check_count++;
                }     
            }
        }
        if (check_count >= (N * N))
            break;
        gravity();
        turn_left();
        gravity();
    }
    printf("%d", point);

    return 0;
}