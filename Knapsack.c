#include<stdio.h>

int findMax(int n, float cp[20]){
    
    float max=0;
    int index;
    
    for(int i = 0; i < n; i++){
        
        if(max < cp[i]){
            max = cp[i];
            index = i;
        }
        
    }
    return index;
}

void calculate(int n, int m, float w[20], float p[20]){

float cp[20]={},totalCost = 0,scale;
int capacity = m, maxIndex;

    for(int i = 0; i < n; i++){
        cp[i] = p[i]/w[i];
    }
    
    for(int i = 0; i < n; i++){
         maxIndex = findMax(n, cp);

        if(m >= w[maxIndex]){
            totalCost += p[maxIndex];
            m -= w[maxIndex];
        }

        else{
            scale = m/w[maxIndex];
            totalCost += scale*p[maxIndex];
            m -= scale*w[maxIndex];
        }
        
        cp[maxIndex] = 0;
    }
    printf("The Maximum Total cost under capacity %d is %f",capacity,totalCost);
}

int main(){
    int n,m;
    float w[20]={},p[20]={};
    
    printf("Enter the total number of elements : ");
    scanf("%d",&n);

    printf("Enter the total capacity : ");
    scanf("%d",&m);

    for(int i = 0; i < n; i++){
    
    printf("Enter the weight for element %d : ",i+1);
    scanf("%f",&w[i]);

    printf("Enter the price for element %d : ",i+1);
    scanf("%f",&p[i]);

    }

    calculate(n,m,w,p);
    return 0;
}
