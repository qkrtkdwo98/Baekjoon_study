#include <iostream>
#include <vector>

/*
�������� �ʹ� ��ư� ������...
��ġ�� �ܼ��� �ֻ����� ��ġ�� �����ϱ����� �����ذ�
�� �������� ���Ѵٰ� �����ϸ� ����

������� 1�� ������ ���� �ڸ��� �ƴ϶� �׻� �ֻ����� ������ �� ������ 1�̶�� �����ϰ�
��, ��, �� �� �������� ������ ��ȭ�� Ȯ������.

vector�� �ʱ�ȭ�� �������� ���簪�� �ִ°��� ���� �������� �迭���� for�� ���ʿ� ���� vector�� �ٷ� ��������.
*/
using namespace std;
int map[20][20];
int N, M, x_f, y_f, K;

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};


vector<int> dice(7); 
vector<int> v;

int diceroll(int dir) {
    if (dir == 1) {  // ��
        dice = { 0, dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] }; // ��, ��, ��, ��, ��, �Ʒ�
    }
    else if (dir == 2) {  // ��
        dice = { 0, dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] }; // ��, ��, ��, ��, ��, �Ʒ�
    }
    else if (dir == 3) {  // ��
        dice = { 0, dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] }; // ��, ��, ��, ��, ��, �Ʒ�
    }
    else if (dir == 4) {  // ��
        dice = { 0, dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] }; // ��, ��, ��, ��, ��, �Ʒ�
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