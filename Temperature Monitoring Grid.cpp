#include <iostream>
using namespace std;

void readTemperatures(float temps[5][5]) {
    cout << "Enter temperature for 5 zones (rows) and 5 locations (cols):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Zone " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Location " << j + 1 << ": ";
            cin >> temps[i][j];
        }
    }
}

void averageTempPerZone(float temps[5][5], float averages[5]) {
    for (int i = 0; i < 5; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++)
            sum += temps[i][j];
        averages[i] = sum / 5.0f;
    }
}

void detectExtremeSpots(float temps[5][5]) {
    cout << "\nExtreme Hot Spots (>= 40):\n";
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (temps[i][j] >= 40)
                cout << "Zone " << i + 1 << ", Location " << j + 1 << ": " << temps[i][j] << "\n";

    cout << "\nExtreme Cold Spots (<= 0):\n";
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (temps[i][j] <= 0)
                cout << "Zone " << i + 1 << ", Location " << j + 1 << ": " << temps[i][j] << "\n";
}

int main() {
    float temps[5][5], averages[5];

    readTemperatures(temps);
    averageTempPerZone(temps, averages);

    cout << "\nAverage temperature per zone:\n";
    for (int i = 0; i < 5; i++)
        cout << "Zone " << i + 1 << ": " << averages[i] << "\n";

    detectExtremeSpots(temps);

    return 0;
}
