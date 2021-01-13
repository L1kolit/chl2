#include <iostream>
#include <vector>

    using namespace std;

int main() {
    vector<int> t[3];
    t[0].insert(t[0].end(), 5);
    t[1].insert(t[1].end(), 75);
    t[2].insert(t[2].end(), 13);
    cout << t[0][0] << endl << t[1][0] << endl << t[2][0] << endl;
    return 0;
}