#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int lefties = low - 1;
    
    for (int i = low; i <= high-1; ++i){
        if (arr[i] <= pivot){
            lefties++;
            swap(&arr[lefties], &arr[i]);
        }
    }
    swap(&arr[lefties+1], &arr[high]);
    return (lefties+1);
}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void){
    int arr[] = {12, 23, 3 ,43, 51, 35, 19, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
