#include <bits/stdc++.h>

using namespace std;

int find_index(string s, int n, char K)
{
    // Lower and upper bounds
    int start = 0;
    int end = n - 1;
    // Traverse the search space
    while (start <= end) {
        int mid = (start + end) / 2;
        // If K is found
        cout << "? " << s[mid] << " " << K << "\n";
        char repl;
        cin >> repl;
        if (repl == '<')
            start = mid + 1;
        else
            end = mid - 1;
    }
    // Return insert position
    return end + 1;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    string s;
/*
    for(int i = 0; i < N; i++) s += (char)('A'+i);

    for(int i = 0; i < N; i++) for(int j = 0; j < N-1; j++) {
        cout << "? " << s[j] << " " << s[j+1] << "\n";
        // fflush(stdout);
        char repl;
        cin >> repl;
        if(repl == '>') swap(s[j], s[j+1]);
    }
*/
    char c;
    for(int i = 0; i < N; i++) {
        c = (char)('A'+i);
        s.insert(find_index(s, i, c), 1, c);
        cout << s << "\n";
    }
    cout << "! " << s << "\n";
    // fflush(stdout);

    return 0;
}
