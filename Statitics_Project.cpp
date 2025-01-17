/* A project of Statistics, */
// Project Made By CHATGPT Kinda Funny
// You can Also Use Your Own Logic
#include <iostream>
// Algorithm library to Include Sort Function Especially std C++ 11
#include <algorithm>
// Complex Mathematical Calculation's Library 
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function prototypes ---> Easier To Do Top (main Function) down (other Functions) Top-Down Approach
double calculateMean(const double data[], int size);
double calculateMedian(double data[], int size);
double calculateMode(const double data[], int size);
double calculateGeometricMean(const double data[], int size);
double calculateHarmonicMean(const double data[], int size);
// Handled Group and Ungroup data Also discrete and continuous in group data

//chapter 1 functions prototype

void handleUngroupedDataForMean();
void handleUngroupedDataForMedian();
void handleUngroupedDataForMode();
void handleUngroupedDataForGM();
void handleUngroupedDataForHM();
void handleGroupedDataForMean();
void handleDiscreteDataOfMean();
void handleGroupedDataForMedian();
void handleDiscreteDataOfMedian();
void handleGroupedDataForMode();
void handleDiscreteDataOfMode();
void handleGroupedDataForGM();
void handleDiscreteDataOfGM();
void handleGroupedDataForHM();
void handleDiscreteDataOfHM();
void calculateWeightedMean();
void calculateCombinedMean();


// chapter 2 data

void rangeOfUngroupedData();
void rangeOfDiscreteData();
void rangeOfGroupedData();

void quartileDeviationOfGroupedData();
void quartileDeviationOfUngroupedData();
void quartileDeviationOfDiscreteData();

void meanDeviationFromMeanUngroupedData();
void meanDeviationFromMeanDiscreteData();
void meanDeviationFromMeanGroupedData();

void varianceOfGroupedData();
void varianceOfUngroupedData();
void varianceOfDiscreteData();

void standardDeviationOfGroupedData();
void standardDeviationOfUngroupedData();
void standardDeviationOfDiscreteData();


//regression

void regressionXOnY();
void regressionYOnX();


