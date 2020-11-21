/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 21, 2020, 6:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int lngstCommonSubStrLength(string str1, string str2){
    int dpTable[str1.length()+1][str2.length()+1];
    int maxValue=0;
    for(int i=0;i< str1.length()+1;i++){
        for(int j=0;j<str2.length()+1;j++){
            if( i==0 || j==0){
                dpTable[i][j]=0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    
    for(int i=1;i< str1.length()+1;i++){
        for(int j=1;j<str2.length()+1;j++){
            if( str1[i-1] == str2[j-1]){
                dpTable[i][j]= 1+ dpTable[i-1][j-1];
                if(dpTable[i][j]> maxValue){
                    maxValue = dpTable[i][j];
                }
            }
            else{
                dpTable[i][j]= 0;
            }
        }
    }
    
    for(int i=0;i< str1.length()+1;i++){
        for(int j=0;j<str2.length()+1;j++){
            cout <<dpTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    return maxValue;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string a="abcdefghklmnsr";
    string b="lbcdejdfghklmpqr";
    
    int lngstCommnSubstrLen = lngstCommonSubStrLength(a,b);
    cout <<"Max Length of longest common substring is " << lngstCommnSubstrLen;
    return 0;
    
}

