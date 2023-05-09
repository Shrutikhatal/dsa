#include<stdio.h>
#include<string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

void insertion_sort(struct Student arr[], int n, int *swap_count) {
    int i, j;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*swap_count)++;
        }
        arr[j + 1] = key;
    }
}

// selection sort
void selection_sort(struct Student arr[], int n, int *swap_count) {
    int i, j, min_index;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].student_roll_no < arr[min_index].student_roll_no) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*swap_count)++;
        }
    }
}

// merge sort 
void merge(struct  Student arr[], int left,int right, int mid, int *swap_count){
    int i, j,k;
    struct Student temp[right-left+1];
    i=left;
    j=mid+1;
    k=0;
    while(i<=mid && j<=right){
        if(arr[i].student_roll_no<=arr[j].student_roll_no){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
            (*swap_count)++;
        }
        k++;
    }
    if(i>mid){
        while(j<=right){
            temp[k]=arr[j];
            j++;
            k++;

        }
    }else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;

        }
        for(k=left;k<=right;k++){
            arr[k]=temp[k];
        }
    }
    
}
void merge_sort(struct Student arr[], int left , int right, int *swap_count){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid, swap_count);
        merge_sort(arr, mid+1, right, swap_count);
        merge(arr, left , mid, right, swap_count);
    }
}

// quick sort
int partition(struct Student arr[],int low, int high, int *swap_count){
    int pivote=arr[low].student_roll_no;
    int start=low;
    int  end=high;
    while(start<end){
        while(arr[start].student_roll_no<=pivote){
            start++;
        }
        while(arr[end].student_roll_no>pivote){
            end--;
        }
        if(start>end){
            int temp=arr[start].student_roll_no;
            arr[start].student_roll_no=arr[end].student_roll_no;
            arr[end].student_roll_no=temp;

        }


    }
    int temp=arr[low].student_roll_no;
            arr[low].student_roll_no=arr[end].student_roll_no;
            arr[end].student_roll_no=temp;

    return end;
}

void quicksort(struct Student arr[], int low , int high , int * swap_count){
    if(low>high){
        int loc=partition(arr, low, high, swap_count);
        quicksort(arr, low, loc-1,swap_count);
        quicksort(arr, loc+1, high, swap_count);
    }
}
int main() {
    int i, n, swap_count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter the details of student %d: \n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].student_name);
        printf("Roll no: ");
        scanf("%d", &arr[i].student_roll_no);
        printf("Total marks: ");
        scanf("%f", &arr[i].total_marks);
    }
    quicksort(arr,0,n-1,&swap_count);
   // insertion_sort(arr, n, &swap_count);
   //selection_sort(arr,n,&swap_count);
   // merge_sort(arr, 0, n-1, &swap_count);
    printf("\nSorted list of students:\n");
    printf("Roll no \t Name \t\t Total Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %s \t\t %.2f\n", arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
    printf("\nNumber of swaps performed: %d\n", swap_count);
    return 0;
}
