#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using  ll = long long;

string txt;

vector<string> split_in2_sentences(string txt) {
    size_t start = 0;
    // look for end of sentence
    size_t finish = txt.find_first_of(".!?", start);
    
    if (finish != string::npos)
    {
        // end of sentence was found, do something here.

        // now find start of next sentence
        start = txt.find_first_not_of(" \t\n", finish+1);
    }
}

vector<string> identify_parts(string sen) {

}
 
int main() {
    cin >> txt;

    return 0;
}