int main()
{
    int choice;
    cout << "\nStatistics Project\n";
    cout << "1. Central Tendency\n";
    cout << "2. Measure Of Dispersion\n";
    cout << "3. Regression\n";
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1)
    {
        int subChoice;
        cout << "\nCentral Tendency:\n";
        cout << "1. Mean\n2. Median\n3. Mode\n4. Geometric Mean\n5. Harmonic Mean";
        cout << "Choose a topic: ";
        cin >> subChoice;

        int dataType;
        cout << "\n1. Grouped Data\n2. Ungrouped Data\nChoose data type: ";
        cin >> dataType;
        if (subChoice == 1)
        {
            if (dataType == 1)
            {
                handleGroupedDataForMean();
            }
            else if (dataType == 2)
            {
                handleUngroupedDataForMean();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 2)
        {
            if (dataType == 1)
            {
                handleGroupedDataForMedian();
            }
            else if (dataType == 2)
            {
                handleUngroupedDataForMedian();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 3)
        {
            if (dataType == 1)
            {
                handleGroupedDataForMode();
            }
            else if (dataType == 2)
            {
                handleUngroupedDataForMode();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 4)
        {
            if (dataType == 1)
            {
                handleGroupedDataForGM();
            }
            else if (dataType == 2)
            {
                handleUngroupedDataForGM();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 5)
        {
            if (dataType == 1)
            {
                handleGroupedDataForHM();
            }
            else if (dataType == 2)
            {
                handleUngroupedDataForHM();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
    }
    else if (choice == 2)
    {
        int subChoice;
        cout << "\nCentral Tendency:\n";
        cout << "1. Range And Coefficient\n2. Quartile Deviation and Coefficient\n3. Mean Deviation and Coefficient\n4. Variance And Coefficient \n5. Standard Deviation";
        cout << "Choose a topic: ";
        cin >> subChoice;

        int dataType;
        cout << "\n1. Grouped Data\n2. Ungrouped Data\nChoose data type: ";
        cin >> dataType;
        if (subChoice == 1)
        {
            if (dataType == 1)
            {
                rangeOfGroupedData();
            }
            else if (dataType == 2)
            {
                rangeOfUngroupedData();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 2)
        {
            if (dataType == 1)
            {
                quartileDeviationOfGroupedData();
            }
            else if (dataType == 2)
            {
                quartileDeviationOfUngroupedData();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 3)
        {
            if (dataType == 1)
            {
                meanDeviationFromMeanGroupedData();
            }
            else if (dataType == 2)
            {
                meanDeviationFromMeanUngroupedData();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 4)
        {
            if (dataType == 1)
            {
                varianceOfGroupedData();
            }
            else if (dataType == 2)
            {
                varianceOfUngroupedData();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
        else if (subChoice == 5)
        {
            if (dataType == 1)
            {
                standardDeviationOfGroupedData();
            }
            else if (dataType == 2)
            {
                standardDeviationOfUngroupedData();
            }
            else
            {
                cout << "Invalid option. Exiting.\n";
            }
        }
    }
    else if (choice == 3)
    {
        cout << "Regression:\n";
        cout << "\n1. X on Y\n";
        cout << "2. Y on X" << endl;

        int subChoice;

        cin >> subChoice;

        if (subChoice == 1)
        {
            regressionXOnY();
        }
        else if (subChoice == 2)
        {
            regressionYOnX();
        }
        else 
        {
            cout << "Wrong Input" << endl;
            
        }
    }
    else
    {
        cout << "Invalid option. Exiting.\n";
    }

    return 0;
}

// Function to calculate Mean
double calculateMean(const double data[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate Median
double calculateMedian(double data[], int size)
{
    sort(data, data + size); // Sorting the array built in function in library ALGORITHM
    if (size % 2 == 0)
    {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else
    {
        return data[size / 2];
    }
}

// Function to calculate Mode
double calculateMode(const double data[], int size)
{
    double uniqueValues[size];
    int frequencies[size];
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i)
    {
        bool found = false;
        for (int j = 0; j < uniqueCount; ++j)
        {
            if (data[i] == uniqueValues[j])
            {
                frequencies[j]++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            uniqueValues[uniqueCount] = data[i];
            frequencies[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxFreq = 0;
    double mode = uniqueValues[0];
    for (int i = 0; i < uniqueCount; ++i)
    {
        if (frequencies[i] > maxFreq)
        {
            maxFreq = frequencies[i];
            mode = uniqueValues[i];
        }
    }
    return mode;
}

// Function to calculate Geometric Mean
double calculateGeometricMean(const double data[], int size)
{
    double product = 1;
    for (int i = 0; i < size; ++i)
    {
        product *= data[i];
    }
    return pow(product, 1.0 / size);
}

// Function to calculate Harmonic Mean
double calculateHarmonicMean(const double data[], int size)
{
    double reciprocalSum = 0;
    for (int i = 0; i < size; ++i)
    {
        reciprocalSum += 1.0 / data[i];
    }
    return size / reciprocalSum;
}

// Function to handle ungrouped data
void handleUngroupedDataForMean()
{
    cout << endl
         << "Mean Of Ungrouped Data:" << endl;
    cout << "\nEnter The data of Individual Series:  " << endl;
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    cout << "Mean: " << calculateMean(data, n) << endl;
}
void handleUngroupedDataForMedian()
{
    cout << "\n Median of ungrouped Data: " << endl;
    cout << "\nEnter the data of Individual Series ";
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }
    cout << "Median: " << calculateMedian(data, n) << endl;
}
void handleUngroupedDataForMode()
{
    cout << endl
         << "Mode Of Ungrouped Data:" << endl;

    cout << "\nEnter the data of Individual Series ";

    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    cout << "Mode: " << calculateMode(data, n) << endl;
}
void handleUngroupedDataForGM()
{
    cout << endl
         << "GM Of Ungrouped Data:" << endl;

    cout << "\nEnter the data of Individual Series ";

    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    cout << "GM: " << calculateGeometricMean(data, n) << endl;
}
void handleUngroupedDataForHM()
{
    cout << endl
         << "HM Of Ungrouped Data:" << endl;

    cout << "\nEnter the data of Individual Series ";

    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    cout << "HM: " << calculateHarmonicMean(data, n) << endl;
}
void handleDiscreteDataOfMean()
{
    cout << endl
         << "Mean Of Discrete Data:" << endl;

    cout << "\nEnter the data of Discrete Series ";

    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    double data[n];
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    float f[n];

    cout << "Enter Frequency of That Discrete Series Data: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    float sumOfFrequency = 0;

    for (int i = 0; i < n; i++)
    {
        sumOfFrequency += f[i];
    }
    cout << "Sum of Frequency is: " << sumOfFrequency << endl
         << endl
         << endl;
    float sum = 0.0;

    cout << "   X   " << "\t f   " << "  (f)(x)" << endl;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (data[i] * f[i]);

        cout << "  " << data[i] << "\t " << f[i] << "\t" << (data[i] * f[i]) << endl;
    }

    cout << "\t\t\t    " << "sumOf(fx) = " << sum << endl;

    float mean = 0.0;
    mean = sum / sumOfFrequency;
    cout << endl
         << endl;

    cout << "Mean is: " << mean << endl
         << endl;
}
// Function to handle grouped data
void handleGroupedDataForMean()
{
    cout << "Enter type of series: DISCRETE SERIES(0) and CONTINOUS SERIES(1) : ";
    int dataType;
    cin >> dataType;
    if (dataType == 0)
    {
        handleDiscreteDataOfMean();
    }
    else if (dataType == 1)
    {

        cout << "\nYou are Just gonna Selecting the Continous series : Happy Ending In SHA ALLLAH : " << endl;
        cout << "Enter Type of data in group Data For inclusive (0) and Exclusive (1) : ";

        cin >> dataType;

        if (dataType == 0)
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

        else if (dataType == 1)
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
            float f[size];
            float sumOfF = 0;
            cout << "Enter Frequency of That data: " << endl;
            for (int i = 0; i < size; i++)
            {
                cin >> f[i];
                sumOfF = sumOfF + f[i];
            }
            cout << "   C.I   " << "\t f " << "  Class Boundaries" << "   MidPoint" << "   (f)(x)" << endl;
            float sum = 0;

            for (int i = 0; i < size; i++)
            {
                sum = sum + (value[i] * f[i]);

                cout << "  " << all[i][0] << " - " << all[i][1] << "\t " << f[i] << "\t" << array[i][0] << " - " << array[i][1] << "\t  " << value[i] << "\t" << "   " << (value[i] * f[i]) << endl;
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
    }
    else
    {
        cout << "Wrong Input!!! Enter Valid Input" << endl;
        return;
    }
}

void handleDiscreteDataOfMedian()
{
    int size = 0;
    cout << "Enter Size of Data Points: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size. Please enter a positive integer.\n";
        return;
    }

    int data[size];
    int freq[size];

    // Input data points
    cout << "Enter the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    // Input corresponding frequencies
    int totalFrequency = 0;
    cout << "Enter Frequencies for the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> freq[i];
        if (freq[i] < 0)
        {
            cout << "Frequency cannot be negative. Please re-enter the data.\n";
            return;
        }
        totalFrequency += freq[i];
    }

    // **Sorting data and frequencies using bubble sort**
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                swap(freq[j], freq[j + 1]);
            }
        }
    }

    // Calculate cumulative frequencies
    int cumulativeFrequency[size];
    // Calculate cumulative frequencies with debug
    cumulativeFrequency[0] = freq[0];
    for (int i = 1; i < size; i++)
    {
        cumulativeFrequency[i] = cumulativeFrequency[i - 1] + freq[i];
        // Debug: Print each step of cumulative frequency calculation
        cout << "Cumulative Frequency at index " << i << ": " << cumulativeFrequency[i] << endl;
    }

    // Find the median position (N/2)
    int N_by_2 = totalFrequency / 2;
    int medianIndex = -1;

    // Locate the median index in cumulative frequency
    for (int i = 0; i < size; i++)
    {
        if (cumulativeFrequency[i] >= N_by_2)
        {
            medianIndex = i;
            break;
        }
    }

    // Output cumulative frequency table
    cout << "\nCumulative Frequency Table:\n";
    cout << "   Data   Frequency   Cumulative Frequency\n";
    for (int i = 0; i < size; i++)
    {
        cout << "   " << data[i] << "       " << freq[i] << "               " << cumulativeFrequency[i] << endl;
    }

    // Output the median
    if (medianIndex != -1)
    {
        cout << "\nMedian Data Point: " << data[medianIndex] << endl;
        cout << "Median is: " << data[medianIndex] << endl;
    }
    else
    {
        cout << "Error in finding the median.\n";
    }
}

void handleGroupedDataForMedian()
{
    cout << "Enter type of series: DISCRETE SERIES(0) and CONTINOUS SERIES(1) : ";
    int dataType;
    cin >> dataType;
    if (dataType == 0)
    {
        handleDiscreteDataOfMedian();
    }
    else if (dataType == 1)
    {
        cout << "Enter Type of data in grouped data ---> Continous data (Inclusive (0) / Exclusive (1)): ";

        cin >> dataType;

        if (dataType == 0 || dataType == 1)
        {
            int size = 0;
            cout << "Enter number of classes: ";
            cin >> size;

            float all[size][2];
            cout << "Enter lower and upper bounds for each class:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> all[i][0] >> all[i][1];
            }

            // Adjust boundaries for exclusive data
            if (dataType == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    all[i][0] -= 0.5;
                    all[i][1] += 0.5;
                }
            }

            int frequencies[size];
            int cumulativeFrequencies[size] = {0};
            int totalFrequency = 0;

            cout << "Enter frequencies for each class:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> frequencies[i];
                totalFrequency += frequencies[i];
                cumulativeFrequencies[i] = (i == 0) ? frequencies[i] : cumulativeFrequencies[i - 1] + frequencies[i];
            }

            // Median calculations
            float medianClassLower = 0, h = 0, CF = 0, f = 0;
            float N_by_2 = totalFrequency / 2.0;

            int medianClassIndex = -1;
            for (int i = 0; i < size; i++)
            {
                if (cumulativeFrequencies[i] >= N_by_2)
                {
                    medianClassIndex = i;
                    break;
                }
            }

            if (medianClassIndex != -1)
            {
                medianClassLower = all[medianClassIndex][0];
                h = all[medianClassIndex][1] - all[medianClassIndex][0];
                CF = (medianClassIndex == 0) ? 0 : cumulativeFrequencies[medianClassIndex - 1];
                f = frequencies[medianClassIndex];

                float median = medianClassLower + ((N_by_2 - CF) / f) * h;

                cout << "\nMedian Class: " << all[medianClassIndex][0] << " - " << all[medianClassIndex][1] << endl;
                cout << "Median = " << median << endl;
            }
            else
            {
                cout << "Error in finding the median class.\n";
            }
        }
    }
    else
    {
        cout << "Invalid input! Please enter 0 for inclusive or 1 for exclusive data.\n";
    }
}
void handleDiscreteDataOfMode()
{
    int size = 0;
    cout << "Enter Size of Data Points: ";
    cin >> size;

    int data[size];
    int freq[size];

    // Input data points and frequencies
    cout << "Enter the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    cout << "Enter Frequencies for the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> freq[i];
    }

    // Find the mode
    int maxFreq = freq[0], modeIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            modeIndex = i;
        }
    }

    cout << "\nMode Data Point: " << data[modeIndex] << endl;
    cout << "Mode is: " << data[modeIndex] << endl;
}

void handleGroupedDataForMode()
{
    cout << "Enter type of series: DISCRETE SERIES(0) and CONTINOUS SERIES(1) : ";
    int dataType;
    cin >> dataType;
    if (dataType == 0)
    {
        handleDiscreteDataOfMode();
    }
    else if (dataType == 1)
    {
        cout << "Enter Type of data in grouped data ---> Continous data (Inclusive (0) / Exclusive (1)): ";
        cin >> dataType;

        if (dataType == 0 || dataType == 1)
        {
            int size = 0;
            cout << "Enter Number of Classes: ";
            cin >> size;

            float all[size][2];
            cout << "Enter Lower and Upper Bounds for Each Class:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> all[i][0] >> all[i][1];
            }

            // Adjust boundaries for exclusive data
            if (dataType == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    all[i][0] -= 0.5;
                    all[i][1] += 0.5;
                }
            }

            int frequencies[size];
            cout << "Enter Frequencies for Each Class:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> frequencies[i];
            }

            // Find the modal class
            int modalClassIndex = 0;
            for (int i = 1; i < size; i++)
            {
                if (frequencies[i] > frequencies[modalClassIndex])
                {
                    modalClassIndex = i;
                }
            }

            // Mode calculations
            float L = all[modalClassIndex][0];
            float h = all[modalClassIndex][1] - all[modalClassIndex][0];
            float fm = frequencies[modalClassIndex];
            float f1 = (modalClassIndex == 0) ? 0 : frequencies[modalClassIndex - 1];
            float f2 = (modalClassIndex == size - 1) ? 0 : frequencies[modalClassIndex + 1];

            float mode = L + ((fm - f1) / ((fm - f1) + (fm - f2))) * h;

            cout << "\nModal Class: " << all[modalClassIndex][0] << " - " << all[modalClassIndex][1] << endl;
            cout << "Mode = " << mode << endl;
        }
    }
    else
    {
        cout << "Invalid input! Please enter 0 for inclusive or 1 for exclusive data.\n";
    }
}
void handleDiscreteDataOfHM()
{
    int size = 0;
    cout << "Enter Size of Data Points: ";
    cin >> size;

    float data[size];
    int freq[size];

    // Input data points
    cout << "Enter the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    // Input frequencies
    cout << "Enter Frequencies for the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> freq[i];
    }

    // Calculate N (sum of frequencies) and sum of reciprocal of data points
    int N = 0;
    float reciprocalSum = 0;
    for (int i = 0; i < size; i++)
    {
        N += freq[i];
        reciprocalSum += freq[i] / data[i];
    }

    // Calculate HM
    float HM = N / reciprocalSum;

    cout << "\nHarmonic Mean (HM) for Discrete Data = " << HM << endl;
}

