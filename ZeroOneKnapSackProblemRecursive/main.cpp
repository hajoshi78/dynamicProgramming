/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 2:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int knapSack(int wt[], int val[], int n, int capacity){
    //Base condition
    if( n ==0|| capacity==0){
        return 0;
    }
    //Choice diagram
    if(wt[n-1]<=capacity){
        //Include that wt[n-1]
        int profit1 = val[n-1] + knapSack(wt, val, n-1, capacity - wt[n-1]);  
        //do not include that wt[n-1]
        int profit2 = knapSack(wt, val, n-1, capacity);
        return ( profit1>profit2 ? profit1:profit2);
    }
    else{
        return knapSack(wt, val, n-1, capacity);
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
    cout <<"Max Profit possible for Knapsack with capacity 12 is " << knapSack(wt,val,size, capacity);
    return 0;
}

