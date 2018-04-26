#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int N = 10000000;
bool isprime[N+2];
 
void prime() {

	memset(isprime, true, sizeof(isprime));
	
	isprime[0] = isprime[1] = false;
	for (int i = 2; i*i<= N; i++)
		if (isprime[i]){
			for (int j = i * i; j <= N; j += i)
				isprime[j] = false;
		}

}
int main() {
	//freopen("test.txt", "rt", stdin);
	prime();
	int n; 
	while (cin >> n && n){
		vector<int > r; 
		int tmp = n; 
		int res = 0; 
		for (int i = 1; i*i <= n; i++){
			if (n%i == 0){
		
				if (isprime[i]){
					while (tmp%i == 0){
						tmp /= i;
						r.push_back(i);
					}
				}
				int x = n / i; 
				if (isprime[x]){
					while (tmp%x == 0){
						tmp /= x;
						r.push_back(x);
					}
				}
				res++;
			}
		}
		sort(r.begin(), r.end());
		printf("%d = %d", n, r[0]);
		for (int i = 1; i < r.size(); i++)
			printf(" * %d", r[i]);
		printf("\nWith %d marbles, %d different rectangles can be constructed.\n", n, res);
	}
	return 0;
}