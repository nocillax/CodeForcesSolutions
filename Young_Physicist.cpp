// ------------------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
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

void NoCiLLaX(){

    ll t, sumA, sumB, sumC; cin >> t; 
    sumA = 0;
    sumB = 0;
    sumC = 0;

    while(t--){
        
        ll a, b, c; cin >> a >> b >> c;
        sumA += a;
        sumB += b;
        sumC += c;

    }

    if(sumA == 0 && sumB == 0 && sumC == 0)  cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main(){
    //FST_IO
    NoCiLLaX();
}
