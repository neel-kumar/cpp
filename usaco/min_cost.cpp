#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin>>x>>y;
    double arr[x+1];
    int visited[x+1];
    vector<pair<int, double>> adj[x+1];
    fill(arr, arr+x+1, 0);
    fill(visited, visited+x+1, 0);
    for(int i=0; i<y; i++){
        int a, b;
        double c;
        cin>>a>>b>>c;
        c=1.0-(c/100.0);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int start, end;
    cin>>start>>end;
    priority_queue<pair<double, int>> q;
    arr[start]=1;
    q.push({1, start});
    while(!q.empty()){
        auto temp=q.top();
        cout << temp.first << " ";
        cout << temp.second << " ";
        q.pop();
        if(visited[temp.second]) continue;
        visited[temp.second]=1;
        for(auto i: adj[temp.second]){
            if(arr[i.first]<arr[temp.second]*i.second){
                arr[i.first]=arr[temp.second]*i.second;
                q.push({arr[i.first], i.first});
            }
        }
    }
    cout<<fixed<<setprecision(8)<<100.0/arr[end];
}
