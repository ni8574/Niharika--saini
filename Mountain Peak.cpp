#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= heights[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(heights[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
