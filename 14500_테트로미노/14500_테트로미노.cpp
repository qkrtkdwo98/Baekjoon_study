#include <iostream>
/*
DFS�� �̿��� ��� ������ǥ���� 4ĭ�� ����� ���鼭 �˻��Ѵ�.
�� ��� �ߺ��� ���� ����� ������ �����ؾ��Ѵ�.
������ �˻��� ��� �밢������ ���� ���ڸ� Ȯ���� ���� �ֺ��� ���� �ִ��� Ȯ���ϴ� ������� üũ�Ѵ�.
������ �̹���� ������ Ȯ���ߴ� ���� �ѹ��� Ȯ���ϱ� ������ ������ ������. �׳� BF�� if���� �̿��� �����ϴ� ���� ����.
*/
using namespace std;
int map[500][500];
bool check[500][500];
int ans;
int ans_max;
int N = 0, M = 0;
int cnt = 0;
/*
int shape_dx[4][4] = { {-1, 0, 1, 0},
                       {-1,0,1,0},
                       {-1,0,1,0},
                       {-1,-1,1,1}};
int shape_dy[4][4] = { {0, -1, 0, 1},
                       {0,-1,0,1},
                       {0,-1,0,1},
                       {1,-1,1,-1}};
                       */
int shape_dx[4][4] = { {-1,0, 1, 0},
                       {-1,0,1,0},
                       {-1,0,1,0},
                       {-1,-1,1,1} };
int shape_dy[4][4] = { {0, -1, 0, 1},
                       {0,-1,0,1},
                       {0,-1,0,1},
                       {1,-1,1,-1} };
int teatro(int x, int y) {
    int flag = 0;
    if (cnt >= 3) {
        if (ans >= ans_max) {
            ans_max = ans;
        }
        return 0;
    }
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 4; j++) {
            if (i < 3 && j == 0 ) {
                j = 1;
            }
            int nx = x + shape_dx[i][j];
            int ny = y + shape_dy[i][j];
            if (nx < N && ny < M && nx >= 0 && ny >= 0 && check[nx][ny] == false) {
                if (i == 3) {
                    for (int a = 0; a < 4; a++) {
                        if (check[nx + shape_dx[0][a]][ny + shape_dy[0][a]] == true) {
                            ans += map[nx][ny];
                            cnt++;
                            check[nx][ny] = true;
                            teatro(nx, ny);
                            cnt--;
                            ans -= map[nx][ny];
                            check[nx][ny] = false;
                        }
                    }
                }
                else if (i < 3) {
                    ans += map[nx][ny];
                    cnt++;
                    check[nx][ny] = true;
                    teatro(nx, ny);
                    cnt--;
                    ans -= map[nx][ny];
                    check[nx][ny] = false;
                }
            }
            if (i == 2 && flag == 0) {
                j = 0;
                i = 3;
                flag = 1;
            }
        }
    }
    return 0;
}

int main() {
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[i][j] = true;
            ans += map[i][j];
            teatro(i, j);
            check[i][j] = false;
            ans = 0;
        }
    }
    printf("%d",ans_max);

    return 0;
}