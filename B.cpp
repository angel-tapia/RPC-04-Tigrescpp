#include <bits/stdc++.h>


#define lli long long
#define pp pair<lli,lli>
#define mp make_pair
#define INF 1e9
#define MOD int(1e9 + 7)
#define IOI ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ALL(array) (array.begin(),array.end())
#define ENDL '\n' 
#define forn(i, n) for(int i = 0; i < n; i++)
#define mod(a,b) ( ( a % b ) + b ) % b
using namespace std;

int O, K, A;

int main(){
    IOI;
    cin >> O >> K >> A;

    forn(i, 150){
        forn(j, 150){
            if((i + 1) * K + (j + 1) * A == O){
                cout << 1 << ENDL;
                return 0;
            } 
        }
    }

    cout << 0 << ENDL;

    return 0;

}