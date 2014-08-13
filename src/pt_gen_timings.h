/** Return the execution time in milisecond
  * @param a the int array to be sorted in place
  * @param length the length of array a
  * @param func the pointer to the sorting function
  */
int time_exec(int a[], int length, void (* func)(int[], int));
