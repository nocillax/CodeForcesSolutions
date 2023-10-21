#include <iostream>
using namespace std;

typedef long long int ll;

int main(){
    ll n, m, a;
    cin >> n >> m >> a;
    ll x, y;

    if(n%a != 0) x = (n/a) + 1;
    else x = n/a;

    if(m%a != 0) y = (m/a) + 1;
    else y = m/a;


    ll result = x*y;
    cout << result;
}
