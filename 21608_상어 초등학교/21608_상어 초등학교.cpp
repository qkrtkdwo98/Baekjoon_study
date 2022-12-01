#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
    int m;
    int a;
    int b;
    int c;
    int d;
}inf;
typedef struct {
    int x;
    int y;
}xy;
bool compare(xy a, xy b)
{
    if (a.x != b.x) return a.x < b.x;
    else			return a.y < b.y;
}
/*
bool compare(xy a, xy b) // 행판별 후 열 판별 등의 경우
{
    if (a.x != b.x) return a.x < b.x; // 오름차순
    else			return a.y < b.y; // 내림차순
}
sort(v.begin(), v.end(), compare);

vector<int> v;

v.erase(unique(v.begin(), v.end()), v.end()); //같은 변수 삭제

for (auto x : v)
{
    cout << x;
}
struct pq_compare
{
    bool operator()(const xy& a, const xy& b)const
    {
        if (a.x != b.x) return a.x < b.x;
        else			return a.y < b.y;
    }
};

priority_queue<xy, vector<xy>, pq_compare> pq; // 우선순위큐 사용시
*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[21][21];
int dir[21][21];
bool check[21][21];
vector<inf> v;
vector<xy> like;
vector<xy> point;
int N = 0;

int main() {
    scanf("%d", &N);
    int m_n = 0, a_n = 0, b_n = 0, c_n = 0, d_n = 0;
    int N_max = N*N;
    for (int i = 0; i < N_max; i++) {
        scanf("%d %d %d %d %d", &m_n, &a_n, &b_n, &c_n, &d_n);
        v.push_back({m_n,a_n,b_n,c_n,d_n});
    }

    int like_max = 0;
    for (int i = 0; i < v.size(); i++) {
        like_max = 0;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                int cnt_like = 0;
                
                if (check[j][k] == false) {
                    for (int l = 0; l < 4; l++) {
                        if ((map[j + dx[l]][k + dy[l]] == v[i].a || map[j + dx[l]][k + dy[l]] == v[i].b
                            || map[j + dx[l]][k + dy[l]] == v[i].c || map[j + dx[l]][k + dy[l]] == v[i].d)
                            && j + dx[l] > 0 && j + dx[l] <= N && k + dy[l] > 0 && k + dy[l] <= N && check[j + dx[l]][k + dy[l]] == true) {
                            cnt_like++; 
                        }
                    }
                    if (cnt_like > like_max) {
                        like_max = cnt_like;
                        like.clear();
                        like.push_back({ j ,k });
                    }
                    else if (cnt_like == like_max) {
                        like_max = cnt_like;
                        like.push_back({ j ,k });
                    }
                }
            }
        }
        //printf("like.size : %d\n", like.size());
        if (like.size() > 1 || like.size() == 0) {
            int cnt_sp = 0;
            int sp_max = 0;
            if (like.size() > 1) {
                for (int o = 0; o < like.size(); o++) {
                    //printf("%d, %d\n", like[o].x, like[o].y);
                    cnt_sp = 0;
                    for (int n = 0; n < 4; n++) {
                        int nx = like[o].x + dx[n];
                        int ny = like[o].y + dy[n];
                        if (map[nx][ny] == 0 && nx > 0 && nx <= N && ny > 0 && ny <= N && check[nx][ny] == false) {
                            cnt_sp++;
                        }
                    }
                    //printf("cnt : %d\n", cnt_sp);
                    if (cnt_sp > sp_max) {
                        sp_max = cnt_sp;
                        point.clear();
                        point.push_back({ like[o].x ,like[o].y });
                    }
                    else if (cnt_sp == sp_max) {
                        sp_max = cnt_sp;
                        point.push_back({ like[o].x ,like[o].y });
                    }
                }
            }			
            else if(like.size() == 0){
                for (int p = 1; p <= N; p++) {
                    for (int o = 1; o <= N; o++) {
                        if (check[p][o] == false) {
                            cnt_sp = 0;
                            for (int n = 0; n < 4; n++) {
                                int nx = p + dx[n];
                                int ny = o + dy[n];
                                if (map[nx][ny] == 0 && nx > 0 && nx <= N && ny > 0 && ny <= N && check[nx][ny] == false) {
                                    cnt_sp++;
                                }
                            }
                            if (cnt_sp > sp_max) {
                                sp_max = cnt_sp;
                                point.clear();
                                point.push_back({ p ,o });
                            }
                            else if (cnt_sp == sp_max) {
                                sp_max = cnt_sp;
                                point.push_back({ p ,o });
                            }
                        }
                    }
                }
            }
            
        }
        //printf("point.size : %d\n", point.size());
        if (point.size() > 1) {
            sort(point.begin(), point.end(), compare);
        }
        
        if (like.size() == 1) {
            map[like.front().x][like.front().y] = v[i].m;
            check[like.front().x][like.front().y] = true;
            dir[like.front().x][like.front().y] = i;
        }
        else if (point.size() >= 1) {
            map[point.front().x][point.front().y] = v[i].m;
            check[point.front().x][point.front().y] = true;
            dir[point.front().x][point.front().y] = i;
        }
        
        like.clear();
        point.clear();
        /*for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                printf("%2d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if ((map[nx][ny] == v[dir[i][j]].a || map[nx][ny] == v[dir[i][j]].b ||
                    map[nx][ny] == v[dir[i][j]].c || map[nx][ny] == v[dir[i][j]].d)
                    && nx <= N && nx > 0 && ny <= N && ny > 0 ) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                ans += 0;
            }
            else if (cnt == 1) {
                ans += 1;
            }
            else if (cnt == 2) {
                ans += 10;
            }
            else if (cnt == 3) {
                ans += 100;
            }
            else if (cnt == 4) {
                ans += 1000;
            }
        }
    }
    printf("%d", ans);

    return 0;
}