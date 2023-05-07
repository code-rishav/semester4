#include <iostream>
using namespace std;
class Counting{
    int* ar;
    int size;
    public:
    Counting(int s){
        size = s;
        ar = new int[size];
        cout<<"Enter the elements of the array"<<endl;
        for(int i=0;i<size;i++)
        cin>>ar[i];

    }

    void sort(int k){
        int count[k+1];
        for(int i=0;i<=k;i++)
        count[i]=0;

        for(int i=0;i<size;i++){
            count[ar[i]]++;
        }


        for(int i=1;i<=k;i++)
        count[i] += count[i-1];

        int out[size];
        for(int i=size-1;i>=0;i--){
            out[count[ar[i]]-1] =ar[i];
            count[ar[i]]--; 
        }

        for(int i=0;i<size;i++)
        ar[i] = out[i];
    }

    void print(){
        for(int i=0;i<size;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Counting c(8);
    cout<<"Enter the maimum element in the array";
    int n;
    cin>>n;
    c.print();
    c.sort(n);
    c.print();
}