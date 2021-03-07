#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// CRYPTOGRAPHY ASSIGNMENT BY PRAKNAM S^3
int32_t main(){
    IOS;
    //cout<<"Coding makes me happy. You, not so much.";
    string key,pt;
    cin>>key>>pt;
    int key_matrix[3][3];
    int cnt=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            key_matrix[i][j]=key[cnt++];

        string ct="";
        for(int k=0;k<pt.size()/3;k++)
        {
            string pt_3=pt.substr(3*k,3);
            for(int i=0;i<3;i++)
            {
                int c=0;
                for(int j=0;j<3;j++)
                {
                   c=c+( (pt_3[j]-'a')*(key_matrix[i][j]-'a') );
                }
             ct.push_back(char(c%26 + 'a'));
         }
     }
     cout<<ct;
 }
