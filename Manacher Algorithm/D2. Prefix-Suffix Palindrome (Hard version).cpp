///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


///   Every soul shall taste death.

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>



///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MUHAMMAD        ios::sync_with_stdio(0);cin.tie(0);
#define all(x)          (x).begin(), (x).end()
#define AE              cout << fixed << setprecision(10);
#define ld              double
#define f               first
#define ss              second


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long int;
const ll MOD = 1e9+7;
const ld PI = acos(-1.0);


typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree< ll, null_type, greater<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set_boro;

typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

/// Geometry section.
ld degree_to_radian( ld x ){
	ld ans = ((ld)(acos(-1.0)/180.0)*x);
	return ans;
}

//***********************************************  The END **********************************************************************************************************************************

const ll N = 5e3+10;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1.5e7 + 5;

/// --------------------------------------------------------------

/* 0-based indexing
p[0][i] is the maximum length of half palindrome around half index i
p[1][i] is the maximum length of half palindrome around characters i
*/

using VI = vector<int>;
VI p[2];

void manacher(const string s) {
    int n = s.size();
    p[0] = VI(n+1);
    p[1] = VI(n);

    for ( int z = 0 ; z<2 ; ++z ) {
        for ( int i = 0 , l = 0 , r = 0; i<n ; ++i ) {
           int t = r - i + !z;
           if(i<r) {
            p[z][i] = min(t,p[z][l+t]);
           }
           int L = i-p[z][i], R = i+p[z][i] - !z;
           while(L>=1 and R+1<n and s[L-1]==s[R+1]) {
            p[z][i]++;
            L--, R++;
           }
           if(R>r) l = L, r = R;
        }
    }
}

bool isPal(int l, int r ) {
   int mid = (l+r+1)>>1;
   int sz = r-l+1;
   bool odd = sz%2;
   int len = p[odd][mid];
   len*=2;
   len+=odd;
   return len>=sz;
}


void Solution ( int tc ){

   string s;
   cin >> s;

   int n = s.size();
   string prefix = "", suffix = "", middle = "";

   int pos = -1;
   for ( int i = 0 ; i < n/2 ; ++i ) {

    if(s[i]!=s[n-i-1]) {
        pos = i;
        break;
    }
    prefix+=s[i];
   }
   
   suffix = prefix;
   reverse(all(suffix));

   if(pos==-1) cout << s << "\n";
   else {
    for ( int i = pos ; i<=n-pos-1 ; ++i ) {
        middle+=s[i];
    }
    manacher(middle);
    int k = middle.size();

    int best = -1;

    for ( int i = 0 ; i < k ; ++i ) {
        //dbg ( p[0][i] , p[1][i] );
        if(isPal(0,i) and i+1>best) {
            best = i+1;
        }
    }
    string ans = "";
    for ( int i = 0 ; i<best ; ++i ) ans+=middle[i];
    best = -1;

    reverse(all(middle));
    manacher(middle);

    for ( int i = 0 ; i < k ; ++i ) {
       // dbg ( p[0][i], p[1][i] );
        if( isPal(0,i) and i+1>best) {
            best = i+1;
        }
       // dbg (  isPal(0,i) , best );
    }

    string ans1 = "";
    for ( int i = 0 ; i<best ; ++i ) ans1+=middle[i];
    reverse(all(ans1));

    //dbg ( ans1 , ans );

    if(ans1.size()>ans.size()) ans = ans1;




    prefix+=ans;
    prefix+=suffix;
    cout << prefix << "\n";
   }
}

int main()
{

   MUHAMMAD;



   // AE;

   /*
   #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
   #endif
   */


    int testcase = 1 , tc = 0;



    cin >> testcase;

    for ( int i = 1 ; i <= testcase ; ++i ){
       Solution( ++tc );
    }

    return 0;
}


  /// __mhs, Do you check
  /// -> overflow
  /// -> array bound.


/*

 LCA:


Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
