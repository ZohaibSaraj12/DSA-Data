#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string nameList[5] = {"Muhammad Zohaib", "Muhammad Mohsin Khan", "Talha Zubair", "Fahad Hassan Khan", "Hassan Raza"};

    cout << "Enter a Character" << endl;
    char character;
    cin >> character;

    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (tolower(nameList[i][0]) == tolower(character))
        {
            cout << nameList[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Not Found" << endl;
    }
}