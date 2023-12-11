//Pylier
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
const char nl = '\n';
const char gg = ' ' ;
template<class T> T cmax(T a, T b){return (a>b?a:b);}

#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;

ll pyL(ll x, ll n)
{
	ll f = (x-1)/n;
	return f;
}

ll lcm(ll a, ll b)
{
	return a/__gcd(a,b) * b;
}

ll bigmod(ll b, ll p, ll m)
{
	if(p == 0) return 1;
	ll x = bigmod(b,p/2,m);
	x = (x%m * x%m) %m;
	if(p&1)
		x = (x%m * b%m) % m;
	return x;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll x1 , y1;
	ll d = ex_gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}

ll inverse(ll a, ll m)
{
	ll x,y;
	ll g = ex_gcd(a,m,x,y);
	if(g != 1) return -1;
	return (x%m + m) % m;
}

void solve()
{
    ll p = 79, q = 83 , n = p*q;
    ll lambda = lcm(p-1,q-1);
    ll r = 5;
    ll tmiu = pyL(bigmod(r,lambda,n*n),n);
    ll miu = inverse(tmiu, n);
    ll m = 800;
    ll i ;
    for(i = 1; i<n ; i++)
    {
    	if(__gcd(i,n) == 1)
    		break;
    }
    ll e = i;
    ll c = bigmod(bigmod(r,m,n*n)*bigmod(e,n,n*n),1,n*n);
    ll t = bigmod(c,lambda,n*n);
    ll t1 = pyL(t,n);
    ll mes = bigmod(t1*miu,1,n);
   	w(m)
   	w(mes)
}

int main()
{
    fast ;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}