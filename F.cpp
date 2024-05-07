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

const int MaxN = 10;
int N;
PT points[MaxN];
double ans = 101020120;

vector < vector<PT> > triangulos;
vector <PT> visitadosPT;

void bruta(int ind, int ant, vector < vector <PT> > actuales){
  if(ind == N){
    vector <double> areas;
    for(int i = 0; i < actuales.size(); i++){
      double areaActual = computeArea(actuales[i]);
      areas.push_back(areaActual);
    }

    sort(areas.begin(), areas.end());

    int tam = areas.size();
    ans = min(ans, areas[tam-1] - areas[0]);
    
    for(int i = 0; i < actuales.size(); i++){
      for(int j = 0; j < actuales[i].size(); i++){
        cout<<actuales[i][j].x<<" "<<actuales[i][j].y<<"\n";
      }
    }
    cout<<areas[tam-1]<<" "<<areas[0]<<" "<<areas[tam-1]-areas[0];
    return;
  }

  for (int i = ant + 1; i < triangulos.size(); i++){
    bool visite = false;
    for(int j = 0; j < triangulos[i].size(); j++){
      for(PT x : visitadosPT){
        if(x.x == triangulos[i][j].x && x.y == triangulos[i][j].y){
          visite = true;
          break;
        }
      }
    }
    
    if(visite == false){
      actuales.push_back(triangulos[i]);
      for(int j = 0; j < triangulos[i].size(); j++){
        visitadosPT.push_back(triangulos[i][j]);
      }
      bruta(ind+1, i, actuales);

      actuales.pop_back();
      visitadosPT.pop_back();
      visitadosPT.pop_back();
      visitadosPT.pop_back();
    }
  }
}

int main(){
  cin>>N;

  for(int i = 1; i <= 3 * N; i++){
    double x, y;
    points[i] = PT(x, y);
  }
  
  for(int i = 1; i <= N*3; i++){
    for(int j = i+1; j <= N*3; j++){
      for(int p = j+1; p <= N*3; p++){
        vector<PT> triangle;
        triangle.push_back(points[i]);
        triangle.push_back(points[j]);
        triangle.push_back(points[p]);

        triangulos.push_back(triangle);
      }
    }
  }

  printf("%.1f", &ans);

}