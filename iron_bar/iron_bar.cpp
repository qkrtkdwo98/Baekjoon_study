#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	int cnt = 0;	
	
	string bar;

	getline(cin,bar);
	deque<int> d;
	for (char ch : bar) {
		if (ch == '(') {	
			d.push_front(n);			
		}
		else{			
			if (d.front()+1 == n) {
				d.pop_front();
				cnt += d.size();
			}				
			else {
				d.pop_front();
				cnt += 1;
			}
		}
		n++;
 	}	
	cout << cnt<<'\n';
	return 0;
}