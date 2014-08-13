#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pt_utils.h"
#include "pt_sorting.h"

#include <string.h>

//Make 2 arrays: 1 for pointers and 1 for names
void (* funcs[])(int[], int) = {selection_sort, insertion_sort
            , merge_sort, heap_sort, quick_sort_hoare
            , quick_sort_median, quick_sort_random};
char * f_names[] = {"selection_sort", "insertion_sort"
            , "merge_sort", "heap_sort", "quick_sort_hoare"
            , "quick_sort_median", "quick_sort_random"};

int find_func_num(char * func_name){

   for (int i = 0; i < 7; i += 1)
   {
       if (strcmp(func_name, f_names[i]) == 0){
           return i; 
       }
   }

    return -1; 

}

int main(int argc, char * argv[]) {

    //Only perform the operation if we have enough args  
    if (argc == 4 || argc ==5){         
        char * sort_function_name = argv[1];
        int sort_function_number = find_func_num(sort_function_name);
        int length = atoi(argv[2]);
        int nbits = atoi(argv[3]);  

        //If there is an argument to specify the seed
        if(argc == 5){
            // set the PRNG seed
            int seed = atoi(argv[4]);
            srand(seed);
        }

        //Generate an array
        int * arrayNums = gen_rand_int_array(length, nbits);

        //Print out the info of the array
        printf("\nRandom array of length %i and nbits %i\n\n", length, nbits);
        printf("Before sorting: ");
        print_int_array(arrayNums, length);
        printf("\n");           
        
        switch(sort_function_number){
            case 0: //Denis
                printf("-------Apply selection sort-------\n\n");            
                break;
            case 1: //Thinh 
                printf("-------Apply insertion sort-------\n\n");
                break;
            case 2: //Luan
                printf("-------Apply merge sort-------\n\n");
                break;
            case 3: //Luan
                printf("-------Apply heap sort-------\n\n");
                break;
            case 4: //Thinh
                printf("-------Apply quick sort (hoare)-------\n\n");
                break;
            case 5: //Hung
                printf("-------Apply quick sort (median)-------\n\n");
                break;
            case 6: //Hung
                printf("-------Apply quick sort (random)-------\n\n");            
                break;
            default:
                printf("There is no function with that number.\n");
                break;
        }

        if (sort_function_number != -1)
        {
            //Run the selected function
            funcs[sort_function_number](arrayNums, length);
        } else {
            printf("Nothing is sorted\n\n");    
        }  
        
        //Print out the array after sorting
        printf("After sorting: ");
        print_int_array(arrayNums, length);  
        printf("\n");
    } else { //If we receive the wrong argc, show the manual
        printf("Wrong number of argument. Please retry.\n");
        printf("Program's recommended arguments:\n");
        printf("./test2_pt_sorting sort_function_name length nbits seed\n");
        printf("\t---sort_function_name: The name of the function to be executed");
        printf(", such as: selection_sort, insertion_sort");
        printf(", merge_sort, heap_sort, quick_sort_hoare");
        printf(", quick_sort_median, quick_sort_random.\n");
        printf("\t---length: The length of the array to be sorted.\n");
        printf("\t---nbits: Values in the array will be randomed from 0 to 2^nbits-1\n");
        printf("\t---seed(optional): the seed to use for the random number generator. ");
        printf("If missing, the current time will be used as a seed.\n");
    }
}
