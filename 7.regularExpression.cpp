#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str,pattern;
    cout<<"Enter String: ";
    getline(cin,str);
    cout<<"Enter Pattern: ";
    getline(cin,pattern);

    regex re(pattern);

   if(regex_match(str,re)) cout<<"valid";
   else cout<<"Not valid";
    return 0;
}

