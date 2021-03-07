#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// CRYPTOGRAPHY ASSIGNMENT BY PRAKNAM S^3

string modify(string pt)
{
    string temp="";
    for(int i=0;i<pt.size()-1;i++)
    {
       if(pt[i]==pt[i+1])
       {
           if(pt[i]=='z' && pt[i+1]=='z')
           {
               temp.push_back('z');
               temp.push_back('y');
           }
           else
           {
               temp.push_back(pt[i]);
               temp.push_back('z');
           }
       }
       else
       {
           temp.push_back(pt[i]);
       }
    }
    temp.push_back(pt[pt.size()-1]);
    if(temp.size()%2!=0)
    {
        if(temp[temp.size()-1]!='z')
            temp.push_back('z');
        else
            temp.push_back('y');
    }
    return temp;
}

string modify_new(string pt)
{
    string temp="";
    int i=0;
    while(i<pt.size())
    {
        if(i==pt.size()-1)
        {
            temp.push_back(pt[i]);
            break;
        }
        if(pt[i]==pt[i+1])
        {
           if(pt[i]=='z' && pt[i+1]=='z')
           {
               temp.push_back('z');
               temp.push_back('y');
               //temp.push_back('z');
               i++;
           }
           else
           {
               temp.push_back(pt[i]);
               temp.push_back('z');
               //temp.push_back(pt[i]);
               i++;
           }
       }
       else
       {
           temp.push_back(pt[i]);
           temp.push_back(pt[i+1]);
           i=i+2;
       }
    }
    //temp.push_back(pt[pt.size()-1]);
    if(temp.size()%2!=0)
    {
        if(temp[temp.size()-1]!='z')
            temp.push_back('z');
        else
            temp.push_back('y');
    }
    return temp;
}

