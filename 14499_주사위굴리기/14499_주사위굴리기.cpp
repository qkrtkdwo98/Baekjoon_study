#include <iostream>
#include <vector>
using namespace std;
int map[20][20];
int N, M, x_f, y_f, K;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
//                    µ¿ ¼­ ºÏ ³²
int dice_dir[7][5] = {0, 0, 0, 0, 0,
                      4, 3, 5, 2, 6,
                      4, 3, 1, 6, 5,
                      1, 6, 5, 2, 4,
                      6, 1, 5, 2, 3,
                      4, 3, 6, 1, 2,
                      4, 3, 2, 5, 1};
int dice[7];

vector<int> v;

int main() {
    scanf("%d %d %d %d %d", &N, &M, &x_f, &y_f, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        int num = 0;
        scanf("%d", &num);
        v.push_back(num);
    }
    int x = x_f;
    int y = y_f;
    int dice_now = 1;
    int dice_next = 1;

    for (int i = 0; i < K; i++) {
        int next = v[i]-1;
        int nx = x + dx[next];
        int ny = y + dy[next];
        if (nx < N && nx >= 0 && ny < M && ny >= 0) {
            dice_next = dice_dir[dice_now][next];
            dice_now = dice_next;
            printf("%d\n", dice_now);
            if (map[nx][ny] == 0) {
                map[nx][ny] = dice[dice_dir[dice_now][4]];
            }
            else {
                dice[dice_dir[dice_now][4]] = map[nx][ny];
                map[nx][ny] = 0;
            }
            printf("%d\n", dice[dice_now]);
            x = nx;
            y = ny;
        }
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", map[k][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

/*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
    }*/
    return 0;
}