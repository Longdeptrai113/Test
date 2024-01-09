#include <stdio.h>
#include <malloc.h>

//de4 (sbd chẵn)

void nhapvain(int *arr,int n){
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    while(n>100){
        printf("gia tri vuot qua 100. Vui long nhap lai. ");
        scanf("%d", &n);
    }
    printf("nhap tung phan tu: ");
    for(int i=0;i<n;i++){
        printf("phan tu thu %d: \n", i+1);
        scanf("%d", &arr[i]);
    }
    printf("day so ban vua nhap la: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    int i,j;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nphan tu lon nhat trong day la: %d", arr[0]);
}

void demphantu(int *arr,int n){
    int dem = 0;
    for(int i = 0 ;i < n;i++){
       dem++;
    }
    printf("day so co %d phan tu. ", dem);
}

int main(){
    int n;
    int *arr;
    nhapvain(arr,n);
    demphantu(arr,n);
    return 0;
}