// Function to calculate HM for grouped data
void handleGroupedDataForHM()
{
    cout << "Enter type of series: DISCRETE SERIES(0) and CONTINOUS SERIES(1) : ";
    int dataType;
    cin >> dataType;
    if (dataType == 0)
    {
        handleDiscreteDataOfHM();
    }
    else if (dataType == 1)
    {
        cout << "Enter Type of Data in Grouped Data ---> Continous Data (Inclusive (0) / Exclusive (1)): ";
        cin >> dataType;

        int size = 0;
        cout << "Enter Number of Classes: ";
        cin >> size;

        float all[size][2]; // Lower and upper bounds
        cout << "Enter Lower and Upper Bounds for Each Class:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> all[i][0] >> all[i][1];
        }

        // Adjust boundaries for exclusive data
        if (dataType == 1)
        {
            for (int i = 0; i < size; i++)
            {
                all[i][0] -= 0.5;
                all[i][1] += 0.5;
            }
        }

        int frequencies[size];
        cout << "Enter Frequencies for Each Class:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> frequencies[i];
        }

        // Calculate midpoints and sum of reciprocal of midpoints
        int N = 0;

        float reciprocalSum = 0;

        for (int i = 0; i < size; i++)
        {
            float midpoint = (all[i][0] + all[i][1]) / 2.0;

            N += frequencies[i];

            reciprocalSum += frequencies[i] / midpoint;
        }

        // Calculate HM
        float HM = N / reciprocalSum;

        cout << "\nHarmonic Mean (HM) for Grouped Data = " << HM << endl;
    }
    else
    {
        cout << "Invalid Input";
    }
}
void handleDiscreteDataOfGM()
{
    int size = 0;
    cout << "Enter Size of Data Points: ";
    cin >> size;

    float data[size];
    int freq[size];

    // Input data points
    cout << "Enter the Data Points: ";
    for (int i = 0; i < size; i++)
    {

        cin >> data[i];
    }

    // Input frequencies
    cout << "Enter Frequencies for the Data Points: ";
    for (int i = 0; i < size; i++)
    {
        cin >> freq[i];
    }

    // Calculate N (sum of frequencies) and product of data points raised to their respective frequencies
    int N = 0;
    float product = 1;
    for (int i = 0; i < size; i++)
    {
        N += freq[i];
        product *= pow(data[i], freq[i]);
    }

    // Calculate GM
    float GM = pow(product, 1.0 / N);

    cout << "\nGeometric Mean (GM) for Discrete Data = " << GM << endl;
}

