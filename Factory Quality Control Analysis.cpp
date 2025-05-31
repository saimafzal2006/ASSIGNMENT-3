#include <iostream>
using namespace std;

void enterData(float defects[3][7]) {
    cout << "Enter defect percentage for 3 shifts over 7 days:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Shift " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> defects[i][j];
        }
    }
}

void averageDefectsPerShift(float defects[3][7], float averages[3]) {
    for (int i = 0; i < 3; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++)
            sum += defects[i][j];
        averages[i] = sum / 7.0f;
    }
}

void averageDefectsPerDay(float defects[3][7], float averages[7]) {
    for (int j = 0; j < 7; j++) {
        float sum = 0;
        for (int i = 0; i < 3; i++)
            sum += defects[i][j];
        averages[j] = sum / 3.0f;
    }
}

void identifyCriticalShifts(float averages[3]) {
    cout << "\nCritical shifts (avg defects > 10%):\n";
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (averages[i] > 10) {
            cout << "Shift " << i + 1 << ": " << averages[i] << "%\n";
            found = true;
        }
    }
    if (!found) cout << "None\n";
}

int main() {
    float defects[3][7], shiftAvg[3], dayAvg[7];

    enterData(defects);
    averageDefectsPerShift(defects, shiftAvg);
    averageDefectsPerDay(defects, dayAvg);

    cout << "\nAverage defects per shift:\n";
    for (int i = 0; i < 3; i++)
        cout << "Shift " << i + 1 << ": " << shiftAvg[i] << "%\n";

    cout << "\nAverage defects per day:\n";
    for (int i = 0; i < 7; i++)
        cout << "Day " << i + 1 << ": " << dayAvg[i] << "%\n";

    identifyCriticalShifts(shiftAvg);

    return 0;
}
