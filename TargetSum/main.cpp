/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 12:02 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
/*
 Target SUM problem 
 * Given an array, assign + or  - against each element to arrive at a target sum of given value
 * We need to check if such a combintaion exists and if so how many
 * 
 * Arr[]={1,1,2,3}
 * Target SUM = 3
 * Possibilities : {+1 -1 -2 +3} {+1+3 -1-2} {-1 +1 -2 +3}
 * 
 * But if we observe closely, this is nothing but breaking the given array into 2 subsets such that the difference is equal 
 * to given sum
 * S1= {+1,+3} S2={-1, -2} etc
 * So we can solve this problem similar to the problem of finding all possible subsets which have a
 * difference of a given value
 * 
 * S1-S2= diff
 * S1+S2 = SUM(arr)
 * Therefore S1 = (diff+ SUM(arr))/2
 * 
 * Count of S1 should given the answer
 *  */


int countOfSubsetsWithTargetSum(int arr[], int size, int targetSum){
    
    int sum =0;
    for(int i=0;i<size;i++){
        sum+= arr[i];
    }
    int reqdSum = ( targetSum + sum)/2;
    
    int dpTable[size+1][reqdSum+1];
    for(int i=0; i<reqdSum+1;i++){
        dpTable[0][i] = 0;
    }
    for(int i=0; i<size+1;i++){
        dpTable[i][0]= 1;
    }
    
    for(int i= 1; i< size+1;i++){
        for( int j=0; j< reqdSum+1;j++){
            if(arr[i-1]<=j){
                dpTable[i][j]= dpTable[i-1][j- arr[i-1]]+ dpTable[i-1][j];
            }
            else{
                dpTable[i][j]= dpTable[i-1][j];
            }
        }
    }
    return dpTable[size][reqdSum];
}



/*
 * 
 */
int main(int argc, char** argv) {

    int arr[]={1,1,2,3};
    int count = countOfSubsetsWithTargetSum(arr, 4,1);
    cout <<"Num of subsets with Target sum is " << count;
    return 0;
}

