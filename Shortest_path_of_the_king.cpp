// ------------------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
// ------------------------------------------------------------------------------
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
// ------------------------------------------------------------------------------
#define FST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define READ          freopen("in.txt","r",stdin)
#define WRITE         freopen("out.txt","w",stdout);
#define nl            "\n"
#define PI            acos(-1.0)
#define mem(arr,val)  memset(arr,val,sizeof(arr))
#define pb            push_back
#define mp            make_pair
#define mpl           make_pair<ll, ll>
#define PR            pair<ll,ll>
#define ff            first
#define ss            second
#define mod           10000007
#define INF           1e18
#define EPS           1e-2
// ------------------------------------------------------------------------------


int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};
ll m = 8, n = 8;    // Size of Grid

struct Mat{
    char ch;
    bool B;
    ll dist;
    PR way;
}matrix[8][8];    // Adust with Max possible value


ll BFS(ll startX, ll startY, ll destX, ll destY) {
    int cnt = 0;
    queue<PR> Q;
    Q.push({startX, startY});
    matrix[startX][startY].B = true;
    matrix[startX][startY].dist = 0;  // Distance from start to start is 0
    matrix[startX][startY].way = mp(0,0);

    while (!Q.empty()) {
        PR v = Q.front();
        Q.pop();

        if (v.first == destX && v.second == destY) {
            // Destination reached
            return matrix[destX][destY].dist;
        }

        for (int i = 0; i < 8; i++) {
            ll r = v.first + dx[i];
            ll c = v.second + dy[i];

            if (r < 0 || c < 0 || r >= m || c >= n || matrix[r][c].B == true) continue;

            Q.push({r, c});
            matrix[r][c].B = true;
            matrix[r][c].dist = matrix[v.first][v.second].dist + 1;  // Update distance
            matrix[r][c].way = v;
            cnt++;
        }
    }

    // Destination not reachable
    return -1;
}

void showKingPath(ll destX, ll destY){
    vector<PR> path;
    PR val = mp(destX, destY);
    path.push_back(val);
    
    while(matrix[destX][destY].way != mpl(0,0)){
        val = matrix[destX][destY].way;
        path.push_back(val);
        destX = val.first;
        destY = val.second;
    }
    reverse(path.begin(), path.end());
    
    for(ll i = 0; i < path.size()-1; i++){
        
        ll x = path[i+1].ff - path[i].ff;
        ll y = path[i+1].ss - path[i].ss;
        
        if(x == 1 && y == 0) cout <<"R"<<nl;
        if(x == 1 && y == 1) cout <<"RU"<<nl;
        if(x == 1 && y == -1) cout <<"RD"<<nl;
        if(x == 0 && y == 1) cout <<"U"<<nl;
        if(x == 0 && y == -1) cout <<"D"<<nl;
        if(x == -1 && y == 0) cout <<"L"<<nl;
        if(x == -1 && y == 1) cout <<"LU"<<nl;
        if(x == -1 && y == -1) cout <<"LD"<<nl;
    }
    
}

void NoCiLLaX(){
    
    string s, t; cin >> s; cin >> t;
    ll sX = s[0]- 'a';
    ll sY = s[1] - '1';
    ll dX = t[0] - 'a';
    ll dY = t[1] - '1';

    cout<< BFS(sX, sY,dX, dY) << nl;
    
    showKingPath(dX, dY);

}

int main(){
    NoCiLLaX();
}
