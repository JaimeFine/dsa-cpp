#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int flipNumber(int num) {
    if (num == 0) {
        return 0;
    }
    bool isNegative = (num < 0);
    if (isNegative) {
        num = -num;
    }

    string numStr = to_string(num);
    reverse(numStr.begin(), numStr.end());

    size_t start = 0;
    while (start < numStr.length() - 1 && numStr[start] == '0') {
        start++;
    }
    numStr = numStr.substr(start);

    int flipped = stoi(numStr);
    return isNegative ? -flipped : flipped;
}

int main() {
    string line;
    int result = 0;
    int normalCount = 0;

    while (getline(cin, line)) {
        if (line == '#') {
            break;
        }

        if (line.empty()) {
            cout << "invalid input" << endl;
            continue;
        }

        char op = line[0];
        string numPart = line.substr(1);

        if (numPart.empty()) {
            cout << "invalid input" << endl;
            continue;
        }

        bool isValidNum = true;
        for (char c : numPart) {
            if (!isdigit(c)) {
                isValidNum = false;
                break;
            }
        }

        if (!isValidNum) {
            cout << "invalid input" << endl;
            continue;
        }

        int x = stoi(numPart);

        switch (op) {
            case '+': {
                int newResult = result + x;
                normalCount++;
                if (normalCount == 3) {
                    result = flipNumber(newResult);
                    cout << result << endl;
                    normalCount = 0;
                } else {
                    result = newResult;
                    cout << result << endl;
                }
                break;
            }
            case '-': {
                int newResult = result - x;
                normalCount++;
                if (normalCount == 3) {
                    result = flipNumber(newResult);
                    cout << result << endl;
                    normalCount = 0;
                } else {
                    result = newResult;
                    cout << result << endl;
                }
                break;
            }
            case '*': {
                int newResult = result * x;
                normalCount++;
                if (normalCount == 3) {
                    result = flipNumber(newResult);
                    cout << result << endl;
                    normalCount = 0;
                } else {
                    result = newResult;
                    cout << result << endl;
                }
                break;
            }
            case '/': {
                if (x == 0) {
                    cout << "divided by zero" << endl;
                    break;
                }
                int newResult;
                if (result >= 0) {
                    newResult = result / x;
                } else {
                    newResult = -((-result) / x);
                }
                normalCount++;
                if (normalCount == 3) {
                    result = flipNumber(newResult);
                    cout << result << endl;
                    normalCount = 0;
                } else {
                    result = newResult;
                    cout << result << endl;
                }
                break;
            }
            default: {
                cout << "invalid input" << endl;
                break;
            }
        }
    }

    return 0;
}