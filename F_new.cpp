#include <bits/stdc++.h>
using namespace std;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c) const { return PT(x*c, y*c); }
  PT operator / (double c) const { return PT(x/c, y/c); }
};

double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}

double computeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}

const int MaxN = 20;
int N;
PT points[MaxN];
double ans = 101020120;

vector < vector<PT> > triangulos;
vector <PT> visitadosPT;
vector<bool> visited;
 vector < vector <PT> > actuales;

void bruta(int ind, int ant){
  if(ind == N){
    vector<double> areas;
    for(auto p: actuales){
        areas.push_back(computeArea(p));
    }

    sort(areas.begin(), areas.end());

    ans = min(ans, areas.back() - areas[0]);

    return;
  }

  vector<PT> actual;
  vector<int> index(3);
  for(int i = ant + 1; i < 3 *  N; i++){
    if(visited[i]) continue;
    actual.push_back(points[i]);
    visited[i] = true;
    index[0] = i;
    break;
  }

  for(int j = index[0] + 1; j < 3 * N; j++){
    if(visited[j]) continue;
    visited[j] = true;
    actual.push_back(points[j]);
    index[1] = j;
    for(int k = j + 1; k < 3 * N; k++){
        if(visited[k]) continue;
        actual.push_back(points[k]);
        index[2] = k;
        visited[k] = true;
        actuales.push_back(actual);
        bruta(ind + 1, index[0]);

        visited[k] = false;
        actuales.pop_back();
        actual.pop_back();
    }
    visited[j] = false;
    actual.pop_back();
  }

  visited[index[0]] = false;
  actual.pop_back();

}

double round_num(double a){
    a*=100;
    double b = a - int(a);
    a -= b;
    long long int d = a;
    if(d%10 >= 5) a += 10 - d % 10;
    else a  = a  - d % 10;

    return a / 100;
}

int main(){
  cin>>N;

  for(int i = 0; i < 3 * N; i++){
    double x, y;
    cin >> x >> y;
    points[i] = PT(x, y);
  }
  
  visited.assign(3 * N, false);
  


  bruta(0, -1);

  cout << setprecision(1) << fixed << round_num(ans) << "\n";

}