#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pt_utils.h"
#include "pt_sorting.h"

#include "pt_sorting.h"
#include "pt_gen_timings.h"

//Make 2 arrays: 1 for pointers and 1 for names
void (* funcs[])(int[], int) = {selection_sort, insertion_sort
            , merge_sort, heap_sort, quick_sort_hoare
            , quick_sort_median, quick_sort_random};
char * f_names[] = {"selection_sort", "insertion_sort"
            , "merge_sort", "heap_sort", "quick_sort_hoare"
            , "quick_sort_median", "quick_sort_random"};

int time_exec(int a[], int length, void (* func)(int[], int)){

    // start the timer
    clock_t start_c = clock();

    func(a, length);

    // stop the timer
    clock_t end_c = clock();

    return (end_c-start_c)/1000.0;

}

int main(int argc, char * argv[]) {

    if (argc == 1){
        printf("No array sizes specified\n");
    } else {
        //Get all the array sizes possible
        for (int i = 1; i < argc; i += 1)
        {
            int size = atoi(argv[i]);
            //Create an array of according size
            int * array = gen_rand_int_array(size, 10);            

            //Run the test throughout all the functions
            for (int j = 0; j < 7; j += 1)
            {
                //For each test, do it 3 times to get better timings
                //(don't ask me why, just read the assigment!)
                int totalTime = 0;
                for (int k = 0; k < 3; k += 1)
                {
                    int * testArray = clone_int_array(array, size);                    

                    totalTime += time_exec(testArray, size, funcs[j]);

                    free(testArray);
                }

                //Print out the result of each test
                printf("%s,%i,%i\n", f_names[j], size, totalTime / 3);                             
            }

            free(array);
        }
    } 

}
