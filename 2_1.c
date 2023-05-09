// Binary Search has been implemented considering the key as Student ID

#include<stdio.h>

int n;

struct Student{
    int id;
    int marks;
    char name[20];
};

int iterativeBinarySearch(struct Student info[n], int s, int e, int find){
    while(s<=e){
        int mid = (s + e) / 2;

        if(info[mid].id == find)
            return mid;
        else{
            if(info[mid].id < find)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return (-1);
}

int recursiveBinarySearch(struct Student info[n], int s, int e, int find){
    if(s<=e){
        int mid = (s + e) / 2;

        if(info[mid].id == find)
            return mid;
        else{
            if(info[mid].id < find)
                recursiveBinarySearch(info, mid+1, e, find);
            else
                recursiveBinarySearch(info, s, mid-1, find);
        }
    }
    else{
        return (-1);
    }
}

int main(){

    printf("Enter the number of students:\n");
    scanf("%d", &n);

    struct Student list[n];

    for(int i=0; i<n; i++){
        printf("Enter the details of student %d\n", i+1);
        scanf("%d %d %s", &list[i].id, &list[i].marks, &list[i].name);
    }

    int find;
    
    printf("Enter the ID of student whose record is to be found:\n");
    scanf("%d", &find);

    // Result without using Recursion
    int result1 = iterativeBinarySearch(list, 0, n, find);
    
    if(result1 != (-1))
        printf("\n%d\t %d\t %s\t\n", list[result1].id, list[result1].marks, list[result1].name);
    else
        printf("Record not found!");

    // Result using Recursion
    int result2 = recursiveBinarySearch(list, 0, n, find);
    
    if(result2 != (-1))
        printf("\n%d\t %d\t %s\t\n", list[result2].id, list[result2].marks, list[result2].name);
    else
        printf("Record not found!");

    return 0;
}