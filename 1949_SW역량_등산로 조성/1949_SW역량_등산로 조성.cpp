/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;
int map[8][8];
int map1[8][8];
int T, N, K;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
typedef struct {
    int x;
    int y;
}xy;
int cnt = 1;
int max_cnt = 0;
vector <xy> v;
int dfs(int x, int y) {
    //printf("%d, %d, %d\n", x, y, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map1[nx][ny] < map1[x][y]) {
                cnt += 1;
                dfs(nx, ny);
            }
        }
    }
    if (max_cnt < cnt)
        max_cnt = cnt;
    cnt -= 1;
    return 0;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
       ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
       //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
       freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
       ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
       freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
       ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {

        scanf("%d %d", &N, &K);
        int high_num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &map[i][j]);
                if (high_num < map[i][j]) {
                    high_num = map[i][j];
                    v.erase(v.begin(), v.end());
                    v.push_back({ i,j });
                }
                else if (high_num == map[i][j]) {
                    v.push_back({ i,j });
                }

            }
        }
        int x = 0, y = 0;
        for (int i = 0; i < v.size(); i++) {
            x = v[i].x;
            y = v[i].y;

            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    for (int c = 0; c <= K; c++) {
                        memcpy(map1, map, sizeof(map));
                        map1[a][b] -= c;
                        cnt = 1;
                        dfs(x, y);
                    }
                }
            }
        }
        printf("#%d %d", test_case, max_cnt);
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}