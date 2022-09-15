#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define mp make_pair

typedef pair<ll, ll> PLL;


const int N=1e6+10;
const int mod=1e9+7;
const int b=101;
ll pw[N+2];
int n;

/// calculate power.
void cal(int n)
{
  pw[0]=1;
  for(int i=1;i<n;i++)
  {
    pw[i]=(1LL*pw[i-1]*b)%mod;
  }
}

ll binpow(ll a, ll b) {
    long long res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

struct Hash {
  string s;
  vector<ll> v;
  int makeHash()
  {
    ll hs=0;
    v.push_back(hs);
    int i = 1;
    for(auto x:s)
    {
      hs=hs+(1LL*(pw[i-1]*x))%mod;
      v.push_back(hs);
      i++;
    }
    return hs;
  }
  int segment(ll lt,ll rt)
  {
      return ((v[rt]-v[lt]+mod)%mod*binpow(pw[lt],mod-2)%mod)%mod;
  }
};



int main(){

    int t;
    cin >> t;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cal(N);
    for ( int i = 1 ; i<=t ; ++i){
        Hash A, B;
        cin >> A.s;
        B.s = A.s;
        n = B.s.size();
        reverse(B.s.begin(),B.s.end());
        A.makeHash();
        B.makeHash();


        ll ans = 0;

        for ( int i = 0 ; i < n;  ++i){
            for ( int j = i ; j < n ; ++j){
                if(A.segment(i,j+1)==B.segment(n-j-1,n-i)) {
                    ll len = j - i + 1;
                    ans+=(len*len*len);
                }
            }
        }
        cout << ans << "\n";
    }
}
