#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pt_utils.h"
#include "pt_sorting.h"


int main(int argc, char * argv[]) {

    //Only perform the operation if we have enough args  
    if (argc == 4 || argc == 5){    
        int sort_function_number = atoi(argv[1]);
        int length = atoi(argv[2]);
        int nbits = atoi(argv[3]);

        //If there is an argument to specify the seed
        if(argc == 5){
            // set the PRNG seed
            int seed = atoi(argv[4]);
            srand(seed);
        } else {
            srand(time(NULL));
        }

        //Generate an array
        int * arrayNums = gen_rand_int_array(length, nbits);

        //Print out the info of the array
        printf("\nRandom array of length %i and nbits %i\n\n", length, nbits);
        printf("Before sorting: ");
        print_int_array(arrayNums, length);
        printf("\n");   

        switch(sort_function_number){
            case 1: //Denis
                printf("-------Apply selection sort-------\n\n");
                selection_sort(arrayNums, length);
                break;
            case 2: //Thinh 
                printf("-------Apply insertion sort-------\n\n");
                insertion_sort(arrayNums, length);
                break;
            case 3: //Luan
                printf("-------Apply merge sort-------\n\n");
                merge_sort(arrayNums, length);
                break;
            case 4: //Luan
                printf("-------Apply heap sort-------\n\n");
                heap_sort(arrayNums, length);
                break;
            case 5: //Thinh
                printf("-------Apply quick sort (hoare)-------\n\n");
                quick_sort_hoare(arrayNums, length);
                break;
            case 6: //Hung
                printf("-------Apply quick sort (median)-------\n\n");
                quick_sort_median(arrayNums, length);
                break;
            case 7: //Hung
                printf("-------Apply quick sort (random)-------\n\n");
                quick_sort_random(arrayNums, length);
                break;
            default:
                printf("There is no function with that number.\n\n");
        }
        
        //Print out the array after sorting
        printf("After sorting: ");
        print_int_array(arrayNums, length);  
        printf("\n");
    } else { //If we receive the wrong argc, show the manual
        printf("Wrong number of argument. Please retry.\n");
        printf("Program's recommended arguments:\n");
        printf("./test_pt_sorting sort_function_number length nbits seed\n");
        printf("\t---sort_function_number: The number of the function to be executed");
        printf(", such as: 1(selection_sort), 2(insertion_sort)");
        printf(", 3(merge_sort), 4(heap_sort), 5(quick_sort_hoare)");
        printf(", 6(quick_sort_median), 7(quick_sort_random).\n");
        printf("\t---length: The length of the array to be sorted.\n");
        printf("\t---nbits: Values in the array will be randomed from 0 to 2^nbits-1\n");
        printf("\t---seed(optional): the seed to use for the random number generator. ");
        printf("If missing, the current time will be used as a seed.\n");
    }
}
