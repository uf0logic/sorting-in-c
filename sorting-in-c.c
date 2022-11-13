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

/*
void merge(int array[], int temp_array[], int start, int mid, int end) {
    int i_temp = 0, i_lower = start, i_upper = mid+1;

    while ((i_lower <= mid) && (i_upper <= end)) {
        if (array[i_lower] < array[i_upper])
            temp_array[i_temp++] = array[i_lower++];
        else
            temp_array[i_temp++] = array[i_upper++];
    }

    if (i_lower <=  mid) {
        for
    }
}

void merge_helper(int array[], int temp_array, int head, int tail) {
    if (head == tail) return;

    int mid = (head + tail) / 2;

    merge_helper(array, temp_array, head, mid);
    merge_helper(array, temp_array, mid+1, tail);

    merge(array, temp_array, head, mid, tail);
}

void merge_sort(int array[], int size) {
    int head = 0, tail = size-1;

    merge_helper(array, temp_array, head, tail);
    delete[] temp_array;
}
*/

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

void quick_sort(int *array, int size) {
    qs_helper(array, 0, size);
}


int main() {
    int array[15] = {4,5,3,2,1,33,2,-5,12,8,3,234,5,-100,23,};

    //bubble_sort(array,15);
    //selection_sort(array,15);
    //insertion_sort(array,15);
    //quick_sort(array, 15);

    print_array(array, 15);

    return 0;
}