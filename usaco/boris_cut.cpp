#include <bits/stdc++.h>

using namespace std;

const int LIM = 200000;
int T, N, M, a[LIM], b[LIM];

int main() {

	// cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;
    while(T--) {
        // INPUT
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i];
        for(int i = 0; i < N; i++) {
            cin >> b[i];
        }
        cin >> M;
        // x.clear(); // SK:
multiset<int> x;
        int n;
        for(int i = 0; i < M; i++) {
            cin >> n;
            x.insert(n);
        }
        set<int> active;
        bool yes = 1;
        for(int i = 0; i < N; i++) {
            /*
            if(a[i] < b[i]) {
                yes = 0;
                break;
            }

            while(!active.empty() && *active.begin() < b[i]) {
                active.erase(active.begin());
            }
            for(auto it = active.begin(); it != active.end();){
				if(*it < b[i]){
					active.erase(it++);
				}else{
					break;
				}
			}

            if(a[i] == b[i])
                continue;

            if(active.count(b[i]) != 0)
                continue;

            if(x.find(b[i]) == x.end()) {
                yes = 0;
                break;
            }

            active.insert(b[i]);
            x.erase(x.find(b[i]));
            continue;
            */
            const int ai = a[i];
            const int bi = b[i];
			if(ai < bi){
				yes = 0;
				break;
			}
			for(auto it = active.begin(); it != active.end();){
				if(*it < bi){
					active.erase(it++);
				}else{
					break;
				}
			}
			if(ai == bi) continue;
			if(active.size() && *active.begin() == bi){
				continue;
			}
			if(x.find(bi) == x.end()){
				yes = 0;
				break;
			}
			active.insert(bi);
			x.erase(x.find(bi));
        }
        if(yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
