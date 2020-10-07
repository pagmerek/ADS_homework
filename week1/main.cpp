#include "main.h"
#include <iostream>
#include <fstream>
#include <array>
 InsertionSort::InsertionSort(const int *table, int len): len(len) {
         this->table = new int[len];
         for(int i = 0; i<len; i++){
             this->table[i] = table[i];
         }

     }
 void InsertionSort::sort() const{
    for(int i = 1; i<len;i++){
        int number = table[i];
        int j = i - 1;
        while(j>=0 && number<table[j]){
            table[j+1] = table[j];
            j = j - 1;
        }
        table[j+1] = number;
    }
}
void InsertionSort::read_table() const {
    for(int i = 0; i< len; i++){
        std::cout<<table[i]<<" ";
    }
}
int cmpfunc(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int main(){
    int table[10000];
    int test_table[10000];
    std::fstream myfile("../tests.txt");
    if(myfile.good()){
        try{
            for(int i=0;i<10000;i++){
                myfile >> table[i];
                test_table[i] = table[i];
            }
            myfile.close();
            InsertionSort sorter = InsertionSort(table,10000);
            sorter.sort();
            std::qsort(test_table,10000,sizeof(int),cmpfunc);
            for(int i = 0; i<10000; i++){
                if(sorter.table[i]!=test_table[i]) throw "Poorly sorted";
            }
            sorter.read_table();
        } catch (const char* msg) {
            std::cerr<<msg<<std::endl;
        }

    }else{
        printf("Can't open testfile");
    }
}

