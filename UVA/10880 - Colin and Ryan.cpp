#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	//freopen("b.txt","rt",stdin);
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);

		vector<int> v;
	//	cout << b << "  " << a << endl;
		for (int i = 1; i * i <= a - b; i++) {
			if ((a - b) % i == 0) {
				if (i > b)
					v.push_back(i);
				if (i * i != a - b && (a - b) / i > b)
					v.push_back((a - b) / i);
			}
		}
		if(a==b)
			v.push_back(0);
		sort(v.begin(), v.end());
		printf("Case #%d:", tt++);
		for (int i = 0; i < v.size(); i++)
			printf(" %d", v[i]);
		puts("");
	}
	return 0;
}

