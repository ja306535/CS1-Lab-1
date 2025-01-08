#include <stdio.h>
#define MAXSIZE 500
#include "main.h"

int main () {

struct Student students[MAXSIZE]; //declaring a student array struct 

int n; //number of students
int i; //student id

readData(students,&n); //function to collect number of students and the details of each

struct Student maxStudent=getMaxAverageStudent(students,n); //set maxStudent to the find the maximum average and the student who has achived the maximum average

printf("\nMaximum Average is %.2f and the student is %d\n",maxStudent.average,maxStudent.student_ID); //print the maximum average and the student

return 0;

}

struct Student getMaxAverageStudent(struct Student *s, int n){

    int i;
    int maxIdx=0; //index cointaining the student with the highest average 

    float maxAvg=0; //highest average

    for(i=0;i<n;i++){
        if(s[i].average > maxAvg){
            maxAvg=s[i].average;
            maxIdx=i;

        }
    }
return s[maxIdx];

}

void readData(struct Student *students, int *c){

    scanf("%d",c);

    for(int i=0; i<*c;i++){
        scanf("%d",&students[i].student_ID);
        
        scanf("%d %d %d",&students[i].g1,&students[i].g2,&students[i].g3);
        
        students[i].average=(students[i].g1+students[i].g2+students[i].g3)/3.0;

        printf(" %d %d %d %d %2f\n", students[i].student_ID, students[i].g1, students[i].g2, students[i].g3 students[i].average)

    }
}