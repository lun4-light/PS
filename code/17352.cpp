#define _LUNAR

/* 

[BOJ] 17352 : 여러분의 다리가 되어드리겠습니다

연결 그래프에서 간선이 하나 제거된 그래프가 있다고 하자.
그 그래프에 어떠한 간선을 하나 추가하여 다시 연결 그래프가 되도록 하려면 어떻게 해야 할까?

*/

#include <bits/stdc++.h> 

using namespace std;

bool vis[300001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifdef _LUNAR
        freopen("_run/in.txt", "r", stdin), freopen("_run/out.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> v(n + 1);
    
    if (n == 2) {
        cout << "1 2\n";
        return 0;
    }

    while (n > 2) {
        int cur, dest;
        cin >> cur >> dest;
        v[cur].push_back(dest);
        v[dest].push_back(cur);
        n--;
    }

    priority_queue<int> pq;

    pq.push(1);

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (vis[cur])
            continue;

        vis[cur] = true;

        for (int i = 0; i < v[cur].size(); i++) {
            pq.push(v[cur][i]);
        }
    }

    int t = 2;

    while (t < v.size()) {
        if (!vis[t]) {
            cout << "1 " << t;
            break;
        }

        t++;
    }

    return 0;
}