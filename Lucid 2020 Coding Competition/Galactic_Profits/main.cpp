#include <iostream>
#include <vector>

using namespace std;

int main() {
    int months, stockNum;
    cin >> months;
    cin >> stockNum;

    int myArray[stockNum][months];



    for (int i = 0; i < stockNum; ++i) {
        for (int j = 0; j < months; ++j) {
            cin >> myArray[i][j];
        }
    }

    vector<int> monthNum, whichStock, difference;

    for (int i = 0; i < stockNum; ++i) {
        for (int j = 0; j < months; ++j) {
            if (myArray[i][j] > myArray[i][months-1])
            {
                monthNum.push_back(j);
                whichStock.push_back(i);
                difference.push_back(myArray[i][j] - myArray[i][months-1]);
            }
        }
    }

    for (int i = 0; i < whichStock.size(); ++i) {
        for (int j = 0; j < monthNum.size(); ++j) {

        }
    }
    return 0;
}
