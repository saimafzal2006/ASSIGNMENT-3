#include <iostream>
using namespace std;

void inputMarks(int marks[10][5]) {
    cout << "Enter marks for 10 students (5 subjects each):\n";
    for (int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
}

void calculateTotals(int marks[10][5], int totals[10]) {
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += marks[i][j];
        totals[i] = sum;
    }
}

void calculateAverages(int totals[10], float averages[10]) {
    for (int i = 0; i < 10; i++) {
        averages[i] = totals[i] / 5.0f;
    }
}

int findTopScorer(int totals[10]) {
    int maxIndex = 0;
    for (int i = 1; i < 10; i++) {
        if (totals[i] > totals[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

char getGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else return 'F';
}

void displayGrades(float averages[10]) {
    cout << "\nGrades:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << ": Grade " << getGrade(averages[i]) << "\n";
    }
}

int main() {
    int marks[10][5], totals[10];
    float averages[10];

    inputMarks(marks);
    calculateTotals(marks, totals);
    calculateAverages(totals, averages);

    int top = findTopScorer(totals);
    cout << "\nTop scorer: Student " << top + 1 << " with total marks " << totals[top] << "\n";

    displayGrades(averages);

    return 0;
}

