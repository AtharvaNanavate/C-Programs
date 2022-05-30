#include<stdio.h>

int min,max;

void findMinMax(int arr[20],int i,int j){

    int mid,max1,min1;
    
    if(i == j){
        min = max = arr[i];
    }

    else if(i == j-1){
        if(arr[i] > arr[j]){
            max = arr[i];
            min = arr[j];
        }
        else{
            max = arr[j];
            min = arr[i];
        }
    }

    else{
        mid = (i+j)/2;
        findMinMax(arr,0,mid);

        max1 = max; min1 = min;
        findMinMax(arr,mid+1,j);

        if(max1 > max){
            max = max1;
        }

        if(min1 < min){
            min = min1;
        }
    }
}
int main(){

    int n,arr[20];

    printf("Enter the total number of elements in your array : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }

    max = arr[0];
    min = arr[0];

    findMinMax(arr,0,n-1);

    printf("The Minimum element is %d.\n",min);
    printf("The Maximum element is %d.\n",max);

    return 0;
}
