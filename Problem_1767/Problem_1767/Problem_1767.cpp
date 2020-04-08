#include <iostream>

using namespace std;
int** map;
int N;
int core = 0;
int line = 0;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		
		map = new int*[N];
		for (int i = 0; i < N; ++i)
			map[i] = new int[N];
		for (int i = 0; i < N; i++) {
			memset(map[i], 0, sizeof(int) * N); //모든 값 0으로 초기화
		}
		for (int y = 0; y< N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}
		
	}


	return 0;
}
void ar() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 1) {
				if (y == 0 || x == 0) {
					core++;
					map[y][x] = -1;
					continue;
				}
				else {
					
					if (checkx(x, y)) {

					}
				}
			}
		}
	}
}
void linex(int x, int y) {
	for (int i = 0; i < x; i++) {
		map[y][i] = 2;
	}
}
void liney(int x, int y) {
	for (int i = 0; i < y; i++) {
	}
}
bool checkx(int x, int y) {
	for (int i = 0; i < x; i++) {
		if (map[y][i] != 0) {
			return true;
		}
	}
	return false;
}
bool checky(int x,int y) {
	for (int i = 0; i < y; i++) {
		if (map[i][x] != 0) {
			return true;
		}
	}
	return false;
}