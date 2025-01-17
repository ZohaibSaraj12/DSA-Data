// // Written by Zabi
// /*
// #include <iostream>

// using namespace std;

// int main()
// {
//     // ticket price and snacks price is defined initially use CONST keywork for redundant code
//     const int ticket_price=300;
//     const int snacks_price=200;
//     int price;

//     int total;
//     cout<< "Ticket price for each movie is: " << ticket_price << endl;
//     cout<< "Snacks price is : " << snacks_price << endl;
//     // Use String class Array for better performance
//     // Switch Case only displays the name it will cause some errors for edge cases
//     string movies[] = {"Iron Man", "Spider Man", "Klaus", "Inside Out"};
//     int option;
//     do {
//         cout << "Select a Movie:\n1: Iron Man\n2: Spider Man\n3: Klaus\n4: Inside Out\n";
//         cin >> option;

//         if (option < 1 || option > 4) {
//             cout << "Invalid Input! Please enter a number between 1 and 4.\n";
//         }
//     } while (option < 1 || option > 4);

//     cout << "You selected: " << movies[option - 1] << endl;

//     cout<<" 1 = booked and 0 = Available " << endl;
//     int A[8][8]=
//     {
//     {0,1,0,0,0,0,0,0},
//     {0,0,0,0,1,0,0,0},
//     {0,1,0,0,0,0,0,0},
//     {0,0,1,0,0,0,0,0},
//     {0,0,0,0,0,1,0,0},
//     {0,1,0,0,0,0,0,0},
//     {0,0,0,1,0,0,0,0},
//     {0,0,0,0,0,0,1,0}
//     };

//     for(int i=0;i<8;i++)
//     {
//         for(int j=0;j<8;j++)
//         {
//             cout<< A[i][j]<< "   ";
//         }
//         cout<< endl;
//     }

//     int ticket;
//     char snacks_choice;
//     char confirm_booking;
//       do {
//         cout << "Enter the number of tickets you want (1 to 56): ";
//         cin >> ticket;
//         if (ticket < 1 || ticket > 56) {
//             cout << "Invalid ticket count. Try again.\n";
//         }
//     } while (ticket < 1 || ticket > 56);
//       price = ticket_price * ticket;
//     cout << "Price for seats: " << price << endl;

//     cout << "Do you want snacks? (Press Y/y for YES, any other key for NO): ";
//     cin >> snacks_choice;

//     cout << "Confirm Booking! (Press Y/y for YES, any other key for NO): ";
//     cin >> confirm_booking;

//     if (confirm_booking == 'Y' || confirm_booking == 'y') {
//         total = price;
//         if (snacks_choice == 'Y' || snacks_choice == 'y') {
//             total += snacks_price;
//         }

//         cout << "Your Seat is Confirmed.\n";
//         cout << "Total Bill: " << total << endl;
//         cout << "Movie: " << movies[option - 1] << endl;
//     } else {
//         cout << "Goodbye!\n";
//     }

//     return 0;
// }
// */

// #include <iostream>

// using namespace std;

// int main()
// {
//     int ticket_price=300;
//     int snacks_price=200;
//     int price;

//     int total;
//     cout<< "Ticket price for each movie is: " << ticket_price << endl;
//     cout<< "Snacks price is : " << snacks_price << endl;

//     string movies[] = {"Iron Man", "Spider Man", "Klaus", "Inside Out"};
//     int option;
//     do {
//         cout << "Select a Movie:\n1: Iron Man\n2: Spider Man\n3: Klaus\n4: Inside Out\n";
//         cin >> option;

//         if (option < 1 || option > 4) {
//             cout << "Invalid Input! Please enter a number between 1 and 4.\n";
//         }
//     } while (option < 1 || option > 4);

//     cout << "You selected: " << movies[option - 1] << endl;

//     cout<<" 1 = booked and 0 = Available " << endl;
//     int A[8][8]=
//     {
//     {0,1,0,0,0,0,0,0},
//     {0,0,0,0,1,0,0,0},
//     {0,1,0,0,0,0,0,0},
//     {0,0,1,0,0,0,0,0},
//     {0,0,0,0,0,1,0,0},
//     {0,1,0,0,0,0,0,0},
//     {0,0,0,1,0,0,0,0},
//     {0,0,0,0,0,0,1,0}
//     };

