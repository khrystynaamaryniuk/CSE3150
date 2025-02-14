#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fisherYates.h"
#include "prefixSum.h"
#include "setUp.h"


using namespace std;



int main() {
    std::cout << "Running main program..." << std::endl;
    
    srand(time(nullptr));
    int n, trials;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the amount of iterations: ";
    cin>> trials;
    int initArray[2*n];
    int non_neg_prefix_count= non_negative(initArray,trials,n);
    int non_pos_prefix_count=non_positive(initArray,trials,n);
    int pos_and_neg=both_pos_and_neg(initArray,trials,n);
    


    double ratio_non_neg = static_cast<double>(non_neg_prefix_count) /trials;
    double ratio_non_pos = static_cast<double>(non_pos_prefix_count) / trials;
    double ratio_non_pos_and_non_neg =  static_cast<double>(pos_and_neg)/trials;

    cout << "Total sequences generated: " << trials << endl;
    cout << "Sequences with only non-negative prefix sums: " << non_neg_prefix_count << endl;
    cout << "Sequences with only non-positive prefix sums: " << non_pos_prefix_count << endl;
    cout << "Sequences with both prefix sums: " << pos_and_neg << endl;
    cout << "Proportion of non-negative prefix sequences: " << ratio_non_neg << endl;
    cout << "Proportion of non-positive prefix sequences: " << ratio_non_pos << endl;
    cout << "Proportion of both " << ratio_non_pos_and_non_neg << endl;
    return 0;
}