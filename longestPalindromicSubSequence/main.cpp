/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 23, 2020, 11:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

string longestPalindromicSubSequence(string a){
    string b = string(a.rbegin(), a.rend());
    int dpTable[a.length()+1][b.length()+1];
    
    for(int i=0;i<a.length()+1;i++){
        for(int j=0; j<b.length()+1;j++){
            if( i ==0 || j==0){
                dpTable[i][j]=0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    
    for(int i=1;i<a.length()+1;i++){
        for(int j=1; j<b.length()+1;j++){
            if( a[i-1]== b[j-1]){
                dpTable[i][j]= 1+ dpTable[i-1][j-1];
            }
            else{
                dpTable[i][j] = (dpTable[i-1][j]>dpTable[i][j-1]?dpTable[i-1][j]:dpTable[i][j-1]);
            }
        }
    }
    
    int i= a.length()+1;
    int j= b.length()+1;
    string result;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            result.push_back(a[i-1]);
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
    reverse(result.begin(), result.end());
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    string a="agbcba";
    string lpsStr = longestPalindromicSubSequence(a);
    cout<<"Longest Palindromic Subseqeunce is " <<lpsStr<<endl;
    return 0;
}

