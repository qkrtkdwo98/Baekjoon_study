#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int map[50][50];
int num[50][50];
bool check[50][50];
bool check_ch[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int cnt;
int pre_ans;
int ans = 101;
typedef struct {
    int x;
    int y;
}xy;

queue <xy> q;
vector <xy> vi;

int main() {
    int N = 0, M = 0;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                vi.push_back({ i,j });
                //check[i][j] = true;
            }
            else if (map[i][j] == 1) {
                check[i][j] = true;
            }
        }
    }

    vector<bool> temp(vi.size(), false);
    for (int i = 0; i < M; i++) {
        temp[i] = true;
    }
    do {
        memset(check_ch, false, sizeof(check_ch));
        memcpy(check_ch, check, sizeof(check));
        for (int l = 0; l < temp.size(); l++) {
            if (temp[l]) {
                q.push({ vi[l].x, vi[l].y });
                check_ch[vi[l].x][vi[l].y] = true;
            }
        }
        memset(num, 0, sizeof(num));
        
        cnt = 0;
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            for (int m = 0; m < 4; m++) {
                int nx = x + dx[m];
                int ny = y + dy[m];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] != 1 && check_ch[nx][ny] == false) {
                    check_ch[nx][ny] = true;
                    num[nx][ny] = num[x][y] + 1;
                    q.push({ nx,ny });
                }

            }
        }

        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                if (num[a][b] == 0 && map[a][b] == 0) {
                    cnt = -1;
                }
                if (num[a][b] > cnt && cnt != -1) {
                    cnt = num[a][b];
                }
            }
        }

        if (ans > cnt || ans == -1) {
            if (cnt == -1) {
                if(ans > 0)
                    pre_ans = ans;
                ans = -1;
            }
            else if(cnt != -1){
                if (pre_ans != 0) {
                    if (pre_ans > cnt)
                        ans = cnt;
                    else if (pre_ans < cnt)
                        ans = pre_ans;
                    pre_ans = 0;
                }
                else {
                    ans = cnt;
                }
            }
        }        
    } while (prev_permutation(temp.begin(), temp.end()));
    if (pre_ans != 0 && pre_ans != 101)
        ans = pre_ans;
    printf("%d", ans);

    return 0;
}