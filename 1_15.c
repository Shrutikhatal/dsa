#include<stdio.h>

int n;

struct Employee{
    int height, weight;
    float avg;
    char name[20];
};

void quickSort(struct Employee info[n], int l, int h){
    int down, up;
    struct Employee temp;
    struct Employee pivot = info[l];
    down = l+1;
    up = h;
    while (down<=up)
    {
        while(info[down].avg < pivot.avg && down<=h)
            down++;
        while(info[up].avg > pivot.avg)
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

    printf("Enter the number of employees:\n");
    scanf("%d", &n);
    
    struct Employee list[n];

    for(int i=0; i<n; i++){
        printf("Enter the height and weight of Employee %d\n", i+1);
        scanf("%d %d %s", &list[i].height, &list[i].weight, &list[i].name);
        list[i].avg = (list[i].height + list[i].weight) / 2;
    }

    quickSort(list, 0, n);

    for(int i=0; i<n; i++){
        printf("\n%d\t %d\t %s\t %f\t\n", list[i].height, list[i].weight, list[i].name, list[i].avg);
    }

    return 0;
}