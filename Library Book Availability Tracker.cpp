#include <iostream>
using namespace std;

void showStatus(char books[5][5]) {
    cout << "Library book status (A=Available, I=Issued, M=Missing):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++)
            cout << books[i][j] << ' ';
        cout << "\n";
    }
}

void countBooks(char books[5][5], int& available, int& issued, int& missing) {
    available = issued = missing = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (books[i][j] == 'A') available++;
            else if (books[i][j] == 'I') issued++;
            else if (books[i][j] == 'M') missing++;
        }
}

void shelfWithMaxMissing(char books[5][5]) {
    int maxMissing = -1;
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++)
            if (books[i][j] == 'M')
                count++;
        if (count > maxMissing)
            maxMissing = count;
    }
    cout << "\nShelf(s) with highest missing books (" << maxMissing << "): ";
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++)
            if (books[i][j] == 'M')
                count++;
        if (count == maxMissing)
            cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    char books[5][5];
    cout << "Enter status of books on 5 shelves (A/I/M):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cin >> books[i][j];
        }
    }

    showStatus(books);

    int available, issued, missing;
    countBooks(books, available, issued, missing);

    cout << "\nAvailable books: " << available << "\nIssued books: " << issued << "\nMissing books: " << missing << "\n";

    shelfWithMaxMissing(books);

    return 0;
}
