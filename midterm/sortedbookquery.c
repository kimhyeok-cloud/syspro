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

int cmp(const void *a, const void *b){
    Book *x = (Book*)a;
    Book *y = (Book*)b;
    return x->numofborrow - y->numofborrow;
}

int main(){
    FILE *fp = fopen("db.dat","rb");
    if(!fp){
        printf("no data\n");
        return 0;
    }
    int mode;
    scanf("%d",&mode);
    Book list[100];
    int n=0;
    while(fread(&list[n],sizeof(Book),1,fp)==1) n++;
    fclose(fp);

    qsort(list,n,sizeof(Book),cmp);

    printf(" id bookname author year numofborrow borrow\n");
    for(int i=0;i<n;i++){
        if(mode==0 || (mode==1 && list[i].borrow==0))
            printf("%2d %-12s %-8s %4d %6d %5s\n",
                list[i].id,list[i].name,list[i].author,list[i].year,
                list[i].numofborrow,list[i].borrow?"True":"False");
    }
    return 0;
}
