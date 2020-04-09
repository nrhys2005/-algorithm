#include <iostream>
#include <vector>
#include<cstring>

using namespace std;

int N;
int map[12][12];
bool visited[12][12];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
vector<pair<int, int> > cores;
int core_num;
int line;

void go(int startidx, int line_len, int core_cnt) {
	if (startidx == (int)cores.size()) {
		if (core_cnt > core_num) {
			core_num = core_cnt;
			line = line_len;
		}
		else if (core_cnt == core_num && line_len < line) {
			line = line_len;
		}
		return;
	}

	int x = cores[startidx].first;
	int y = cores[startidx].second;

	int temp[12][12];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			temp[i][j] = visited[i][j];

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		bool linechk = true;
		int temp_len = 0;
		while (1) {
			if (0 > nx || nx >= N || 0 > ny || ny >= N) break;
			if (map[nx][ny] == 1 || visited[nx][ny] == true) {
				linechk = false; break;
			}
			visited[nx][ny] = true;
			nx += dx[i];
			ny += dy[i];
			++temp_len;
		}
		if (linechk) {
			go(startidx + 1, line_len + temp_len, core_cnt + 1);
		}

		if (temp_len > 0) {
			for (int k = 0; k < N; ++k)
				for (int h = 0; h < N; ++h)
					visited[k][h] = temp[k][h];
		}

	}
	go(startidx + 1, line_len, core_cnt);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 1 &&
					(0 < i && i < N - 1 && 0 < j && j < N - 1)) {
					cores.emplace_back(make_pair(i, j));
				}
			}
		}
		go(0, 0, 0);
		cout << "#" << t << " " << line << endl;

		core_num = 0;
		line = 0;
		for (int i = 0; i < 12; i++) {
			memset(map[i], 0, sizeof(int) * 12); //모든 값 0으로 초기화
		}
		for (int i = 0; i < 12; i++) {
			memset(visited[i], 0, sizeof(int) * 12); //모든 값 0으로 초기화
		}
		cores.clear();
	}

	return 0;
}


