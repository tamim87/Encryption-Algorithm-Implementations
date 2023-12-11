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


// messege: m
// prime: p
// public key: (e1,e2,p)
// private key: (d)
// e1, e2 encryption key
// encrypted messege: c1 = e1^r % p
// encrypted messege: c1 = (m*e1^r) % p
// decrypted messege: dec = (c2*(c1^d)^-1) % p


ll bigmod(ll b, ll p, ll m)
{
	if(p == 0) return 1;
	ll x = bigmod(b,p/2,m);
	x = (x%m * x%m) % m;
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
	ll x1, y1;
	ll d = ex_gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
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
    ll m = 646, p = 1007977, r = 8, d = 719;	
	cout << "enter messege: " << nl;
	// cin >> m;
	
	ll e1 = 29;
	ll e2 = bigmod(e1,d,p);

	ll c1 = bigmod(e1,r,p);
	ll c2 = ( m%p * bigmod(e2,r,p) )%p  ;

	ll t1 = bigmod(c1,d,p);
	ll t2 = inverse(t1,p);
	ll dec = bigmod(c2*t2,1,p);

	cout << "messege is: " << m << nl;
	cout << "decrypted plaintext is: " << dec << nl;
}

int main()
{
	// freopen("in.txt","r",stdin);
    fast ;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}