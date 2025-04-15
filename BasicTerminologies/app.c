#include <stdio.h>
#include <string.h>

int main(){
    //Question 1,explaining arrays,structure and pointers
//1.An array is a collection of similar data types.
//Below is an example of an array of integers.
    printf("---------Program showing the usage of an array---------\n");
    int array[5] = {1,2,3,4,5};
    printf("The array is: %d\n",array[0]);
    printf("The array is: %d\n",array[1]);
    printf("The array is: %d\n",array[2]);

//2.A structure is a user defined data type that can be used to group items of different types.
//Below is an example of a structure.
   printf("---------Program showing the usage of a structure---------\n");
    struct student{
        char name[50];
        int age;
        float gpa;
    };
    struct student student1;
    strcpy(student1.name, "John");
    student1.age = 18;
    student1.gpa = 3.5;
    printf("The student's name is %s\n",student1.name);
    printf("The student's age is %d\n",student1.age);
    printf("The student's gpa is %f\n",student1.gpa);

//3.A pointer is a variable that stores the memory address of another variable.
//Below is an example of a pointer.
    printf("--------Program showing the working of a pointer---------\n");
    int age = 10;
    int *pAge = &age;
    printf("The value of age is %d\n",age);
    printf("The value of pAge is %d\n",*pAge);
    printf("The address of age is %p\n",&age);
    printf("The address of pAge is %p\n",pAge);
   
    //Question 2,using do while and for next loops 
    int i = 3;
    //tabulated interface increasing in values of 4 with the square on left side using do while loop
    printf("--------Do while loop to show the square of a number in incremented values of 4---------\n");
    do{
        int j = i*i;
        printf("%d\t%d\n",i,j);
        i+=4;
    }
    while(i<=19);

    //tabulated interface increasing in values of 4 with the square on right side using for loop
   printf("--------For loop to show the square of a number in incremented values of 4---------\n");
   for(int i = 3; i<=19; i+=4){
    int j = i*i;
    printf("%d\t%d\n",i,j);
    };

    //using for loop to display an asterisk triangle 
    printf("--------For loop to show an asterisk triangle---------\n");
  for (int intitialAsterisk = 1; intitialAsterisk<=6; intitialAsterisk++){
    for(int asterisk = 1; asterisk<=intitialAsterisk; asterisk++){
        printf("*");
    }
    printf("\n");
  }

    //using do while loop to display an asterisk triangle 
    printf("--------Do while loop to show an asterisk triangle---------\n");
       int initialAsterisks = 1;
       do {
        int asterisks = 1;
    do {
        printf("*");
        asterisks++;
    } while (asterisks<=initialAsterisks);
    
    printf("\n");
    initialAsterisks++;
} while (initialAsterisks<= 6);

    //A program displaying 20 lines of text using for loop
    printf("---------A program displaying 20 lines of text using for loop-----------\n");
    for(int lines = 0; lines<20; lines++){
        printf("%d.Arsenal is the best English team\n",lines);
    }

    ///A program displaying 20 lines of text using do while loop
    printf("---------A program displaying 20 lines of text using do while loop-----------\n");
    int lines = 0;
    do{
        printf("%d.Arsenal is the best English team\n",lines);
        lines++;
    }
        while(lines<20);


    return 0;
}