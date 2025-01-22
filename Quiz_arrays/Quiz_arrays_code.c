//The expected output of the following C program is to print the elements in the array. But when actually run, it doesn't do so.
  #include<stdio.h>

  #define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
  int array[] = {23,34,12,17,204,99,16};

  int main()
  {
      int d;

      for(d=-1;d <= (TOTAL_ELEMENTS-2);d++)
          printf("%d\n",array[d+1]);

      return 0;
  }
//Find out what's going wrong




/* Answer:
To debug the code first check line by line
1. sizeof array: sizeof is an operator which denotes the memory size of the data type given for the character
2. Eg: sizeof(array) - array is denoted in int . int data type memory size is 4 bytes
3. So according to this code macro defined here is TOTAL_ELEMENTS which has sizeof(array) is equal to 7 elements x 4 bytes = 28 bytes / sizeof(array[0]) which represents the size of 1st indices which is 4 bytes (i.e 28/4 = 7 elements)
4. Next to the main loop- In the for loop initializing the d=-1; d<= (7-2); d++(increments once) and then prints the array as d+1
5. here d starts with -1 and compares the number which is less than or equal to d<=5 and then increments the next step. This gives no output elements since -1.
6. we should make that to d=0 then it compares from 0th indices. 
7. Next step is d<= 7-2. here every number cannot be printed since -2 so upto 5th indices will be printed
8. So we should change that to -1 , then it stops the loop until 6th indices
9. Next is the print statement which has d+1, this leads to print the next element of the compared one in loop. So that +1 is not needed.

  #include<stdio.h>

  #define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
  int array[] = {23,34,12,17,204,99,16};

  int main()
  {
      int d;

      for(d=0;d <= (TOTAL_ELEMENTS-1);d++)
          printf("%d\n",array[d]);

      return 0;
  }

output:
23
34
12
17
204
99
16

*/
