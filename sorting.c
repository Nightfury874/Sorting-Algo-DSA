#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
void swap(long int* a, long int* b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 
  
// Bubble_sort_method
void bubbleSort(long int a[], long int n) 
{ 
    for (long int i = 0; i < n - 1; i++) { 
        for (long int j = 0; j < n - i - 1; j++) { 
            if (a[j] > a[j + 1]) { 
                swap(&a[j], &a[j + 1]); 
            } 
        } 
    } 
} 
  
// Insertion_sort_method
void insertionSort(long int arr[], long int n) 
{ 
    long int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
  
// Selection_sort_method 
void selectionSort(long int arr[], long int n) 
{ 
    long int i, j, midx; 
  
    for (i = 0; i < n - 1; i++) { 
  
        midx = i; 
  
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[midx]) 
                midx = j; 
  
        swap(&arr[midx], &arr[i]); 
    } 
} 

// to reverse sort a sorted array
void reverse_sort(long int arr[], long int n)
{
    long int i;
    for(i=0;i<n/2;i++)
    {
        swap(&arr[i],&arr[n-i]);
    }
}
  
int main() 
{ 
    long int n = 10000; 
    int it = 0; 
  
    double tim1[3], tim2[3], tim3[3]; 
  
    printf("A_size, Bubble, Insertion, Selection\n"); 
  
   
        long int a[n], b[n], c[n]; 
        
        for (int i = 0; i < n; i++) { 
            long int no = rand() % n + 1; 
            a[i] = no; 
            b[i] = no; 
            c[i] = no;
        }
  //with random arrays
        clock_t start, end; 
  
        start = clock(); 
        bubbleSort(a, n); 
        end = clock(); 
  
        tim1[0] = ((double)(end - start)); 
  
        start = clock(); 
        insertionSort(b, n); 
        end = clock(); 
  
        tim2[0] = ((double)(end - start)); 
  
        start = clock(); 
        selectionSort(c, n); 
        end = clock(); 
  
        tim3[0] = ((double)(end - start)); 
  
        printf(" With random array of size %li, time(in seconds)  for \nbubble sort: %li, \ninsertion sort: %li, \nselection sort: %li\n\n", 
               n, (long int)tim1[0]/1000, (long int)tim2[0]/1000, (long int)tim3[0]/1000); 
  
  //with sorted arrays
  
        start = clock(); 
        bubbleSort(a, n); 
        end = clock(); 
  
        tim1[1] = ((double)(end - start)); 
  
        start = clock(); 
        insertionSort(b, n); 
        end = clock(); 
  
        tim2[1] = ((double)(end - start)); 
  
        start = clock(); 
        selectionSort(c, n); 
        end = clock(); 
  
        tim3[1] = ((double)(end - start)); 
  
        printf(" With sorted array of size %li, time(in seconds)  for \nbubble sort: %li, \ninsertion sort: %li, \nselection sort: %li\n\n", 
               n, (long int)tim1[1]/1000, (long int)tim2[1]/1000, (long int)tim3[1]/1000);
               
    //with reversed sorted arrays
    reverse_sort(a,n);
    reverse_sort(b,n);
    reverse_sort(c,n);
    
  
        start = clock(); 
        bubbleSort(a, n); 
        end = clock(); 
  
        tim1[2] = ((double)(end - start)); 
  
        start = clock(); 
        insertionSort(b, n); 
        end = clock(); 
  
        tim2[2] = ((double)(end - start)); 
  
        start = clock(); 
        selectionSort(c, n); 
        end = clock(); 
  
        tim3[2] = ((double)(end - start)); 
  
        printf(" With reverse sorted array of size %li, time(in seconds) for \nbubble sort: %li, \ninsertion sort: %li, \nselection sort: %li\n\n", 
               n, (long int)tim1[2]/1000, (long int)tim2[2]/1000, (long int)tim3[2]/1000);
    
  
    return 0; 
}
