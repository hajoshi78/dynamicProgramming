/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 21, 2020, 7:49 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string getLongestCommonSubSequence(string a, string b){
    int dpTable[a.length()+1][b.length()+1];
    string lcs;
    for(int i=0;i<a.length()+1;i++){
        for(int j=0; j< b.length()+1;j++){
            if( i==0 || j==0){
                dpTable[i][j] = 0;
            }
            else{
                dpTable[i][j] -1;
            }
        }
    }
    
    for(int i=1;i<a.length()+1;i++){
        for(int j=1; j< b.length()+1;j++){
            if( a[i-1]== b[j-1]){
                dpTable[i][j] = 1+dpTable[i-1][j-1];
            }
            else{
                dpTable[i][j] = (dpTable[i-1][j]>dpTable[i][j-1]?dpTable[i-1][j]:dpTable[i][j-1]);
            }
        }
    }
    
    int i= a.length();
    int j = b.length();
    while(j>0 && i>0){
        if(a[i-1]== b[j-1]){
            lcs.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
           if(dpTable[i-1][j]> dpTable[i][j-1]){
               i--;
           }     
           else{
               j--;
           }
                
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}


/*
 * 
 */
int main(int argc, char** argv) {
    string a="abcfklm";
    string b="acfbkmpr";
    string c = getLongestCommonSubSequence(a,b);
    cout<< "Longest Common Sub sequence is " <<c;
    return 0;
}

