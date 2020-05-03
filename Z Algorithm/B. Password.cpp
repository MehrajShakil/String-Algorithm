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
    vector<int> z = z_function(pattern);
    int n = pattern.size();
    priority_queue<int> pq;
    pq.push(0);
    for( int i=1; i<z.size(); i++)
    {
        int x = z[i];
        if(n-i==x && pq.top()>=x){
          cout << pattern.substr(0,x);
          return 0;
        }
        pq.push(x);
    }


    cout << "Just a legend\n";

}

