#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board[10][10];
    int piece[4][4];

    while (cin >> board[0][0]) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i == 0 && j == 0) continue;
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> piece[i][j];
            }
        }

        int total_ways = 0;

        for (int r = -3; r < 10; ++r) {
            for (int c = -3; c < 10; ++c) {
                
                bool can_place = true;

                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if (piece[i][j] == 1) {
                            int target_row = r + i;
                            int target_col = c + j;

                            if (target_row < 0 || target_row >= 10 || target_col < 0 || target_col >= 10) {
                                can_place = false;
                                break;
                            }
                            if (board[target_row][target_col] == 1) {
                                can_place = false;
                                break;
                            }
                        }
                    }
                    if (!can_place) break;
                }

                if (can_place) {
                    total_ways++;
                }
            }
        }

        cout << total_ways << "\n";
    }

    return 0;
}
