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

int main(){
    FILE *fp = fopen("db.dat","rb");
    if(!fp){
        printf("no data\n");
        return 0;
    }
    char target[64];
    printf("input name of book) ");
    scanf(" %63s", target);
    Book b;
    int found=0;
    while(fread(&b,sizeof(Book),1,fp)==1){
        if(strcmp(b.name,target)==0){
            found=1;
            printf(" id bookname author year numofborrow borrow\n");
            printf("%2d %-12s %-8s %4d %6d %5s\n",
                b.id,b.name,b.author,b.year,b.numofborrow,b.borrow?"True":"False");
            break;
        }
    }
    if(!found){
        printf("not found book name : '%s'\n", target);
    }
    fclose(fp);
    return 0;
}
