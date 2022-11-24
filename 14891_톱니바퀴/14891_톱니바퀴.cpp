#include <iostream>
#include <queue>
#include <cstring>

/*
��Ϲ��� ������ �迭�� ����, �� ��Ϲ����� �´��� ��ϵ��� ������ ���� ����
BFS�������� �� ��Ϲ������� ����� ��Ϲ����� ��Ȳ�� äũ�ϸ鼭 ���ÿ� turn�Լ��� ���� ����� ������.
������ �¹��� �ִٸ� ���� ������ �ݴ� �����̹Ƿ� (-)��ȣ�� ���� ���� ����
���� �� ��Ϲ����� 1, 4�� ��Ϲ����� queue�� ���� �ʵ��� ��ġ �ʿ�
*/
using namespace std;
int wheel[5][8];
int flag[3];
int dirnum[5];
bool check[5];
int dx[2] = { -1, 1 };
queue<int> q;

void turn(int N, int dir) {
    if (dir == 1) {
        int num = 0;
        num = wheel[N][7];
        for (int i = 0; i < 7; i++) {
            wheel[N][7 - i] = wheel[N][6 - i];
        }
        wheel[N][0] = num;
    }
    else if (dir == -1) {
        int num = 0;
        num = wheel[N][0];
        for (int i = 0; i < 7; i++) {
            wheel[N][i] = wheel[N][i + 1];
        }
        wheel[N][7] = num;
    }
}

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &wheel[i][j]);
        }
    }
    int K = 0;
    scanf("%d", &K);
    while (K--) {
        int N = 0, dir = 0;
        memset(check, false, sizeof(check));
        memset(dirnum, 0, sizeof(dirnum));
        scanf("%d %d", &N, &dir);
        for (int i = 1; i < 4; i++) {
            if (wheel[i][2] != wheel[i + 1][6]) {
                flag[i-1] = 1;
            }
            else if (wheel[i][2] == wheel[i + 1][6]) {
                flag[i-1] = 0;
            }
        }
        dirnum[N] = dir;
        turn(N, dir);
        q.push(N);
        check[N] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                if (nx > 0 && nx <= 4 && check[nx]==false) {
                    if (i == 0) {
                        if (flag[nx - 1] == 1) {
                            if(nx != 1)
                                q.push(nx);
                            dirnum[nx] = -dirnum[x];
                            turn(nx, dirnum[nx]);
                            check[nx] = true;
                        }
                    }
                    else if (i == 1) {
                        if (flag[nx - 2] == 1) {
                            if(nx != 4)
                                q.push(nx);
                            dirnum[nx] = -dirnum[x];
                            turn(nx, dirnum[nx]);
                            check[nx] = true;
                        }
                    }
                }
            }
        }
    }
    int point = 0;
    point = wheel[1][0] * 1 + wheel[2][0] * 2 + wheel[3][0] * 4 + wheel[4][0] * 8;
    printf("%d", point);

    return 0;
}