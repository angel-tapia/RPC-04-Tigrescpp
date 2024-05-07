#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int MaxN = 200005;
int N, K;
int arr[MaxN];
int pre[MaxN];

int main(){
  cin>>N>>K;

  for(int i = 1; i <= N; i++){
    cin>>arr[i];
    pre[i] = pre[i-1] + arr[i];
  }

  int total = 0;
  for(int i = 1; i <= K; i++){
    total += arr[i] * (i);
  }

  priority_queue <pair <int, int> > pq;

  pq.push({-total, -1});

  // 1 2 3 4  5
  // 1 3 6 10 15
  // 
  //cout<<total<<" 1\n";
  for(int i = K+1; i <= N; i++){
    total = total - pre[i-1] + pre[i-K-1];
    total += arr[i] * K;
    
    //cout<<total<<" "<<i-K+1<<"\n";

    pq.push({-total, -(i-K+1)});
  }

  /*
  for(int i = 1; i <= N; i++){
  	cout<<arr[i]<<" ";
  }
  cout<<"\n";
  for(int i = 1; i <= N; i++){
  	cout<<pre[i]<<" ";
  }
  cout<<"\n";*/

  while(!pq.empty()){
    pair <int, int> actual = pq.top();
    pq.pop();

    cout<<-actual.second<<" "<<-actual.first<<"\n";
  }

}