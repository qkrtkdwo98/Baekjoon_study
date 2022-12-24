#include <iostream>
#include <vector>
#include <cstring>

/*



*/
using namespace std;

typedef struct {
    int x;
    int y;
}xy;
int map[101][101];
bool check[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int dx_sq[3] = { 1,0,1 };
int dy_sq[3] = { 0,1,1 };

vector<int> v;
vector<xy> pt;

int main() {
    int N = 0;
    scanf("%d", &N);
    memset(check, false, sizeof(check));
    for (int i = 0; i < N; i++) {
        int x = 0, y = 0, d = 0, g = 0;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        map[x][y] = 1;
        v.push_back(d);
        if (check[x][y] == false) {
            pt.push_back({ x,y });
            check[x][y] = true;
        }
        for (int j = 0; j <= g; j++) {
            int cnt = v.size();
            while (cnt--) {
                int dir = v[cnt];
                if (j == 0) {
                    
                }
                else {
                    dir++;
                    if (dir > 3)
                        dir = 0;
                }
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100) {
                    map[nx][ny] = 1;
                    if (check[nx][ny] == false) {
                        pt.push_back({ nx,ny });
                        check[nx][ny] = true;
                    }
                }
                x = nx;
                y = ny;
                if (j > 0) {
                    v.push_back(dir);
                }
            }
        }
        v.clear();
    }
    int ans = 0;
    
    for (int i = 0; i < pt.size(); i++) {
        int cnt = 0;
        int x = pt[i].x;
        int y = pt[i].y;
        for (int j = 0; j < 3; j++) {
            int nx = x + dx_sq[j];
            int ny = y + dy_sq[j];
            if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100 && map[nx][ny] == 1) {
                cnt++;
            }
        }
        if (cnt == 3) {
            ans += 1;
            
        }
        cnt = 0;
    }
    printf("%d", ans);

    return 0;
}