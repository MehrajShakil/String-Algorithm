#include<bits/stdc++.h>
using namespace std;
#define ios    ios::sync_with_stdio(0);cin.tie(0);

using ll = long long;
map<ll,ll> mp;
vector<ll> compute_prefix(string s)
{

    ll sz= s.size();
    ll k=0;
    vector<ll> prefix(sz+1);
    prefix[0]=0;
    for(ll i=1; i<s.size(); i++)
    {

        while(k>0 and s[i]!=s[k])
            k=prefix[k-1];

        if(s[i]==s[k])
            k++;
        prefix[i]=k;
        mp[prefix[i]]++;
    }
    return prefix;
}



int main()
{
    ios
    string s;
    cin>>s;
    vector<ll> prefix = compute_prefix(s);
    ll ans=0;
    ll n = s.size();
    if(prefix[n-1]!=0 &&  mp[prefix[n-1]]>1)
    {
        cout<<s.substr(0,prefix[n-1]);
    }
    else if(prefix[n-1]!=0 && mp[prefix[n-1]]==1 && prefix[prefix[n-1]-1]!=0)
    {
        cout<<s.substr(0,prefix[prefix[n-1]-1]);
    }
    else
    {
        cout<<"Just a legend";
    }




}
