#include <iostream>

using namespace std;

long long A, B, C;
long long ans;
long long multi(long long a, long long b) {
	if (b == 1) return a%C;
	long long val = multi(a,b/2);
	val = val * val%C;
	if (b % 2 != 0) return val * a%C;
	return val;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long ansl;
	cin >> A >> B >> C;
	
	cout << multi(A,B);
	return 0;
}