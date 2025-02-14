#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fisherYates.h"
#include "prefixSum.h"


using namespace std;

void generated_sequence(int initArray [], int n){
    for (int i = 0; i < n; i++) {
        int length = 2 * n;
        int inintArray[length];
        for (int i = 0; i < n; i++) {
            initArray[i] = 1;
            initArray[n + i] = -1;
        }

}
}
int both_pos_and_neg(int initArray[], int iterations, int n) {

    int pos_and_neg = 0;

    for (int i = 0; i < iterations; i++) {
        generated_sequence(initArray,n);
        
        fisher_yates(initArray, 2*n, std::rand);
        if (!non_negative_prefix(initArray, 2*n) && !non_positive_prefix(initArray, 2*n) ) {
            pos_and_neg ++;
        }
    }

    return pos_and_neg;
}
int non_negative(int initArray[], int iterations, int n) {

    int non_negative= 0;

    for (int i = 0; i < iterations; i++) {
        generated_sequence(initArray,n);
        
        fisher_yates(initArray, 2*n, std::rand);
        if (non_negative_prefix(initArray, 2*n)) {
            non_negative ++;
        }
    }

    return non_negative;
}
int non_positive(int initArray[], int iterations, int n) {

    int non_positive= 0;

    for (int i = 0; i < iterations; i++) {
        generated_sequence(initArray,n);
        
        fisher_yates(initArray, 2*n, std::rand);
        if (non_negative_prefix(initArray, 2*n)) {
            non_positive++;
        }
    }

    return non_positive;
}