// Function to calculate GM for grouped data
void handleGroupedDataForGM()
{
    cout << "Enter type of series: DISCRETE SERIES(0) and CONTINOUS SERIES(1) : ";
    int dataType;
    cin >> dataType;
    if (dataType == 0)
    {
        handleDiscreteDataOfGM();
    }
    else if (dataType == 1)
    {
        cout << "Enter Type of Data in Grouped Data ---> Continous Data (Inclusive (0) / Exclusive (1)): ";
        cin >> dataType;

        int size = 0;
        cout << "Enter Number of Classes: ";
        cin >> size;

        float all[size][2]; // Lower and upper bounds
        cout << "Enter Lower and Upper Bounds for Each Class:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> all[i][0] >> all[i][1];
        }

        // Adjust boundaries for exclusive data
        if (dataType == 1)
        {
            for (int i = 0; i < size; i++)
            {
                all[i][0] -= 0.5;
                all[i][1] += 0.5;
            }
        }

        int frequencies[size];
        cout << "Enter Frequencies for Each Class:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> frequencies[i];
        }

        // Calculate midpoints and product of midpoints raised to their respective frequencies
        int N = 0;
        float product = 1;
        for (int i = 0; i < size; i++)
        {
            float midpoint = (all[i][0] + all[i][1]) / 2.0;
            N += frequencies[i];
            product *= pow(midpoint, frequencies[i]);
        }

        // Calculate GM
        float GM = pow(product, 1.0 / N);

        cout << "\nGeometric Mean (GM) for Grouped Data = " << GM << endl;
    }
    else
    {
        cout << "Invalid Input";
    }
}
void rangeOfUngroupedData() {
    cout << "Enter size : ";
    int size;
    cin >> size;
    
    float data[size];  
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
    float min = data[0], max = data[0];
    // Find the minimum and maximum values
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }
    // Return the range
    cout << "Range is : " <<  max - min << endl;
    float coefficientOfRange = (max - min) / (max + min);

    cout << "Coefficient of Range is: " << coefficientOfRange << endl;

}
void rangeOfDiscreteData()
{
    cout << "Enter size of data points: ";
    int size;
    cin >> size;
    float data[size];
    int f[size];
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
    cout << "Enter the frequency of data: ";
    for (int i = 0; i < size; i++)
    {
        cin >> f[i];
    }
    float min = data[0], max = data[0];
    // Find the minimum and maximum values
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }
    // Return the range
    cout << "Range is : " <<  max - min << endl;
    float coefficientOfRange = (max - min) / (max + min);

    cout << "Coefficient of Range for Discrete data is: " << coefficientOfRange << endl;
}
void rangeOfGroupedData()
{
    cout << "Enter the type of data series : Discrete (0) and Continuous (1)   : ";
    int seriesType;
    cin >> seriesType;

    if (seriesType == 0)
    {
        rangeOfDiscreteData();
    }
    else if (seriesType == 1)
    {
        cout << "Enter data of continous : ";
        cout << "Enter number of classes: ";
        int n;
        cin >> n;
        int arr[n][2];

        cout << "Enter data lower class limit first and then upper class limit: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        int f[n];

        cout << "Enter frequency : ";
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
        }

        int min = arr[0][0];
        int max = arr[n][1];
        
        float range = max - min;

        float coefficientOfRange = range / (max + min);

        cout << "Coefficient of Range of Grouped Data is: " << coefficientOfRange << endl;


    }
}
void quartileDeviationOfUngroupedData() {
    cout << "Enter size : ";
    int size;
    cin >> size;

    float data[size];
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    // Sort the data to calculate quartiles
    sort(data, data + size);

    // Calculate Q1 (25th percentile) and Q3 (75th percentile)
    int q1Index = (size + 1) / 4;
    int q3Index = 3 * (size + 1) / 4;

    float Q1 = data[q1Index - 1];  // Adjusting index as arrays are 0-based
    float Q3 = data[q3Index - 1];

    // Calculate the Quartile Deviation
    float quartileDeviation = (Q3 - Q1) / 2;
 
    cout << "Quartile Deviation is : " << quartileDeviation << endl;

    float quartileDeviationCoefficient = (Q3 - Q1) / (Q3 + Q1);

    cout << "Quartile Deviation Coefficient is: " << quartileDeviationCoefficient << endl;

}

