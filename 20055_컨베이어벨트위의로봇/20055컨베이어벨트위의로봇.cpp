#include <iostream>
#include <vector>
#include <queue>
/*
������, �κ���ġ, �κ���ġ Ȯ���� ���� ������ �����ϴµ� �κ� ��ġ�� ������ ���� ������ �κ��� �����Ƿ� vector�� �̿��� ������ �����Ѵ�. 
���� N�� �����Ͽ� �����ؾ��ϴ� ����  ������ ���� �� �����Ѵ�.
�κ� ��ġ Ȯ���� �׻� �����Ѵ�. ��������� false�� �Ѵ�.
*/
using namespace std;
int dur[201];
bool check[201];

vector <int> v;
queue <int> q;

int main() {
    int N = 0, K = 0;
    scanf("%d %d",&N, &K);
    int max_n = 2 * N;
    for (int i = 1; i <= max_n; i++) {
        scanf("%d",&dur[i]);
    }
    int ans = 0;
    int cnt = 0;
    while (1) {
        cnt++;
        int num = dur[max_n];
        for (int i = max_n; i > 1; i--) {
            dur[i] = dur[i - 1];
        }
        dur[1] = num;
        
        for (int j = 0; j < v.size(); j++) {
            check[v[j]] = false;
            v[j] += 1;
            check[v[j]] = true;
            if (v[j] >= N) {
                check[v[j]] = false;
                v[j] = 0;
                q.push(j);
            }
        }
        while (!q.empty()) {
            v.erase(v.begin() + q.front());
            q.pop();
        }
        for (int i =  0; i < v.size(); i++) {
            if (dur[v[i] + 1] > 0 && check[v[i]+1] == false && (v[i]+1 ) <= N ) {
                check[v[i]] = false;
                v[i] += 1;
                check[v[i]] = true;
                dur[v[i]] -= 1;
                if (v[i] >= N) {
                    check[v[i]] = false;
                    v[i] = 0;
                    q.push(i);
                }
            }
        }
        while (!q.empty()) {
            v.erase(v.begin() + q.front());
            q.pop();
        }

        if (dur[1] > 0) {
            v.push_back(1);
            dur[1] -= 1;
        }
        ans = 0;
        for (int i = 1; i <= max_n; i++) {
            if (dur[i] == 0)
                ans++;
        }
        if (ans >= K)
            break;
    }
    printf("%d", cnt);
    return 0;
}