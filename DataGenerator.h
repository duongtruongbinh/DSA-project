#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
void HoanVi(T &a, T &b);

void GenerateRandomData(long long a[], int n);

void GenerateSortedData(long long a[], int n);

void GenerateReverseData(long long a[], int n);

void GenerateNearlySortedData(long long a[], int n);

void GenerateData(long long a[], int n, int dataType);
