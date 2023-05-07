#include <iostream>
#include <vector>
using namespace std;

class Bucket{
    int *ar;
    int size;
    public:
    Bucket(int s){
        size = s;
        ar = new int[size];
        cout<<"Enter the elements of the array"<<endl;
        for(int i=0;i<size;i++)
        cin>>ar[i];
    }

    void sort(int k){
        int max = ar[0];
        for(int i=0;i<size;i++){
            if(ar[i]>max)
            max = ar[i];
        }
        max +=1;

        vector<int> bckt[k];
        for(int i=0;i<size;i++){
            int index = (ar[i]*k)/max;
            bckt[index].push_back(ar[i]);
        }
        

        for(int i=0;i<k;i++){
            insertionsort(bckt[i]);
        }

       

        int index = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<bckt[i].size();j++){
                ar[index] = bckt[i][j];
                index++;
            }
        }
    }

    void insertionsort(vector<int>& v){
        int n = v.size();
        for(int i=0;i<n;i++){
            int j = i;
            int temp = v[j];
            while(j>0 & temp<v[j-1]){
                v[j] = v[j-1];
                j--;
            }
            v[j] = temp;
        }
    }
    
    void print(){
        for(int i=0;i<size;i++)
        cout<<ar[i]<<" ";
        cout<<endl;
    }

    
};

int main(){
    Bucket b(7);
    b.sort(4);
    b.print();
}