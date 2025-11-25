#include<bits/stdc++.h>
using namespace std;

int main()
{
    string filename;
    getline(cin,filename);

    ifstream file(filename);

    if(!file)
    {
        cout<<"Error opening file !!"<<endl;
        return 1;
    }

    char ch;
    int totalchar=0;
    int line=0;
    int special=0;
    int digit=0;
    int alpha=0;

    while(file.get(ch))
    {
        totalchar++;

        if(isalpha(ch)) alpha++;
        else if(isdigit(ch)) digit++;
        else if(ch=='\n') line++;
        else special++;
    }

    cout<<"Char :"<<totalchar<<"\nLine :"<<line<<"\nAlpha: "<<alpha<<"\nspecial : "<<special<<"\nDigit: "<<digit;

    file.close();
    return 0;
}
