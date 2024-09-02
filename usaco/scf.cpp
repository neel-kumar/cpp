#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

int N;
int v[300001];
int p[300001];
stack<int> st1;

    long long ans = 0;

void foo() {
    stack<int> st;
    st.push(v[1]);
    for(int i = 2; i <= N; i++) {
        while(!st.empty() &&v[i] > st.top()) {
            int j = max(p[v[i]], p[st.top()]);
            int k = min(p[v[i]], p[st.top()]);
            ans += j - k +1;
            st.pop();
        }
        st.push(v[i]);
    }
}

int main() {
    // freopen("scf.in", "r", stdin);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        v[i] = h;
        p[h] = i;
    }

    foo();
    // cout << ans << endl;
    reverse(v+1, v + N + 1);
    foo();
/*
    st1.push(v[N]);
    for(int i = N-1; i >= 1; i--) {
        while(!st1.empty() &&v[i] > st1.top()) {
            ans += p[st1.top()]-i+1;
            st1.pop();
        }
        st1.push(v[i]);
    }
*/

    cout << ans << endl;
    return 0;
}
