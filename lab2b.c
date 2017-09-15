#include <stdio.h>
#include <stdlib.h>

int* search(int* begin, int* end, int needle);

int main(int argc, char **argv){
    int num;
    int nums[10], i;
    int *found = NULL;
    if(argc != 2){
        printf("Usage: search <number>\n");
        return 1;
    }
    num = atoi(argv[1]);
    for(i = 0; i < 10; i++){
        nums[i] = 1 << i;
        //printf("nums[%d] = %d\n", i, nums[i]);
    }
    found = search(nums, &nums[9], num);
    if(found)
        printf("Number %d found in index %d.\n", num, found - nums);
    else
        printf("Number %d was not found.\n", num);

    return 0;
}

int* search(int* begin, int* end, int needle){
    if(end<begin)
        return NULL;
    //printf("The addresses are: begin: %p, end %p\n", begin, end);
    int sizeOfTheArray = (end - begin);
    //printf("The size of the array is: %d\n", sizeOfTheArray);

    //get the mid
    int *mid = NULL;
    if(sizeOfTheArray%2 == 1)
        mid = begin + (sizeOfTheArray/2 + 1);// give the value in array
    else
        mid = begin + (sizeOfTheArray/2);
    //printf("The value mid is: %d %d\n", *mid, mid - begin);
    //start the search...
    if(needle > *mid){
        return search(mid+1, end, needle);
    }
    else if(needle < *mid){
        return search(begin, mid-1, needle);
    }
    else if(needle == *mid)
        return mid;
    return NULL;
}
