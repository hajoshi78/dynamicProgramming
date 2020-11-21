/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 21, 2020, 10:00 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> getMinNumOfInsAndDelsToConvStrAToStrB(string a, string b){
    int dpTable[a.length()+1][b.length()+1];
    for(int i=0; i< a.length()+1; i++){
        for(int j=0; j<b.length()+1; j++){
            if( i==0 || j==0){
                dpTable[i][j] =0;
            }
            else{
                dpTable[i][j]=-1;
            }
        }
    }
    for(int i=1; i<a.length()+1;i++){
        for(int j=1; j<b.length()+1; j++){
            if(a[i-1] == b[j-1]){
                dpTable[i][j] = 1+ dpTable[i-1][j-1];
            }
            else{
                dpTable[i][j] = ( dpTable[i-1][j]>dpTable[i][j-1]? dpTable[i-1][j]: dpTable[i][j-1]);
            }
        }
    }
    int lcs = dpTable[a.length()][b.length()];
    
    int numOfDeletions = 0;
    int numOfAdditions = 0;
    if(a.length()>= b.length()){
        numOfDeletions = a.length()-lcs;
        numOfAdditions = b.length() - lcs;
    }
    else{
        numOfDeletions = b.length()-lcs;
        numOfAdditions = a.length() - lcs;
    }
    vector<int> result;
    result.push_back(numOfAdditions);
    result.push_back(numOfDeletions);
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    string a="heap";
    string b="pea";
    vector<int> result = getMinNumOfInsAndDelsToConvStrAToStrB(a, b);
    cout << "Num of Additions : " << result[0];
    cout <<endl<< " Num of Deletions : " << result[1];
    return 0;
}

