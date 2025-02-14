#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "./include/doctest.h"
#include "prefixSum.h"
#include "fisherYates.h" 
#include "setUp.h"

TEST_CASE("Test non-negative prefix sum") {
  int num0[]={1,0,1,-1};
  int num1[]={-1, 0, 1, 1};
  CHECK(non_negative_prefix(num0, 4) == true); 
  CHECK(non_negative_prefix(num1, 3) == false);
}
TEST_CASE("Test non-positive prefix sum") {
    int num0[] = {-1, 0, 1, -1}; 
    int num1[] = {1, -1, 1}; 
    CHECK(4==sizeof(num0)/sizeof(num0[0]));
    CHECK(3==sizeof(num1)/sizeof(num1[0]));
    CHECK(non_positive_prefix(num0, 4) == true);
    CHECK(non_positive_prefix(num1, 3) == false);
}
TEST_CASE("Swap Testing ") {

    int a = 1, b = -1;
    swap(&a, &b);
    CHECK(a == -1);
    CHECK(b == 1);
    CHECK_FALSE(b == -1);


}
bool in_list(int list[], int length, int val){
  for (int i = 0; i < length; i++) {
    if (list[i] == val) return true;
  }
  return false;
}
bool once_in_list(int list[], int length,int val){
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (list[i] == val) count++;
    if (count > 1) return false;  
  }
  return count == 1;
}
TEST_CASE("Test in_list") {

  int num0[]={1,2,3,4,5};
  CHECK(5==sizeof(num0)/sizeof(num0[0]));
  CHECK(in_list(num0,5,1));
  CHECK(in_list(num0,5,2));
  CHECK(in_list(num0,5,3));
  CHECK(in_list(num0,5,4));
  CHECK(in_list(num0,5,5));
  CHECK_FALSE(in_list(num0,5,6));

}
TEST_CASE("Test once_in_list") {
  
  int num0[]={1,2,3,4,5,5};
  CHECK(6==sizeof(num0)/sizeof(num0[0]));
  CHECK(once_in_list(num0,6,1));
  CHECK(once_in_list(num0,6,2));
  CHECK(once_in_list(num0,6,3));
  CHECK(once_in_list(num0,6,4));
  CHECK_FALSE(once_in_list(num0,6,5));
}
static int i=0;
int not_random_function(){
  return i++;
}
TEST_CASE("Test non-random Fisher-Yates shuffle with 3 numbers") {
    int num0[] = {1, 2, 3};
    CHECK(3 == sizeof(num0) / sizeof(num0[0]));
    show_data(num0, 3);
    fisher_yates(num0, 3, not_random_function);
    show_data(num0, 3);

    /* not_rand_function in fisher yates will do the following:
    1st iteration - random_location = 0 % (3 - 0) = 0, no change 
    2nd iteration - random_location = 1 % (3 - 1) = 1, swap(array[1], array[1+1]);
    the array becomes: {1, 3, 2}
    3rd iteration - random_location = 2 % (3 - 2) = 0, swap(array[2], array[2+0]);
    the array becomes: {1, 3, 2}
    */
    CHECK(num0[0] == 1); 
    CHECK(num0[1] == 3); 
    CHECK(num0[2] == 2); 
}


TEST_CASE("Test non-random Fisher-Yates shuffle 5 numbers ") {
    //reseting static int i
    i=0;
    int num0[] = {1, 2, 3, 4, 5};
    CHECK(5==sizeof(num0)/sizeof(num0[0]));
    show_data(num0,5);
    fisher_yates(num0,5, not_random_function);
    show_data(num0,5);
    /* not_rand_function in fisher yates will do the following
    1st iteration - random_location = 0 % (5 - 0) = 0, no change 
    2nd iteration - random_location = 1 % (5 - 1) = 1, swap(array[1],array[1+1]);
    the array becomes: {1, 3, 2, 4, 5}
    3rd iteration - random_location = 2 % (5 - 2) = 2, swap(array[2],array[2+2]);
    the array becomes: {1, 3, 5, 4, 2}
    4th iteration - random_location = 3 % (5 - 3) = 1, swap(array[3],array[3+1]);
    the array becomes: {1, 3, 5, 4, 2}
  */
    CHECK(num0[0] == 1); 
    CHECK(num0[1] == 3); 
    CHECK(num0[2] == 5);  
    CHECK(num0[3] == 2); 
    CHECK(num0[4] == 4); 
}
  TEST_CASE("Fisher-yates tests std::rand") { 
    int num1[] = {1,2,3};
    CHECK( 3 == sizeof(num1)/sizeof(num1[0]) );
    show_data(num1,3);
    fisher_yates(num1, 3, std::rand);
    show_data(num1,3);
    bool first  = once_in_list(num1,3, num1[0]);
    bool second = once_in_list(num1,3, num1[1]);
    bool third  = once_in_list(num1,3, num1[2]);
    bool three_tests = first && second && third;
    CHECK( three_tests == true );
  }
  TEST_CASE("Test generated_sequence function") {
    int initArray[10];
    generated_sequence(initArray, 5);
    bool correct_sequence = true;
    for (int i = 0; i < 5; i++) {
        if (initArray[i] != 1 || initArray[5 + i] != -1) {
            correct_sequence = false;
            break;
        }
    }
    
    CHECK(correct_sequence == true);
}
TEST_CASE("Test both_pos_and_neg function") {
  int initArray[10];
  int result = both_pos_and_neg(initArray, 100, 5);
  CHECK(result >= 0);
  CHECK(result <= 100);
}

TEST_CASE("Test non_negative function") {
  int initArray[10];
  int result = non_negative(initArray, 100, 5);
  CHECK(result >= 0);
  CHECK(result <= 100);
}
  
TEST_CASE("Test non_positive function") {
  int initArray[10];
  int result = non_positive(initArray, 100, 5);
  CHECK(result >= 0);
  CHECK(result <= 100);
}
TEST_CASE("Testing unit-test functions") {

  int nums_2[2];
  int nums_2reverse[2];

  SUBCASE("setupPlusAndMinuses") {
      generated_sequence(nums_2, 1);
      CHECK(nums_2[0] == 1);
      CHECK(nums_2[1] == -1);

      generated_sequence(nums_2reverse, 1);
      CHECK(nums_2reverse[0] == 1);
      CHECK(nums_2reverse[1] == -1);
  };

  SUBCASE("both_pos_and_neg") {
      generated_sequence(nums_2, 1);
      CHECK(0 == both_pos_and_neg(nums_2, 10, 1));  // +1, -1 which only has non-negative prefix sums

      generated_sequence(nums_2reverse, 1);
      CHECK(0 == both_pos_and_neg(nums_2reverse, 10, 1));  // -1, +1 which only has non-positive prefix sums
  };
};
