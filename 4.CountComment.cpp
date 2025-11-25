#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    int multi = 0, single=0;
    bool inblock = false;
    string line;

    while(getline(file,line))
    {
        int a = line.find("/*");
        int b = line.find("*/");
        int c = line.find("//");

        if(!inblock)
        {
            if(a!=-1 and b!=-1 and a<b)
            {
                multi++;
                continue;
            }
            if(c!=-1 and (a==-1 || c < a))
            {
                single++;
                continue;
            }
            if(a!=-1)
            {
                inblock = true;
                continue;
            }

        }
        else
        {
            if(b!=-1)
            {
                multi++;
                inblock = false;
            }
        }
    }

    file.close();

    cout<<"Single: "<<single<<"\nMulti: "<<multi;
    return 0;
}
