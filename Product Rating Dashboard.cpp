#include <iostream>
using namespace std;

void getRatings(int ratings[5][10]) {
    cout << "Enter ratings (1-5) for 5 products by 10 users:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ":\n";
        for (int j = 0; j < 10; j++) {
            cout << "  User " << j + 1 << ": ";
            cin >> ratings[i][j];
        }
    }
}

void averageRatings(int ratings[5][10], float averages[5]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++)
            sum += ratings[i][j];
        averages[i] = sum / 10.0f;
    }
}

void countPerfectRatings(int ratings[5][10], int perfectCounts[5]) {
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (ratings[i][j] == 5)
                count++;
        }
        perfectCounts[i] = count;
    }
}

int findWorstProduct(float averages[5]) {
    int minIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (averages[i] < averages[minIndex])
            minIndex = i;
    }
    return minIndex;
}

int main() {
    int ratings[5][10], perfectCounts[5];
    float averages[5];

    getRatings(ratings);
    averageRatings(ratings, averages);
    countPerfectRatings(ratings, perfectCounts);

    cout << "\nAverage ratings:\n";
    for (int i = 0; i < 5; i++)
        cout << "Product " << i + 1 << ": " << averages[i] << "\n";

    cout << "\nPerfect ratings count:\n";
    for (int i = 0; i < 5; i++)
        cout << "Product " << i + 1 << ": " << perfectCounts[i] << "\n";

    cout << "\nWorst average score product: Product " << findWorstProduct(averages) + 1 << "\n";

    return 0;
}