string make_spiral(string s)
{
    string s_new="";
    int char_array[26];
    int cnt=0;
    for(int i=0;i<26;i++)
        char_array[i]=0;
    // CHECKING ALL CHARACTERS THAT ARE SEEN IN STRING
    for(int i=0;i<s.size();i++)
    {
        if( (char_array[s[i]-97]==0) )
        {
            s_new.push_back(s[i]);
            char_array[s[i]-97]=1;
            if(s[i]=='i' || s[i]=='j')
            {
                char_array[8]=1;
                char_array[9]=1;
            }
        }
    }
    // ADDING UNSEEN CHARACTERS AT THE BACK
    char_array[9]=1;
    for(int i=0;i<26;i++)
    {
        if(char_array[i]==0)
            s_new.push_back( (char)(97+i));
    }
    //cout<<"\n"<<s_new;
    char matrix[5][5];

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            matrix[i][j]=0;
    //cout<<"\n";
    int i, k = 4, l = 4;
    int m=0,n=0;
    cnt=0;
    while (k >= m && l >= n) {
        for (i = l; i >= n; --i) {
            matrix[k][i]=s_new[cnt++];
        }
        k--;
        for (i = k; i >= m; --i) {
            matrix[i][n]=s_new[cnt++];
        }
        n++;
        if (k > m) {
            for (i = n ; i <= l; ++i) {
                matrix[m][i]=s_new[cnt++] ;
            }
            m++;
        }
        if (l > n) {
            for (i = m ; i <= k; ++i) {
                matrix[i][l]=s_new[cnt++];
            }
            l--;
        }
    }
    string spiral_string="";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            spiral_string.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
        }
        //cout<<"\n";
    }
    return spiral_string;
}
string railfence(string s,int rail_key)
{
    char matrix[rail_key][s.size()];
    int down=1;
    int cnt=0;
    int row=0;
    for(int i=0;i<rail_key;i++)
        for(int j=0;j<s.size();j++)
            matrix[i][j]='*';
    for(int i=0;i<s.size();i++)
    {
        if(down==1)
        {
            matrix[row][i]=s[i];
            row++;
            if(row==rail_key)
            {
                down=0;
                row=row-2;
            }
        }
        else if(down==0)
        {
            matrix[row][i]=s[i];
            row--;
            if(row==-1)
            {
                down=1;
                row=row+2;
            }
        }
    }
    string temp="";
    for(int i=0;i<rail_key;i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(matrix[i][j]!='*')
                temp.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
        }
        //cout<<"\n";
    }
    return temp;
}
string change_matrix(string spiral_string,int railfence_key)
{
    //cout<<"Spiral string before railfence:"<<spiral_string<<"\n";
    string rail_string=railfence(spiral_string,railfence_key);
    //cout<<"\nAfter Railfence:"<<rail_string;
    string spiral_string_modified=make_spiral(rail_string);
    return spiral_string_modified;
}
string playfair(string s,string mpt)
{
    string playfair_modified="";
    char matrix[5][5];
    int cnt=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            matrix[i][j]=s[cnt++];
        }
    }
    for(int i=0;i<mpt.size()-1;i=i+2)
    {

        char crypt_ch1,crypt_ch2;
        int crypt_r1,crypt_r2,crypt_c1,crypt_c2;
       char ch1=mpt[i];
       char ch2=mpt[i+1];
       int r1,c1,r2,c2;
        for(int i=0;i<5;i++)
        {
        for(int j=0;j<5;j++)
            {
            if(matrix[i][j]==ch1)
                {
                r1=i;
                c1=j;
                }
            if(matrix[i][j]==ch2)
                {
                r2=i;
                c2=j;
                }
            }
        }
        if(r1==r2)
        {
            if(c1==4)
            {
                crypt_c1=0;
                crypt_r1=r1;
            }
            else
            {
                crypt_c1=c1+1;
                crypt_r1=r1;
            }
            if(c2==4)
            {
                crypt_c2=0;
                crypt_r2=r2;
            }
            else
            {
                crypt_c2=c2+1;
                crypt_r2=r2;
            }
        }
        else if(c1==c2)
        {
            if(r1==4)
            {
                crypt_r1=0;
                crypt_c1=c1;
            }
            else
            {
                crypt_r1=r1+1;
                crypt_c1=c1;
            }
            if(r2==4)
            {
                crypt_r2=0;
                crypt_c2=c2;
            }
            else
            {
                crypt_r2=r2+1;
                crypt_c2=c2;
            }
        }
        else
        {
            crypt_r1=r1;
            crypt_c1=c2;
            crypt_r2=r2;
            crypt_c2=c1;
        }
        playfair_modified.push_back(matrix[crypt_r1][crypt_c1]);
        playfair_modified.push_back(matrix[crypt_r2][crypt_c2]);
    }
    return playfair_modified;
}

int32_t main(){
    IOS;
    //cout<<"Coding makes me happy. You, not so much.";
    int test_cases;
    cin>>test_cases;
    for(int t=0;t<test_cases;t++)
    {
        int key_railfence;
        cin>>key_railfence;
        string key_playfair;
        cin>>key_playfair;
        int no_change;
        cin>>no_change;
        string pt;
        cin>>pt;
        int key_j=-1,key_i=-1;
        for(int i=0;i<key_playfair.size();i++)
        {
            if(key_playfair[i]=='i')
                key_i=1;
            if(key_playfair[i]=='j')
                key_j=1;
        }
        for(int i=0;i<pt.size();i++)
        {
            if(key_i==1 && pt[i]=='j')
                pt[i]='i';
            if(key_j==1 && pt[i]=='i')
                pt[i]='j';
            if(key_i==-1 && key_j==-1 && pt[i]=='j')
                pt[i]='i';
        }
        string mpt=modify(pt);
        string spiral_string=make_spiral(key_playfair);
        string playfair_modified="";
        string spiral_string_modified=spiral_string;
        for(int j=0;j<no_change;j++)
        {
            spiral_string_modified=change_matrix(spiral_string_modified,key_railfence);
        }
        int cnt=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout<<spiral_string_modified[cnt++]<<" ";
            }
            cout<<"\n";
        }
        playfair_modified=playfair(spiral_string_modified,mpt);
        cout<<playfair_modified<<"\n";
    }
}
