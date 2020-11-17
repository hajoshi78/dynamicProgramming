/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 4:08 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int knapSackMemoziation(int wt[], int val[], int n, int w, int **dpTable){
    
    //base condition
    if(n==0 || w==0){
        return 0;
    }
    //Choice diagram
    if(dpTable[n][w]!=-1){
        return dpTable[n][w];
    }
    else{
        if(wt[n-1]<=w){
            int profit1 = val[n-1] + knapSackMemoziation(wt,val, n-1, w-wt[n-1], dpTable);
            int profit2 = knapSackMemoziation(wt, val, n-1, w, dpTable);
            dpTable[n][w] = (profit1>profit2? profit1:profit2);
            return dpTable[n][w];
        }
        else{
            dpTable[n][w] = knapSackMemoziation(wt, val, n-1, w, dpTable);
            return dpTable[n][w];
            
        }
    }
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    int wt[]={1,3,4,2,6,7};
    int val[]={2,5,1,3,6,4};
    int size = 6;
    
    int capacity = 12;
    
    int **dpTable;
    dpTable = new int*[size+1];
    for(int i=0;i<size+1;i++){
        dpTable[i] = new int[capacity+1];
    }
    for(int i=0;i<size+1;i++){
        for(int j=0;j<capacity+1;j++){
            dpTable[i][j]=-1;
        }
    }
    cout <<"Max Profit possible for Knapsack with capacity 12 is " << knapSackMemoziation(wt,val,size, capacity, dpTable);
    return 0;
}

