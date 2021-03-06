
#include <stdio.h>

//function protorype
void Selection_Sort(int *, int );
void Print(int*, int);
void Bubble_Sort(int *,int );
void insertion_sort(int *, int );

int main()
{
    printf("please enter the size of your array: \n");
    int size=0;
    scanf("%d",&size);
    printf("Please enter the array elements: \n");
    int i;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    
    }
    // selection sort
    //printf("\nSelection sort: ");
    //Selection_Sort(arr, size);
    
    //printf("\n Buble sort: ");
    //Bubble_Sort(arr,size);
    
    printf("insertion sort\n");
    insertion_sort(arr,size);
    

    

    Print(arr,size);

    return 0;
}
void merge_sort(int* arr, int size)
{
    int * left, *right; // pointer to left aand right arrays
    int mid=0;// a variable to store middle number of arrays
    
    mid=size/2;
    
    left=(int*)malloc(mid*sizeof(int));// create left array 
    right=(int*) malloc((size-mid)*sizeof(int));// create right array
    
    int i=0;
    for(i = 0;i<mid;i++){ 
        left[i] = arr[i];
        
    } // creating left subarray
	for(i = mid;i<size;i++) {
	    right[i-mid] = arr[i];
	    
	} // creating right subarray

	merge_sort(left,mid);  // sorting the left subarray
	merge_sort(right,size-mid);  // sorting the right subarray
	merge(left,right,arr,mid,size-mid);  // Merging L and R into A as sorted list.
        free(left);
        free(right);
}

// a function to merge two arrays
void merge(int left[],int right[],int arr[], int leftcount, int rightcount)
{
    int i=0;// index for left array 
    int j=0;// iondex for right array
    int k=0;// index for original array
    
    while(i<leftcount && j<rightcount)
    {
        if(right[i]>left[j])
        {
            arr[k]=left[j];
            j++;
            k++;
        }else
        {
           arr[k]=right[i];
            i++;
            k++;
        }
    }
    
    // if one of the array run out of the elements ealier than the other
    while(i<leftcount)
    {
        arr[k]=right[i];
        i++;
        k++;
    }
    while(j<rightcount)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}


// insertion sort 
void insertion_sort(int arr[], int size)
{
    int i,j,temp;
    
    for (i=1;i<size;i++)
    {
        temp=arr[i];
        for(j=i;j>0 && temp<arr[j-1];j--)// j has to be bugger than 0 because of the next linewhere j-1 has to be atleat 0
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}

// a function to print arrays elements
void Print(int *arr, int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf(" %d",*(arr+i));
    }
    printf("\n");
} 

//buble sort algorithm
void Bubble_Sort(int *arr,int size)
{
    int i=0,j=0;
    int temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)// the array of size n, needs n-1 move to shift the arr[0] to arr[n-1];
        {
            if (arr[j]>arr[j+1])
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+(j+1));
                *(arr+(j+1))=temp;
            }
        }
    }
}

//seclection sort algorithm
void Selection_Sort(int arr[], int size)
{
    int i=0;
    int min=0;
    int j;
    int temp;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for (j = i+1; j < size; j++){ 
            if (arr[j] < arr[min]){ 
                min = j;
            }
            
        }
        int temp = *(arr+min); 
        *(arr+min) = *(arr+i); 
        *(arr+i) = temp;
    }
}

