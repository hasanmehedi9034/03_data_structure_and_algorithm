#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void reverse_sentence(string chk) {
    Stack <string> st;
    
    for (int i = 0; i < chk.length(); i++) {
        string word = "";

        while(i < chk.length() && chk[i] != ' ') {
            word +=  chk[i];
            i++;
        }

        st.push(word);
    }

    while(!st.empty()) {
        cout << st.Top() << endl;
        st.pop();
    }
}
  
int main() {
    string s = "I am Mehedi";
    reverse_sentence(s);
}