#include<stdio.h>
    int n;
    

void swap(int heap[n], int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heap_up(int heap[n], int i){
int parent = (i - 1)/2;

    if(i > 0 && heap[i] > heap[parent]){
        swap(heap, parent, i);
        heap_up(heap,parent);
    }
}

void createHeap(int heap[n]){
    
    for(int i = 0; i < n; i++){
        printf("Enter the elements : ");
        scanf("%d",&heap[i]);
        heap_up(heap,i);    
    }
}

void display(int heap[20], int size){
    
    for(int i = 0; i < size; i++){
        printf("%d\t",heap[i]);    
    }

}

void heap_down(int heap[n],int i, int last){ //logic : find largest of left child(heap[left]), right child(heap[right]), and heap[i]. Then if heap[i] is not the largest then swap heap[i] with largest and heap down again.

    int left = 2*i+1;
    int right = 2*i+2;
    int largest;

    if(heap[left] >= heap[right] && heap[left] >= heap[i] && left <= last){
        largest = left;
    }
    else if(heap[right] >= heap[left] && heap[right] >= heap[i] && right <= last){
        largest = right;
    }
    else{
        largest = i;
    }

    if(largest != i){
        swap(heap, i, largest);
        heap_down(heap, largest, last);
    }
}

void delete(int heap[n]){
// int size = n;
while(n > 0){
    swap(heap,0,n-1);
    n--;
    heap_down(heap,0,n-1);

}
}

int main(){
    int heap[20];
    
    printf("Enter the number of elements in your heap : ");
    scanf("%d",&n);
    
    int size = n;
    
    createHeap(heap);
    printf("Max Heap : ");
    display(heap,n);
    
    delete(heap);
    
    printf("\nSorted Array : ");
    display(heap, size);
    
    return 0;
}
