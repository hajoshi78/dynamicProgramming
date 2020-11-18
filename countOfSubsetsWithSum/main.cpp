/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 18, 2020, 10:45 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int countOfSubsetWithSum(int arr[],int size, int sum){
    int dpTable[size+1][sum+1];
    
    for(int i=0;i<size+1;i++){
        for(int j=0;j<sum+1; j++){
            if( i==0){
                dpTable[i][j]=0;
            }
            if( j==0){
                //empty set  possible
                dpTable[i][j]=1;
            }
        }
    }
   
    for(int i=1; i<size+1;i++){
        for(int j=1;j<sum+1; j++){
            //The element choosen is less than or equal to the sum 
            if(arr[i-1]<=j){
                //2 case 
                //Case 1: arr[i-1] -> included in the subset
                int value1 = dpTable[i-1][j-arr[i-1]];
                //Case 2: arr[i-1] -> not included in the subset
                int value2= dpTable[i-1][j];
                dpTable[i][j] = value1 + value2;
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
    int arr[] ={2,4,5,6,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    int count = countOfSubsetWithSum(arr,6, sum);
    cout<<endl<<"Number of subsets with sum 10 is " <<count<<endl;
    return 0;
}

