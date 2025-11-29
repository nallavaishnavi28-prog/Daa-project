#include <bits/stdc++.h>
using namespace std;

// Scanner class for preprocessing and KMP search
class scaner {

public:
    string text;
    string pattern;

    // Constructor to initialize text and pattern
    scaner(string t, string p) {
        text = t;
        pattern = p;
    }

public:
    // LPS TABLE CALCULATION
    vector<int> computelps() {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n) {
            // Case 1: Matching characters → extend prefix-suffix
            if (pattern[len] == pattern[i]) {
                len++;
                lps[i] = len;
                i++;
            }
            // Case 2: Mismatch after some matches
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }

                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    //KMP algo
    vector<int> kmp(vector<int>& lps) {
        vector<int> result;
        int i = 0;              // Pointer for text
        int j = 0;              // Pointer for pattern

        while (i < text.size()) {
            // Case 1: Characters match → move both pointers
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            // Case 2: Mismatch handling using LPS to skip unnecessary comparisons
            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }

            // Case 3: Full pattern matched → store index and continue search
            if (j == pattern.length()) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        }
        return result;
    }
};

int main() {
    string pattern, text;

    // Input text and pattern (supports spaces)
    cout << "Enter the text   : ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Create scanner object
    scaner s(text, pattern);

    // Compute LPS array
    vector<int> lps = s.computelps();

    // Print LPS table
    cout << "\n--- LPS (Prefix Table) ---\n";
    for (int i = 0; i < pattern.size(); i++) {
        cout << "lps[" << i << "] = " << lps[i] << endl; // Show value of each LPS index
    }

    // Perform KMP search
    vector<int> result = s.kmp(lps);

    // Print matches
    cout << "\n--- Match Results ---\n";
    if (result.empty()) {
        cout << "Pattern not found in the text.\n";
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << "Pattern found at index: " << result[i] << endl;
        }
    }

    return 0;
}
