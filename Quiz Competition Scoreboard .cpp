#include <iostream>
using namespace std;

void inputScores(int scores[6][4]) {
    cout << "Enter scores for 6 teams in 4 rounds:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Team " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++) {
            cout << "  Round " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
}

void totalScoresPerTeam(int scores[6][4], int totals[6]) {
    for (int i = 0; i < 6; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += scores[i][j];
        totals[i] = sum;
    }
}

int findWinner(int totals[6]) {
    int maxIndex = 0;
    for (int i = 1; i < 6; i++) {
        if (totals[i] > totals[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int findRunnerUp(int totals[6], int winnerIndex) {
    int maxIndex = -1;
    int maxVal = -1;
    for (int i = 0; i < 6; i++) {
        if (i != winnerIndex && totals[i] > maxVal) {
            maxVal = totals[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void displayFailures(int scores[6][4]) {
    cout << "\nTeams failing to score >10 in any round:\n";
    for (int i = 0; i < 6; i++) {
        bool failed = false;
        for (int j = 0; j < 4; j++) {
            if (scores[i][j] <= 10) {
                failed = true;
                break;
            }
        }
        if (failed)
            cout << "Team " << i + 1 << "\n";
    }
}

int main() {
    int scores[6][4], totals[6];

    inputScores(scores);
    totalScoresPerTeam(scores, totals);

    int winner = findWinner(totals);
    int runnerUp = findRunnerUp(totals, winner);

    cout << "\nTotal scores per team:\n";
    for (int i = 0; i < 6; i++)
        cout << "Team " << i + 1 << ": " << totals[i] << "\n";

    cout << "\nWinner: Team " << winner + 1 << "\n";
    cout << "Runner-up: Team " << runnerUp + 1 << "\n";

    displayFailures(scores);

    return 0;
}
