/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 20, 2020, 10:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int lcsRecursive(string a, string b, int m, int n){
    
    if(m==0 || n==0){
        return 0;
    }

    else{
        if(a[m-1]==b[n-1]){
            return (1+lcsRecursive(a,b, m-1, n-1));
        }
        else{
            int lcs1 = lcsRecursive(a,b,m-1,n);
            int lcs2 = lcsRecursive(a,b,m, n-1);
            return (lcs1>lcs2?lcs1:lcs2);
        }
    }
    
}

int lcsMemozization(string a, string b, int m, int n, int **dpTable){
    
    if(m==0 || n==0){
        return 0;
    }
    if(dpTable[m][n]!= -1){
        return dpTable[m][n];
    }
    else{
        if(a[m-1]==b[n-1]){
            dpTable[m][n] = 1+lcsRecursive(a,b, m-1, n-1);
            return dpTable[m][n];
        }
        else{
            int lcs1 = lcsRecursive(a,b,m-1,n);
            int lcs2 = lcsRecursive(a,b,m, n-1);
             dpTable[m][n] = lcs1>lcs2?lcs1:lcs2;
            return dpTable[m][n];
        }      
    }
}


int lcsTopDown(string a, string b){
    int dpTable[a.length()+1][b.length()+1];
    for(int i=0; i< a.length()+1;i++){
        for(int j =0; j<b.length()+1;j++){
            if(i==0 || j==0){
                dpTable[i][j] =0;
            }
            else{
                dpTable[i][j] =-1;
            }
        }
    }
    
    for(int i=1; i< a.length()+1; i++){
        for(int j=1;j<b.length()+1; j++){
            if(a[i-1]== b[j-1]){
                dpTable[i][j] = 1+ dpTable[i-1][j-1];
            }
            else{
                int val1 = dpTable[i-1][j];
                int val2 = dpTable[i][j-1];
                dpTable[i][j] = val1>val2?val1:val2;
            }
        }
    }
    return dpTable[a.length()][b.length()];
}
/*
 * 
 */
int main(int argc, char** argv){
    string a="abcdghpr";
    string b="abedfhlkpqrs";

    int **dpTable = (int **)malloc((a.length()+1) * sizeof(int *)); 
    for (int i=0; i<a.length()+1; i++) 
         dpTable[i] = (int *)malloc((b.length()+1) * sizeof(int)); 
    for( int i=0;i< a.length()+1;i++){
        for(int j=0; j<b.length()+1;j++){
            dpTable[i][j]=-1;
        }
    }
    cout<<"LCS length ( Recursive Method) : " <<lcsRecursive(a,b,a.length(),b.length())<<endl; 
    cout<<"LCS length ( Memozise Method) : " <<lcsMemozization(a,b,a.length(),b.length(),dpTable)<<endl;
    cout<<"LCS length ( with  Top Down Approach) : " <<lcsTopDown(a,b);
    return 0;
}

