// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int>z_function(string pattern)
{
    int n = pattern.size();

    vector<int> z(n);
    z.assign(n, 0);

    for(int i =1,l=0,r=0; i<n; i++)
    {
        if(i<=r)
        {
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && pattern[z[i]]==pattern[i+z[i]])
            ++z[i];

        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

int main()
{

    string pattern ;

    cin >> pattern;

    vector<int> v,  z = z_function(pattern);
    int n = pattern.size();

    for(int i=1; i<n; i++)
    {
        if(z[i])
            v.push_back(z[i]);
    }
    sort(v.begin(),v.end());

    vector<pair<int,int> > ans;
    for(int i=0; i<n-1; i++)
    {
        if(z[n-i-1]==i+1)
        {
            int x = z[n-i-1];
            auto it = (lower_bound(v.begin(),v.end(),x)-v.begin());
            int valu = v.size() - it;

            ans.push_back({i+1,valu+1});

        }
    }
    ans.push_back({n,1});
    cout << ans.size() << '\n';
    for(auto it : ans)
    {
        cout << it.first << " " << it.second << '\n';
    }


}

