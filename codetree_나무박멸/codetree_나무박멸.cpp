/*
조건을 잘 확인하자. 중간에 막히는 조건은 없는지 있는지 등.
그리고 좀더 간단히 할 수 있을거 같긴함 변수 정리, 과정 간단히 할수 있다면?

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
    int x;
    int y;
} xy;

typedef struct {
    int x;
    int y;
    int bir;
}g;

typedef struct {
    int x;
    int y;
    int fire_cnt;
}ex;

int n, m, k, c;
int map[21][21];
int fire[21][21];
int flag[21][21];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dx2[4] = { -1, 1, -1, 1 };
int dy2[4] = { -1, -1, 1, 1 };

queue <xy> q;
queue <g> birth;
vector <xy> grow[21][21];
vector <ex> tree;

bool temp(ex a, ex b) {
    if (a.fire_cnt > b.fire_cnt) return true;
    else if (a.fire_cnt == b.fire_cnt) {
        if (a.x < b.x) return true;
        else if (a.x == b.x) {
            return a.y < b.y;
        }
        else return false;
    }
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;

    cin >> n >> m >> k >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0) {
                q.push({ i,j });
            }
        }
    }

    for (int cnt = 0; cnt < m; cnt++) {
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int plus_tree = 0;
            int cnt_tree = 0;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
                    if (map[nx][ny] > 0) {
                        plus_tree++;
                    }
                    else if (map[nx][ny] == 0 && fire[nx][ny] == 0) {
                        grow[x][y].push_back({ nx,ny });
                        cnt_tree++;
                    }
                }

            }
            map[x][y] += plus_tree;
            birth.push({ x,y,cnt_tree });
        }
        memset(flag, 0, sizeof(flag));
        while (!birth.empty()) {
            int x = birth.front().x;
            int y = birth.front().y;
            int bir = birth.front().bir;
            if (flag[x][y] == 0) {
                tree.push_back({ x,y,0 });
                flag[x][y] = 1;
            }
            birth.pop();
            while (!grow[x][y].empty()) {
                int nx = grow[x][y].front().x;
                int ny = grow[x][y].front().y;
                grow[x][y].erase(grow[x][y].begin());
                map[nx][ny] += map[x][y] / bir;
                if (flag[nx][ny] == 0) {
                    tree.push_back({ nx,ny,0 });
                    flag[nx][ny] = 1;
                }
            }
        }

        int max_num = tree.size();
        if (max_num != 0) {
            for (int t = 0; t < max_num; t++) {
                int x = tree[t].x;
                int y = tree[t].y;
                int fire_tree_num = 0;
                //if (map[x][y] > 0)
                fire_tree_num += map[x][y];

                for (int i = 0; i < 4; i++) {
                    for (int j = 1; j <= k; j++) {
                        int nx = x + j * dx2[i];
                        int ny = y + j * dy2[i];
                        if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
                            if (map[nx][ny] > 0 && fire[nx][ny] == 0)
                                fire_tree_num += map[nx][ny];
                            else break;
                        }

                    }
                }

                tree[t].fire_cnt = fire_tree_num;
            }

            sort(tree.begin(), tree.end(), temp);

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (fire[i][j] > 0) {
                        fire[i][j]--;
                    }
                }
            }

            map[tree[0].x][tree[0].y] = 0;
            fire[tree[0].x][tree[0].y] = c;
            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= k; j++) {
                    int nx = tree[0].x + j * dx2[i];
                    int ny = tree[0].y + j * dy2[i];
                    if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
                        if (map[nx][ny] > 0 && fire[nx][ny] == 0) {
                            map[nx][ny] = 0;
                            fire[nx][ny] = c;
                        }
                        else if (map[nx][ny] == -1) {
                            break;
                        }
                        else if (fire[nx][ny] > 0 || map[nx][ny] == 0) {
                            fire[nx][ny] = c;
                            break;
                        }
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (map[i][j] > 0) {
                        q.push({ i,j });
                    }
                    grow[i][j].clear();
                }
            }

            ans += tree[0].fire_cnt;

        }
        else break;

        tree.clear();

    }
    cout << ans << "\n";


    return 0;
}