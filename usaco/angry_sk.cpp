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

// short cut for defining vars
typedef set<int> si;
// now si = set<int>

// String replacemnt, lets you replace some text with some other text, and it can have args
#define DEBUG if(!DEBUG_LOG) {} else cout << "DEBUG: "
// 

bool DEBUG_LOG = true;

void init()
{
    freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
}

template<typename T>
string to_string(T begin, T end)
{
    stringstream ss;
    bool first = true;
    for(; begin != end; begin++)
    {
        if(!first) ss << ", ";
        first = false;
        ss << *begin;
    }

    return ss.str();
}

template<typename T>
string to_string(const vector<T>& v)
{
    return to_string(v.begin(), v.end());
}

template<typename T>
string to_string(const vector<T>* v)
{
    return to_string(v->begin(), v->end());
}

vector<int>* read_input() {
    DEBUG << "Reading input" << endl;

    vector<int>* bale_pos = new vector<int>();

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        bale_pos->push_back(pos);
    }

    DEBUG << "There are " << bale_pos->size() << " bales" << endl;
    DEBUG << "Position of bales: " << to_string(bale_pos) << endl;

    return bale_pos;
}

vector<int> read_input2() {
    DEBUG << "Reading input" << endl;

    vector<int> bale_pos;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        bale_pos.push_back(pos);
    }

    return bale_pos;
}

void read_input3(vector<int>& bale_pos)
{
    DEBUG << "Reading input" << endl;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        bale_pos.push_back(pos);
    }
}

void read_input4(vector<int>* bale_pos)
{
    DEBUG << "Reading input" << endl;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int pos;
        cin >> pos;

        bale_pos->push_back(pos);
        // OR
        // (*bale_pos).push_back(pos);
    }
}


vector<int>* get_within_br(vector<int>& bale_pos, int start_bale, int br, set<int>& exploded)
{
    vector<int>* bales = new vector<int>();
    const int blasted_bale_pos = bale_pos[start_bale];

    for(unsigned i = 0; i < bale_pos.size(); i++) {
        if(exploded.count(i) == 0 && abs(bale_pos[i] - blasted_bale_pos) <= br) {
            bales->push_back(i);
        }
    }

    return bales;
}

int num_explosions(vector<int>& bale_pos, int start_bale)
{
    int ne = 0;
    // bale index and blast radius
    list<pair<int, int> > q;
    si exploded;
    q.push_back(make_pair(start_bale, 1));
    exploded.insert(start_bale);

    while(!q.empty()) {
        pair<int, int> pos_br = q.front();
        q.pop_front();
        ++ne;
        // Get list of bales which are within blast radius and have not exploded yet.
        vector<int>* next_bales = get_within_br(bale_pos, pos_br.first, pos_br.second, exploded);
        for(auto i: *(next_bales)) {
            exploded.insert(i);
            q.push_back(make_pair(i, pos_br.second + 1));
        }
        delete next_bales;
    }

    return ne;
}

int main() {
    init();

    vector<int>* bale_pos = read_input();

    vector<int> bale_pos2 = read_input2();

    vector<int> bale_pos3;

    read_input3(bale_pos3);

    read_input4(&bale_pos3);

    int me = 0;
    for(unsigned i = 0; i < bale_pos->size(); i++) {
        me = max(me, num_explosions(*bale_pos, i));
    }

    delete bale_pos;

    cout << me << endl;

    return 0;
}

