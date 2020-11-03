#ifndef INSERTIONSORT_MAIN_H
#define INSERTIONSORT_MAIN_H

class Heap {
    int len;
    int heap_size;

    int left_child(int i) const;

    int right_child(int i) const;


public:
    Heap(const int *table, int len);

    int *table;

    int extract_max();

    void insert_key(int i);

    void build_heap();

    void heapify(int i,int n);
};
class Sort {
public:
    int len;
    int *table;
    Sort(const int *table, int len);

    void insertion_sort() const;

    void read_table() const;

    void merge_sort(int l, int r) const;

    void heap_sort();

};

#endif //INSERTIONSORT_MAIN_H
