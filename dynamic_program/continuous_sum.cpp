/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> d(n);


	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	vector<int> s(n);

	for (int i = 0; i < n; i++) {
		s[i] = d[i];
		if (i == 0) continue;
		if(s[i]<s[i-1]+d[i])
			s[i] = s[i - 1] + d[i];
	}
	
	cout << *max_element(s.begin(), s.end()) << '\n';

	return 0;
}
*/