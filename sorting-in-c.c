//
// Created by Арсений Горячев on 03.11.2022.
//

#include <stdio.h>

void print_array(int array[], int size){
     for (int i = 0; i < size; ++i) printf("%d ", array[i]);
}

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = size-1; j > i; --j) {
            if (array[j-1] > array[j]) swap(array, j, j-1);
        }
    }
}

void selection_sort(int array[], int size) {
    int index;

    for (int i = 0; i < size-1; ++i) {
        index = i;
        for (int j = i; j <= size-1; ++j) {
            if (array[j] < array[index]) index = j;
        }
        if (index != 1) swap(array,i,index);
    }
}

void insertion_sort(int array[], int size) {
    int index, newElement;

    for (int i = 1; i < size; ++i) {
        newElement = array[i];
        index = i - 1;
        while (index >= 0 && array[index] > newElement) {
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = newElement;
    }
}

void merge(int array[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = array[start + i];
    for (j = 0; j < n2; j++)
        right[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void ms_helper(int array[], int start, int end)
{
    if (start < end) {
        int m = start + (end - start) / 2;

        ms_helper(array, start, m);
        ms_helper(array, m + 1, end);

        merge(array, start, m, end);
    }
}

void merge_sort(int array[], int size) {
    int head = 0, tail = size;
    ms_helper(array,head,tail);
}

void qs_helper(int array[], int head, int tail) {
    int start = head;
    int end = tail;
    int mid = array[(start + end) / 2];

    while (start <= end)
    {
        while (array[start] < mid)
            start++;
        while (array[end] > mid)
            end--;
        if (start <= end)
        {
            swap(array, start, end);
            start++;
            end--;
        }
    }
    if (end > head)
        qs_helper(array, head, end);
    if (start < tail)
        qs_helper(array, start, tail);
}

void quick_sort(int array[], int size) {
    qs_helper(array, 0, size);
}


int main() {
    int array[15] = {4,5,3,2,1,33,2,-5,12,8,3,234,5,-100,23,};

    //bubble_sort(array,15);
    //selection_sort(array,15);
    //insertion_sort(array,15);
    //quick_sort(array, 15);
    //merge_sort(array,15);

    print_array(array, 15);

    return 0;
}