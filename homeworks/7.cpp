#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> users;

    users["tourist"] = 3858;
    users["ksun48"] = 3679;
    users["Benq"] = 3658;
    users["Um_nik"] = 3648;
    users["apiad"] = 3638;
    users["Stonefeang"] = 3630;
    users["ecnerwala"] = 3613;
    users["mnbvmar"] = 3555;
    users["newbiedmy"] = 3516;
    users["semiexp"] = 3481;

    string name;
    cin >> name;
    cout << users[name] << endl;
}