// Function to calculate Quartile Deviation for Discrete Data
void quartileDeviationOfDiscreteData() {
    cout << "Enter size of data points: ";
    int size;
    cin >> size;

    float data[size];
    int f[size];
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
    cout << "Enter the frequency of data: ";
    for (int i = 0; i < size; i++) {
        cin >> f[i];
    }

    // Calculate cumulative frequencies
    int cumulativeFreq[size];
    cumulativeFreq[0] = f[0];
    for (int i = 1; i < size; i++) {
        cumulativeFreq[i] = cumulativeFreq[i - 1] + f[i];
    }

    // Find Q1 and Q3
    int n = cumulativeFreq[size - 1];
    int q1Pos = n / 4;
    int q3Pos = 3 * n / 4;

    // Finding Q1
    float Q1 = data[0];
    for (int i = 0; i < size; i++) {
        if (cumulativeFreq[i] >= q1Pos) {
            Q1 = data[i];
            break;
        }
    }

    // Finding Q3
    float Q3 = data[0];
    for (int i = 0; i < size; i++) {
        if (cumulativeFreq[i] >= q3Pos) {
            Q3 = data[i];
            break;
        }
    }

    // Calculate Quartile Deviation
    float quartileDeviation = (Q3 - Q1) / 2;
    cout << "Quartile Deviation for Discrete Data is: " << quartileDeviation << endl;
    float quartileDeviationCoefficient = (Q3 - Q1) / (Q3 + Q1);

    cout << "Quartile Deviation Coefficient is: " << quartileDeviationCoefficient << endl;
}

