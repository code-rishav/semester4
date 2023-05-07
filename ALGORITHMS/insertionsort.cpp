#include <iostream>
#include <fstream>
using namespace std;
class Insertion{
    int* ar;
    int size;
    public:
    

    void generate_array(){
        int size = rand() % 971+30;
        ar = new int[size];
        for(int i=0;i<size;i++){
            ar[i] = rand()%2*size+1;
        }
    }

    void sort(){
        int count = 0;
        for(int i=1;i<size;i++){
            int key = ar[i];
            int j = i-1;
            while(j>=0 && ar[j]>key){
                count++;
                ar[j+1] = ar[j];
                j = j-1;
            }
            ar[j+1] = key;
        }
        saveResult(count);
    }

    void saveResult(int count){
        ofstream fout;
        fout.open("insertion.csv",ios::app);
        fout<<size<<","<<count<<endl;
        fout.close();
    }
    void execute(){
        for(int i=0;i<100;i++){
            generate_array();
            sort();
            delete ar;
        }
    }

     ~Insertion(){
        delete ar;
    }

};
int main(){
    Insertion ob;
    ob.execute();
}

