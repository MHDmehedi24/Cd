#include<bits/stdc++.h>
using namespace std;

bool isInteger(const string& s)
{
    int i=0,digit=0;
    if(s[i]=='-' || s[i]=='+') i=1;

    for(int j=i; j<s.size(); j++)
    {
        if(isdigit(s[j])) digit++;
        else
        {
            return false;
        }
    }

    return (digit>0);
}

bool isFloat(const string& s)
{
    int i=0;
    if(s[i]=='-' || s[i]=='+') i=1;

    int dot=0,digit=0;

    for(int j=i; j<s.size(); j++)
    {
        if(s[j]=='.')
        {
            dot++;

            if(dot>1) return false;
        }
        else if(isdigit(s[j])) digit++;
        else return false;
    }

    return (dot==1 and digit>=1);
}

int main()
{
    string input;
    cin>>input;

    if(input.size()==1 and isalpha(input[0])) cout<<"Charecter\n";

    else if(isInteger(input)) cout<<"Integer";

    else if(isFloat(input)) cout<<"Float";

    else cout<<"String";

    return 0;
}
