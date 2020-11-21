/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 21, 2020, 12:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int lenOfshortestCommonSuperSequence(string a , string b){
    int dpTable[a.length()+1][b.length()+1];
    int superSeqLen=0;
    
    for(int i=0;i<a.length()+1;i++){
        for(int j=0; j< b.length()+1;j++){
            if(i==0 || j==0){
                dpTable[i][j] =0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    for(int i=1;i<a.length()+1;i++){
        for(int j=1; j< b.length()+1;j++){
            if( a[i-1]==b[j-1]){
                dpTable[i][j] = 1+ dpTable[i-1][j-1];
            }
            else{
                dpTable[i][j] = (dpTable[i-1][j]>dpTable[i][j-1]?dpTable[i-1][j]:dpTable[i][j-1]);
            }
        }
    }
    
    int longestSubSeqlen = dpTable[a.length()][b.length()];
    superSeqLen= a.length()+ b.length()- longestSubSeqlen;
    return superSeqLen;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string a="AXGTBYP";
    string b="AYPLXGYP";
    int superSeqLen =lenOfshortestCommonSuperSequence(a,b);
    cout <<"Shortest Super Subsequence Length is " << superSeqLen;
    return 0;
}

