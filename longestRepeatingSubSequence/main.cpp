/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 22, 2020, 8:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longestRepeatingSubSequence(string a){
    string result;
    string s1= a;
    string s2 =a;
    int len = a.length()+1;
    int dpTable[len][len];
    
    for(int i=0; i<len;i++){
        for(int j=0; j< len;j++){
            if(i==0 || j==0){
                dpTable[i][j]=0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    for(int i=1; i<len;i++){
        for(int j=1; j< len;j++){
            if(s1[i-1]== s2[j-1] && i!=j){
                dpTable[i][j] = 1+ dpTable[i-1][j-1];
            }
            else{
                dpTable[i][j] = (dpTable[i][j-1]>dpTable[i-1][j]?dpTable[i][j-1]:dpTable[i-1][j]);
            }
        }
    }
    cout<<endl<<"Length of Longest Repeating Subsequence is " << dpTable[len-1][len-1]<<endl;
    int i = len;
    int j= len;
    
    while(i>0 && j>0){
        if( s1[i-1]==s2[j-1] ){
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
        if(dpTable[i][j-1]> dpTable[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    reverse(result.begin(), result.end());
    cout << result;
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string a="aabbcddeeee";
    string b= longestRepeatingSubSequence(a);
    cout<<endl<<"Longest Repeating sub Sequence is " << b;
    return 0;
}


