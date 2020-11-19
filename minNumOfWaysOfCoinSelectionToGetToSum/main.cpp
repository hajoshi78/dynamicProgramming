/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 7:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int minWaysUsingRecursion(int coin[], int size, int value ){
    if(value==0){
        return 0;
    }
    else{
        int result = INT_MAX;
        for(int i=0; i<size;i++){
            if(coin[i]<=value){
                int temp= minWaysUsingRecursion(coin, size, value-coin[i]);
                if( temp!=INT_MAX && temp+1<result){
                    result = temp+1;
                }
            }
        }
        return result;
    }
}

int minWaysUsingDP(int coins[], int m, int V) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
    int dpTable[V+1]; 
  
    // Base case (If given value V is 0) 
    dpTable[0] = 0; 
  
    // Initialize all table values as Infinite 
    for (int i=1; i<=V; i++) 
        dpTable[i] = INT_MAX; 
  
    // Compute minimum coins required for all 
    // values from 1 to V 
    for (int i=1; i<=V; i++) 
    { 
        // Go through all coins smaller than i 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = dpTable[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < dpTable[i]) 
                  dpTable[i] = sub_res + 1; 
          } 
    } 
    return dpTable[V]; 
}
/*
 * 
 * 
 */
int main(int argc, char** argv) {
    
    int coins[] =  {9, 6, 5, 1}; 
    int m = sizeof(coins)/sizeof(coins[0]); 
    int V = 11; 
    cout << "Minimum coins required is ( Using Naive recursion)  "<< minWaysUsingRecursion(coins, m, V)<<endl; 
    cout << "Minimum coins required is ( Using DP)  "<< minWaysUsingDP(coins, m, V); 
    return 0; 
    return 0;
}

