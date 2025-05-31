#include <iostream>
using namespace std;

void inputVotes(int votes[4][6]) {
    cout << "Enter votes for 4 candidates from 6 polling stations:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Candidate " << i + 1 << ":\n";
        for (int j = 0; j < 6; j++) {
            cout << "  Station " << j + 1 << ": ";
            cin >> votes[i][j];
        }
    }
}

void totalVotesPerCandidate(int votes[4][6], int totals[4]) {
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 6; j++)
            sum += votes[i][j];
        totals[i] = sum;
    }
}

void totalVotesPerStation(int votes[4][6], int totals[6]) {
    for (int j = 0; j < 6; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += votes[i][j];
        totals[j] = sum;
    }
}

int findWinner(int totals[4]) {
    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (totals[i] > totals[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

void checkLowTurnout(int totals[6]) {
    cout << "\nPolling stations with voter turnout less than 100:\n";
    bool found = false;
    for (int i = 0; i < 6; i++) {
        if (totals[i] < 100) {
            cout << "Station " << i + 1 << ": " << totals[i] << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "None\n";
}

int main() {
    int votes[4][6], candidateTotals[4], stationTotals[6];

    inputVotes(votes);
    totalVotesPerCandidate(votes, candidateTotals);
    totalVotesPerStation(votes, stationTotals);

    cout << "\nTotal votes per candidate:\n";
    for (int i = 0; i < 4; i++)
        cout << "Candidate " << i + 1 << ": " << candidateTotals[i] << "\n";

    cout << "\nTotal votes per polling station:\n";
    for (int i = 0; i < 6; i++)
        cout << "Station " << i + 1 << ": " << stationTotals[i] << "\n";

    int winner = findWinner(candidateTotals);
    cout << "\nWinner: Candidate " << winner + 1 << "\n";

    checkLowTurnout(stationTotals);

    return 0;
}
