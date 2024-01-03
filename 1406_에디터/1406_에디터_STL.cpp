#include <iostream>
#include <list>
#include <string>

using namespace std;
int point;
list<char> ll;
list<char>::iterator iter = ll.end();
list<char>::iterator cnt;

void moveLeft() {
    if (iter == ll.begin())
        return;
    iter--;
}

void moveRight() {
    if (iter == ll.end())
        return;
    iter++;
}

void delNode() {
    if (iter == ll.begin())
        return;
    iter--;
    ll.erase(iter++);
}

void addLeft(char s) {
    ll.insert(iter, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        ll.push_back(str[i]);
    }
    iter = ll.end();
    int M = 0;
    cin >> M;
    for (int j = 0; j < M; j++) {
        char S = 0, s = 0;
        cin >> S;
        if (S == 'L') {
            moveLeft();
        }
        else if (S == 'D') {
            moveRight();
        }
        else if (S == 'B') {
            delNode();
        }
        else {
            cin >> s;
            addLeft(s);
        }
    }
    for (cnt = ll.begin(); cnt != ll.end(); cnt++) {
        cout << *cnt;
    }
    cout << endl;

    return 0;
}