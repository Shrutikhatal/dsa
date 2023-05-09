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

int main(){
    int i, n, swap_count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for(i=0; i<n; i++){
        printf("\nEnter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%d", &students[i].total_marks);
    }
    bubbleSort(students, n);
    printf("\n\nSorted Array based on Roll Number:\n");
    for(i=0; i<n; i++){
        printf("Name: %s, Roll Number: %d, Total Marks: %d\n", 
               students[i].student_name, students[i].student_roll_no, 
               students[i].total_marks);
    }
    printf("\n\nTotal number of swaps performed: %d\n", s);
    return 0;
}
