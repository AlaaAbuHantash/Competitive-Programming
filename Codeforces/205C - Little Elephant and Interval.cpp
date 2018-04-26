#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };


int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("myfile.txt", "w", stdout);
	string a, b;
	cin >> a >> b;

	int lenb = b.length();
	int lena = a.length();
	if (lena == lenb){
		if (lena == 1){
			cout << b[0] - a[0] + 1 << endl;
			return 0;
		}
		long long res = 0;

		int x;
		x = b[0] - '0';
		if (b[0] <= b[lenb - 1]){
			string tmp = b.substr(1, lenb - 2);
			if (tmp.size() == 0)
				tmp = "0";
	
			long long  tmp_nub = 0;
			for (int i = 0; i < tmp.size(); i++)
				tmp_nub = tmp_nub * 10 + (tmp[i] - '0');

			res += tmp_nub;
			
			res++;
			x--;
		}
		else if (b[lenb - 1] < b[0]){
			bool f = 0;
			for (int i = lenb - 2; i >= 1; i--){
				if (b[i] != '0'){
					f = 1;
					b[i]--;
					break;
				}
				else
					b[i] = '9';
			}

			if (f){
				string tmp = b.substr(1, lenb - 2);
				if (tmp.size() == 0)
					tmp = "0";
				
				long long  tmp_nub = 0;
				for (int i = 0; i < tmp.size(); i++)
					tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
				res += tmp_nub;
				res++;
			}
			x--;
		}
		
		if (x >= 1){
			long long nub2 = 1;
			for (int i = 1; i < lenb - 1; i++)
				nub2 *= 10;
		
			res += x*nub2;
		}
		
		
		long long  aa = 0;
		for (int i = 0; i < a.size(); i++)
			aa = aa * 10 + (a[i] - '0');
		aa--;

		a = "";
		while (aa != 0){
			a = char('0' + aa % 10)+a;
			aa /= 10;
		}
		if (a.length() < lena){
			cout << res << endl; 
			return 0;
		}
		x = a[0] - '0';
		if (a[0] <= a[lena - 1]){
			string tmp = a.substr(1, lena - 2);
			if (tmp.size() == 0)
				tmp = "0";
			
			long long  tmp_nub = 0;
			for (int i = 0; i < tmp.size(); i++)
				tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
			res -= tmp_nub;
			res--;
			x--;
		}
		else if (a[lena - 1] < a[0]){
			bool f = 0;
			for (int i = lena - 2; i >= 1; i--){
				if (a[i] != '0'){
					f = 1;
					a[i]--;
					break;
				}
				else
					a[i] = '9';
			}

			if (f){
				string tmp = a.substr(1, lena - 2);
				if (tmp.size() == 0)
					tmp = "0";
			
				long long  tmp_nub = 0;
				for (int i = 0; i < tmp.size(); i++)
					tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
				res -= tmp_nub;
				res--;
			}
			x--;
		}

		
		if (x >= 1){
			long long nub2 = 1;
			for (int i = 1; i < lena - 1; i++)
				nub2 *= 10;
			res -= x*nub2;
		}
		cout << res << endl;
		
	}
	else{
		long long res = 0;
		int x;

		x = b[0] - '0';
		if (b[0]<=b[lenb-1]){
			string tmp = b.substr(1, lenb - 2);
			if (tmp.size() == 0)
				tmp = "0";
			
			long long  tmp_nub = 0;
			for (int i = 0; i < tmp.size(); i++)
				tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
			res += tmp_nub;
			res++;
			x--;
		}else if (b[lenb - 1] < b[0]){
			bool f = 0;
			for (int i = lenb - 2; i >= 1; i--){
				if (b[i] != '0'){
					f = 1;
					b[i]--;
					break;
				}
				else
					b[i] = '9';
			}
			
			if (f){
				string tmp = b.substr(1, lenb - 2);
				if (tmp.size() == 0)
					tmp = "0";
			
				long long  tmp_nub = 0;
				for (int i = 0; i < tmp.size(); i++)
					tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
				res += tmp_nub;
				res++;
			}
			x--;
		}
		
		if (x >= 1){
			long long nub2 = 1;
			for (int i = 1; i < lenb - 1; i++)
				nub2 *= 10;
			res += x*nub2;
		}
		
		lenb--;
		while (lenb != lena){
			long long nub = 1; 
			for (int i = 1; i < lenb - 1; i++)
				nub *= 10;
			res += 9 * nub;
			lenb--;
		}
		
		if (lena == 1){
			res += 10 -( a[0] - '0');
		}
		else {

			if (a[0] >= a[lena - 1]){
				string tmp = a.substr(1, lena - 2);
				
				if (tmp.size() == 0)
					tmp = "0";
				
					long long  tmp_nub=0;
					for (int i = 0; i < tmp.size(); i++)
						tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
					
					
					long long nub = 1;
					for (int i = 0; i < tmp.size(); i++)
						nub = nub * 10;
					
					if (tmp == "0")
						nub = 1;
					res += nub-tmp_nub;
				
				
				x = a[0] - '0' + 1;				
				if (x <= 9){
					x = 10 - x;
					long long nub2 = 1;
					for (int i = 1; i < lena - 1; i++)
						nub2 *= 10;
					res += x*nub2;
				}
			}
			else {
				
				x = 10 - (a[lena - 1] - '0' )+ (a[0] - '0');
				
			
				long long  aa = 0;
				for (int i = 0; i < a.size(); i++)
					aa = aa * 10 + (a[i] - '0');
				aa += x;
				string tmp2 = "";
				while (aa != 0){
					tmp2 = char('0' + aa % 10) + tmp2;
					aa /= 10;
				}
				x = 10 - (tmp2[0] - '0');
				if (tmp2[0] == a[0]){
	
					string tmp = tmp2.substr(1, lena - 2);

					if (tmp.size() == 0)
						tmp = "0";
					
				
					long long  tmp_nub = 0;
					for (int i = 0; i < tmp.size(); i++)
						tmp_nub = tmp_nub * 10 + (tmp[i] - '0');
					long long nub = 1;
					for (int i = 0; i < tmp.size(); i++)
						nub = nub * 10;
					if (tmp == "0")
						nub = 1;
					res += nub - tmp_nub;
					x--;
				}
				if (x <= 9){
					long long nub = 1;
					for (int i = 1; i < lena - 1; i++)
						nub *= 10;
					res += x*nub;
				}
				//cout << res << endl;
			}
			
		}
		cout << res << endl;
	}
}