#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int count_unique_substring(string const&s)
{

    int n = s.size();

    const int p = 31;
    const int m = 1e9+9;

    vector<long long> p_pow(n);

    p_pow[0]=1;

    for(int i=1; i<n; i++)
    {
        p_pow[i]=(p_pow[i-1]*p)%m;
    }

    vector<long long> h(n+1,0);

    for(int i=0; i<n ; i++)
    {
        h[i+1]=(h[i]+(s[i]-'a' + 1)*p_pow[i])%m;
    }

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        set<long long> hs;
        for(int j = 0 ; j<= n-i ; j++)
        {
            long long cur_h = (h[j+1]+m-h[j])%m;
            cur_h = (cur_h * p_pow[n-j-1])%m;
            hs.insert(cur_h);
        }
        cnt+=hs.size();
    }
    return cnt;
}

int main()
{

    string s;
    cin >> s;

    cout<<count_unique_substring(s)<<'\n';


}
