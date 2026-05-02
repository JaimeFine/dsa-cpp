#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n;
	if (cin >> n) {
		while (n--) {
			vector<int> a(4);
			vector<int> b(4);

			for (int i = 0; i < 4; ++i) cin >> a[i];
			for (int i = 0; i < 4; ++i) cin >> b[i];

			int s;
			cin >> s;

			int max_a = *max_element(a.begin(), a.end());
			int max_b = *max_element(b.begin(), b.end());

			int team_power = max_a + max_b;

			int required_x = s - team_power;

			if (required_x <= 30) {
				printf("3.0\n");
			} else if (required_x > 160) {
				cout << "Sad" << endl;
			} else {
				double score = required_x * 0.1;
				printf("%.1f\n", score);
			}
		}
	}
	return 0;
}

