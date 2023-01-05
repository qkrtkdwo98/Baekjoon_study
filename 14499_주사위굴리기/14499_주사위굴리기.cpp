#include <iostream>
#include <vector>

/*
쓸데없이 너무 어렵게 생각함...
위치는 단순히 주사위의 위치를 생각하기위해 정해준것
매 굴림마다 변한다고 생각하면 편함

예를들어 1이 영원히 같은 자리가 아니라 항상 주사위를 굴릴때 위 방향이 1이라고 생각하고
동, 서, 남 북 방향으로 굴릴때 변화를 확인하자.

vector의 초기화는 이전값을 현재값에 넣는것이 가능 쓸데없이 배열에서 for문 쓸필요 없고 vector로 바로 선언하자.
*/
using namespace std;
int map[20][20];
int N, M, x_f, y_f, K;

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};


vector<int> dice(7); 
vector<int> v;

int diceroll(int dir) {
    if (dir == 1) {  // 동
        dice = { 0, dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] }; // 위, 북, 동, 서, 남, 아래
    }
    else if (dir == 2) {  // 서
        dice = { 0, dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] }; // 위, 북, 동, 서, 남, 아래
    }
    else if (dir == 3) {  // 북
        dice = { 0, dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] }; // 위, 북, 동, 서, 남, 아래
    }
    else if (dir == 4) {  // 남
        dice = { 0, dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] }; // 위, 북, 동, 서, 남, 아래
    }
    return 0;
}

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
        int next = v[i];
        int nx = x + dx[next];
        int ny = y + dy[next];
        if (nx < N && nx >= 0 && ny < M && ny >= 0) {
            diceroll(next);
            if (map[nx][ny] == 0) {
                map[nx][ny] = dice[6];
            }
            else {
                dice[6] = map[nx][ny];
                map[nx][ny] = 0;
            }
            printf("%d\n", dice[1]);
            x = nx;
            y = ny;
        }
    }
    return 0;
}