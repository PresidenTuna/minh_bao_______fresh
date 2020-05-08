#include <iostream>
#include <vector>
#include <string>
using namespace std;

void in_mang(vector<vector<int>>data2) {
	for (int i = 0; i < data2.size(); i++) {
		for (int j = 0; j < data2[i].size(); j++) {
			if (data2[i][j] != 0) cout << "O";
			else cout << ".";
		}
		cout << endl;
	}
}

void fill(vector<vector<int>>&data2, int t) {
	for (int i = 0; i < data2.size(); i++) {
		for (int j = 0; j < data2[0].size(); j++) {
			if (data2[i][j] == 0) {
				data2[i][j] = t + 3;
			}
		}
	}
}

void clean(vector<vector<int>>&data2, int t) {
	vector<vector<int>>data3 = data2;
	for (int i = 0; i < data2.size(); i++) {
		for (int j = 0; j < data2[i].size(); j++) {
			if (data2[i][j] == t) {
				data3[i][j] = 0;
				if (i - 1 >= 0) data3[i-1][j] = 0;
				if (j - 1 >= 0) data3[i][j - 1] = 0;
				if (i + 1 < data2.size()) data3[i + 1][j] = 0;
				if (j + 1 < data2[i].size()) data3[i][j + 1] = 0;
			}
		}
	}
	data2 = data3;
}

int main() {
	int r, c, n;
	cin >> r >> c >> n;
	vector<string>data1(r);
	vector<vector<int>>data2(r, vector<int>(c));
	int i, j;
	for (i = 0; i < r; i++) {
		cin >> data1[i];
	}
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (data1[i][j] == 'O') data2[i][j] = 3;
			else data2[i][j] = 0;
		}
	}
	cout << endl<<"t= " << 1 << endl;
	in_mang(data2);
	cout << endl;
	int t = 2;
	while (t <= n) {
		fill(data2, t);
		clean(data2, t);
		cout << "t= " << t << endl;
		in_mang(data2);
		cout << endl;
		t++;
	}
}