//     for(int i=0;i<8;i++)
//     {
//         for(int j=0;j<8;j++)
//         {
//             cout<< A[i][j]<< "   ";
//         }
//         cout<< endl;
//     }

//     int ticket;
//     char snacks_choice;
//     char confirm_booking;
//       do {
//         cout << "Enter the number of tickets you want (1 to 56): ";
//         cin >> ticket;
//         if (ticket < 1 || ticket > 56) {
//             cout << "Invalid ticket count. Try again.\n";
//         }
//     } while (ticket < 1 || ticket > 56);
//       price = ticket_price * ticket;
//     cout << "Price for seats: " << price << endl;

//     cout << "Do you want snacks? (Press Y/y for YES, any other key for NO): ";
//     cin >> snacks_choice;

//     cout << "Confirm Booking! (Press Y/y for YES, any other key for NO): ";
//     cin >> confirm_booking;

//     if (confirm_booking == 'Y' || confirm_booking == 'y') {
//         total = price;
//         if (snacks_choice == 'Y' || snacks_choice == 'y') {
//             total += snacks_price;
//         }

//         cout << "Your Seat is Confirmed.\n";
//         cout << "Total Bill: " << total << endl;
//         cout << "Movie: " << movies[option - 1] << endl;
//     } else {
//         cout << "Goodbye!\n";
//     }

//     return 0;
// }
#include <iostream>

using namespace std;

int main()
{
    int ticket_price = 300;
    int snacks_price = 200;
    int price;
    // code for selection of movie
    int total;
    cout << "Ticket price for each movie is: " << ticket_price << endl;
    cout << "Snacks price is : " << snacks_price << endl;
    cout << "Select a Movie: ";
    int option;

    string movies[] = {"Iron Man", "Spider Man", "Klause", "Inside Out"};
    do
    {
        cout << "Select a Movie:\n1: Iron Man\n2: Spider Man\n3: Klaus\n4: Inside Out\n";
        cin >> option;

        if (option < 1 || option > 4)
        {
            cout << "Invalid Input! Please enter a number between 1 and 4.\n";
        }
    } while (option < 1 || option > 4);

    // code for displaying seating arrangement
    cout << " 1 = booked and 0 = Available " << endl;
    int A[8][8] =
        {
            {0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0}};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << A[i][j] << "   ";
        }
        cout << endl;
    }
    // code for number of tickets
    int ticket;
    cout << " Enter number of tickets you want " << endl;
    cin >> ticket;
    while (ticket > 56 || ticket <= 0)
    {
        cout << "please enter correct number of tickets";
        cin >> ticket;
    }

    price = ticket_price * ticket;
    cout << " price for seats is : " << price << endl;

    // code for snacks
    cout << " Do you want Snacks?" << endl;
    char i;
    cout << " Press Y or y for YES and press any key for NO " << endl;
    cin >> i;
    if (i == 'Y' || i == 'y')
        cout << " YES " << endl;
    else
        cout << " NO " << endl;
    // code for asking for confirmation
    cout << " Do you want to book tickets " << endl;
    char n;
    cout << "Confirm Booking! Press Y or y for YES and any key for NO " << endl;
    cin >> n;
    if ((n == 'Y' || n == 'y') && (i == 'Y' || i == 'y'))
    {
        total = price + snacks_price;
        cout << " Your Seat is Confirmed " << endl;
        cout << " Total Bill is : " << total << endl;
        cout << " movie is : " << movies[option - 1] << endl;
        cout << " Seat as selected by you " << endl;
    }
    else if ((n == 'y' || n == 'Y') && (i != 'Y' && i != 'y'))
    {
        total = price;
        cout << " Your Seat is Confirmed " << endl;
        cout << " Total Bill is : " << total << endl;
        cout << " movie is : " << movies[option - 1] << endl;
        cout << " Seat as selected by you " << endl;
    }
    else
    {
        cout << " Good bye " << endl;
    }

    return 0;
}