#include <cstring>
#include "DataGenerator.h"
#include <vector>

void selectionSort(long long a[], int n, long long &compare);

void selectionSort(long long a[], int n, double &runtime);

void insertionSort(long long arr[], long int n, long long &comp);

void insertionSort(long long arr[], long int n, double &runtime);

void bubbleSort(long long a[], int n, long long &compare);

void bubbleSort(long long a[], int n, double &runtime);

void Heap_max(long int k, long long a[], long int n, long long &comp);

void Heap_max(long int k, long long a[], long int n);

void heapSort(long long a[], long int n, long long &comp);

void heapSort(long long a[], long int n, double &runtime);

void merge(long long a[], long int n, long int l, long int mid, long int r, long long &comp);

void merge(long long a[], long int n, long int l, long int mid, long int r);

void Split(long long a[], long int n, long int l, long int r, long long &comp);

void Split(long long a[], long int n, long int l, long int r);

void mergeSort(long long a[], long int n, int l, int r, long long &comp);

void mergeSort(long long a[], long int n, int l, int r, double &runtime);

void quickSort(long long a[], int l, int r, long long &comp);

void quickSort(long long a[], int l, int r, double &runtime);

void radixSort(long long arr[], int n, long long &compare);

void radixSort(long long arr[], int n, double &runtime);

void shakerSort(long long arr[], int n, long long &compare);

void shakerSort(long long arr[], int n, double &runtime);

void shellSort(long long arr[], int n, long long &comp);

void shellSort(long long arr[], int n, double &runtime);

void countingSort(long long arr[], long int n, long long &comp);

void countingSort(long long arr[], long int n, double &runtime);

void flashSort(long long a[], int n, long long &compare);

void flashSort(long long a[], int n, double &runtime);