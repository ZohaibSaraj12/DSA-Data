#include <iostream>
using namespace std;
void inclusive ()
{
    int size = 0;
    cout << "Enter class Numbers: " << endl;

    cin >> size;
    float all[size][2];

    cout << "Enter lowerBound First " << " UpperBound second " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> all[i][j];
        }
    }
    float value[size];
    for (int i = 0; i < size; i++)
    {
        value[i] = (all[i][0] + all[i][1]) / 2.0;
    }
    int f[size];
    int sumOfF = 0;
    cout << "Enter Frequency of That data: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> f[i];
        sumOfF = sumOfF + f[i];
    }
    cout << "   C.I   " << "\t f   " << " MidPoint" << "  (f)(x)" << endl;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + (value[i] * f[i]);

        cout << "  " << all[i][0] << " - " << all[i][1] << "\t " << f[i] << "\t" << value[i] << "\t " << (value[i] * f[i]) << endl;
    }

    cout << "\t\t\t    " << "sumOf(fx) = " << sum << endl;

    float mean = 0.0;
    mean = sum / sumOfF;
    cout << endl
         << endl;

    cout << "Mean is: " << mean << endl
         << endl
         << endl;
}
void Exclusive ()
{
    int size = 0;
    cout << "Enter class Numbers: " << endl;

    cin >> size;
    float all[size][2];

    cout << "Enter lowerBound First " << " UpperBound second " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> all[i][j];
        }
    }

    float ans = (all[1][0] - all[0][1]) / 2.0;
    float array[size][2];

    for (int i = 0; i < size; i++)
    {
        array[i][0] = all[i][0] - 0.5;
        array[i][1] = all[i][1] + 0.5;
    }
    for (int i = 0; i < size; i++)
    {
        
    }
    float value[size];
    // For Midpoints 
    for (int i = 0; i < size; i++)
    {
        value[i] = (array[i][0] + array[i][1]) / 2.0;
    }
    int f[size];
    int sumOfF = 0;
    cout << "Enter Frequency of That data: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> f[i];
        sumOfF = sumOfF + f[i];
    }
    cout << "   C.I   " << "\t f " << "  Class Boundaries" << "   MidPoint" << "   (f)(x)" << endl;
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum = sum + (value[i] * f[i]);

        cout << "  " << all[i][0] << " - " << all[i][1] << "\t " << f[i] << "\t" << array[i][0] << " - "  << array[i][1] << "\t  " << value[i] << "\t" << "   " << (value[i] * f[i]) << endl;
    }
}
int main()
{
    int typeOfseries = 0;
    cout << "What is the type of the series Inclusive (0) and Exclusive (1): " << endl;
    cin >> typeOfseries;

   switch (typeOfseries)
   {
    case 0:
    inclusive();
    break;
    case 1:
    Exclusive();
    break;
   }

}
