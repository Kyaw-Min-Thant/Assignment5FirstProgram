#include "stdio.h"

int min(int first, int second){
    if(second>first){
        return first;
    } else{
        return second;
    }
}

int jumpSearch(int arr[],int size,int key) {

    int step = size / 4;

    int previous;

    while (arr[min(step, size) - 1] < key) {

        int a = arr[min(step, size)];

        if (a == key) {
            return min(step, size);
        }

        previous = step;

        step = step + (size / 4);

        if (previous >= size) {
            return -1;
        }

    }

    int mid = previous + ((step - previous) / 2);

    if (arr[mid] == key) {

        return mid;

    } else if (arr[mid] < key && step<size) {

        for (int i = mid; i < step; i++) {

            if (arr[i] == key) {
                return i;
            }
        }

    } for (int i = previous; i < step; i++) {

        if (arr[i] == key) {
            return i;
        }
    }

}

int main(){

    int arr[]={1,11,12,22,23,33,34,44,45,55,56,66,67,77,78,88,89,99,100,111,222,333};

    int size = sizeof(arr)/sizeof(arr[0]);

    int toFind = 222;

    int indexNumber = jumpSearch(arr, size, toFind);

    if(toFind == arr[indexNumber]){

        printf("indexNumber :%d\n",indexNumber);

        printf("we found :%d\n",arr[indexNumber]);

    } else{

        printf("notFound\n");

    }

    return 0;

}