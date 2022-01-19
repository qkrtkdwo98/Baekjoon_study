#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cin.ignore();
	int flag = 0;
	string S;
	getline(cin, S);
	
	S += '\n';
	deque<char> dq;
	for (char ch : S) {
		if ((ch == ' ' || ch == '\n' ||ch =='<')&&flag==0) {
			while (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}
			if (ch == '<')
				flag = 1;
			cout << ch;
		}
		else if (ch == '<' || flag == 1) {
			//cout << "check";
			//flag = 1;
			cout << ch;
			if (ch == '>')
				flag = 0;
		}
		else {
			dq.push_front(ch);
		}
	}
	return 0;
}