#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define MAX_N 51
using namespace std;

int map[MAX_N][MAX_N];
int sum_dust[MAX_N][MAX_N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

typedef struct {
    int x;
    int y;
}xy;
vector <xy> v;
int main() {
    int r, c, t = 0;
    scanf("%d %d %d", &r, &c, &t);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1)
                v.push_back({ i,j });
        }
    }
    while (t--) {
        int cur_dust = 0;
        int sp_dust = 0;
        int next_dust = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int cnt = 0;
                if (map[i][j] > 0) {
                    cur_dust = map[i][j];
                    sp_dust = cur_dust / 5;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx > 0 && ny > 0 && nx <= r && ny <= c && map[nx][ny] >= 0) {
                            sum_dust[nx][ny] += sp_dust;
                            cnt += 1;
                        }
                    }
                    map[i][j] = cur_dust - (sp_dust * cnt);
                }
            }
        }
        for (int l = 1; l <= r; l++) {
            for (int m = 1; m <= c; m++) {
                if (sum_dust[l][m] > 0) {
                    map[l][m] += sum_dust[l][m];
                }
            }
        }
        memset(sum_dust, 0, sizeof(sum_dust));
        
        for (int i = 0; i < 2; i++) {
            int order1 = 0;
            int x = v[i].x;
            int y = v[i].y;
            if ((y - 1) == 0 && i ==0) {
                x -= 1;
                order1 = 1;
            }
            else if ((y - 1) == 0 && i == 1) {
                x += 1;
                order1 = 1;
            }
            else {
                y -= 1;
            }
            if (i == 0)
                while (1) {
                    if ((y-1) == 0 && x == v[i].x) {
                        order1 = 1;
                    }
                    else if ((x - 1) == 0 && order1 == 1) {
                        order1 = 2;
                    }
                    else if ((y + 1) == c+1 && order1 == 2) {
                        order1 = 3;
                    }
                    else if ((x + 1) > v[i].x && order1 == 3) {
                        order1 = 0;
                    }
                    else if ((y - 1) == v[i].y && x == v[i].x) {
                        break;
                    }
                    if (order1 == 0) {
                        map[x][y] = map[x][y - 1];
                        map[x][y - 1] = 0;
                        y -= 1;
                    }
                    else if (order1 == 1) {
                        map[x][y] = map[x-1][y];
                        map[x - 1][y] = 0;
                        x -= 1;
                    }
                    else if (order1 == 2) {
                        map[x][y] = map[x][y + 1];
                        map[x][y + 1] = 0;
                        y += 1;
                    }
                    else if (order1 == 3) {
                        map[x][y] = map[x+1][y];
                        map[x + 1][y] = 0;
                        x += 1;
                    }
                }
            else
                while (1) {
                    if ((y - 1) == 0 && x == v[i].x && order1 == 0) {
                        order1 = 1;
                    }
                    else if ((x +1) == r+1 && order1 == 1) {
                        order1 = 2;
                    }
                    else if ((y + 1) == c+1 && order1 == 2) {
                        order1 = 3;
                    }
                    else if ((x - 1) < v[i].x && order1 == 3) {
                        order1 = 0;
                    }
                    else if ((y - 1) == v[i].y && x == v[i].x) {
                        break;
                    }
                    if (order1 == 0) {
                        map[x][y] = map[x][y - 1];
                        map[x][y - 1] = 0;
                        y -= 1;
                    }
                    else if (order1 == 1) {
                        map[x][y] = map[x + 1][y];
                        map[x + 1][y] = 0;
                        x += 1;
                    }
                    else if (order1 == 2) {
                        map[x][y] = map[x][y + 1];
                        map[x][y + 1] = 0;
                        y += 1;
                    }
                    else if (order1 == 3) {
                        map[x][y] = map[x - 1][y];
                        map[x - 1][y] = 0;
                        x -= 1;
                    }
                }
        }
    }
    int sum = 0;
    for (int i = 1; i <= r; i++) 
        for (int j = 1; j <= c; j++) 
            if (map[i][j] > 0) 
                sum += map[i][j];

    printf("%d",sum);

    return 0;
}