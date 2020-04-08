#include <iostream>

using namespace std;

void main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			if (num % 2 == 1) {
				sum += num;
			}
		}
		cout << "#" << t << " "<< sum << endl;
		
	}
}