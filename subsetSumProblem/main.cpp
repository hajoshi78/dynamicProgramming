/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 8:18 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

bool isSubsetWithSumPossible(int arr[], int size, int sum){
    bool dpTable[size+1][sum+1];
    for(int i=0; i< size+1; i++){
        for(int j=0;j< sum+1; j++){
            if(i==0){
                dpTable[i][j]= false;
            }
            if(j==0){
                dpTable[i][j] = true;
            }
        }
    }
    
    for(int i=1; i<size+1;i++){
        for(int j=1;j<sum+1; j++){
            //The element choosen is less than or equal to the sum 
            if(arr[i-1]<=j){
                //2 case 
                //Case 1: arr[i-1] -> included in the subset
                bool value1 = dpTable[i-1][j-arr[i-1]];
                //Case 2: arr[i-1] -> not included in the subset
                bool value2= dpTable[i-1][j];
                dpTable[i][j] = value1 || value2;
            }
            else{
               dpTable[i][j] = dpTable[i-1][j]; 
            }
        }
    }
    for(int i=0; i< size+1; i++){
        for(int j=0;j<sum+1;j++){
            cout<< dpTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    return dpTable[size][sum];
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={2,3,7,8,10};
    int size = 5;
    
    int sum = 16;
    bool result = isSubsetWithSumPossible(arr,size, sum);
    cout <<endl<<"Subset with sum 11 is possible? :" << result;
    return 0;
}

