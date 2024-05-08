#include <bits/stdc++.h>

using namespace std;

void djikistra(vector<vector<pair<long long, long long>>>& graph, long long source, vector<int>& vis, vector<long long>& d){
    priority_queue<pair<long long, long long>> pq;

    d[source] = 0;
    pq.push({0, source});

    pair<long long, long long> act;

    while(!pq.empty()){
        act = pq.top();
        pq.pop();
        if(vis[act.second]) continue;
        vis[act.second] = 1;

        for(auto next : graph[act.second]){

            if(d[next.second] >= d[act.second] + next.first){
                d[next.second] = d[act.second] + next.first;
                pq.push({-d[next.second], next.second});
            }

        }
    }
}

int main()
{
    long long n, m, aux1, aux2, aux_time;
    char br;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> graph(n);
    for(int i = 0; i < m; i++){
        cin>>aux1>>aux2>>br>>aux_time;
        if(br == 'b'){
            graph[aux1-1].push_back({aux_time, aux2-1});
        } else{
            graph[aux1-1].push_back({-aux_time, aux2-1});
        }
    }
    vector<int> vis(n, 0);
    vector<long long> d(n, INT_MAX);
    djikistra(graph, 0, vis, d);
    for(int i = 0; i < d.size(); i++){
        if(d[i] < 0) {
            cout<<i + 1<<"\n";
        }
    }
    return 0;
}
