#include <iostream>
using namespace std;

void readSales(float sales[4][7]) {
    cout << "Enter daily sales of 4 items over 7 days:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Item " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}

void totalSalesPerItem(float sales[4][7], float itemTotals[4]) {
    for (int i = 0; i < 4; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++)
            sum += sales[i][j];
        itemTotals[i] = sum;
    }
}

void totalSalesPerDay(float sales[4][7], float dayTotals[7]) {
    for (int j = 0; j < 7; j++) {
        float sum = 0;
        for (int i = 0; i < 4; i++)
            sum += sales[i][j];
        dayTotals[j] = sum;
    }
}

int dayWithMaxSales(float dayTotals[7]) {
    int maxIndex = 0;
    for (int i = 1; i < 7; i++) {
        if (dayTotals[i] > dayTotals[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int itemWithMaxSales(float itemTotals[4]) {
    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (itemTotals[i] > itemTotals[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int main() {
    float sales[4][7], itemTotals[4], dayTotals[7];

    readSales(sales);
    totalSalesPerItem(sales, itemTotals);
    totalSalesPerDay(sales, dayTotals);

    cout << "\nTotal sales per item:\n";
    for (int i = 0; i < 4; i++)
        cout << "Item " << i + 1 << ": " << itemTotals[i] << "\n";

    cout << "\nTotal sales per day:\n";
    for (int i = 0; i < 7; i++)
        cout << "Day " << i + 1 << ": " << dayTotals[i] << "\n";

    cout << "\nDay with highest sales: Day " << dayWithMaxSales(dayTotals) + 1 << "\n";
    cout << "Item sold the most: Item " << itemWithMaxSales(itemTotals) + 1 << "\n";

    return 0;
}
