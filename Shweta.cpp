#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// CRYPTOGRAPHY ASSIGNMENT BY PRAKNAM S^3
int mod(int a)
{
    if(a==0)
        return 0;
    if(a>0)
        return a%26;
    else
        return (26-(abs(a)%26));
}
int multiplicative_inverse(int a)
{
    for(int i=1;i<26;i++)
    {
        if( (a*i)%26 ==1)
            return i;
    }
}
int32_t main(){
    IOS;
    //cout<<"Coding makes me happy. You, not so much.";

    string ct,pair1,pair2;
    cin>>ct>>pair1>>pair2;
    int p1[2][1],p2[2][1],ans1[2][1],ans2[2][1];
    string pt="";
    p1[0][0]=pair1[0]-65;
    p1[1][0]=pair1[1]-65;
    p2[0][0]=pair2[0]-65;
    p2[1][0]=pair2[1]-65;

    int k1,k2,k3,k4;
    for(int a=0;a<26;a++)
        for(int b=0;b<26;b++)
            for(int c=0;c<26;c++)
                for(int d=0;d<26;d++)
                {
                    int v1=(a*19+b*7)%26;
                    int v2=(c*19+d*7)%26;
                    int v3=(a*7+b*4)%26;
                    int v4=(c*7+d*4)%26;
                    if(v1==p1[0][0] && v2==p1[1][0] && v3==p2[0][0] && v4==p2[1][0])
                    {
                        k1=a,k2=b,k3=c,k4=d;
                        break;
                    }
                }
                int det=k1*k4-k2*k3;
                det=mod(det);
                int mul_inv=multiplicative_inverse(det);
                int temp=k1;k1=k4;k4=temp;
                k2=k2*-1;k3=k3*-1;
                k1=mod(k1);k2=mod(k2);k3=mod(k3);k4=mod(k4);
                k1=(k1*mul_inv)%26;
                k2=(k2*mul_inv)%26;
                k3=(k3*mul_inv)%26;
                k4=(k4*mul_inv)%26;
                if(ct.size()%2!=0)
                    ct.push_back('Z');
                for(int i=0;i<ct.size();i=i+2)
                {
                    char c1=ct[i];
                    char c2=ct[i+1];
                    ans1[0][0]=(k1*(c1-65) + k2*(c2-65) )%26;
                    ans1[1][0]=(k3*(c1-65) + k4*(c2-65) )%26;
                    pt.push_back( (char)(65+ans1[0][0]) );
                    pt.push_back( (65+ans1[1][0]) );
                }
                cout<<pt;
}




