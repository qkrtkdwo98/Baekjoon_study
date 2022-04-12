#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt[10][7] = { 1,1,1,0,1,1,1
					, 0,0,1,0,0,1,0
					, 1,0,1,1,1,0,1
					, 1,0,1,1,0,1,1
					, 0,1,1,1,0,1,0
					, 1,1,0,1,0,1,1
					, 1,1,0,1,1,1,1
					, 1,1,1,0,0,1,0
					, 1,1,1,1,1,1,1
					, 1,1,1,1,0,1,1 };
	int T;
	cin >> T;
	queue<int> q;
	for (int i = 0; i < T; i++) {
		string a, b;
		int num = 0;
		int al, bl = 0;
		cin >> a >> b;
		al = a.size();
		bl = b.size();
		int n,m = 0;
		n = al;
		m = bl;
		num = 0;
		if (al == bl) {
			while (al!=-1) {
				for (int j = 0; j < 7; j++) {
					if (cnt[a[n-1]-48][j] != cnt[b[m-1]-48][j]) {
						num++;

					}
				}
				n--;
				m--;
				al--;
			}
		}
		else if (al > bl) {
			al = al - bl;
			while (bl != 0) {
				for (int j = 0; j < 7; j++) {
					if (cnt[a[n-1]-48][j] != cnt[b[m-1]-48][j]) {
						num++;
					}
				}
				n--;
				m--;
				bl--;
			}
			while (al!=0) {
				for (int j = 0; j < 7; j++) {
					if (cnt[a[n-1]-48][j] == 1)
						num++;
				}
				n--;
				al--;
			}
		}
		else{
			bl = bl - al;
			while (al != 0) {
				for (int j = 0; j < 7; j++) {
					if (cnt[a[n-1] - 48][j] != cnt[b[m-1] - 48][j]) {
						num++;
					}
				}
				n--;
				m--;
				al--;
			}
			while (bl != 0) {
				for (int j = 0; j < 7; j++) {
					if (cnt[b[m-1] - 48][j] == 1) {
						num++;
					}
				}
				n--;
				m--;
				bl--;
			}
		}
		q.push(num);
	}
	while (T != 0) {
		cout << q.front()<<"\n";
		q.pop();
		T--;
	}
	return 0;
}