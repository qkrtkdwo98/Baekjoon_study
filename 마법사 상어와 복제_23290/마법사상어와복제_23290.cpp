#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int M, S, fx, fy, sx, sy, d;
int shark[5][5];  // 0 : 상어없음, 1 : 물고기 냄새, 2 : 물고기 냄새, 3 : 상어있음
int smell[5][5];
int smell_ans[5][5];
int map[5][5][9];
int map_ch[5][5][9];
int map_ans[5][5][9];


int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int snx[4] = { -1, 0, 1, 0 };
int sny[4] = { 0, -1, 0, 1 };
int max_fish;
int fish;
int cnt;


typedef struct {
    int x;
    int y;
}xy;
//vector <int> map[5][5];
//vector <int> map_ch[5][5];
//vector <int> fish;
queue <xy> q;

int shark_num(int x, int y) {
    int smell_c[5][5];
    int map_c[5][5][9];
    cnt++;
    if (cnt >= 4) {
        if (max_fish < fish) {
            memcpy(map_ans, map_ch, sizeof(map_ch));
            memcpy(smell_ans, smell, sizeof(smell));
            memset(shark, 0, sizeof(shark));
            shark[x][y] = 1;
            sx = x;
            sy = y;
            max_fish = fish;
        }
        cnt--;
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + snx[i];
        int ny = y + sny[i];
        if (nx > 0 && nx < 5 && ny > 0 && ny < 5) {
            memcpy(map_c, map_ch, sizeof(map_ch));
            memcpy(smell_c, smell, sizeof(smell));
            if (map_ch[nx][ny][0] > 0) {
                fish += map_ch[nx][ny][0];
                smell[nx][ny] = 2;
                for (int l = 0; l < 9; l++) {
                    map_ch[nx][ny][l] = 0;
                }
            }
            shark_num(nx,ny);
            memcpy(map_ch, map_c, sizeof(map_c));
            memcpy(smell, smell_c, sizeof(smell_c));
            if (map_ch[nx][ny][0] > 0) {
                fish -= map_ch[nx][ny][0];
            }
        }
    }
    cnt--;
    return 0;
}

int main() {
    scanf("%d %d",&M, &S);
    while (M--) {
        scanf("%d %d %d", &fx, &fy, &d);
        map[fx][fy][d]++;
        map[fx][fy][0]++;
    }
    scanf("%d %d", &sx, &sy);
    shark[sx][sy] = 1;

    memcpy(map_ans, map, sizeof(map));
    while (S--) {
        memset(map_ch, 0, sizeof(map_ch));
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                for (int m = 1; m < 9; m++) {
                    if (map_ans[k][l][m]>0) {
                        int i = m;
                        for (int j = 0; j < 8; j++) {
                            int nx = k + dx[i];
                            int ny = l + dy[i];
                            if (nx > 0 && nx < 5 && ny > 0 && ny < 5 && shark[nx][ny] == 0 && smell[nx][ny] == 0) {
                                map_ch[nx][ny][i] = map_ans[k][l][m];
                                map_ch[nx][ny][0] += map_ch[nx][ny][i];
                                break;
                            }
                            i--;
                            if (i == 0) {
                                i = 8;
                            }
                        }
                    }
                }
            }
        }
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                if (smell[k][l] > 0) {
                    if (smell[k][l] == 2)
                        smell[k][l] = 1;
                    else if (smell[k][l] == 1)
                        smell[k][l] = 0;
                }
            }
        }

        printf("pre\n");
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                printf("%d ", map_ch[k][l][0]);
            }
            printf("\n");
        }
        printf("\n");
        printf("pre_shark\n");
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                printf("%d ", shark[k][l]);
            }
            printf("\n");
        }
        printf("\n");

        max_fish = 0;
        fish = 0;
        cnt = 0;
       
        shark_num(sx, sy);
        memcpy(smell, smell_ans, sizeof(smell_ans));
        memset(smell_ans, 0, sizeof(smell_ans));
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                if (map[k][l][0] > 0) {
                    for (int m = 0; m < 9; m++) {
                        map_ans[k][l][m] += map[k][l][m];
                    }
                }
            }
        }
        memcpy(map, map_ans, sizeof(map_ans));
        printf("map_ans\n");
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                printf("%d ", map_ans[k][l][0]);
            }
            printf("\n");
        }
        printf("\n");
        printf("shark\n");
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                printf("%d ", shark[k][l]);
            }
            printf("\n");
        }
        printf("\n");
        printf("smell\n");
        for (int k = 1; k < 5; k++) {
            for (int l = 1; l < 5; l++) {
                printf("%d ", smell[k][l]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int ans = 0;
    for (int k = 1; k < 5; k++) {
        for (int l = 1; l < 5; l++) {
            ans += map_ans[k][l][0];
        }
    }
    printf("%d",ans);
    return 0;
}