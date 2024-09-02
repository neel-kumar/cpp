#include <bits/stdc++.h>

using namespace std;

string s;
long long n;
char bessie[6] = {'b', 'e', 's', 's', 'i', 'e'};
vector<long long> bs, be;

void init_bessie() {
   bessie['b'] = 1;
   bessie['e'] = 2;
   bessie['s'] = 2;
   bessie['i'] = 1;
}
	
long long f(long long i, long long j) {
	long long nb = j-i+1;
	long long nl = (i == 0) ? bs[i] + 1 : bs[i] - bs[i-1];
	long long nr = (j == be.size()-1) ? n-be[j] : be[j + 1] - be[j];
	//cout << "i = " << i << ", j = " << j << endl;
	//cout << nb << " " << nl << " " << nr << endl;
	return nb*nl*nr;
}

long long find_left(string& s, const long long r) {
   init_bessie();
   long long tofind = 6; // length of bessie
   // Move r as far as possible to encompass bessie
   long long l = r;
   while(l >= 0) {
      if(bessie[s[l]] > 0) {
         bessie[s[l]]--;
         --tofind;
      }
      if(tofind == 0) break;
      l--;
   }
   return l;
}

void calc_bs_be(string& s, const long long n) {
	long long NB = 0;
   long long r = 0;
   while(r < n) {
      init_bessie();
      long long tofind = 6; // length of bessie
      // Move r as far as possible to encompass bessie
      while(r < n && tofind > 0) {
         if(bessie[s[r]] > 0) {
            bessie[s[r]]--;
            --tofind;
         }
         r++;
      }
      if(tofind == 0) {
		 NB++;
         long long l = find_left(s, r - 1);
         cout << "l = " << l << ", r = " << (r - 1) << endl;
		 bs.push_back(l);
		 be.push_back(r - 1);
      }
   }
}

int main() {
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; i++) {
		if(s[i] == 'b') {
			long long l=i, r=i, bcounter = 1;
			while(r < n) {
				r++;
				if(s[r] == bessie[bcounter])
					bcounter++;
				if(bcounter == 6) {
					bs.push_back(l);
					be.push_back(r);
					printf("LR(%d, %d)\n", l, r);
					break;
				}
			}
		}
	}


/*
	long long l=0, r=0, bcounter = 1;
	while(r < n) {
		while(l < n && s[l] != 'b')
			l++, r = l;
		r++;
		if(s[r] == bessie[bcounter])
			bcounter++;
		if(bcounter == 6) {
			bs.push_back(l);
			be.push_back(r);
			l++;
		}
	}
	*/

   //cout << "Number of bessie are " << bs.size() << endl;
	long long ans = 0;
	for(long long i = 0; i < bs.size(); i++) {
		for(long long j = i; j < bs.size(); j++)
			ans += f(i, j);
	}
	cout << ans << "\n";
	return 0;
}
