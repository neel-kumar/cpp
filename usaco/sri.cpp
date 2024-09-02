#include <cstdint>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int N;
int64_t fx, fy;
vector<pair<int64_t, int64_t>> is;

void print_map(std::string comment, const std::map<pair<int64_t, int64_t>, int>& m)
{
    std::cout << comment << endl;
    // iterate using C++17 facilities
    for (const auto& el : m) {
        std::cout << '[' << el.first.first << ", " << el.first.second << "] = " << el.second << "; "<< endl;
    }
}

void move(const map<pair<int64_t, int64_t>, int>& prev, map<pair<int64_t, int64_t>, int>& next) {
    for(auto & i: is) {
        for(auto & el: prev) {
            int64_t x, y;
            x = el.first.first + i.first;
            y = el.first.second + i.second;
            pair<int64_t, int64_t> n = make_pair(x, y);
            next[n] ++;
            /*
            if(next.count(n) == 0) {
                next[n] = 1;
            } else {
                next[n] += 1;
            }
            */
        }
    }
}

/*
7
5 10
-2 0
3 0
4 0
5 0
0 10
0 -10
0 10
*/

int main() {
    cin >> N;
    cin >> fx >> fy;

    for(int i = 0; i < N; i++) {
        int64_t x, y;
        cin >> x >> y;
        is.push_back(make_pair(x,y));
    }

    map<pair<int64_t, int64_t>, int> prev;
    prev[make_pair(0,0)] = 1;

    pair<int64_t, int64_t> fp = make_pair(fx, fy);

    for(int i = 0; i < 2; i++) {
        map<pair<int64_t, int64_t>, int> next;
        move(prev, next);
        cout << "For i = " << i << endl;
        print_map("prev ", prev);
        print_map("next ", next);
        cout << (next.count(fp) == 0 ? 0 : next[make_pair(fx, fy)]) << endl;
        prev.clear();
        prev = next;
    }

    return 0;
}
