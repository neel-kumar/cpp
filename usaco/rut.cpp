#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#define in(i, s, e) for(int i = s; i < e; i++)

int nt(vector<tuple<int, int, char>> &c2i, int c, int N) {
    //cout << "Cow " << c << endl;
    vector<int> nce;
    in(j, 0, N) {
        if (get<2>(c2i[j]) == get<2>(c2i[c])) {
            //cout << "Same Direc " << j << get<2>(c2i[j]) << get<2>(c2i[c]) << endl;
            continue;
        } else if (get<2>(c2i[c]) == 'N' && get<0>(c2i[c]) - get<0>(c2i[j]) >= 0 && 
                get<0>(c2i[c]) - get<0>(c2i[j]) < get<1>(c2i[j]) - get<1>(c2i[c])) {
            int jans = nt(c2i, j, N);
            //cout << j << " " << 'E' << " " << jans << endl;
            if(jans > get<0>(c2i[c]) - get<0>(c2i[j]) || jans == -1) {
                nce.push_back(get<1>(c2i[j]) - get<1>(c2i[c]));
            }
        } else if (get<2>(c2i[c]) == 'E' && get<1>(c2i[c]) - get<1>(c2i[j]) >= 0 && 
                get<1>(c2i[c]) - get<1>(c2i[j]) < get<0>(c2i[j]) - get<0>(c2i[c])) {
            int jans = nt(c2i, j, N);
            //cout << j << " " << 'N' << " " << jans << endl;
            if(jans > get<1>(c2i[c]) - get<1>(c2i[j]) || jans == -1) {
                nce.push_back(get<0>(c2i[j]) - get<0>(c2i[c]));
            }
        }
    }
    if(nce.size() == 0) {
        return -1;
    } else {
        return *min_element(nce.begin(), nce.end());
    }
}    


int main() {
	freopen("rut.in", "r", stdin);
	//freopen("rut.out", "w", stdout);
    int N;
    vector<tuple<int, int, char>> c2i;
    cin >> N;
    in(i, 0, N) {
        char d;
        int x, y;
        cin >> d >> x >> y;
        c2i.push_back(tie(x, y, d));
    }

    int ans[N];
    in(i, 0, N) {
        ans[i] = nt(c2i, i, N);
    }

    in(i, 0, N) {
        if(ans[i] == -1)
            cout << "Infinity" << endl;
        else
            cout << ans[i] << endl;
    }
	return 0;
}



