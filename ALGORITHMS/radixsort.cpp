#include <iostream>
using namespace std;
class Radix{
    int *ar;
    int size;
    public:

    Radix(int s){
        size = s;
        ar = new int[size];
        cout<<"Enter the elements of the array"<<endl;
        for(int i=0;i<size;i++)
        cin>>ar[i];
    }

    void sort(){
        int max = ar[0];
        for(int i=1;i<size;i++){
            if(max<ar[i])
            max = ar[i];
        }

        for(int exp=1;max/exp>0;exp *=10)
        countingsort(exp);
    }

    void countingsort(int exp){
        int count[10];
        for(int i=0;i<10;i++)
        count[i] = 0;

        int index;

        for(int i=0;i<size;i++){
            index = (ar[i]/exp)%10;
            count[index]++;
        }

        for(int i=1;i<10;i++)
        count[i] += count[i-1];

       int out[size];
       for(int i=size-1;i>=0;i--){
         index = (ar[i]/exp)%10;
         out[count[index]-1] = ar[i];
         count[index]--;
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
    Radix r(10);
    r.print();
    r.sort();
    r.print();
}