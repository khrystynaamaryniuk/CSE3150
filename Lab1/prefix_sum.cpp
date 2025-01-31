#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

bool non_negative_prefix(int list[], int len){
    //invalid input 
    if(len==0){
        std::cout << "Invalid input"<<std::endl;
       return false;
    }
    int sum =0;
    for (int i=0;i<len; i++){
        if (list[i]>1 || list[i]<-1){
            std::cout << "List should contain only -1, 0, +1"<<std::endl;
            return false;
        }
        sum+=list[i];
        if(sum<0){
            return false;
        }
    }
    return true;
    
}

bool non_positive_prefix(int list[], int len){
    //invalid input 
    if(len==0){
        std::cout << "Invalid input"<<std::endl;
       return false;
    }
    int sum =0;
    for (int i=0;i<len; i++){
        if (list[i]>1 || list[i]<-1){
            std::cout << "List should contain only -1, 0, +1"<<std::endl;
            return false;
        }
        sum+=list[i];
        if(sum>0){
            return false;
        }
    }
    return true;
    
}
TEST_CASE("testing the non_negative_prefix function ") {
    int list0[]={};
    int list1[]={1,-1,1,-1};
    int list2[]={1,-1,-1,-1};
    int list3[]={1};
    int list4[]= {-1};
    int list5[] = {-1, 1, 1, -1};
    int list6[] = {0, 0, 0, 0};
    int list7[] = {0, 1, -1, 3};
    // checking for empty list = invalid input
    CHECK(!non_negative_prefix(list0,sizeof(list0)/sizeof(int)));
    //does not go below zero = true 
    CHECK(non_negative_prefix(list1,sizeof(list1)/sizeof(int)));
    //goes below zero = false
    CHECK(!non_negative_prefix(list2, sizeof(list2)/sizeof(int)));
    //does not go below zero = true
    CHECK(non_negative_prefix(list3,sizeof(list3)/sizeof(int)));
    //negative = false
    CHECK(!non_negative_prefix(list4,sizeof(list4)/sizeof(int)));
    // first element is negative = false
    CHECK(!non_negative_prefix(list5,sizeof(list5)/sizeof(int)));
     // list of all zero's = true 
    CHECK(non_negative_prefix(list6,sizeof(list6)/sizeof(int)));
    // list including other numbers than -1, 0, +1 =. message + false
    CHECK(!non_negative_prefix(list7,sizeof(list7)/sizeof(int)));
}
TEST_CASE("testing the non_positive_prefix function ") {
    int list0[]={};
    int list1[]={-1,1,-1,1};
    int list2[]={-1,1,1,-1};
    int list3[]={1};
    int list4[]= {-1};
    int list5[] = {1, 1, 1, -1};
    int list6[] = {0, 0, 0, 0};
    int list7[] = {0, -1, 1, 3};
    // checking for empty list = invalid input
    CHECK(!non_positive_prefix(list0,sizeof(list0)/sizeof(int)));
    //does not go above zero  = true 
    CHECK(non_positive_prefix(list1,sizeof(list1)/sizeof(int)));
    //goes above zero = false 
    CHECK(!non_positive_prefix(list2, sizeof(list2)/sizeof(int)));
    //one element, goes above zero = false 
    CHECK(!non_positive_prefix(list3,sizeof(list3)/sizeof(int)));
    //one element, does not go above zero = true 
    CHECK(non_positive_prefix(list4,sizeof(list4)/sizeof(int)));
    // first element is positive = false
    CHECK(!non_positive_prefix(list5,sizeof(list5)/sizeof(int)));
     // list of all zero's = true
    CHECK(non_positive_prefix(list6,sizeof(list6)/sizeof(int)));
    // list including other numbers than -1, 0, +1 = message + false
    CHECK(!non_positive_prefix(list7,sizeof(list7)/sizeof(int)));
}