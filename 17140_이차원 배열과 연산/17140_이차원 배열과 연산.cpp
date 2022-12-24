#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    int num;
    int cnt;
}nc;

int map[101][101];
int cnt[101]; 
bool check[101];
int max_r = 3;
int max_c = 3;
int max_rn = 0;
int max_cn = 0;
int ans = 0;
vector<nc> v;
queue<int> q;

bool compare(nc a, nc b) {
    if (a.cnt != b.cnt) return a.cnt < b.cnt;
    else                return a.num < b.num;
}

int main() {
    int r = 0, c = 0, k = 0;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    while (map[r][c]!=k) {
        if (ans >= 100)
            break;
        ans++;
        if (max_r >= max_c) {
            for (int i = 1; i <= max_r; i++) {
                v.clear();
                memset(check, false, sizeof(check));
                memset(cnt, 0, sizeof(cnt));
                for (int j = 1; j <= max_c; j++) {
                    cnt[map[i][j]] += 1;

                    if (check[map[i][j]] == false) {
                        check[map[i][j]] = true;
                        q.push(map[i][j]);
                    }
                    map[i][j] = 0;
                }
                while (!q.empty()) {
                    if (q.front() != 0) {
                        v.push_back({ q.front(), cnt[q.front()] });
                    }
                    q.pop();
                }
                sort(v.begin(), v.end(), compare);
                int temp = v.size();
                if (temp > 50)
                    temp = 50;
                for (int k = 0; k < temp; k++) {
                    map[i][2 * k + 1] = v[k].num;
                    map[i][2 * k + 2] = v[k].cnt;
                }
                if ((temp * 2) > max_cn) {
                    max_cn = v.size() * 2;
                }
            }
            max_c = max_cn;
            max_cn = 0;
        }
        else if (max_r < max_c) {
            for (int i = 1; i <= max_c; i++) {
                v.clear();
                memset(check, false, sizeof(check));
                memset(cnt, 0, sizeof(cnt));
                for (int j = 1; j <= max_r; j++) {
                    cnt[map[j][i]] += 1;

                    if (check[map[j][i]] == false) {
                        check[map[j][i]] = true;
                        q.push(map[j][i]);
                    }
                    map[j][i] = 0;
                }
                while (!q.empty()) {
                    if (q.front() != 0) {
                        v.push_back({ q.front(), cnt[q.front()] });
                    }
                    q.pop();
                }
                sort(v.begin(), v.end(), compare);
                int temp = v.size();
                if (temp > 50)
                    temp = 50;
                for (int k = 0; k < temp; k++) {
                    map[2 * k + 1][i] = v[k].num;
                    map[2 * k + 2][i] = v[k].cnt;
                }
                if ((temp * 2) > max_rn) {
                    max_rn = v.size() * 2;
                }
            }
            max_r = max_rn;
            max_rn = 0;
        }
        /*for (int a = 1; a <= 100; a++) {
            for (int b = 1; b <= 100; b++) {
                printf("%2d", map[a][b]);
            }
            printf("\n");
        }
        printf("\n");*/
    }
    if (map[r][c] == k) {
        printf("%d", ans);
    }
    else if (map[r][c] != k) {
        printf("%d", -1);
    }
    return 0;
}