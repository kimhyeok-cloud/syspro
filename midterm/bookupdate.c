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
    FILE *fp = fopen("db.dat","rb+");
    if(!fp){
        printf("No data file\n");
        return 0;
    }
    int action, bookId;
    if(scanf("%d %d",&action,&bookId)!=2){ fclose(fp); return 0; }
    Book b;
    int found=0;
    long idx=0;
    while(fread(&b,sizeof(Book),1,fp)==1){
        if(b.id==bookId){
            found=1;
            break;
        }
        idx++;
    }
    if(!found){
        printf("Book not found\n");
        fclose(fp);
        return 0;
    }
    if(action==0){
        if(b.borrow==1){
            printf("You cannot borrow below book since it has been booked.\n");
        } else {
            b.numofborrow += 1;
            b.borrow = 1;
            fseek(fp, idx * sizeof(Book), SEEK_SET);
            fwrite(&b,sizeof(Book),1,fp);
            printf("You've got bellow book..\n");
            printf(" id bookname author year numofborrow borrow\n");
            printf("%2d %-12s %-8s %4d %6d %5s\n", b.id, b.name, b.author, b.year, b.numofborrow, b.borrow ? "True" : "False");
        }
    } else if(action==1){
        if(b.borrow==0){
            printf("Book is not borrowed\n");
        } else {
            b.borrow = 0;
            fseek(fp, idx * sizeof(Book), SEEK_SET);
            fwrite(&b,sizeof(Book),1,fp);
            printf("You've returned bellow book..\n");
            printf(" id bookname author year numofborrow borrow\n");
            printf("%2d %-12s %-8s %4d %6d %5s\n", b.id, b.name, b.author, b.year, b.numofborrow, b.borrow ? "True" : "False");
        }
    }
    fclose(fp);
    return 0;
}

