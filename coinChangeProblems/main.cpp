/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 5:11 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int getNumberofWaysofSelectingCoinsToMakeSum(int coins[], int size, int sum){
    int dpTable[size+1][sum+1];
    
    
    for(int i=0;i<sum+1;i++){
        dpTable[0][i]=0;
    }
    for(int i=0;i<size+1;i++){
        dpTable[i][0]=1;
    }
    for(int i=1;i<size+1; i++){
        for(int j=1;j<sum+1;j++){
            if(coins[i-1]<=j){
                dpTable[i][j] = dpTable[i][j-coins[i-1]] + dpTable[i-1][j];
            }
            else{
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    
    cout<<"Printing DP Table: " << endl;
    for(int i=0;i<sum+1;i++){
        cout<<i<<"\t";
    }
    cout<<endl;
    for(int i=0;i<size+1; i++){
        for(int j=0;j<sum+1;j++){
            cout<<dpTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    return dpTable[size][sum];
}


/*
 * 
 */
int main(int argc, char** argv) {
    int coins[]={1,2,3,5,4};// {1 2 4 3} {}
    int sum = 20;
    int count =getNumberofWaysofSelectingCoinsToMakeSum(coins, 5, sum);
    
    cout<<"Number of ways to create SUM of " << sum << " is : " << count;
    return 0; 
}

