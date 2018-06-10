#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int v[111*2+1];
int main() {
	//freopen("input","rt",stdin);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n * 2 + 1; i++)
		cin >> v[i];
	while (x) {
		for (int i = 1; i < n*2 && x; i++)
			if (v[i - 1] + 1 < v[i] && v[i] > v[i + 1] + 1) {
				v[i]--;
				x--;
			}
	}
	for (int i = 0; i < n * 2 + 1; i++)
		printf("%d ", v[i]);
	return 0;
}

