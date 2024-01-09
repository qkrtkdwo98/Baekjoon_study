#include <iostream>


using namespace std;

int N;

int map[16][16];
bool isused[16];   // 열
bool isused1[31];  // 우상향 대각선
bool isused2[31];   // 우하향 대각선
int ans;

void func(int num) {
    if (num == N) {
        ans++;
        return;
    }

    for (int j = 0; j < N; j++) {
        if (isused[j] == false && isused1[num+j] == false && isused2[num-j + N -1] == false) {
            isused[j] = true;
            isused1[num + j] = true;
            isused2[num - j + N - 1] = true;
            func(num + 1);
            isused[j] = false;
            isused1[num + j] = false;
            isused2[num - j + N - 1] = false;
        }
    }
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    func(0);
    cout << ans;

    return 0;
}