// Function to calculate Quartile Deviation for Grouped Data
void quartileDeviationOfGroupedData() {
    cout << "Enter the type of data series : Discrete (0) and Continuous (1)   : ";
    int seriesType;
    cin >> seriesType;

    if (seriesType == 0) {
        quartileDeviationOfDiscreteData();
    } 
    else if (seriesType == 1) {
        cout << "Enter data of continuous : ";
        cout << "Enter number of classes: ";
        int n;
        cin >> n;
        
        int arr[n][2];
        cout << "Enter data lower class limit first and then upper class limit: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int f[n];
        cout << "Enter frequency : ";
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        // Calculate cumulative frequencies
        int cumulativeFreq[n];
        cumulativeFreq[0] = f[0];
        for (int i = 1; i < n; i++) {
            cumulativeFreq[i] = cumulativeFreq[i - 1] + f[i];
        }

        // Find Q1 and Q3
        int N = cumulativeFreq[n - 1];
        int q1Pos = N / 4;
        int q3Pos = 3 * N / 4;

        // Finding Q1
        float Q1, Q3;
        for (int i = 0; i < n; i++) {
            if (cumulativeFreq[i] >= q1Pos) {
                Q1 = (arr[i][0] + arr[i][1]) / 2.0;  // Approximation of midpoint
                break;
            }
        }

        // Finding Q3
        for (int i = 0; i < n; i++) {
            if (cumulativeFreq[i] >= q3Pos) {
                Q3 = (arr[i][0] + arr[i][1]) / 2.0;  // Approximation of midpoint
                break;
            }
        }

        // Calculate Quartile Deviation
        float quartileDeviation = (Q3 - Q1) / 2;
        cout << "Quartile Deviation of Grouped Data is: " << quartileDeviation << endl;
        float quartileDeviationCoefficient = (Q3 - Q1) / (Q3 + Q1);

        cout << "Quartile Deviation Coefficient is: " << quartileDeviationCoefficient << endl;
    }
}
void meanDeviationFromMeanUngroupedData() {
    cout << "Enter size : ";
    int size;
    cin >> size;

    float data[size];
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    // Calculate the Mean
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float mean = sum / size;

    // Calculate Mean Deviation from Mean
    float meanDeviation = 0;
    for (int i = 0; i < size; i++) {
        meanDeviation += abs(data[i] - mean);
    }
    meanDeviation /= size;

    cout << "Mean Deviation from Mean is : " << meanDeviation << endl;
}

// Function to calculate Mean Deviation from Mean for Discrete Data
void meanDeviationFromMeanDiscreteData() {
    cout << "Enter size of data points: ";
    int size;
    cin >> size;

    float data[size];
    int f[size];
    cout << "Enter Data : ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
    cout << "Enter the frequency of data: ";
    for (int i = 0; i < size; i++) {
        cin >> f[i];
    }

    // Calculate the Mean
    float sumFx = 0;
    int sumF = 0;
    for (int i = 0; i < size; i++) {
        sumFx += data[i] * f[i];
        sumF += f[i];
    }
    float mean = sumFx / sumF;

    // Calculate Mean Deviation from Mean
    float meanDeviation = 0;
    for (int i = 0; i < size; i++) {
        meanDeviation += f[i] * abs(data[i] - mean);
    }
    meanDeviation /= sumF;

    cout << "Mean Deviation from Mean for Discrete Data is: " << meanDeviation << endl;
    float coefficientOfmeanDeviation = meanDeviation / mean;
    cout << "Coefficient of Mean Deviation is: " << coefficientOfmeanDeviation << endl;
}

