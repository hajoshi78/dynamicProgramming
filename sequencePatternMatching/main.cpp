/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 22, 2020, 8:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool CheckIfSubsequencePresent(string a, string b){
    int dpTable[a.length()+1][b.length()+1];
    for(int i=0;i<a.length()+1;i++){
        for( int j=0;j<b.length()+1;j++){
            if( i==0 || j==0){
                dpTable[i][j]=0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    
    for(int i=1;i<a.length()+1;i++){
        for(int j=1;j<b.length()+1;j++){
            if(a[i-1] == b[j-1]){
                dpTable[i][j] = 1+ dpTable[i-1][j-1];
            }
            else{
               dpTable[i][j] = (dpTable[i][j-1] >dpTable[i-1][j]?dpTable[i][j-1]:dpTable[i-1][j]);
            }
        }
    }
    
    int lcs = dpTable[a.length()][b.length()];
    if( lcs == b.length() || lcs== a.length()){
        return  true;
    }
    else{
        return false;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    string a="AXY";
    string b="WERAYUTXOPNYZS";//"WER";
    cout <<"is A subsequence of B? " <<CheckIfSubsequencePresent(a,b);
    return 0;
}

