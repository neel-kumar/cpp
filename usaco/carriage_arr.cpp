#include <bits/stdc++.h>

using namespace std;

int ans = 0, arr[10001];

void swap(int* xp, int* yp) {
    //printf("SWAP(%d, %d) ", *xp, *yp);
    ans++;
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    bubbleSort(N);
    cout << ans << "\n";
    return 0;
}
