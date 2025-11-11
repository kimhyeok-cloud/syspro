#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define START_ID 1001001 

struct student {
    char name[24]; 
    int id;        
    int score;     
};

#endif 
