#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> required;
    vector<int> spare;
    int amountOfDifParts = 0;

    cin >> amountOfDifParts;

    for (int i = 0; i < amountOfDifParts; ++i) {
        int value;
        cin >> value;
        required.push_back(value);
        cin >> value;
        spare.push_back(value);
    }

    vector<int> amount;
    for (int i = 0 ; i < amountOfDifParts ; i++)
    {
        amount.push_back(spare.at(i)/required.at(i));
    }

    int canBeBuilt = amount.at(0);
    for (int i = 0; i < amountOfDifParts; ++i) {
        if (canBeBuilt > amount.at(i))
        {
            canBeBuilt = amount.at(i);
        }
    }

    cout << canBeBuilt;

    return 0;
}
