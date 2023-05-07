#include<iostream>
#include <fstream>
using namespace std;
class Mergesort{
    int* ar;
    int size;

     public:

    void generate_array(){
        ar = new int[size];
        for(int i=0;i<size;i++){
            ar[i] = rand()%2*size+1;
        }
    }

    int sort(int l,int r,int count){
        if(r>l){
            int mid = l +(r-l)/2;
            sort(l,mid,count);
            sort(mid+1,r,count);
            count+=merge(l,r,mid);
        }
        return count;
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

    void store(int count){ 
        ofstream fout;
        fout.open("mergesort.csv",ios::app);
        fout<<size<<","<<count<<endl;
        fout.close();
    }

    void manage(){
        for(int i=1;i<=100;i++ ){
            size=rand() % 971+30;
            generate_array();
            int comp = sort(0,size-1,0);
            store(comp);
            cout<<"execution completed for iteration "<<i<<"with array size"<<size<<endl;
        }
    }


};
int main(){
    Mergesort ob;
    ob.manage();
    cout<<"Task done"<<endl;
}
