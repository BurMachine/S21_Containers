using namespace std;

#include <iostream>
#include <vector>

int main() {
    vector<int> var1{1, 2, 3};

    var1.insert(var1.begin(), var1.capacity(), var1.at(2));
    for (int item : var1) {
        cout << item << endl;
    }
}
