#include<bits/stdc++.h>
using namespace std;

bool keyword(const string& var)
{
  unordered_set<string>keywords ={
    "auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","inline","int","long",
        "register","return","short","signed","sizeof","static","struct","switch",
        "typedef","union","unsigned","void","volatile","while","class","public",
        "private","protected","template","typename","namespace","new","delete",
        "this","using","virtual","bool","true","false","nullptr"
        };
    return keywords.count(var)>0;
}

bool isvalid(const string & var)
{
    if(var.empty()) return false;

    if(!(isalpha(var[0]) || var[0]=='_')) return false;

    for(int i=1;i<var.size();i++)
    {
        if(!(isalnum(var[i])||var[i]=='_')) return false;
    }

    if(keyword(var)) return false;

    return true;

}

int main()
{
    string var;
    getline(cin,var);

    int n=var.size();

    if(isvalid(var))
        cout<<"Yes,Valid."<<endl;
    else cout<<"Invalid !!"<<endl;

    return 0;
}
