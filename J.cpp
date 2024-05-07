#include <bits/stdc++.h>


#define lli long long
#define ld long double
#define pp pair<ld,ld>
#define mp make_pair
#define INF 1e9
#define MOD int(1e9 + 7)
#define IOI ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ALL(array) (array.begin(),array.end())
#define ENDL '\n' 
#define forn(i, n) for(int i = 0; i < n; i++)
#define mod(a,b) ( ( a % b ) + b ) % b
using namespace std;

int N;
vector<pp> coords;

ld cross_product(pp a, pp b){
    return abs(b.first * a.second - b.second * a.first);
}

ld compute_triangle_area(pp a, pp b, pp c){
    pp v1 = mp(b.first - a.first, b.second - a.second);
    pp v2 = mp(c.first  - a.first, c.second - a.second);

    return cross_product(v1, v2) / 2;
}

ld compute_area(){
    ld AREA = 0;
    for(int i = 2; i < N; i++){
        AREA += compute_triangle_area(coords[0], coords[i - 1], coords[i]);
    }

    return AREA;
}

ld compute_minimum(){
    ld AREA = compute_area(), AUX;

    ld minimum = AREA;

    forn(i, N){
        AUX = 0;
        forn(j, N-2){
            int first = (i + j)%N, second = (first + 1)% N;
            ld area = compute_triangle_area(coords[i], coords[first], coords[second]);
            AUX += area;
            minimum = min(minimum, abs(AREA - 2 * AUX));
        }
    }

    return minimum;
}

ld round_num(ld a){
    a*=10;
    ld b = a - int(a);
    a -= b;
    lli d = a;
    if(d%10 >= 5) a += 10 - d % 10;
    else a  = a  - d % 10;

    return a / 10;
}

int main(){
    IOI;

    cin >> N;

    coords.assign(N, mp(0,0));

    forn(i, N){
        cin >> coords[i].first >> coords[i].second;
    }

    cout <<setprecision(1) << fixed <<  round_num(compute_minimum()) << ENDL;
    return 0;
}