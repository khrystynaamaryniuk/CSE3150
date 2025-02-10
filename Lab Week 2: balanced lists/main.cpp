#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fisherYates.h"
#include "prefixSum.h"

using namespace std;

const int TRIALS = 15000;

int main() {
    srand(time(nullptr));
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int non_neg_prefix_count= 0;
    int non_pos_prefix_count=0;

    for (int i = 0; i < TRIALS; i++) {
        int length = 2 * n;
        int array[length];
        for (int i = 0; i < n; i++) {
            array[i] = 1;
            array[n + i] = -1;
        }
        show_data(array,length);
        fisher_yates(array, length, rand);
        show_data(array,length);
       if (non_negative_prefix(array, length)){ non_neg_prefix_count++;}
       if (non_positive_prefix(array, length)){non_pos_prefix_count++;}
       
    }
    double ratio_non_neg = static_cast<double>(non_neg_prefix_count) /TRIALS;
    double ratio_non_pos = static_cast<double>(non_pos_prefix_count) / TRIALS;

    cout << "Total sequences generated: " << TRIALS << endl;
    cout << "Sequences with only non-negative prefix sums: " << non_neg_prefix_count << endl;
    cout << "Sequences with only non-positive prefix sums: " << non_pos_prefix_count << endl;
    cout << "Proportion of non-negative prefix sequences: " << ratio_non_neg << endl;
    cout << "Proportion of non-positive prefix sequences: " << ratio_non_pos << endl;
    return 0;
}