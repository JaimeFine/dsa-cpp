#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int h[505][505];
int dp[505][505];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    
    int max_len = 1;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && h[nx][ny] <= h[x][y]) {
            max_len = max(max_len, 1 + dfs(nx, ny));
        }
    }
    
    return dp[x][y] = max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> n >> m)) return 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
