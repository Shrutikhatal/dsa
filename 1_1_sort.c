#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int s;
struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

int bubbleSort(struct Student arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j].student_roll_no > arr[j+1].student_roll_no){
                // swap arr[j] and arr[j+1]
                struct Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                s++;
            }
        }
    }
    return s;
}
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
int main(){
    int i, n, swap_count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student arr[n];
    for(i=0; i<n; i++){
        printf("\nEnter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &arr[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%d", &arr[i].total_marks);
    }
    bubbleSort(arr, n);
    //  quicksort(arr,0,n-1,&swap_count);
    printf("\n\nSorted Array based on Roll Number:\n");
    for(i=0; i<n; i++){
        printf("Name: %s, Roll Number: %d, Total Marks: %d\n", 
               arr[i].student_name, arr[i].student_roll_no, 
               arr[i].total_marks);
    }
    printf("\n\nTotal number of swaps performed: %d\n", s);
    return 0;
}
