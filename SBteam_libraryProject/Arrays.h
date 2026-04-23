#pragma once
//Author: sekal bashir
//This header file deefeines the most used array functions 

#include"Common.h"

/* --- 1D Array --- */
void  initArray(int arr[], int* size);
void  printArray(int arr[], int size);

//Inserttion, searching and deletion functions
int   insertAt(int arr[], int* size, int index, int value);
int   deleteAt(int arr[], int* size, int index);
int   linearSearch(int arr[], int size, int value);
int   binarySearch(int arr[], int size, int value);

//Sorting functions
void  bubbleSort(int arr[], int size);
void  selectionSort(int arr[], int size);
void  insertionSort(int arr[], int size);
void merge(int arr[], int left, int middle, int right);
void  mergeSort(int arr[], int left, int right);
void  quickSort(int arr[], int low, int high);

//Other functions
int   findMax(int arr[], int size);
int   findMin(int arr[], int size);
int   sumArray(int* arr, int size);
double averageArray(int arr[], int size);
void  reverseArray(int arr[], int size);
void reserveArray(int arr[], int size, int reservedarr[]);
void restoreArray(int arr[], int reservedarr[], int size, int k);
void  rotateLeft(int arr[], int size, int k);
void  mergeSortedArrays(int a[], int na, int b[], int nb, int out[]);

/* --- 2D Matrix --- */
void  initMatrix(int m[][MAX_COLS], int* rows, int* cols);
void  printMatrix(int m[][MAX_COLS], int rows, int cols);
void  transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]);
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols);
void  multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n);
int sumDiagonal(int m[][MAX_COLS], int size);
int sumAntiDiagonal(int m[][MAX_COLS], int size);
int isSymmetric(int m[][MAX_COLS], int size);
void sortRows(int m[][MAX_COLS], int rows, int cols);

/* --- Dynamic Array --- */
int* createDynamicArray(int capacity);
void  fillArray(int* arr, int size);
void  printDynamicArray(int* arr, int size);
int* resizeArray(int* arr, int newCapacity);
void  freeArray(int* arr);
