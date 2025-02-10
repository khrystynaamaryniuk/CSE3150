#include <iostream>
#include <random>
#include "fisherYates.h"


using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void show_data(int array[], const int length) {
  for (int i=0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout<< endl;
}

void fisher_yates(int array[], const int length, int (* random_function)()) {
  for (int i = 0; i < length -1; i++) {
    int random_location = random_function() % (length-i);
    swap(&array[i], & array[random_location + i]);
  }
}