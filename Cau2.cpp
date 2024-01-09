#include <stdio.h>
#include <string.h>
#define MAX 100

//de 4 (sbd chẵn)

typedef struct diennang{
    char macanho[5];
    char tenchuho[MAX];
    int sothanhvien;
    unsigned long long sodien;
}DN;
void xoaxuongdong( char *xau){
    int len = strlen(xau);
    if(xau[len-1]=='\n') xau[len -1] == '\0';
}
void nhapthongtin(DN *diennang, int n){
    fflush(stdin);
    printf("nhap thong tin can ho: \n ");
    for(int i=0;i<n;i++){
        printf("nhap ma can ho: ");
        scanf("%s", diennang[i].macanho);
        while(strlen(diennang[i].macanho) < 4){
            printf("ma can ho khong hop le. Vui long nhap lai. ");
            scanf("%s", diennang[i].macanho);
        }
        fflush(stdin);
        printf("nhap ten chu ho: ");
        fgets(diennang[i].tenchuho, sizeof(diennang[i].tenchuho), stdin); xoaxuongdong(diennang[i].tenchuho);

        printf("nhap so thanh vien: ");
        scanf("%d", &diennang[i].sothanhvien);
        fflush(stdin);
        printf("nhap so dien: ");
        scanf("llu", &diennang[i].sodien);
        fflush(stdin);
        while(diennang[i].sodien < 0){
            printf("so dien nhap khong phu hop. vui long nhap lai: ");
            scanf("%llu", &diennang[i].sodien);
            fflush(stdin);
        }
    }
    fflush(stdin);
}
void inmacanho(DN *diennang, int n){
    int i,j;
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(diennang[j].sodien < diennang[j+1].sodien){
                DN temp = diennang[j];
                diennang[j] = diennang[j+1];
                diennang[j+1] = temp;
            }
        }
    }
    printf("Ma can ho cua ho gia dinh su dung so dien cao nhat la: %s ", diennang[0].macanho);
}
void inthongtin(DN *diennang,int n){
    printf("+-----+------+-----------------+-----------------+----------+\n");
    printf("| STT | MaCH | Ten chu ho      | So Thanh Vien   | So dien  |\n");
    printf("+-----+------+-----------------+-----------------+----------+\n");
    for(int i=0; i<n;i++){
        printf("|%-5d|%-5s|%-8s|%-8d|%-8llu|",i+1,diennang[i].macanho,diennang[i].tenchuho,diennang[i].sothanhvien,diennang[i].sodien);
        printf("+-----+------+-----------------+-----------------+----------+\n");
    }
}

int main(){
    int n;
    printf("nhap so can ho can tinh dien nang: ");
    scanf("%d", &n);
    DN danhsachcanho[n];
    nhapthongtin(danhsachcanho,n);
    inthongtin(danhsachcanho,n);
    inmacanho(danhsachcanho,n);
    return 0;
}
