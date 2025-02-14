#include <iostream>
#include "prefixSum.h"
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