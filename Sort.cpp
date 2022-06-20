#include "Sort.h"

void selectionSort(long long a[], int n, long long &compare)
{
    int minIndex;

    for (int i = 0; ++compare && i < n; i++)
    {
        for (int j = i + 1; ++compare && j < n; j++)
        {

            if (++compare && a[j] < a[j - 1])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void selectionSort(long long a[], int n, double &runtime)
{
    int minIndex;
    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] < a[j - 1])
            {
                minIndex = a[j];
            }
        }
        swap(a[i], a[minIndex]);
    }

    clock_t end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void insertionSort(long long arr[], long int n, long long &comp)
{

    long int i, temp, j;
    for (i = 1; ++comp && i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (++comp && j >= 0 && ++comp && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void insertionSort(long long arr[], long int n, double &runtime)
{
    clock_t start, end;
    start = clock();
    long int i, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void bubbleSort(long long a[], int n, long long &compare)
{
    for (int i = 0; ++compare && i < n; i++)
    {
        for (int j = n - 1; ++compare && j > i; j--)
        {
            if (++compare && a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}

void bubbleSort(long long a[], int n, double &runtime)
{
    clock_t start, end;
    start = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }

    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void Heap_max(long int k, long long a[], long int n, long long &comp)
{
    if (++comp && 2 * k + 1 >= n)
        return;
    int l = 2 * k + 1;

    int maxx = l;
    if (++comp && 2 * k + 2 < n)
    {
        int r = 2 * k + 2;
        if (++comp && a[r] > a[l])
        {
            maxx = r;
        }
    }

    if (++comp && a[k] < a[maxx])
    {
        swap(a[k], a[maxx]);
        Heap_max(maxx, a, n, comp);
    }
}

void Heap_max(long int k, long long a[], long int n)
{
    if (2 * k + 1 >= n)
        return;
    int l = 2 * k + 1;

    int maxx = l;
    if (2 * k + 2 < n)
    {
        int r = 2 * k + 2;
        if (a[r] > a[l])
        {
            maxx = r;
        }
    }

    if (a[k] < a[maxx])
    {
        swap(a[k], a[maxx]);
        Heap_max(maxx, a, n);
    }
}

void heapSort(long long a[], long int n, long long &comp)
{

    for (int i = (n - 1) / 2; ++comp && i >= 0; i--)
    {
        Heap_max(i, a, n, comp);
    }
    swap(a[0], a[n - 1]);
    n--;
    while (++comp && n > 1)
    {
        Heap_max(0, a, n, comp);
        n--;
        swap(a[0], a[n]);
    }
}

void heapSort(long long a[], long int n, double &runtime)
{
    clock_t start, end;
    start = clock();
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        Heap_max(i, a, n);
    }
    swap(a[0], a[n - 1]);
    n--;
    while (n > 1)
    {
        Heap_max(0, a, n);
        n--;
        swap(a[0], a[n]);
    }
    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void merge(long long a[], long int n, long int l, long int mid, long int r, long long &comp)
{
    int l1 = l, r1 = mid, l2 = mid + 1, r2 = r;
    int *temp = new int[n];
    int i = l1;

    while (++comp && l1 <= r1 && ++comp && l2 <= r2)
    {
        if (++comp && a[l1] <= a[l2])
        {
            temp[i] = a[l1];
            i++;
            l1++;
        }
        else
        {
            temp[i] = a[l2];
            i++;
            l2++;
        }
    }
    while (++comp && l1 <= r1)
    {
        temp[i++] = a[l1++];
    }
    while (++comp && l2 <= r2)
    {
        temp[i++] = a[l2++];
    }
    for (int k = l; ++comp && k <= r; k++)
    {
        a[k] = temp[k];
    }
    delete[] temp;
}

void merge(long long a[], long int n, long int l, long int mid, long int r)
{
    int l1 = l, r1 = mid, l2 = mid + 1, r2 = r;
    int *temp = new int[n];
    int i = l1;

    while (l1 <= r1 && l2 <= r2)
    {
        if (a[l1] <= a[l2])
        {
            temp[i] = a[l1];
            i++;
            l1++;
        }
        else
        {
            temp[i] = a[l2];
            i++;
            l2++;
        }
    }
    while (l1 <= r1)
    {
        temp[i++] = a[l1++];
    }
    while (l2 <= r2)
    {
        temp[i++] = a[l2++];
    }
    for (int k = l; k <= r; k++)
    {
        a[k] = temp[k];
    }
    delete[] temp;
}

void Split(long long a[], long int n, long int l, long int r, long long &comp)
{
    if (++comp && l < r)
    {
        long int mid = (l + r) / 2;
        Split(a, n, l, mid, comp);
        Split(a, n, mid + 1, r, comp);
        merge(a, n, l, mid, r, comp);
    }
}

void Split(long long a[], long int n, long int l, long int r)
{
    if (l < r)
    {
        long int mid = (l + r) / 2;
        Split(a, n, l, mid);
        Split(a, n, mid + 1, r);
        merge(a, n, l, mid, r);
    }
}

void mergeSort(long long a[], long int n, int l, int r, long long &comp)
{

    Split(a, n, 0, n - 1, comp);
}

void mergeSort(long long a[], long int n, int l, int r, double &runtime)
{
    clock_t start, end;
    start = clock();
    Split(a, n, 0, n - 1);
    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void quickSort(long long a[], int first, int last, long long &comp)
{
    int pivot = a[(last + first) / 2];
    int i = first, j = last;
    do
    {
        while (++comp && a[i] < pivot)
            i++;
        while (++comp && a[j] > pivot)
            j--;
        if (++comp && i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (++comp && i < j);
    if (++comp && j > first)
        quickSort(a, first, j, comp);
    if (++comp && i < last)
        quickSort(a, i, last, comp);
}

void quickSort(long long a[], int first, int last, double &runtime)
{
    clock_t start, end;
    start = clock();

    int pivot = a[(last + first) / 2];
    int i = first, j = last;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (j > first)
        quickSort(a, first, j, runtime);
    if (i < last)
        quickSort(a, i, last, runtime);

    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void radixSort(long long arr[], int n, long long &compare)
{ // code cô Thảo

    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; ++compare && i < n; ++i)
        if (++compare && arr[i] > max_val)
        {
            max_val = arr[i];
        }

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;
        div = max_val / pow(10, digits);
    } while (++compare && div > 0);

    int **tempArr = new int *[10]; // declare variables for temp store
    for (int i = 0; ++compare && i < 10; ++i)
        tempArr[i] = new int[n];
    int tempCount[10];
    for (int i = 0; ++compare && i < digits; ++i)
    {
        int exp = pow(10, i);
        for (int j = 0; ++compare && j < 10; ++j) // reset the counting
            tempCount[j] = 0;
        for (int j = 0; ++compare && j < n; ++j)
        { // form groups
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0; // combine groups
        for (int j = 0; ++compare && j < 10; ++j)
            for (int k = 0; ++compare && k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
        delete[] tempArr;
    }
}

void radixSort(long long arr[], int n, double &runtime)
{ // code cô Thảo

    clock_t start = clock();
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; i < n; ++i)
        if (arr[i] > max_val)
        {

            max_val = arr[i];
        }

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;

        div = max_val / pow(10, digits);
    } while (div > 0);

    int **tempArr = new int *[10]; // declare variables for temp store
    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];
    int tempCount[10];
    for (int i = 0; i < digits; ++i)
    {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j) // reset the counting
            tempCount[j] = 0;
        for (int j = 0; j < n; ++j)
        { // form groups
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0; // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
    clock_t end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
    delete[] tempArr;
}

void shakerSort(long long arr[], int n, long long &compare)
{ // code cô Thảo

    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; ++compare && j >= left; --j)
            if (++compare && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top

        left = k + 1;
        for (int j = left; ++compare && j <= right; ++j)
            if (++compare && arr[j - 1] > arr[j])
            {

                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (++compare && left <= right);
}

void shakerSort(long long arr[], int n, double &runtime)
{ // code cô Thảo

    clock_t start = clock();
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top

        left = k + 1;
        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j])
            {

                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end

        right = k - 1;
    } while (left <= right);
    clock_t end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void shellSort(long long arr[], int n, long long &comp)
{

    for (long int gap = n / 2; ++comp && gap > 0; gap /= 2)
    {
        for (long int i = gap; ++comp && i < n; i += 1)
        {
            long int temp = arr[i];
            long int j;
            for (j = i; ++comp && j >= gap && ++comp && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSort(long long arr[], int n, double &runtime)
{
    clock_t start, end;
    start = clock();
    for (long int gap = n / 2; gap > 0; gap /= 2)
    {
        for (long int i = gap; i < n; i += 1)
        {
            long int temp = arr[i];
            long int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void countingSort(long long arr[], long int n, long long &comp)
{
    long long Max, Min;
    Max = arr[0];
    for (long int i = 1; ++comp && i < n; i++)
    {
        Max = max(Max, arr[i]);
        comp++;
    }

    Min = arr[0];
    for (long int i = 1; ++comp && i < n; i++)
    {
        Min = min(Min, arr[i]);
        comp++;
    }

    int range = (Max - Min) + 1;
    vector<long int> count(range), out(n);

    for (long int i = 0; ++comp && i < n; i++)
    {
        count[arr[i] - Min]++;
    }

    for (long int i = 1; ++comp && i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for (long int i = n - 1; ++comp && i >= 0; i--)
    {
        out[count[arr[i] - Min] - 1] = arr[i];
        count[arr[i] - Min]--;
    }

    for (long int i = 0; ++comp && i < n; i++)
    {
        arr[i] = out[i];
    }
}

void countingSort(long long arr[], long int n, double &runtime)
{
    clock_t start, end;
    start = clock();

    long long Max, Min;
    Max = arr[0];
    for (long int i = 1; i < n; i++)
    {
        Max = max(Max, arr[i]);
    }

    Min = arr[0];
    for (long int i = 1; i < n; i++)
    {
        Min = min(Min, arr[i]);
    }

    int range = (Max - Min) + 1;
    vector<long int> count(range), out(n);

    for (long int i = 0; i < n; i++)
    {
        count[arr[i] - Min]++;
    }

    for (long int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for (long int i = n - 1; i >= 0; i--)
    {
        out[count[arr[i] - Min] - 1] = arr[i];
        count[arr[i] - Min]--;
    }

    for (long int i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }

    end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}

void flashSort(long long a[], int n, long long &compare)
{
    long minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; ++compare && i < m; i++)
    {
        l[i] = 0;
    }

    for (int i = 1; ++compare && i < n; i++)
    {
        if (++compare && a[i] < minVal)
            minVal = a[i];
        if (++compare && a[i] > a[max])
            max = i;
    }

    if (++compare && a[max] == minVal)
        return;

    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; ++compare && i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    for (int i = 1; ++compare && i < m; i++)
    {
        l[i] += l[i - 1];
    }

    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++compare && nmove < n - 1)
    {
        while (++compare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++compare && k < 0)
            break;
        while (++compare && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    insertionSort(a, n, compare);
}

void flashSort(long long a[], int n, double &runtime)
{
    clock_t start = clock();

    long minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
    {
        l[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }

    if (a[max] == minVal)
        return;

    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    for (int i = 1; i < m; i++)
    {
        l[i] += l[i - 1];
    }

    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    insertionSort(a, n, runtime);
    clock_t end = clock();
    runtime += (double)(end - start) * 1000 / CLOCKS_PER_SEC;
}
