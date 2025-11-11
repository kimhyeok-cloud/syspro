#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[64];
    char author[64];
    int year;
    int numofborrow;
    int borrow;
} Book;

int cmpYearDesc(const void *a, const void *b){
    Book *x = (Book*)a;
    Book *y = (Book*)b;
    return y->year - x->year;
}

int main(){
    FILE *fp = fopen("db.dat","rb");
    Book arr[100];
    int n=0;
    if(fp){
        while(fread(&arr[n],sizeof(Book),1,fp)==1) n++;
        fclose(fp);
    }
    Book b;
    if(scanf("%d",&b.id)!=1) return 0;
    scanf(" %63s",b.name);
    scanf(" %63s",b.author);
    scanf("%d",&b.year);
    scanf("%d",&b.numofborrow);
    scanf("%d",&b.borrow);
    arr[n++] = b;

    qsort(arr,n,sizeof(Book),cmpYearDesc);

    fp = fopen("db.dat","wb");
    for(int i=0;i<n;i++){
        fwrite(&arr[i],sizeof(Book),1,fp);
    }
    fclose(fp);
    return 0;
}




