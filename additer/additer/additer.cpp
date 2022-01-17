#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char> left, right;
    int n = 0;
    string s;

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++)
        left.push(s[i]);

    int cnt = 0;
    cin >> cnt;
    while (cnt--) {
        char com;
        cin >> com;
        if (com == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (com == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (com == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (com == 'P') {
            char c;
            cin >> c;
            left.push(c);
           
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout<<right.top();
        right.pop();
    }
    cout << "\n";
    return 0;
}