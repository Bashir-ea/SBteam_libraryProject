#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include "Common.h"
#include "pch.h"

namespace Arr {

    //!D array functions
    void  initArray(int arr[], int* size) {
        *size = 0;
    }

    void printArray(int ary[], int size) {
        std::cout << "Arrays elements: [ " << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << ary[i];
            if (i < size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << " ]." << std::endl;
    }

    //Modification functions 
    int insertAt(int arr[], int* size, int index, int value) {
        if (index < 0 || index > *size) return -1;  // invalid index
        if (*size >= MAX_1D) return -1;             // array full

        for (int i = *size; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = value;
        (*size)++;
        return 0;
    }

    int deletAt(int arr[], int* size, int index) {
        if (index < 0 || index > *size) return -1;  // invalid index

        for (int i = index; i < *size - 1; i++)
            arr[i] = arr[i + 1];


        (*size)--;
        return 0;
    }

    //Search functions
    int   linearSearch(int arr[], int size, int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;  // not found
    }

    int binarySearch(int arr[], int size, int value) {
        int low = 0, high = size - 1, mid;
        mid = (low + high) / 2;

        while (low <= high) {

            if (value == arr[mid])  return mid;
            else if (value < arr[mid]) high = mid - 1;
            else low = mid + 1;

            mid = (low + high) / 2;
        }
        return -1; // not found 
    }

    //Sorting functions 
    void  bubbleSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void selectionSort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }

    void insertionSort(int arr[], int size) {
        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    std::swap(arr[j], arr[j - 1]);
                }
            }
        }
    }

    void mergeSortedArrays(int a[], int b[], int sizeA, int sizeB, int out[]) {
        int i = 0, j = 0, k = 0;
        while (i < sizeA && j < sizeB) {
            if (a[i] < b[j]) {
                out[k] = a[i];
                i++, k++;
            }
            else {
                out[k] = b[j];
                j++, k++;
            }
        }
        while (i < sizeA) {
            out[k] = a[i];
            i++, k++;
        }
        while (j < sizeB) {
            out[k] = b[j];
            j++, k++;
        }
    }
    void merge(int arr[], int left, int middle, int right) {
        int a[MAX_1D], b[MAX_1D];
        int sizeA = middle - left + 1, sizeB = right - middle;
        for (int i = 0; i < sizeA; i++) {
            a[i] = arr[left + i];
        }
        for (int j = 0; j < sizeB; j++) {
            b[j] = arr[middle + 1 + j];
        }
        mergeSortedArrays(a, b, sizeA, sizeB, arr + left);
    }

    void mergeSort(int arr[], int left, int right) {
        if (left >= right) return;
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);

    }

    void quickSort(int arr[], int start, int end) {
        int pivot = arr[end];
        int i = start - 1;
        if (start >= end) return;
        for (int j = start; j < end; j++) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[end]);

        quickSort(arr, start, i);
        quickSort(arr, i + 2, end);

    }

    //max and min functions
    int findMax(int arr[], int size) {
        int maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
    int findMin(int arr[], int size) {
        int minVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }

    //other functions
    int sumArray(int arr[], int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    double avergeArray(int arr[], int size) {
        return static_cast<double>(sumArray(arr, size)) / size;
    }

    void reversarray(int ary[], int size) {
        for (int i = 0; i < size / 2; i++) {
            std::swap(ary[i], ary[size - i - 1]);
        }
    }

    void reserveArray(int arr[], int size, int reservedarr[]) {
        for (int i = 0; i < size; i++) {
            reservedarr[i] = arr[i];
        }
    }
    void restoreArray(int arr[], int reservedarr[], int size, int k) {
        for (int i = 0; i < k; i++) {
            arr[size - k + i] = reservedarr[i];
        }
    }
    void rotateLeft(int arr[], int size, int k) {
        k = k % size; // handle cases where k >= size
        int reservedarr[MAX_1D];
        reserveArray(arr, k, reservedarr);

        for (int i = 0; i < size - k; i++) {
            arr[i] = arr[i + k];
        }

        restoreArray(arr, reservedarr, size, k);

    }


    //2D array functions
    void intMatrix(int matrix[][MAX_COLS], int* rows, int* cols) {
        for (int i = 0; i < *rows; i++) {
            for (int j = 0; j < *cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
        std::cout << "Matrix elements: [ " << std::endl;
        for (int i = 0; i < rows; i++) {
            std::cout << "  [ ";
            for (int j = 0; j < cols; j++) {
                std::cout << matrix[i][j];
                if (j < cols - 1)
                {
                    std::cout << ", ";
                }
            }
            std::cout << " ]" << std::endl;
        }
        std::cout << " ]." << std::endl;
    }
    void transpoeMatrix(int matrix[][MAX_COLS], int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < rows; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                out[i][j] = a[i][j] + b[i][j];
            }

        }
    }

    void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int out[][MAX_COLS], int n) {
        int sum;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += a[i][k] * b[k][j];
                }
                out[i][j] = sum;
            }
        }

    }

    int sumDiagonal(int m[][MAX_COLS], int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += m[i][i];
        }
        return sum;
    }

    int sumAntiDiagonal(int m[][MAX_COLS], int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += m[size - 1 - i][size - 1 - i];
        }
        return sum;
    }
    int isSymmetric(int m[][MAX_COLS], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (m[i][j] != m[j][i]) {
                    return 0; // not symmetric
                }
            }

        }
        return 1; // symmetric
    }
    void sortRows(int m[][MAX_COLS], int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            bubbleSort(m[i], cols);
        }
    }

    //Dynamic array functions 
    int* initDynamicArray(int capcity) {
        return new int[capcity];
    }

    int fillArray(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << "Element [" << i + 1 << "]: " << std::endl;
            std::cin >> arr[i];
            while (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');                
                std::cout << "Invalid input. Please enter a valid number: ";
                std::cin >> arr[i];
            }
        }
        return 0;
    }
    void printDynamicArray(int* ary, int size) {
        std::cout << "Array elemts: ";
        for (int i = 0; i < size; i++) {
            std::cout << ary[i] << " ";
        }
        std::cout << std::endl;
    }
    int* resizeArray(int* arr,int originalCapacity, int newCapacity) {
        int* newArr = new int[newCapacity + originalCapacity];
        for (int i = 0; i < originalCapacity; i++) {
			newArr[i] = arr[i];
        }
        delete[] arr;
        return newArr;
    }
    void freearry(int* arr) {
        delete[] arr;
        arr = nullptr;
    }
    
}