#include <iostream>

using namespace std;

int N;

void cal(int s, int e, int n) {
    if (n == 1) {
        cout << s << ' ' << e << '\n';
        return;
    }
    cal(s, 6 - s - e, n - 1);
    cout << s << ' ' << e << '\n';
    cal(6 - s - e, e, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << (1 << N) - 1 << '\n';
    cal(1, 3, N);
    
    return 0;
}