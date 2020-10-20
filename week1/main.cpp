#include "main.h"
#include <iostream>
#include <fstream>
#include <array>

InsertionSort::InsertionSort(const int *table, int len) : len(len) {
    this->table = new int[len];
    for (int i = 0; i < len; i++) {
        this->table[i] = table[i];
    }

}

void InsertionSort::sort() const {
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

void InsertionSort::read_table() const {
    for (int i = 0; i < len; i++) {
        std::cout << table[i] << " ";
    }
}

MergeSort::MergeSort(const int *table, int len) : len(len) {
    this->table = new int[len];
    for (int i = 0; i < len; i++) {
        this->table[i] = table[i];
    }
}

void MergeSort::sort(int l, int r) const {
    if (l < r) {
        int m = (r + l) / 2;
        sort(l, m);
        sort(m + 1, r);

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

void MergeSort::read_table() const {
    for (int i = 0; i < len; i++) {
        std::cout << table[i] << " ";
    }
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
            MergeSort sorter = MergeSort(table, 10000);
            sorter.sort(0, 10000 - 1);
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

