#include<stdio.h>

int n;

struct Student{
    int marks;
    char name [20];
};

void quickSort(struct Student info[n], int l, int h){
    int down, up;
    struct Student temp;
    struct Student pivot = info[l];
    down = l+1;
    up = h;
    while (down<=up)
    {
        while(info[down].marks <= pivot.marks && down<=h)
            down++;
        while(info[up].marks > pivot.marks)
            up--;
        if(down<=up){
            temp = info[down];
            info[down] = info[up];
            info[up] = temp;
            down++; up--;
        }
    }
    info[l] = info[up];
    info[up] = pivot;
    if(up>(l+1))
        quickSort(info, l, up-1);
    if(down<h)
        quickSort(info, down, h);
    
}

int main(){

    printf("Enter the number of students:\n");
    scanf("%d", &n);

    struct Student details[n];
    
    for(int i=0; i<n; i++){
        printf("Enter the details of student %d\n", i+1);
        scanf("%d %s", &details[i].marks, &details[i].name);
    }

    quickSort(details, 0, n);

    printf("\nMarks\tName\tRoll No\t\n");

    for(int i=n-1; i>=0; i--)
        printf("\n%d\t %s\t %d\t\n", details[i].marks, details[i].name, n-i);

    return 0;
}