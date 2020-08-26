#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
	int answer = 0;	
	sort(routes.begin(), routes.end(), cmp);
	int index = routes[0][1];
	answer++;
	for (int i = 1; i < routes.size(); i++) {
		if (index < routes[i][0]) {
			index = routes[i][1];
			answer++;
		}
	}
	return answer;
}
int main() {
	int n = 4;
	vector<vector<int>> routes = { {-20, 15},{-14, -5},{-18, -13},{-5, -3} };

	cout << solution(routes);
	system("pause");
	return 0;
}