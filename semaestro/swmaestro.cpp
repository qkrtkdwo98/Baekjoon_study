#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0;
	string n;
	cin >> n;
	stack<int> s;
	int x = 0;
	for (int i = 0; i < ((n / 2)-1); i++) {
		s.push(1);
	}
	if ((n % 2) == 0) {
		s.push(1);
	}
	else {
		s.push(7);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
		
	
	return 0;
}