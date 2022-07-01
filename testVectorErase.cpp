#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(8);
    test.push_back(9);

    for (auto i : test) {
        cout << i << "-";
    }

    cout << endl;

    auto it = test.begin();
    for (auto i : test) {
        if (i == 3) {
            test.erase(it);
        }
        it++;
    }

    for (auto i : test) {
        cout << i << "-";
    }

    cout << endl;

    return 0;
}