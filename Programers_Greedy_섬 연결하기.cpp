#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool con(vector<int> a, vector<int> b) {
	return a[2] > b[2];
}
int fun(int n, vector<vector<int>> costs, int start, int end, int sum, bool check[]) {
	return 0;
}
int getParent(int check[], int num) {
	if (check[num] == num)
		return num;
	else
		return getParent(check, check[num]);
}
void unionParent(int check[], int a, int b) {\
	a = getParent(check, a);
	b = getParent(check, b);
	if (a < b)
		check[b] = a;
	else
		check[a] = b;
}
int solution(int n, vector<vector<int>> costs) {
	sort(costs.begin(), costs.end(), con);
	int *check = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		check[i] = i;
	}
	for (int i = costs.size()-1; i >=0; i--) {
		if (getParent(check, costs[i][0]) != getParent(check, costs[i][1])) {
			unionParent(check, costs[i][0], costs[i][1]);
			sum += costs[i][2];
		}
	}
	
	return  sum;

}
int main() {
	int n = 4;
	vector<vector<int>> costs = { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} };

	cout << solution(4, costs);
	system("pause");
	return 0;
}