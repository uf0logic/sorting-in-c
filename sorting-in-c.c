//
// Created by Арсений Горячев on 03.11.2022.
//

#include <stdio.h>

void printArray(int arr[], int size){
     for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
}

int swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (arr[j-1] > arr[j]) swap(arr, j, j-1);
        }
    }
}

void selectionSort(int arr[], int size) {
    int index;

    for (int i = 0; i < size-1; ++i) {
        index = i;
        for (int j = i; j <= size - 1; ++j) {
            if (arr[j] < arr[index]) index = j;
        }
        if (index != 1) swap(arr,i,index);
    }
}

void insertionSort(int arr[], int size) {
    int index, newElement;

    for (int i = 1; i < size; ++i) {
        newElement = arr[i];
        index = i - 1;
        while (index >= 0 && arr[index] > newElement) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = newElement;
    }
}

int main() {
    int arr[15] = {4,5,3,2,1,33,2,-5,12,8,3,234,5,-100,23,};

    //bubbleSort(arr,15);
    //selectionSort(arr,15);
    //insertionSort(arr,15);

    printArray(arr,15);



    return 0;
}