#include <iostream>
#include <bits/stdc++.h>

using namespace std;



string div(string data,int n,string div)
{

    int m=div.size();
    char bit;
    for(int i=0;i<n;i++)
    {
        bit=data[i];
        if(bit=='1')
        {
          for(int j=0;j<m;j++)
          {
            if(data[i+j]!=div[j])
                data[i+j]='1';
            else
                data[i+j]='0';

          }
        }
    }
    string chksum=data.substr(n,16);
    return chksum;
}
int main()
{
    int n;
    string data,cpy;
    string Gen="10001000000100001";
    cout<<"enter data"<<endl;
    cin>>data;
    cpy=data;
    n=data.size();
    cout<<endl;
    cout<<"Original data :"<<data<<endl;
    cout<<"G(x) :"<<Gen<<endl;
    data+="0000000000000000";
    cout<<endl;
    cout<<"Sender"<<endl;
    cout<<"Modified Data :"<<data<<endl;

    string chksum=div(data,n,Gen);
    cout<<"Checksum :"<<chksum<<endl;

    cout<<endl;
    data=cpy+chksum;
    cout<<"Receiver"<<endl;
    cout<<"Codeword :"<<data<<endl;
    chksum=div(data,n,Gen);
    cout<<"Checksum :"<<chksum<<endl;

}


