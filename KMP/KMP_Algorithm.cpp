#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> compute_prefix(string pattern)
{

    ll sz = pattern.size();
    vector<ll> prefix(sz+1);

    prefix[0]=0;
    int k = 0;

    for(ll i=1; i<sz; i++)
    {
        while(k>0 and pattern[k]!=pattern[i])    // if pattern[k] not equal to pattern[i] then decrease k with one until pattern[k]==pattern[i] or k>0
            k=prefix[k-1];

        if(pattern[k]==pattern[i])    //    if k and i is match then increase k with 1.
            k=k+1;

        prefix[i]=k;
    }

    return prefix;

}

void KMP(string text,string pattern)
{

    vector<ll> prefix;
    prefix= (compute_prefix(pattern));

    ll matched_pos = 0;

    for(ll current = 0 ; current<text.size(); current++)
    {
        while(matched_pos>0 and pattern[matched_pos]!=text[current])
        {
            matched_pos=prefix[matched_pos-1];
        }
        if(pattern[matched_pos]==text[current])
        {
            matched_pos=matched_pos+1;
        }
        if(matched_pos==pattern.size())
        {
            cout<<"Pattern occurs with shift "<< current - (pattern.length() -1 )<<endl;
            matched_pos = prefix[matched_pos-1];
        }
    }

}

int main()
{
    string text,pattern;
    cin>>text>>pattern;

    KMP(text,pattern);

}
