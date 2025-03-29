// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[2][2];

//     int array[2];
//     int array2[2];

//     for (int i = 0; i < 2; i++)
//     {
//         cin >> array[i];
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         cin >> array2[i];
//     }

//     for (int i = 0; i < 2; i++)
//     {
//         arr[0][i] = array[i];
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         arr[1][i] = array2[i];
//     }

//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             cout << arr[i][j] << " ";

//         }
//         cout << endl;
//     }
// }
#include <iostream>
using namespace std;
int main()
{
   int a = 5; 
   int b = 4;


   a = a + b;
   b = a - b;
   a = a - b;


   cout << a << " "  << b << endl;
}