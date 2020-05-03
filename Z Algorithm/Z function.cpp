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
    z.assign(n , 0);

    /// abcabc

    for(int i =1,l=0,r=0; i<n; i++)
    {
        if(i<=r)
        {
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && pattern[z[i]]==pattern[i+z[i]])
            ++z[i];

        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

int main()
{

    int  t;
    cin >> t;
    string pattern;

    while(t--)
    {
        cin >> pattern;
        vector<int> z = z_function(pattern);
        for(int i=0;i<z.size();i++){
                cout << z[i] << ' ';
        }
        cout << '\n' ;
    }
}
