// Question#4: You are developing a search feature for a large book database.
// Implement the KMP algorithm to search for a query string in the book’s content.
// Return all positions where the query occurs. Example:
// Input: Text = &quot;ababababc&quot; Pattern = &quot;abab&quot;
// Output: [0, 2, 4]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildLPS(string p) {
    int m = p.size();
    vector<int> lps(m,0);
    int len = 0, i = 1;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string t, string p, vector<int>& lps) {
    vector<int> ans;
    int n = t.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n) {
        if (t[i] == p[j]) {
            i++; j++;
            if (j == m) {
                ans.push_back(i-m);
                j = lps[j-1];
            }
        } else {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    return ans;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";

    vector<int> lps = buildLPS(pattern);
    for (int x : lps) cout << x << " ";
    cout << endl;

    vector<int> ans = kmp(text, pattern, lps);
    for (int x : ans) cout << x << " ";
}