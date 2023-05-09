#include<stdio.h>

int n;
struct student
{
    char name[20];
    int roll_no;
    int marks;
};

void traversal(struct student s[],int n){
    for (int i = 0; i < n; i++)
    {
       printf("%s\t %d\t %d",s[i].name,s[i].roll_no,s[i].marks);
       printf("\n");
    }
    
}

void bubblesort(struct student s[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (s[j].roll_no>s[j+1].roll_no)
            {
                struct student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
            
        }
        
    }
    
}

void insertionsort(struct student s[],int n){
    for (int i = 1; i < n; i++)
    {
        int key,j;
        key=s[i].roll_no;
        j=i-1;
      while (j>=0 && s[j].roll_no>key)
      {
        s[j+1].roll_no=s[j].roll_no;
        j--;
      }
      s[j+1].roll_no=key;
      
    }
    
}

void selectionsort(struct student s[],int n){
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min =i;
        for (int j = i+1; j < n; j++)
        {
            if (s[j].roll_no<s[min].roll_no)
            {
                min =j;
            }
            
        }
        struct student temp=s[i];
        s[i]=s[min];
        s[min]=temp;

    }
    
}

void mergesort(struct student s[],int low ,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    struct student b[n];
    
    while (i<=mid && j<=high)
    {
        if (s[i].roll_no<s[j].roll_no)
        {
            b[k]=s[i];
            i++;
            k++;
        }
        else{
            b[k]=s[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
       b[k]=s[i];
       i++;
       k++;
    }
    while (j<=high)
    {
        b[k]=s[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
       s[i]=b[i];
    }
    
    
}

void ms(struct student s[],int low,int high){
    int mid;
    if (low<mid)
    {
        mid = (low+high)/2;
        ms(s,low,mid);
        ms(s,mid+1,high);
        mergesort(s,low,mid,high);
    }
    
}

int partition(struct student s[],int low,int high){
    int pivot=s[low].roll_no;
    int i=low+1;
    int j=high;
    struct student temp;
    do
    {
        while (s[i].roll_no<=pivot)
        {
            i++;
        }
        while (s[j].roll_no>pivot)
        {
          j--;
        }
        if (i<j)
        {
             temp=s[i];
            s[i]=s[j];
            s[j]=s[i];
        }
        
    } while (i<j);
    temp =s[low];
    s[low]=s[j];
    s[j]=temp;
    return j;
}

void quicksort(struct student s[],int low,int high){
    int partitionindex;
    if (low<high)
    {
       partitionindex=partition(s,low,high);
       quicksort(s,low,partitionindex-1);
       quicksort(s,partitionindex+1,high);
    }
    
}

int main() 
{
printf("Enter the number of students\n");
scanf("%d",&n);
struct student s[n];
printf("enter the name,roll number , marks of the student\n");
for (int i = 0; i < n; i++)
{
    scanf("%s %d %d",&s[i].name,&s[i].roll_no,&s[i].marks);
}
// bubblesort(s,n);
// printf("\n");
// printf("after bubble sorting\n");
traversal(s,n);
printf("\n");
// insertionsort(s,n);
// printf("after insertion sorting\n");
// traversal(s,n);
// printf("\n");
// selectionsort(s,n);
// printf("after selection sort\n");
// traversal(s,n);
// printf("\n");
// ms(s,0,n-1);
// printf("after merge sorting\n");
// traversal(s,n);
quicksort(s,0,n-1);
printf("after quick sorting\n");
traversal(s,n);
return 0;
}