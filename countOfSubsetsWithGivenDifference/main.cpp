/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 10:51 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int countOfSubSetWithGivenDiff(int arr[], int size, int diff){
    //S1-S2 = diff
    //S1+S2 = sum(arr)
    //2S= diff + sum(arr)
    //S1 = (diff+ sum(Arr))/2
    //So lets find number of subsets with Sum S1;
   
    
    int sum=0;
    for(int i=0;i<size;i++){
        sum+= arr[i];
    }
    int reqdSum = (diff + sum)/2;
    int dpTable[size+1][reqdSum+1];
    
    for(int i=0;i<size+1;i++){
        for(int j=0;j<reqdSum+1;j++){
            if(i==0){
                dpTable[i][j]=0;
            }
            if(j==0){
                dpTable[i][j]=1;
            }
        }
    }
    for(int i=1;i<size+1;i++){
        for(int j=1;j<reqdSum+1;j++){
            if(arr[i-1]<=j){
                dpTable[i][j]= dpTable[i-1][j-arr[i-1]] + dpTable[i-1][j];
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
    int arr[]= {1,1,2,3};
    int count = countOfSubSetWithGivenDiff(arr, 4,1);
    cout <<"Number of subset with diff =1 is " <<count;
    return 0;
}

