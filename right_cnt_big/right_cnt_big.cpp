#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(1000000);
    vector<int> ngf(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(i);
        }
        while (!s.empty() && f[a[s.top()]] < f[a[i]]) {
            ngf[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        ngf[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ngf[i] << ' ';
    }
    return 0;
}