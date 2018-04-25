#include <iostream>
#include<stdio.h>
#include<string>
#include <cstring>
#include<stack>
#include<algorithm>
#include<queue>
#include<set>
#include<string.h>
using namespace std;
char s[1555], a[33], tmp[1555];
int k, res = 0, c;
vector<vector<int> > v;
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%s%s%d", &s, &a, &k);
	vector<int> r(26, -1);
	v.push_back(r);
	int l = strlen(s);
	for (int ii = 0; ii < l; ii++) {
		c = k;
		int cur = 0;
		for (int j = 0, g = 0; j < l - ii; j++, g++) {
			tmp[g] = s[j + ii];
			if (a[tmp[g] - 'a'] == '0' && c) {
				c--;
			} else if (a[tmp[g] - 'a'] == '0')
				break;
			if (v[cur][tmp[g] - 'a'] == -1) {
				res++;
				vector<int> r(26, -1);
				v.push_back(r);
				v[cur][tmp[g] - 'a'] = v.size() - 1;
			}
			cur = v[cur][tmp[g] - 'a'];

		}
	}
	printf("%d\n", res);

	return 0;

}

