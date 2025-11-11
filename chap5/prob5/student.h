#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define MAX 24
#define START_ID 1001001

struct student {
   char name[MAX];
   int id;
   int score;
};

#endif 

