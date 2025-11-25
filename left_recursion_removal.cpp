#include<bits/stdc++.h>
using namespace std;
int main()
{
    string production, left = "", right = "";
    cout<<"Enter a production: "<<endl;
    getline(cin, production);
    production += '\n';
    for(int i=0; i<production.size()-1;){
        if(production[i]=='-' && production[i+1]=='>'){
            i += 2;
            while(production[i] != '\n'){
                right += production[i];
                i++;
            }
        }
        else{
            left += production[i];
            i++;
        }
    }

    vector <string> tokens;
    stringstream ss(right);

    while(ss.good())
    {
        string sub;
        getline(ss, sub, '|');
        tokens.push_back(sub);
    }
    string prod1, prod2;
    bool is_lr=false;
    for(int i=0; i<tokens.size(); i++){
        if(left[0] == tokens[i][0]){
            is_lr = true;
            string suff="";
            for(int j=1; j<tokens[i].size(); j++){
                suff += tokens[i][j];
            }
            if(prod2.size() == 0){
                string s = left+"'"+"->"+suff+left+"'";
                prod2 = s;
            }
            else{
                prod2 = prod2+"|"+suff+left+"'";
            }
        }
        else{
            if(prod1.size() == 0){
                string s = left+"->"+tokens[i]+left+"'";
                prod1 = s;
            }
            else{
                prod1 = prod1+"|"+tokens[i]+left+"'";
            }
        }

    }
    prod2 += "|eps";
    if(is_lr == false){
        cout<<"There is no left recursion"<<endl;
    }
    else cout<<prod1<<endl<<prod2<<endl;
}

