/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	int index = max_element(d.begin(), d.end()) - d.begin();
	cout << *max_element(d.begin(), d.end()) << '\n';
	
	stack<int> st;
	st.push(a[index]);
	while (v[index]!=-1) {
		
		index=v[index];
		st.push(a[index]);

	}
	while (!st.empty()) {
		cout << st.top() <<' ';
		st.pop();
	}
	cout << '\n';
	return 0;
}
*/