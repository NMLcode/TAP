#include <iostream>

using namespace std;

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = start-1;

    for(int j = start; j < end; j++) {
        if(array[j]<pivot) {
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[end]);
    return (i+1);
}

void quicksort(int array[], int start, int end) {
    if(start<end) {
        int pi = partition(array, start, end);

        quicksort(array, start, pi - 1);
        quicksort(array, pi + 1, end);
    }
}


int main() {
    int array[] = {2,8,10,1,3,6,5,9,4,7,11,0,-1,23,-4,30};
    int n=sizeof(array)/sizeof(array[0]);

    quicksort(array, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }

    return 0;
}