#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Global DP table
int dpTable[100][100];
int breakTable[100][100];

// Recursive function
int ov_for_total_amount_of_pages_reviewed(int p[], int m[], int n) {
    int maxValue = 0; // To track the maximum value in dpTable

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 1) {
                if (i % 2 == 0) {
                    dpTable[i][j] = dpTable[i - 1][j];
                    breakTable[i][j] = 1;
                } else {
                    dpTable[i][j] = min(m[j - 1], p[i - 1]) + dpTable[i - 1][j];
                }
            } else if (dpTable[i - 1][j - 1] == dpTable[i - 2][j - 1]) {
                dpTable[i][j] = 0;
            } else {
                int workToday = min(p[i - 1], m[j - 1]) + dpTable[i - 1][j];
                int takeBreak = dpTable[i - 1][j - 1] + min(p[i - 1], m[j - 1]);
                dpTable[i][j] = max(workToday, takeBreak);
            }
            // Update the maxValue if the current dpTable[i][j] is greater
            maxValue = max(maxValue, dpTable[i][j]);
        }
    }

    return maxValue; // Return the largest value found in dpTable
}

int main() {
    int days = 4;
    int pages[4] = {100, 10, 70, 70};
    int efficiency[4] = {80, 40, 20, 10};

    // Initialize DP table to -1
    for (int i = 0; i <= days; ++i) {
        for (int j = 0; j <= days; ++j) {
            dpTable[i][j] = 0;
        }
    }

    int result = ov_for_total_amount_of_pages_reviewed(pages, efficiency, days);

    // Output results to file
    ofstream a("pages_pb_out.txt");
    if (a.is_open()) {
        // Write DP table
        for (int i = 1; i <= days; i++) {
            for (int k = 1; k <= days; k++) {
                a << dpTable[k][i] << " ";
            }
            a << endl;
        }

        a << "RESULT: " << result << endl;
        // Write optimal result
        a.close();
    }

    ofstream b("pages_pc_out.txt");
    if (b.is_open()){
        b << "Choice Table:\n";
        for (int i = 1; i <= days; i++) {
            for (int k = 1; k <= days; k++) {
                b << breakTable[k][i] << " ";
            }
            b << endl;
        }

        b.close();

    }
    

    return 0;
}