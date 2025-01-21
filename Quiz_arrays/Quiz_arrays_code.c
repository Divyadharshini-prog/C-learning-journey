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
3. So according to this code macro defined here is TOTAL_ELEMENTS which has sizeof(array) 



*/
