#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string name = "ahfsaklasfjklwera";

    cout << "Enter Character to find" << endl;
    char c;
    cin >> c;

    size_t pos = name.find(c);

    if (pos != string::npos)
    {
        cout << "found";
    }
    else 
    {
        cout << "not found" << endl;
    }
    

    
}

