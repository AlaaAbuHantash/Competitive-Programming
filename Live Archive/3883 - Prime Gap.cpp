#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int x;
const int N = 4000000;
int isPrime[N * 2];
vector<int> v;
void getPrime() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;

	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = 0;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			v.push_back(i);
	}
}

int main() {
	//freopen("a.txt", "r", stdin);
	getPrime();
	while (scanf("%d", &x) && x) {
		if (isPrime[x]) {
			puts("0");
			continue;
		}
		int pos = upper_bound(v.begin(), v.end(), x) - v.begin();
		//cout << x << " " << v[pos - 1] << " " << v[pos] << endl;
		printf("%d\n", v[pos] - v[pos - 1]);

	}

}

