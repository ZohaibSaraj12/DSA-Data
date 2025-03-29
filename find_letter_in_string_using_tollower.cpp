
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string name = "ahfsaklasfjklwera";

    cout << "Enter Character to find" << endl;

    char c;
    cin >> c;
    int n = name.length();
    bool found = false;
    for (int i = 0; i < n; i++)
    {
       if (tolower(name[i]) == tolower(c))
       {
        cout << "letter found at " << i << endl; 
        found = true;
       }
    }
    if (!found)
    {
        cout << "Not Found Oh! No" << endl;
    }

}