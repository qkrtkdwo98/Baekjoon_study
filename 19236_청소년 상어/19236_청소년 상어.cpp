#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef struct {
    int x;
    int y;
}xy;

int map[4][4][2];
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int last_ans = 0;

int dfs(int x, int y, int ans) {
    int map_f[4][4][2];
    int ans_f = ans;
    ans_f += map[x][y][0];
    map[x][y][0] = 0;
    int shark_next = map[x][y][1];
    map[x][y][1] = 0;
    
    for (int i = 1; i <= 16; i++) {
        int flag = 0;
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                if (map[a][b][0] == i) {
                    flag = 1;
                    int fish_x = a;
                    int fish_y = b;
                    int fish_ord = map[fish_x][fish_y][1];

                    for (int j = 0; j < 8; j++) {
                        int fish_nx = fish_x + dx[fish_ord];
                        int fish_ny = fish_y + dy[fish_ord];

                        if (fish_nx >= 0 && fish_nx < 4 && fish_ny >= 0 && fish_ny < 4) {
                            if (fish_nx == x && fish_ny == y) {
                                fish_ord++;
                                if (fish_ord > 8)
                                    fish_ord = 1;
                            }
                            else if (map[fish_nx][fish_ny][0] >= 0) {
                                int temp1 = map[fish_x][fish_y][0];
                                map[fish_x][fish_y][0] = map[fish_nx][fish_ny][0];
                                map[fish_nx][fish_ny][0] = temp1;

                                map[fish_x][fish_y][1] = map[fish_nx][fish_ny][1];
                                map[fish_nx][fish_ny][1] = fish_ord;
                                break;
                            }
                            else {
                                fish_ord++;
                                if (fish_ord > 8)
                                    fish_ord = 1;
                            }
                        }
                        else {
                            fish_ord++;
                            if (fish_ord > 8)
                                fish_ord = 1;
                        }
                    }
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    }

    queue<xy> q;
    for (int i = 1; i <= 4; i++) {
        int nx = x + i * dx[shark_next];
        int ny = y + i * dy[shark_next];
        if ( nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
            if (map[nx][ny][0] > 0) {
                q.push({ nx,ny });
            }
        }
    }
    while (!q.empty()) {
        int shark_x = q.front().x;
        int shark_y = q.front().y;
        memcpy(map_f, map, sizeof(map));
        dfs(shark_x, shark_y, ans_f);
        memcpy(map, map_f, sizeof(map_f));
        q.pop();
    }

    if (ans_f > last_ans) {
        last_ans = ans_f;
    }
    return 0;
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                scanf("%d",&map[i][j][k]);
            }
        }
    }
    int x = 0;
    int y = 0;
    dfs(x, y,0);

    printf("%d\n", last_ans);

    return 0;
}