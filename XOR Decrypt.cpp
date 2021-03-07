#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// CRYPTOGRAPHY ASSIGNMENT BY PRAKNAM S^3
int32_t main(){
    IOS;
    //cout<<"Coding makes me happy. You, not so much.";
    string ct,pt_temp="",pt="";
    cin>>ct;
    vector<int>arr;
    vector<int>hex;
    if(ct.size()==0) return 0;
    for(int i=0;i<ct.size();i++)
    {
        if( ct[i]-48<=9 )
            arr.push_back(ct[i]-48);
        else
            arr.push_back(ct[i]-97+10);
    }
    hex.push_back(arr[0]);
    for(int i=1;i<arr.size()/2 +1;i++)
        hex.push_back(arr[i] ^ arr[i-1]);

    for(int i=0;i<hex.size();i++)
    {
        if(hex[i]<=9)
            pt.push_back( (char) (hex[i]+48) );
        else
            pt.push_back((char)(87+hex[i]) );
    }
    if(ct.size()%2==0)
    {
        pt.pop_back();
    }
    cout<<pt;
}
