#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int map[51][51];
int N, M, K;

typedef struct {
    int m;
    int s;
    int d;
}inf;

vector <inf> v[51][51];
vector <inf> v1[51][51];

int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int r_n = 0, c_n = 0, m_n = 0, d_n = 0, s_n = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d",&r_n,&c_n,&m_n,&s_n,&d_n);
        v[r_n][c_n].push_back({m_n,s_n,d_n });
        map[r_n][c_n]++;
    }

    while (K--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < v[i][j].size(); k++) {
                    map[i][j]--;
                    int nr = i + v[i][j][k].s * dr[v[i][j][k].d];
                    int nc = j + v[i][j][k].s * dc[v[i][j][k].d];
                    if (nr > N) {
                        nr = nr % N;
                    }
                    if (nc > N) {
                        nc = nc % N;
                    }
                    if (nr < 1) {
                        nr = (-((-nr) % N)) + N;
                    }
                    if (nc < 1) {
                        nc = (-((-nc) % N)) + N;
                    }
                    map[nr][nc]++;
                    v1[nr][nc].push_back({v[i][j][k].m,v[i][j][k].s,v[i][j][k].d });
                }
                v[i][j].clear();
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (v1[i][j].size() > 1) {
                    int sum_m = 0;
                    int sum_s = 0;
                    int sum_d = 0;
                    int cnt = v1[i][j].size();
                    int cnt_odd = 0;
                    int cnt_even = 0;
                    for (int k = 0; k < v1[i][j].size(); k++) {
                        cnt = v1[i][j].size();
                        map[i][j] = 0;
                        sum_m += v1[i][j][k].m;
                        sum_s += v1[i][j][k].s;
                        if (v1[i][j][k].d % 2 == 0) {
                            cnt_even++;
                        }
                        else if (v1[i][j][k].d % 2 != 0) {
                            cnt_odd++;
                        }
                    }
                    v1[i][j].clear();
                    if (cnt_even == 0 || cnt_odd == 0) {
                        if (sum_m / 5 > 0) {
                            for (int l = 0; l < 4; l++) {
                                v[i][j].push_back({ sum_m / 5,sum_s / cnt,l * 2 });
                            }
                            map[i][j] = 4;
                        }
                    }
                    else {
                        if (sum_m / 5 > 0) {
                            for (int l = 0; l < 4; l++) {
                                v[i][j].push_back({ sum_m / 5,sum_s / cnt,((l * 2) + 1) });
                            }
                            map[i][j] = 4;
                        }
                    }
                }
                else if (v1[i][j].size() == 1) {
                    v[i][j].push_back({ v1[i][j][0].m,v1[i][j][0].s,v1[i][j][0].d });
                    v1[i][j].clear();
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                
                ans += v[i][j][k].m;
            }
        }
    }
    printf("%d", ans);

    return 0;
}												 