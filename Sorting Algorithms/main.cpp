#include <iostream>

using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i; j < size - 1; j++)
        {
            if (arr[min] > arr[j + 1])
                min = j + 1;
        }
        if (i != min)
            swap(arr[min], arr[i]);
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 1; j < (size - i); j++)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l == r) // if one element, return (sorted)
        return;

    int m = (l + r) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


int linearSearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1; // not found
}

int binarySearch(int arr[], int l, int r, int val)
{
    // if(l > r)
    //     return -1;

    if (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == val)
            return mid;

        if (arr[mid] < val)
            return binarySearch(arr, mid + 1, r, val);
        else
            return binarySearch(arr, l, mid - 1, val);
    }
    return -1;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";

    cout << endl;
}
int main()
{
    cout << "Selection Sort" << endl;
    int arr1[] = {4, 1, 5, 2, 3};
    printArr(arr1, 5);
    selectionSort(arr1, 5);
    printArr(arr1, 5);

    cout << "Bubble Sort" << endl;
    int arr2[] = {4, 1, 5, 2, 3};
    printArr(arr2, 5);
    bubbleSort(arr2, 5);
    printArr(arr2, 5);

    cout << "Merge Sort" << endl;
    int arr3[] = {4, 1, 5, 2, 3};
    printArr(arr3, 5);
    mergeSort(arr3, 0, 4);
    printArr(arr3, 5);

    cout << "Quick Sort" << endl;
    int arr4[] = {4, 1, 5, 2, 3};
    printArr(arr4, 5);
    quickSort(arr4, 0, 4);
    printArr(arr4, 5);

    cout << "Insertion Sort" << endl;
    int arr5[] = {4, 1, 5, 2, 3};
    printArr(arr5, 5);
    insertionSort(arr5, 5);
    printArr(arr5, 5);

    cout << "Linear Search: ";
    cout << linearSearch(arr5, 5, 5) << endl;
    cout << "Binary Search: ";
    cout << binarySearch(arr5, 0, 4, 4) << endl;
    return 0;
}
