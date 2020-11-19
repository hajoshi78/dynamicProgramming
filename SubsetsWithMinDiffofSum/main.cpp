/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 8:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int findMinSumDiff(int arr[], int size){
    //2 subsets (S1, S2 created out of the given array such that
    //SUM(S1elements ) - SUM(S2 elements) -> Minimum
    //Since we do not know the SUM, we have to find  the range of Possible SUMs
    //Some of these numbers on the range might not be possible to create.
    //Remove those elements . COnsider only elements 
    //Range-2S1 =>  minimum
    int range =0;
    int minVal =INT_MAX;
    for(int i=0;i<size;i++){
        range+= arr[i];
    }
    int dpTable[size+1][range+1];
    
    for(int i=0;i<size+1;i++){
        for(int j=0;j<range+1;j++){
            if(i==0){
                dpTable[i][j]= 0;
            }
            if( j==0){
                dpTable[i][j]= 1;
            }
        }
    }
    
    for(int i=1;i<size+1;i++){
        for(int j=1;j<range+1;j++){
            if(arr[i-1]<=j){
                dpTable[i][j] = dpTable[i-1][j-arr[i-1]] || dpTable[i-1][j];
            }
            else{
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    
    vector<int> lastRow;
    for( int i=1;i<=(range+1)/2;i++){
        if(dpTable[size][i] == 1){
            lastRow.push_back(i);
        }
    }
    
    
    for(int i=0;i<lastRow.size();i++){
        int val = range - 2*lastRow[i];
        if( val<minVal){
            minVal = val;
        }
    }
    return minVal;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,5,6,7,12};
    int minDiff =   findMinSumDiff(arr,5);
    cout <<endl<<"Min Diff :" <<minDiff;
    return 0;
}


