#ifndef INSERTIONSORT_MAIN_H
#define INSERTIONSORT_MAIN_H

class InsertionSort {
public:
    int len;
    int *table;
    InsertionSort(const int *table, int len);

    void sort() const;

    void read_table() const;
};


#endif //INSERTIONSORT_MAIN_H
