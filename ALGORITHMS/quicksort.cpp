#include<iostream>
#include <fstream>
using namespace std;
class Quicksort{
    int* ar;
    int size;
    int count;

     public:

    void generate_array(){
        ar = new int[size];
        for(int i=0;i<size;i++){
            ar[i] = rand()%2*size+1;
        }
    }

    void quicksort(int l,int r){
        if(r>l){
            int p = partition(l,r);
            quicksort(l,p);
            quicksort(p+1,r);
        }
    }

    int partition(int l,int r){
        //creating a random index 
      
        int num = rand() % size;
        swap(ar[num],ar[r]); //swapping it with the last element for lamuto's partition

        int pivot=ar[r];
        int i=l-1;
        for(int j=l;j<=r-1;j++){
            count++;
            if(ar[j]<pivot){
                i++;
                swap(ar[i],ar[j]);
            }
        }
        swap(ar[i+1],ar[r]);
        return i+1;
    }

    int merge(int l,int r,int m){
        int ls = m-l+1,rs=r-m;
        int left[ls],right[rs];
        int i=0,j=0;
        int k = l;
        int comp=0;
        while(i<ls && j<rs){
            comp++;
            if(left[i]<=right[j])
            ar[k++] = left[i++];
            else
            ar[k++] = right[j++];
        }
        while(i<ls)
        ar[k++] = left[i++];
        while(j<rs)
        ar[k++] = right[j++];
        return comp;
    }

    void store(){ 
        ofstream fout;
        fout.open("quicksort.csv",ios::app);
        fout<<size<<","<<count<<endl;
        fout.close();
    }

    void manage(){
        for(int i=1;i<=100;i++ ){
            size=rand() % 971+30;
            generate_array();
            count = 0;
            quicksort(0,size-1);
            store();
            cout<<"execution completed for iteration "<<i<<"with array size"<<size<<endl;
        }
    }


};
int main(){
    Quicksort ob;
    ob.manage();
    cout<<"Task done"<<endl;
}
