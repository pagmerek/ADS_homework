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
class MergeSort {
public:
    int len;
    int *table;
    MergeSort(const int *table, int len);


    void sort(int l, int r) const;

    void read_table() const;
};

#endif //INSERTIONSORT_MAIN_H
