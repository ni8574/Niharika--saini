#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        stack<char> st;
        string ans = "";

        for (char ch : s) {

           
            if (isalpha(ch)) {
                ans += ch;
            }

           
            else if (ch == '(') {
                st.push(ch);
            }

        
            else if (ch == ')') {
                while (st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }

            
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       priority(st.top()) >= priority(ch)) {
                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << ans << endl;
    }

    return 0;
}
