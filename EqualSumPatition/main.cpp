/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 9:28 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
int checkIfEqualSumPartitionExists(int arr[], int size){
    
    int reqdSum =0;
    // if the num of elements is odd. then we cannot do sum equal sum partition
    int totalSum =0;
    for(int i=0;i<size;i++){
        totalSum+= arr[i];
    }

    if(totalSum%2==0){
        reqdSum= totalSum/2;
        bool dpTable[size+1][reqdSum +1];
        //lets initialize the dpTable;
        for(int i=0; i<size+1; i++){
            for(int j=0;j<reqdSum+1;j++){
                if(i==0){
                    dpTable[i][j]=false;
                }
                if(j==0){
                    dpTable[i][j]= true;
                }
            }
        }
        
        //Now lets build the rest of the DP Table
        for(int i=1;i<size+1; i++){
            for(int j=1;j<reqdSum+1;j++){
                if(arr[i-1]<=j){
                    //2 choice
                    //Choice 1: we include this number in our subset
                    bool val1= dpTable[i-1][j-arr[i-1]];
                  
                    //choice 2: we do not include this number in the subset
                    bool val2= dpTable[i-1][j];
                      
                    dpTable[i][j] = val1||val2;
                }
                else{
                    dpTable[i][j] = dpTable[i-1][j];
                }
            }
        }
        return dpTable[size][reqdSum];
    }
    else{
        return 0;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={2,3,5,6,8,10};
    int size = 6;
    
    bool result = checkIfEqualSumPartitionExists(arr,size);
    cout <<endl<<"Equal sum partition exists ? :" << result;
    
    
    int arr2[]={2,3,7,8,10,12,70};
    int size2 = 7;
    
    bool result2 = checkIfEqualSumPartitionExists(arr2,size2);
    cout <<endl<<"Equal sum partition exists ? :" << result2;
    return 0;
}

