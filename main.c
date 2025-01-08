/*
questions to ask:
1.In the read data funciton do you use a pointer for the number of students because that value is not known yet? 
2.Why in getMAxAverageStudent you dont use a pointer? is it because by then the value for the number of students is known and passed from readData?
3.In the read data funciton why after you scan in the number of students you derefernce in the for loop?
4.In getMaxAverageStudent what does int i represent?
5.Can you help me set up c lion 
6.help turning in the assignment 
*/


#include <stdio.h>
#define MAXSIZE 500
#include "main.h"

int main() {

struct Student students[MAXSIZE]; //declaring a student array struct with a max size of 500

int n; //number of students
int i; //student id

readData(students,&n); //function to collect number of students and the details of each

struct Student maxStudent=getMaxAverageStudent(students,n); //set maxStudent to the find the maximum average and the student who has achived the maximum average

printf("\nMaximum Average is %.2f and the student is %d\n",maxStudent.average,maxStudent.student_ID); //print the maximum average and the student

return 0;

}

struct Student getMaxAverageStudent(struct Student *s, int n){ //struct function that takes in a pointer to the student array and the number of students

    int i; //variable to store highest average position?
    
    int maxIdx=0; //variable index cointaining the student with the highest average 

    float maxAvg=0; //highest average

    for(i=0;i<n;i++){ //for loop that iterates through the array to find the highest average 
        if(s[i].average > maxAvg){ //if student average at index 0 is greater than current max average 
            maxAvg=s[i].average; //the new average is set 
            maxIdx=i; //the students position with the highest average is stored

        }
    }
return s[maxIdx]; //return the index where the highest average is 

}

void readData(struct Student *students, int *c){ //function that takes in a pointer to the student array and a pointer to the number of students

    scanf("%d",c); //scan in the number of students

    for(int i=0; i<*c;i++){ // for loop that iterates through the number of students 
        
        scanf("%d",&students[i].student_ID); //for each student scan in their id
        
        scanf("%d %d %d",&students[i].g1,&students[i].g2,&students[i].g3); //scan in the 3 different grades for each student
        
        students[i].average=(students[i].g1+students[i].g2+students[i].g3)/3.0; //find the average of the grades for each student

        printf(" %d %d %d %d %2f\n", students[i].student_ID, students[i].g1, students[i].g2, students[i].g3 students[i].average) //print all information 

    }
}