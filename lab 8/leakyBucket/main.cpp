#include <iostream>

using namespace std;

int main()
{
    int buffer=0;
    int outputRate;
    int capacity;
    int rem;

    cout<<"Enter buffer capacity in Mbps\n";
    cin>>capacity;
    rem=capacity;

    cout<<"Enter output rate in Mbps\n";
    cin>>outputRate;


    cout<<"Capacity :"<<capacity<<endl;
    cout<<"Buffer :"<<buffer<<endl;
    cout<<"Residual :"<<rem<<endl;

    while(true)
    {
        int inputRate;
        cout<<"enter input rate\n";
        cin>>inputRate;

        if(inputRate>rem)
        {
            cout<<"Cannot accept input. Beyond buffer capacity\n";
            continue;

        }

        rem-=inputRate;
        buffer+=inputRate;

        if(buffer<=outputRate)
        {
            buffer=0;
            rem=capacity;
        }
        else
        {
            buffer-=outputRate;
            rem+=outputRate;

        }

        cout<<"Amount in buffer: "<<buffer<<endl;
        cout<<"Amount space left in buffer: "<<rem<<endl;
    }


}