// Function to calculate Mean Deviation from Mean for Grouped Data
void meanDeviationFromMeanGroupedData() {
    cout << "Enter the type of data series : Discrete (0) and Continuous (1): ";
    int seriesType;
    cin >> seriesType;

    if (seriesType == 0) {
        meanDeviationFromMeanDiscreteData();
    } 
    else if (seriesType == 1) {
        cout << "Enter number of classes: ";
        int n;
        cin >> n;

        int arr[n][2];
        cout << "Enter data lower class limit first and then upper class limit: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int f[n];
        cout << "Enter frequency : ";
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        // Calculate cumulative frequencies and midpoints
        int sumF = 0;
        float sumFx = 0;
        float midpoints[n];
        for (int i = 0; i < n; i++) {
            midpoints[i] = (arr[i][0] + arr[i][1]) / 2.0; // Midpoint of the class
            sumFx += midpoints[i] * f[i];
            sumF += f[i];
        }

        // Calculate the Mean
        float mean = sumFx / sumF;

        // Calculate Mean Deviation from Mean
        float meanDeviation = 0;
        for (int i = 0; i < n; i++) {
            meanDeviation += f[i] * abs(midpoints[i] - mean);
        }
        meanDeviation /= sumF;

        cout << "Mean Deviation from Mean for Grouped Data is: " << meanDeviation << endl;
    }
}
void varianceOfUngroupedData() {
    cout << "Enter size: ";
    int size;
    cin >> size;

    float data[size];
    cout << "Enter Data: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    // Calculate Mean
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float mean = sum / size;

    // Calculate Variance
    float variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= size;

    // Calculate Variance Coefficient
    float varianceCoefficient = sqrt(variance) / mean;

    cout << "Variance is: " << variance << endl;
    cout << "Variance Coefficient is: " << varianceCoefficient << endl;
}

// Variance and Variance Coefficient for Discrete Data
void varianceOfDiscreteData() {
    cout << "Enter size of data points: ";
    int size;
    cin >> size;

    float data[size];
    int f[size];
    cout << "Enter Data: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    cout << "Enter the frequency of data: ";
    for (int i = 0; i < size; i++) {
        cin >> f[i];
    }

    // Calculate Mean
    float sumFreq = 0, sumFreqData = 0;
    for (int i = 0; i < size; i++) {
        sumFreq += f[i];
        sumFreqData += data[i] * f[i];
    }
    float mean = sumFreqData / sumFreq;

    // Calculate Variance
    float variance = 0;
    for (int i = 0; i < size; i++) {
        variance += f[i] * pow(data[i] - mean, 2);
    }
    variance /= sumFreq;

    // Calculate Variance Coefficient
    float varianceCoefficient = sqrt(variance) / mean;

    cout << "Variance for Discrete Data is: " << variance << endl;
    cout << "Variance Coefficient is: " << varianceCoefficient << endl;
}

// Variance and Variance Coefficient for Grouped Data
void varianceOfGroupedData() {
    cout << "Enter the type of data series: Discrete (0) and Continuous (1): ";
    int seriesType;
    cin >> seriesType;

    if (seriesType == 0) {
        varianceOfDiscreteData();
    } 
    else if (seriesType == 1) {
        cout << "Enter number of classes: ";
        int n;
        cin >> n;

        int arr[n][2];
        cout << "Enter data (lower class limit first and then upper class limit): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int f[n];
        cout << "Enter frequency: ";
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        // Calculate midpoints and Mean
        float midpoints[n], sumFreq = 0, sumFreqMid = 0;
        for (int i = 0; i < n; i++) {
            midpoints[i] = (arr[i][0] + arr[i][1]) / 2.0;
            sumFreq += f[i];
            sumFreqMid += midpoints[i] * f[i];
        }
        float mean = sumFreqMid / sumFreq;

        // Calculate Variance
        float variance = 0;
        for (int i = 0; i < n; i++) {
            variance += f[i] * pow(midpoints[i] - mean, 2);
        }
        variance /= sumFreq;

        // Calculate Variance Coefficient
        float varianceCoefficient = sqrt(variance) / mean;

        cout << "Variance for Grouped Data is: " << variance << endl;
        cout << "Variance Coefficient is: " << varianceCoefficient << endl;
    }
}
void standardDeviationOfUngroupedData() {
    cout << "Enter size: ";
    int size;
    cin >> size;

    float data[size];
    cout << "Enter Data: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    // Calculate Mean
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float mean = sum / size;

    // Calculate Variance
    float variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= size;

    // Calculate Standard Deviation
    float standardDeviation = sqrt(variance);

    // Calculate Standard Deviation Coefficient
    float standardDeviationCoefficient = standardDeviation / mean;

    cout << "Standard Deviation is: " << standardDeviation << endl;
    cout << "Standard Deviation Coefficient is: " << standardDeviationCoefficient << endl;
}

