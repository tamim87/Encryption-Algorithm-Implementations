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
// prime: p,q
// n = p*q
// phi(n): (p-1)*(q-1)
// e is coprime to phi(n)
// d is coprime to e
// public key: (e,n)
// private key: (d,n)
// encrypted messege: c = m^e % n
// decrypted messege: d = c^d % n

ll bigmod(ll b, ll p, ll m)
{
	if(p == 0) return 1;

	ll x = bigmod(b,p/2,m);
	x = (x%m * x%m) % m ;
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
	ll x, y;
	ll g = ex_gcd(a,m,x,y);
	if(g != 1) return -1;
	return (x % m + m) % m;
}

void solve()
{
	ll m ;
	cout << "enter messege: ";
	cin >> m;
	ll p = 1007977, q = 1008001;
	ll n = p*q;
	ll phi = (p-1) * (q-1);

	ll i,e;
	for(i = 1 ; i<phi ; i++)
	{
		if(__gcd(i,phi) == 1)
			break;
	}
	e = i;

	ll d = inverse(e,phi);
	ll c = bigmod(m,e,n);
	ll plain = bigmod(c,d,n);
	// w(c) w(plain)
	cout << "messege is: " << c << nl;
	cout << "plaintext is: " << plain << nl;
	cout << nl;

}

int main()
{
	// freopen("in.txt","r",stdin);
    // fast ;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}