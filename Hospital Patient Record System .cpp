#include <iostream>
using namespace std;

void recordStatus(char status[5][7]) {
    cout << "Enter status for 5 patients over 7 days (S/C/R):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Patient " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> status[i][j];
        }
    }
}

void countStatus(char status[5][7], int& stable, int& critical, int& recovered) {
    stable = critical = recovered = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++) {
            if (status[i][j] == 'S') stable++;
            else if (status[i][j] == 'C') critical++;
            else if (status[i][j] == 'R') recovered++;
        }
}

void countCriticalDays(char status[5][7], int criticalDays[5]) {
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 7; j++)
            if (status[i][j] == 'C') count++;
        criticalDays[i] = count;
    }
}

int main() {
    char status[5][7];
    int stable, critical, recovered, criticalDays[5];

    recordStatus(status);
    countStatus(status, stable, critical, recovered);
    countCriticalDays(status, criticalDays);

    cout << "\nTotal Stable: " << stable << "\nTotal Critical: " << critical << "\nTotal Recovered: " << recovered << "\n";

    for (int i = 0; i < 5; i++)
        cout << "Patient " << i + 1 << " critical days: " << criticalDays[i] << "\n";

    return 0;
}
