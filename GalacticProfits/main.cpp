#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int months, stock;
    cin >> months;
    cin >> stock;

    int myArray[stock][months];

    string thing;

    for (int stockIndex = 0; stockIndex < stock; ++stockIndex)
    {
        cin >> thing;
        for (int monthIndex = 0; monthIndex < months; ++monthIndex)
        {
            cin >> myArray[stockIndex][monthIndex];
        }
    }

    int difference[stock][months-1];

    for (int stockIndex = 0; stockIndex < stock; ++stockIndex)
    {
        for (int monthIndex = 0; monthIndex < months-1; ++monthIndex)
        {
            difference[stockIndex][monthIndex] = (myArray[stockIndex][months - 1] - myArray[stockIndex][monthIndex]);
        }
    }

    int maxValues;
    int minValues;

    int stockShareMax[stock] ;
    int stockShareMin[stock];

    for (int stockIndex = 0; stockIndex < stock; ++stockIndex)
    {
        stockShareMax[stockIndex] = 0;
        stockShareMin[stockIndex] = 0;
    }

    int maxSpent = 0;
    int minSpent = 0;

    for (int monthIndex = 0; monthIndex < months - 1 ; ++monthIndex)
    {
        maxValues = 0;
        minValues = 0;
        int whichStockMax = -1;
        int whichStockMin = -1;
        for (int stockIndex = 0; stockIndex < stock; ++stockIndex)
        {
            if (maxValues < difference[stockIndex][monthIndex])
            {
                maxValues = difference[stockIndex][monthIndex];
                whichStockMax = stockIndex;
            }

            if (minValues > difference[stockIndex][monthIndex])
            {
                minValues = difference[stockIndex][monthIndex];
                whichStockMin = stockIndex;
            }
        }
        if (whichStockMax != -1)
        {
            stockShareMax[whichStockMax] += (5000 / myArray[whichStockMax][monthIndex]) ;
            maxSpent += 5000;
        }

        if (whichStockMin != -1)
        {
            stockShareMin[whichStockMin] += (5000 / myArray[whichStockMin][monthIndex]);
            minSpent += 5000;
        }

    }

    int totalMax = 0;
    int totalMin = 0;

    for (int stockIndex = 0; stockIndex < stock; ++stockIndex)
    {
        totalMax += stockShareMax[stockIndex] * myArray[stockIndex][months - 1];
        totalMin += stockShareMin[stockIndex] * myArray[stockIndex][months - 1];
    }

    totalMax -= maxSpent;
    totalMin -= minSpent;

    cout << "Max: " << totalMax<< endl;
    cout << "Min: " << totalMin;

    return 0;
}
