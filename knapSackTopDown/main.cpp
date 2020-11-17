/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 4:53 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int knapSackTopDownApproach(int wt[], int val[], int n, int w, int **dpTable){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if( i==0 || j==0){
                dpTable[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                int profit1 = val[i-1] + dpTable[i-1][j - wt[i-1]];
                int profit2 = dpTable[i-1][j];
               dpTable[i][j] = (profit1>profit2? profit1:profit2);
            }
            else{
                dpTable[i][j]= dpTable[i-1][j];
            }
        }
    }
    return dpTable[n][w];
}



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
    cout <<"Max Profit possible for Knapsack with capacity 12 is " << knapSackTopDownApproach(wt,val,size, capacity, dpTable);
    return 0;
}

