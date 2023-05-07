#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class insertion{
    int size;
    int *ar;
    
    public:

    void generate_array(){
        ar = new int[size];
        for(int i=0;i<size;i++){
            ar[i] = rand()%2*size+1;
        }
    }

    int sort(){
        int i, key, j;
        int count = 0;
        for (i = 1; i < size; i++)
        {
            key = ar[i];
            j = i - 1;
            count++;
            while (j >= 0 && ar[j] > key)
            {
                count++;
                ar[j + 1] = ar[j];
                j = j - 1;
             }
            ar[j + 1] = key;
        }
        return count;
    }

    void store(int count){ 
        ofstream fout;
        fout.open("insertion.csv",ios::app);
        fout<<size<<","<<count<<endl;
        fout.close();
    }

    void manage(){
        for(int i=1;i<=100;i++ ){
            size=rand() % 971+30;
            generate_array();
            int comp = sort();
            store(comp);
            cout<<"execution completed for iteration "<<i<<"with array size"<<size<<endl;
        }
    }


};
int main(){
    insertion i1;
    i1.manage();

    cout<<"Task done"<<endl;
}