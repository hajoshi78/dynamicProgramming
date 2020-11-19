/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 19, 2020, 4:29 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int getMaxProfit(int len[], int size, int price[], int N){
    int dpTable[size+1][N+1];
    
    for(int i=0;i<size+1;i++){
        dpTable[i][0]=0;
    }
    
    for(int i=0;i<N+1;i++){
        dpTable[0][i]=0;
    }
    
    for(int i=1;i< size+1;i++){
        for(int j=1;j< N+1;j++){
            if(len[i-1]<=j){
                int val1= price[i-1]+ dpTable[i][j-len[i-1]];
                int val2 = dpTable[i-1][j];
                dpTable[i][j] = (val1>val2? val1:val2);
            }
            else{
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    cout<<"DPTable " <<endl;
     for(int i=0;i< size+1;i++){
        for(int j=0;j< N+1;j++){
            cout<<dpTable[i][j]<<"\t";
        }
        cout <<endl;
     }
    return dpTable[size][N];
}

/*
 * 
 */
int main(int argc, char** argv) {
    int len[]={1,2,3,4};
    int price[]= {1,1,8,25};
    int N= 7;
    int profit = getMaxProfit(len,4,price,N);
    
    cout <<"Maximum Profit cutting the roads :" <<profit;
    return 0;
}

