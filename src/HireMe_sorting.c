#include <string.h>
#include "HireMe_u8.h"
#include "HireMe_u32.h"
#include "HireMe_utils.h"
#include "HireMe_sorting.h"

// Selection Sort
void SelectionSort(u8 *array1, u8 *array2, u32 n)
{
    u32 i, j, min_element;
    for (i = 0; i < n-1; i++)
    {
        min_element = i;
        for (j = i+1; j < n; j++)
            if (array1[j] < array1[min_element])
                min_element = j;
        swap(&array1[min_element], &array1[i]);
        swap32(&array2[min_element*32], &array2[i*32]);
    }
}

// Merge Function
void Merge(u8 *arr, u8 *arr2, u32 l, u32 m, u32 r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    u8 L[n1], R[n2], L2[n1*32], R2[n2*32];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        memcpy(&L2[i*32], &arr2[(l + i)*32], 32);
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        memcpy(&R2[j*32], &arr2[(m + 1 + j)*32], 32);
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            memcpy(&arr2[k*32], &L2[i*32], 32);
            i++;
        }
        else
        {
            arr[k] = R[j];
            memcpy(&arr2[k*32], &R2[j*32], 32);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        memcpy(&arr2[k*32], &L2[i*32], 32);
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        memcpy(&arr2[k*32], &R2[j*32], 32);
        j++;
        k++;
    }
}
// Merge Sort Function in C
void MergeSort(u8 *arr, u8 *arr2, u32 l, u32 r)
{
    if (l < r)
    {
        u8 m = l+(r-l)/2;
        MergeSort(arr, arr2, l, m);
        MergeSort(arr, arr2, m+1, r);
        Merge(arr, arr2, l, m, r);
    } 
}