// Standard Deviation for Discrete Data
void standardDeviationOfDiscreteData() {
    cout << "Enter size of data points: ";
    int size;
    cin >> size;

    float data[size];
    int f[size];
    cout << "Enter Data: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    cout << "Enter the frequency of data: ";
    for (int i = 0; i < size; i++) {
        cin >> f[i];
    }

    // Calculate Mean
    float sumFreq = 0, sumFreqData = 0;
    for (int i = 0; i < size; i++) {
        sumFreq += f[i];
        sumFreqData += data[i] * f[i];
    }
    float mean = sumFreqData / sumFreq;

    // Calculate Variance
    float variance = 0;
    for (int i = 0; i < size; i++) {
        variance += f[i] * pow(data[i] - mean, 2);
    }
    variance /= sumFreq;

    // Calculate Standard Deviation
    float standardDeviation = sqrt(variance);

    // Calculate Standard Deviation Coefficient
    float standardDeviationCoefficient = standardDeviation / mean;

    cout << "Standard Deviation for Discrete Data is: " << standardDeviation << endl;
    cout << "Standard Deviation Coefficient is: " << standardDeviationCoefficient << endl;
}

// Standard Deviation for Grouped Data
void standardDeviationOfGroupedData() {
    cout << "Enter the type of data series: Discrete (0) and Continuous (1): ";
    int seriesType;
    cin >> seriesType;

    if (seriesType == 0) {
        standardDeviationOfDiscreteData();
    }
    else if (seriesType == 1) {
        cout << "Enter number of classes: ";
        int n;
        cin >> n;

        int arr[n][2];
        cout << "Enter data (lower class limit first and then upper class limit): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        int f[n];
        cout << "Enter frequency: ";
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        // Calculate midpoints and Mean
        float midpoints[n], sumFreq = 0, sumFreqMid = 0;
        for (int i = 0; i < n; i++) {
            midpoints[i] = (arr[i][0] + arr[i][1]) / 2.0;
            sumFreq += f[i];
            sumFreqMid += midpoints[i] * f[i];
        }
        float mean = sumFreqMid / sumFreq;

        // Calculate Variance
        float variance = 0;
        for (int i = 0; i < n; i++) {
            variance += f[i] * pow(midpoints[i] - mean, 2);
        }
        variance /= sumFreq;

        // Calculate Standard Deviation
        float standardDeviation = sqrt(variance);

        // Calculate Standard Deviation Coefficient
        float standardDeviationCoefficient = standardDeviation / mean;

        cout << "Standard Deviation for Grouped Data is: " << standardDeviation << endl;
        cout << "Standard Deviation Coefficient is: " << standardDeviationCoefficient << endl;
    }
}
void regressionXOnY() {
    cout << "Enter size for X and Y series (Enter for X same for Y will be considered): " << endl;
    int n1;
    cin >> n1;
    
    vector<double> x(n1), y(n1);
    cout << "Enter data for X: ";
    for (int i = 0; i < n1; i++) cin >> x[i];

    cout << "Enter data for Y: ";
    for (int i = 0; i < n1; i++) cin >> y[i];

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    for (int i = 0; i < n1; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }
    
    
    double b = (n1 * sumXY - sumX * sumY) / (n1 * sumY2 - sumY * sumY);
    double a = (sumX - b * sumY) / n1;



    double meanY = sumY / n1;
    double ssTot = 0, ssRes = 0;
    for (int i = 0; i < n1; i++) {
        double yPred = a + b * y[i]; // Predicted value for X
        ssTot += (y[i] - meanY) * (y[i] - meanY); // Total Sum of Squares
        ssRes += (y[i] - yPred) * (y[i] - yPred); // Residual Sum of Squares
    }
    double rSquared = 1 - (ssRes / ssTot);

    // Calculate Standard Error of Estimate (SEE)
    double see = sqrt(ssRes / (n1 - 2));

    // Output results
    cout << fixed << setprecision(2);
    cout << "Regression line (X on Y): X = " << a << " + " << b << "Y" << endl;
    cout << "Coefficient of Determination (R*R): " << rSquared << endl;
    cout << "Standard Error of Estimate (SEE): " << see << endl;
}

// Function to calculate regression line Y on X: Y = a + bX
void regressionYOnX() {

    cout << "Enter size for X and Y series (Enter for X same for Y will be considered): " << endl;
    int n1;
    cin >> n1;
    
    vector<double> x(n1), y(n1);
    cout << "Enter data for X: ";
    for (int i = 0; i < n1; i++) cin >> x[i];

    cout << "Enter data for Y: ";
    for (int i = 0; i < n1; i++) cin >> y[i];

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    for (int i = 0; i < n1; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }
    
    
    double b = (n1 * sumXY - sumX * sumY) / (n1 * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n1;
    double meanX = sumX / n1;
    double ssTot = 0, ssRes = 0;
    for (int i = 0; i < n1; i++) {
        double yPred = a + b * x[i]; // Predicted value for Y
        ssTot += (x[i] - meanX) * (x[i] - meanX); // Total Sum of Squares
        ssRes += (x[i] - yPred) * (x[i] - yPred); // Residual Sum of Squares
    }
    double rSquared = 1 - (ssRes / ssTot);

    // Calculate Standard Error of Estimate (SEE)
    double see = sqrt(ssRes / (n1 - 2));

    // Output results
    cout << fixed << setprecision(2);
    cout << "Regression line (Y on X): Y = " << a << " + " << b << "X" << endl;
    cout << "Coefficient of Determination (R*R): " << rSquared << endl;
    cout << "Standard Error of Estimate (SEE): " << see << endl;
}
