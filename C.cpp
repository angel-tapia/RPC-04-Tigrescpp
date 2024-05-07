#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 50;

int DP[MaxN];
int arr[MaxN];
int N;
int ans = 1;

int main(){
  cin>>N;

  for (int i = 0; i < N; i++){
    cin >> arr[i];
  }

  DP[0] = 1;
  for (int i = 1; i < N; i++){
    DP[i] = 1;
    int j = i-1;
    if(arr[i] > arr[j]){
      DP[i] = DP[j] + 1;
      ans = max(DP[i], ans);
    }
  }

  cout<<ans<<"\n";
}