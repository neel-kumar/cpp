#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> apps, rooms;
    for(int i = 0; i < n; i++) {
        int app; cin >> app;
        apps.push_back(app);
    }
    for(int i = 0; i < m; i++) {
        int room; cin >> room;
        rooms.push_back(room);
    }

    sort(rooms.begin(), rooms.end());
    sort(apps.begin(), apps.end());

    int ri = 0, ai = 0, ans = 0;
    while(ri < m && ai < n) {
        //cout << rooms[ri] << " " << apps[ai] << " " << ans << "\n";
        if(rooms[ri] <= apps[ai]+k && rooms[ri] >= apps[ai]-k) {
            ans++;
            ai++;
            ri++;
        } else if(rooms[ri] > apps[ai]+k) ai++;
        else ri++;
    }

    cout << ans << "\n";

    return 0;
}
