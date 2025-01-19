#include <iostream>
#include <string>

using namespace std;

int get_input(string user_prompt) {
    int input;
    cout << user_prompt;
    cin >> input;
    return input;
}

int main() {
    string positions[2][4] = {{"AA", "AB", "AC", "AD"}, {"BA", "BB", "BC", "BD"}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int value = get_input("positional value of " + positions[i][j] + " matrix " + static_cast<char>('1' + i) + ": ");
            positions[i][j] = value;
        }
    }

    return 0;
}
