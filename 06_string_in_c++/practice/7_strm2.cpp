#include <bits/stdc++.h>
using namespace std;

int main() {
    string friends = "ripon karim raju faruk noor-novi awal afran didar bappi";
    stringstream name(friends);

    string single_name;
    int total_friend = 0;

    while (name >> single_name) {
        total_friend++;
        single_name[0] = single_name[0] - 'a' + 'A';

        cout << total_friend << ". " << single_name << endl;
    }
}