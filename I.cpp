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

int A, B, C;

int main(){
    IOI;

    cin >> A >> B >> C;

    lli mat[A + 1][B + 1][C + 1][3];

    forn(i, A + 1){
        forn(j, B + 1){
            forn(k, C + 1){
                forn(r, 3){
                    mat[i][j][k][r] = 0;
                }
            }
        }
    }

    mat[1][0][0][0] = mat[0][1][0][1] = mat[0][0][1][2] = 1;

    forn(i, A + 1){
        forn(j, B + 1){
            forn(k, C + 1){
                if(i == 0 && k == 0 && k == 0) continue;
                forn(r, 3){
                   if(r == 0 && i > 0){
                    mat[i][j][k][r] += mat[i - 1][j][k][1] + mat[i-1][j][k][2];
                   }else if(r == 1 && j > 0){
                    mat[i][j][k][r] += mat[i][j - 1][k][0] + mat[i][j - 1][k][2];
                   }else if(r == 2 && k > 0){
                    mat[i][j][k][r] += mat[i][j][k - 1][1] + mat[i][j][k - 1][0];
                   }
                   mat[i][j][k][r] %= MOD;
                }
            }
        }
    }

    lli sum = 0;

    forn(i, 3){
        sum = (sum + mat[A][B][C][i]) % MOD;
    }

    cout << sum << ENDL;
}