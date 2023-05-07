#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class HeapSort{
    int size;
    int* arr;
    static int count;

    public:
    void store(){ 
        ofstream fout;
        fout.open("heap_sort.csv",ios::app);
        fout<<size<<","<<count<<endl;
        fout.close();
    }

     void generate_array(){
        arr = new int[size];
        for(int i=0;i<size;i++){
            arr[i] = rand()%2*size+1;
        }
    }

    void buildheap(){
        for(int i=(size-2)/2;i>=0;i--){
		maxheapify(i);
	    }
    }

    void maxheapify(int i){
        int lt = 2*i+1;
        int rt = 2*i+2;
        int largest = i;
        if(lt<size && arr[lt]>arr[largest])
        largest = lt;
        if(rt<size && arr[rt]>arr[largest])
        largest = rt;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            count++;
            maxheapify(largest);
        }
    }

    void heapsort(){
        buildheap();
        for(int i=size-1;i>=1;i--){
            swap(arr[0],arr[i]);
            maxheapify(0);
        }
}

     void manage(){
        for(int i=1;i<=100;i++ ){
            size=rand() % 971+30;
            generate_array();
            count = 0;
            heapsort();
            store();
            cout<<"execution completed for iteration "<<i<<"with array size"<<size<<endl;
        }
    }

};

int main(){
    HeapSort h1;
    h1.manage();
}