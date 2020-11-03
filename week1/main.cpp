#include "main.h"
#include <iostream>
#include <fstream>
#include <array>

Sort::Sort(const int *table, int len) : len(len) {
    this->table = new int[len];
    for (int i = 0; i < len; i++) {
        this->table[i] = table[i];
    }

}

void Sort::insertion_sort() const {
    for (int i = 1; i < len; i++) {
        int number = table[i];
        int j = i - 1;
        while (j >= 0 && number < table[j]) {
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = number;
    }
}

void Sort::read_table() const {
    for (int i = 0; i < len; i++) {
        std::cout << table[i] << " ";
    }
}

void Sort::merge_sort(int l, int r) const {
    if (l < r) {
        int m = (r + l) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);

        int len_1 = m - l + 1;
        int len_2 = r - m;

        int left[len_1], right[len_2];

        for (int i = 0; i < len_1; i++) {
            left[i] = table[l + i];
        }
        for (int i = 0; i < len_2; i++) {
            right[i] = table[m + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = l;

        while (i < len_1 && j < len_2) {
            if (left[i] <= right[j]) {
                table[k] = left[i];
                i++;
            } else {
                table[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < len_1) {
            table[k] = left[i];
            i++;
            k++;
        }
        while (j < len_2) {
            table[k] = right[j];
            j++;
            k++;
        }
    }
}

Heap::Heap(const int *table, int len): len(len){
    this->table = new int[len];
    for (int i = 0; i < len; i++) {
        this->table[i] = table[i];
    }
    heap_size = len;
}
int Heap::right_child(int i) const {
    return (i<<1) + 1;
}
int Heap::left_child(int i) const {
    return (i<<1);
}
void Heap::heapify(int i, int n) {
    int largest = i;
    int left_i = left_child(i);
    int right_i = right_child(i);
    if(left_i < n && table[left_i] > table[largest]) largest = left_i;
    if(right_i < n  && table[right_i] > table[largest]) largest = right_i;
    if(largest!=i){
        int temp = table[i];
        table[i] = table[largest];
        table[largest] = temp;
        heapify(largest,n);
    }
}
void Heap::build_heap() {
    for(int i = len/2 -1; i>=0; i--) heapify(i,len);
}
int Heap::extract_max() {
    int max = table[0];
    table[0] = table[len-1];
    heap_size--;
    heapify(0,len);
    return max;
}
void Heap::insert_key(int i) {
    if(heap_size<len){
        heap_size++;
        int k = heap_size-1;
        table[k] = i;
        heapify(k,heap_size);
    }
}
void Sort::heap_sort() {
    Heap kopiec = Heap(table,len);
    kopiec.build_heap();

    for(int i = len-1; i>0; i--){
        int temp = kopiec.table[0];
        kopiec.table[0] = kopiec.table[i];
        kopiec.table[i] = temp;
        kopiec.heapify(0,i);
    }
    table = kopiec.table;
}
int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int table[10000];
    int test_table[10000];
    std::fstream myfile("../tests.txt");
    if (myfile.good()) {
        try {
            for (int i = 0; i < 10000; i++) {
                myfile >> table[i];
                test_table[i] = table[i];
            }
            myfile.close();
            Sort sorter = Sort(table, 10000);
            sorter.heap_sort();
            std::qsort(test_table, 10000, sizeof(int), cmpfunc);
            for (int i = 0; i < 10000; i++) {
                if (sorter.table[i] != test_table[i]) throw "Poorly sorted";
            }
            sorter.read_table();
        } catch (const char *msg) {
            std::cerr << msg << std::endl;
        }

    } else {
        printf("Can't open testfile");
    }
}

