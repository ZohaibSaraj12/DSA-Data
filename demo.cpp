#include <iostream>
using namespace std;

int main() {
    int ticket_price = 300;
    int snacks_price = 200;
    int total_price = 0, ticket_count;
    int total_seats = 8 * 8; // 8x8 theater
    int seats[8][8] = {0}; // Initialize all seats as available (0)
    string movies[] = {"Iron Man", "Spider Man", "Klaus", "Inside Out"};
    int movie_option, row, col;
    char confirm_snacks, confirm_booking;

    // Display ticket and snacks prices
    cout << "Ticket price for each movie: " << ticket_price << endl;
    cout << "Snacks price: " << snacks_price << endl;

    // Movie selection
    do {
        cout << "Select a Movie:\n1: Iron Man\n2: Spider Man\n3: Klaus\n4: Inside Out\n";
        cin >> movie_option;
        if (movie_option < 1 || movie_option > 4) {
            cout << "Invalid Input! Please enter a number between 1 and 4.\n";
        }
    } while (movie_option < 1 || movie_option > 4);

    // Display initial seating arrangement
    cout << "1 = Booked, 0 = Available\n";
    cout << "Seat Availability:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    // Ticket booking
    cout << "Enter the number of tickets you want to book (1-56): ";
    cin >> ticket_count;
    while (ticket_count <= 0 || ticket_count > 56) {
        cout << "Invalid number of tickets. Please enter between 1 and 56: ";
        cin >> ticket_count;
    }

    int booked_tickets = 0;
    while (booked_tickets < ticket_count) {
        cout << "Enter row number (1-8): ";
        cin >> row;
        cout << "Enter column number (1-8): ";
        cin >> col;

        if (row >= 1 && row <= 8 && col >= 1 && col <= 8) {
            if (seats[row - 1][col - 1] == 0) {
                seats[row - 1][col - 1] = 1;
                booked_tickets++;
                cout << "Seat (" << row << ", " << col << ") booked successfully.\n";
            } else {
                cout << "Seat already booked. Choose a different seat.\n";
            }
        } else {
            cout << "Invalid seat selection. Try again.\n";
        }
    }

    // Calculate ticket price
    total_price += ticket_count * ticket_price;

    // Ask for snacks
    cout << "Do you want snacks? Press Y/y for YES or any other key for NO: ";
    cin >> confirm_snacks;
    if (confirm_snacks == 'Y' || confirm_snacks == 'y') {
        total_price += snacks_price;
        cout << "Snacks added to your bill.\n";
    } else {
        cout << "No snacks selected.\n";
    }

    // Confirm booking
    cout << "Do you want to confirm your booking? Press Y/y for YES or any other key for NO: ";
    cin >> confirm_booking;

    if (confirm_booking == 'Y' || confirm_booking == 'y') {
        cout << "Booking confirmed!\n";
        cout << "Movie: " << movies[movie_option - 1] << endl;
        cout << "Total bill: " << total_price << endl;

        // Display final seating arrangement
        cout << "Updated Seat Availability:\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Booking canceled. Goodbye!\n";
    }

    return 0;
}
