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

vector<int>compute_prefix(string pattern)
{

    int n = pattern.size();
    vector<int> prefix(n+1);
    prefix[0]=0;
    int k=0;
    for(int i =1; i<n; i++)
    {
        while(k>0 and pattern[k]!=pattern[i])
            k=prefix[k-1];

        if(pattern[i]==pattern[k])
            k++;
        prefix[i]=k;
    }
    return prefix;
}

int KMP(string text,string pattern)
{
    int n = pattern.size(), occurance=0;

    pattern = pattern + '#' + text;

    vector <int> prefix = compute_prefix(pattern);

    for(int i=n+1;i<pattern.size();i++){
         if(prefix[i]==n) occurance++;
    }

    return occurance;
}

int main()
{

    int n ,tc=0 , t;
    cin >> t;

    while(t--){

    string text, pattern;
    cin >> text >> pattern;

    cout << "Case "<<++tc<<": " << KMP(text,pattern) << '\n';
    }
}
