#include "pt_sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int a[], int length) {
    int min_pos, tmp;
    
    /* find the min value in a[i] to a[length-1], and swap it with a[i] */
    for (int i = 0; i < length; i++) {
        min_pos = i;
        /* find the minimum value in what is left of the array */
        for (int j = i+1; j < length; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        tmp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = tmp;
    }
    
}

//Nguyen Phuc Thinh - s3372765
void insertion_sort(int a[], int length) {

    for (int i = 1; i < length; i += 1)
    {
        int insPos = i;
        int insVal = a[i];

        while (insVal < a[insPos -1] && insPos > 0){
            a[insPos] = a[insPos - 1];
            insPos--;
        }

        a[insPos] = insVal;
    }

}

//Trinh Luan - s3372775

//////////////////////////////MERGE SORT///////////////////////////////////////
    
    void merge(register int a[], register int start, register int mid, register int end){
        //declare 2 array: left store first half and right store second half       
        int left[mid + 1 - start];
        int right[end - mid];
        register int i = 0;
        register int j = 0;

        //left array take first half elements
        for (register int i = 0; i < sizeof(left)/sizeof(*left); i += 1)
        {
            left[i] = a[start+i];
        }
        
        //right array take second half elements
        for (register int j = 0; j < sizeof(right)/sizeof(*right); j += 1)
        {
            right[j] = a[mid+1+j];
        }
        
        //loop from start to end
        while(start <= end)
        {           
            //check the index on right sub-array
            if(j < sizeof(right)/sizeof(*right))
            {
                //loop through all elements then take smaller elements from
                //the left array compare to right array and store in array a
                while(left[i] <= right[j] && i < sizeof(left)/sizeof(*left))
                {                        
                    a[start] = left[i];
                    i++;
                    start++;
                        //if the index on left sub-array greater than left array's length'
                        //then array a will store elements from right array
                        if (i >= sizeof(left)/sizeof(*left)) 
                        {                                    
                            for (;j < sizeof(right)/sizeof(*right); j += 1)
                            {
                                a[start] = right[j];
                                start++;
                            }
                        }
                }
            }
            
            //check the index on left sub-array
            if(i < sizeof(left)/sizeof(*left))
            {
                //loop through all elements then take smaller elements from
                //the right array compare to left array and store in array a
                while(right[j] <= left[i] && j < sizeof(right)/sizeof(*right))
                {
                    a[start] = right[j];
                    j++;
                    start++;
                        //if the index on right sub-array greater than right array's length
                        //then array a will store elements from left array
                        if (j >= sizeof(right)/sizeof(*right)) 
                        {                          
                            for (; i < sizeof(left)/sizeof(*left) ; i += 1)
                            {
                                a[start] = left[i];
                                start++;
                            }
                        }
                }

            }       
            
        }
    }

    void merge_sort_recursive(register int a[], register int start, register int end)
    {   
        //check the length of array must greater than 0
        if(end - start >= 1)
        {
            merge_sort_recursive(a,start, start + (end - start) / 2);
            merge_sort_recursive(a,(start + (end - start) / 2) + 1, end);     
            merge(a,start, start + (end - start) / 2, end);
        }     
    }   

    void merge_sort(register int a[], register int length)
    {
        merge_sort_recursive(a, 0 ,length - 1); 
    }


//////////////////////////////////HEAP SORT///////////////////////////////////

    void swap(register int a[], register int i, register int j) {
        register int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    void build(register int a[],register int i,register int length) {
        register int max;
        register int left = 2 * i;
        register int right = 2 * i + 1;
        //find the max of the left side
        if (left <= length && a[left] > a[i]) {
            max = left;
        } else {
            max = i;
        }
        //find the max on right side
        if (right <= length && a[right] > a[max]) {
            max = right;
        }
        //swap if max is not equal to default i
        //then build again by replace i = max
        //until max == i
        if (max != i) {
            swap(a, i, max);
            build(a, max, length);
        }
    }     

    void heap_sort(register int a[], register int length)
    {            
        register int n = length - 1;
        for (register int i = n / 2; i >= 0; i--) {
            build(a, i, n);
        }
        for (register int i = n; i > 0; i--) {
            swap(a, 0, n);
            n--;
            build(a, 0, n);
        } 
    }
    
//Cao Phi Hung - s3372748

void quicksort(int list[],int start, int end,int type){
        if (start < end) {
       
        int pivot = 0;
        // median
        if (type == 1)
        {
             pivot = (start + end) / 2;
        // random        
        }else if (type == 2)
        {
            pivot = (rand() % (end + 1 -start)) + start;
        
         // hoare        
        }else if (type == 3)
        {
            pivot = start;
        }             
        
         if (list[start] > list[end]) {
            int temp = list[start];
                list[start] =list[end];
                list[end]= temp;
     
        } else if (list[start] > list[pivot]) {
            int temp2 = list[start];
                list[start]=list[pivot];
                list[pivot]= temp2;
        } else if (list[end] < list[pivot]) {
            int temp3 = list[end];
                 list[end] = list[pivot];
                 list[pivot]= temp3;
      
        }
        
        // This part will find the patition
        int x = list[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (list[j] < x) {
                i++;
                if (list[i] != list[j]) {
                   int temp5 = list[i];
                    list[i]=list[j];
                    list[j]=temp5;
                }
            }
        }
        
        if (list[i + 1] != list[end]) {
            int temp4 = list[i+1];
                list[i+1]= list[end];
                list[end] = temp4;
        }
          int patition = i+1;      

            //this part will run the recusive function            
            quicksort(list, start, patition - 1,type);
            quicksort(list, patition + 1, end,type);
        }
}

void quick_sort_median(int list[], int length){
        int end = length -1;
        int type = 1;
        quicksort(list,0,end,type);
}

void quick_sort_random(int list[], int length){
        int end = length -1;
        int type = 2;
        quicksort(list,0,end,type);
}

void quick_sort_hoare(int list[], int length){
        int end = length -1;
        int type = 3;
        quicksort(list,0,end,type);
}

