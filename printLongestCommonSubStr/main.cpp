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
#include <algorithm>

using namespace std;

string lngstCommonSubStr(string str1, string str2){
    int dpTable[str1.length()+1][str2.length()+1];
    int maxValue=0;
    string lcsStr;
    int maxI=0, maxJ=0;
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
                    maxI= i;
                    maxJ=j;
                }
            }
            else{
                dpTable[i][j]= 0;
            }
        }
    }
    cout<<"Max I : " << maxI<<" Max J : "<<maxJ<<endl;;
    for(int i=0;i< str1.length()+1;i++){
        for(int j=0;j<str2.length()+1;j++){
            cout <<dpTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    int i= maxI;
    int j=maxJ;
    while( i>0 && j>0){
        if(str1[i]== str2[j]){
            lcsStr.push_back(str1[i]);

        }
        i--;
        j--;
    }
    cout<< lcsStr;
    reverse(lcsStr.begin(),lcsStr.end());
    
    return lcsStr;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string a="abcdepqrsfghklmnsr";
    string b="lbcdepqrsjdfghklmpqr";
    
    string lngstCommnSubstr = lngstCommonSubStr(a,b);
    cout <<"Max Length of longest common substring is " << lngstCommnSubstr;
    return 0;
    
}

