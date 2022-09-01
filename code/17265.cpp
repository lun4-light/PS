#define _LUNAR

/* */

#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

char arr[6][6];
int max_res[6][6];
int min_res[6][6];

int calc(char c, int x, int y) {
    if (c == '+') {
        return x + y;
    }
    
    if (c == '-') {
        return x - y;
    }

    if (c == '*') {
        return x * y;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifdef _LUNAR
        freopen("_run/in.txt", "r", stdin), freopen("_run/out.txt", "w", stdout);
    #endif

    int n; cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[x][y];
            max_res[x][y] = -10000;
            min_res[x][y] = 10000;
        }
    }

    max_res[0][0] = arr[0][0] - '0';
    min_res[0][0] = arr[0][0] - '0';

    queue<pair<int,int>> q;
    
    q.push({0,0});

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;

        q.pop();

        int nx, ny, next;

        int max_cur = max_res[x][y];
        int min_cur = min_res[x][y];

        nx = x + 2; ny = y;

        if (nx < n) {
            next = arr[nx][ny] - '0';
            int max_calc = calc(arr[nx-1][ny], max_cur, next);
            int min_calc = calc(arr[nx-1][ny], min_cur, next);
            max_res[nx][ny] = max(max_res[nx][ny], max_calc);
            min_res[nx][ny] = min(min_res[nx][ny], min_calc);
            q.push({nx,ny});
        }

        nx = x; ny = y + 2;
        
        if (ny < n) {
            next = arr[nx][ny] - '0';
            int max_calc = calc(arr[nx][ny-1], max_cur, next);
            int min_calc = calc(arr[nx][ny-1], min_cur, next);

            max_res[nx][ny] = max(max_res[nx][ny], max_calc);
            min_res[nx][ny] = min(min_res[nx][ny], min_calc);
            q.push({nx,ny});
        }

        nx = x + 1; ny = y + 1;

        if (nx < n && ny < n) {
            next = arr[nx][ny] - '0';
            int right_max_calc = calc(arr[nx-1][ny], max_cur, next);
            int down_max_calc = calc(arr[nx][ny-1], max_cur, next);

            int right_min_calc = calc(arr[nx-1][ny], min_cur, next);
            int down_min_calc = calc(arr[nx][ny-1], min_cur, next);
            max_res[nx][ny] = max(max(max_res[nx][ny], right_max_calc), down_max_calc);
            min_res[nx][ny] = min(min(min_res[nx][ny], right_min_calc), down_min_calc);
            q.push({nx,ny});
        }
    }

    cout << max_res[n-1][n-1] << " " << min_res[n-1][n-1];

    return 0;
}