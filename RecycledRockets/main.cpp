#include <iostream>
#include <vector>

using namespace std;

int main() {
    // This is the number that determines what is required
    vector<int> required;

    // This is the number that shows what number is available
    vector<int> spare;

    // How many different parts are we dealing with
    int amountOfDifParts = 0;

    // Get the number of different parts
    cin >> amountOfDifParts;

    // Gets the number of spare and required parts
    for (int i = 0; i < amountOfDifParts; ++i) {
        int value;
        cin >> value;
        required.push_back(value);
        cin >> value;
        spare.push_back(value);
    }

    // The ratio of spare parts to required
    vector<int> amount;
    for (int i = 0 ; i < amountOfDifParts ; i++)
    {
        amount.push_back(spare.at(i)/required.at(i));
    }

    // Determines how many total rockets can be rebuilt
    int canBeBuilt = amount.at(0);
    for (int i = 0; i < amountOfDifParts; ++i) {
        if (canBeBuilt > amount.at(i))
        {
            canBeBuilt = amount.at(i);
        }
    }

    // Output the number of rockets that can be built
    cout << canBeBuilt;

    return 0;
}
