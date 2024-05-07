#include <bits/stdc++.h>

using namespace std;

void djikistra(vector<vector<pair<long long, long long>>>& graph, long long source, vector<long long>& d){
    priority_queue<pair<long long, long long>> pq;

    d[source] = 0;
    pq.push({0, source});

    pair<long long, long long> act;

    while(!pq.empty()){
        act = pq.top();
        pq.pop();

        for(auto next : graph[act.second]){
            else{
                if(d[next.second] >= d[act.second] + next.first){
                    d[next.second] = d[act.second] + next.first;
                    pq.push({-next.first, next.second});
                }
            }
        }
    }
    for(int i = 0; i < d.size(); i++){
        if(d[i] < 0) {
            if(i==d.size()-1) cout<<i+1;
            else cout<<i + 1<<"\n";
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
    vector<long long> d(n, INT_MAX);
    djikistra(graph, 0, d);

    return 0;
}
