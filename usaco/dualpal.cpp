/*
ID: n27k
TASK: dualpal
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Function to convert a given decimal number
// to a base 'base' and
string fromDeci(string& res, int base, int inputNum)
{
    int index = 0; // Initialize index of result

    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0) {
        res.push_back(reVal(inputNum % base));
        index++;
        inputNum /= base;
    }

    // Reverse the result
    reverse(res.begin(), res.end());

    return res;
}

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());

    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

int main() {
    ifstream fin("dualpal.in");
    //ifstream tin("dualpal.txt");
    ofstream fout("dualpal.out");

    int N, S;
    fin >> N >> S;

    int i = S+1;
    while(N > 0) {
        int palc = 0;
        for(int j = 2; j <= 10; j++) {
            string res = "";
            fromDeci(res, j, i);
            if(isPalindrome(res)) palc++;
        }
        if(palc >= 2) {
            fout << i << "\n";
            N--;
        }
        i++;
    }

    return 0;
}
