#include <iostream>
using namespace std;

void displaySeats(char seats[6][4]) {
    cout << "Seat Chart (E=Empty, B=Booked):\n";
    for (int i = 0; i < 6; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
            cout << seats[i][j] << ' ';
        cout << "\n";
    }
}

void bookSeat(char seats[6][4], int row, int col) {
    if (row < 1 || row > 6 || col < 1 || col > 4) {
        cout << "Invalid seat!\n";
        return;
    }
    if (seats[row - 1][col - 1] == 'E') {
        seats[row - 1][col - 1] = 'B';
        cout << "Seat booked successfully.\n";
    }
    else {
        cout << "Seat already booked.\n";
    }
}

int countAvailable(char seats[6][4]) {
    int count = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (seats[i][j] == 'E')
                count++;
    return count;
}

int rowWithMaxEmpty(char seats[6][4]) {
    int maxEmpty = -1, maxRow = -1;
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++)
            if (seats[i][j] == 'E')
                count++;
        if (count > maxEmpty) {
            maxEmpty = count;
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    char seats[6][4];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            seats[i][j] = 'E';

    displaySeats(seats);

    int row, col;
    cout << "Enter seat to book (row col): ";
    cin >> row >> col;
    bookSeat(seats, row, col);

    displaySeats(seats);

    cout << "Available seats: " << countAvailable(seats) << "\n";
    cout << "Row with maximum empty seats: " << rowWithMaxEmpty(seats) + 1 << "\n";

    return 0;
}
