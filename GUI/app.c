#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int regNo;
    char name[50];
    char school[100];
    char department[100];
    char course[50];
    int year;
    int semester;
    int marks[8];
    int total;
    float average;
    int high;
    int low;
    char grade[3];
};

void DisplayMenu(){
    printf("\nEEE Student Management System\n");
    printf("1. Add student\n");
    printf("2. View students\n");
    printf("3. Search student\n");
    printf("4. Update student\n");
    printf("5. Delete student\n");
    printf("6. Save records\n");
    printf("7. Load records\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
};

char* CalculateGrade(float avg, char grade[]){
    if(avg >= 90)
        strcpy(grade, "A");
    else if(avg >= 80)
        strcpy(grade, "B");
    else if(avg >= 70)
        strcpy(grade, "C");
    else if(avg >= 60)
        strcpy(grade, "D");
    else
        strcpy(grade, "F");
    return grade;
}

void AddStudent(struct Student students[], int *count){
    if (*count >= 100){
        printf("Maximum number of students reached\n");
        return;
    }
    struct Student newStudent;
    int sum = 0, high, low;
    
    printf("Enter the registration number: ");
    scanf("%d", &newStudent.regNo);
    getchar();
    
    printf("Enter the name of the student: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    
    printf("Enter the school: ");
    fgets(newStudent.school, sizeof(newStudent.school), stdin);
    
    printf("Enter the department: ");
    fgets(newStudent.department, sizeof(newStudent.department), stdin);
    
    printf("Enter the course: ");
    fgets(newStudent.course, sizeof(newStudent.course), stdin);
    
    printf("Enter the year: ");
    scanf("%d", &newStudent.year);
    
    printf("Enter the semester: ");
    scanf("%d", &newStudent.semester);
    
    printf("Enter marks for all the 8 subjects:\n");
    for (int i = 0; i < 8; i++){
        scanf("%d", &newStudent.marks[i]);
    }
    
    high = newStudent.marks[0];
    low = newStudent.marks[0];
    for (int i = 0; i < 8; i++){
        sum += newStudent.marks[i];
        if(newStudent.marks[i] > high)
            high = newStudent.marks[i];
        if(newStudent.marks[i] < low)
            low = newStudent.marks[i];
    }
    
    newStudent.total = sum;
    newStudent.average = sum / 8.0;
    newStudent.high = high;
    newStudent.low = low;
    CalculateGrade(newStudent.average, newStudent.grade);
    
    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully\n");   
}

void ViewStudent(struct Student students[], int count){
    if(count == 0){
        printf("No students were found\n");
        return;
    }
    printf("\nStudent Records\n");
    for (int i = 0; i < count; i++){
        printf("Registration Number: %d\n", students[i].regNo);
        printf("Name: %s", students[i].name);
        printf("School: %s", students[i].school);
        printf("Department: %s", students[i].department);
        printf("Course: %s", students[i].course);
        printf("Year: %d\n", students[i].year);
        printf("Semester: %d\n", students[i].semester);
        printf("Marks: %d, %d, %d, %d, %d, %d, %d, %d\n",
            students[i].marks[0],
            students[i].marks[1],
            students[i].marks[2],
            students[i].marks[3],
            students[i].marks[4],
            students[i].marks[5],
            students[i].marks[6],
            students[i].marks[7]);
        printf("Total Score: %d\n", students[i].total);
        printf("Average Score: %.2f\n", students[i].average);
        printf("Highest Score: %d\n", students[i].high);
        printf("Lowest Score: %d\n", students[i].low);
        printf("Grade: %s\n", students[i].grade);
        printf("___________________________________\n");    
    }
}

void SearchStudent(struct Student students[], int count){
    int regNo;
    printf("Enter the registration number: ");
    scanf("%d", &regNo);
    int found = 0;
    for (int i = 0; i < count; i++){
        if (students[i].regNo == regNo){
            printf("Student found\n");
            printf("Registration Number: %d\n", students[i].regNo);
            printf("Name: %s", students[i].name);
            printf("School: %s", students[i].school);
            printf("Department: %s", students[i].department);
            printf("Course: %s", students[i].course);
            printf("Year: %d\n", students[i].year);
            printf("Semester: %d\n", students[i].semester);
            printf("Marks: %d, %d, %d, %d, %d, %d, %d, %d\n",
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2],
                students[i].marks[3],
                students[i].marks[4],
                students[i].marks[5],
                students[i].marks[6],
                students[i].marks[7]);
            printf("Total Score: %d\n", students[i].total);
            printf("Average Score: %.2f\n", students[i].average);
            printf("Highest Score: %d\n", students[i].high);
            printf("Lowest Score: %d\n", students[i].low);
            printf("Grade: %s\n", students[i].grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with registration number: %d not found\n", regNo);
    }
}

void UpdateStudent(struct Student students[], int count){
    int regNo;
    printf("Enter the registration number: ");
    scanf("%d", &regNo);
    getchar();
    for (int i = 0; i < count; i++){
        if (students[i].regNo == regNo){
            int sum = 0, high, low;
            printf("Enter the new registration number: ");
            scanf("%d", &students[i].regNo);
            getchar();
            printf("Enter the new name of the student: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            printf("Enter the new school: ");
            fgets(students[i].school, sizeof(students[i].school), stdin);
            printf("Enter the new department: ");
            fgets(students[i].department, sizeof(students[i].department), stdin);
            printf("Enter the new course: ");
            fgets(students[i].course, sizeof(students[i].course), stdin);
            printf("Enter the new year: ");
            scanf("%d", &students[i].year);
            printf("Enter the new semester: ");
            scanf("%d", &students[i].semester);
            printf("Enter new marks for all the 8 subjects:\n");
            for (int j = 0; j < 8; j++){
                scanf("%d", &students[i].marks[j]);
            }
            high = students[i].marks[0];
            low = students[i].marks[0];
            for (int j = 0; j < 8; j++){
                sum += students[i].marks[j];
                if(students[i].marks[j] > high)
                    high = students[i].marks[j];
                if(students[i].marks[j] < low)
                    low = students[i].marks[j];
            }
            students[i].total = sum;
            students[i].average = sum / 8.0;
            students[i].high = high;
            students[i].low = low;
            CalculateGrade(students[i].average, students[i].grade);
            printf("Student updated successfully\n");
            return;
        }
    }
    printf("Student with registration number: %d not found\n", regNo);
}

void DeleteStudent(struct Student students[], int *count){
    int regNo;
    printf("Enter the registration number: ");
    scanf("%d", &regNo);
    for (int i = 0; i < *count; i++){
        if (students[i].regNo == regNo){
            for (int j = i; j < *count - 1; j++){
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully\n");
            return;
        }
    }
    printf("Student with registration number: %d not found\n", regNo);
}

void SaveRecords(struct Student students[], int count, char filename[]){
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < count; i++){
        fprintf(file, "%d\n", students[i].regNo);
        fprintf(file, "%s", students[i].name);
        fprintf(file, "%s", students[i].school);
        fprintf(file, "%s", students[i].department);
        fprintf(file, "%s", students[i].course);
        fprintf(file, "%d\n", students[i].year);
        fprintf(file, "%d\n", students[i].semester);
        for (int j = 0; j < 8; j++){
            fprintf(file, "%d\n", students[i].marks[j]);
        }
        fprintf(file, "%d\n", students[i].total);
        fprintf(file, "%.2f\n", students[i].average);
        fprintf(file, "%d\n", students[i].high);
        fprintf(file, "%d\n", students[i].low);
        fprintf(file, "%s\n", students[i].grade);
    }
    fclose(file);
    printf("Records saved successfully\n");
}

void LoadRecords(struct Student students[], int *count, char filename[]){
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Error opening file\n");
        return;
    }
    *count = 0;
    while (!feof(file)){
        struct Student newStudent;
        if(fscanf(file, "%d\n", &newStudent.regNo) != 1)
            break;
        fgets(newStudent.name, sizeof(newStudent.name), file);
        fgets(newStudent.school, sizeof(newStudent.school), file);
        fgets(newStudent.department, sizeof(newStudent.department), file);
        fgets(newStudent.course, sizeof(newStudent.course), file);
        if(fscanf(file, "%d\n", &newStudent.year) != 1)
            break;
        if(fscanf(file, "%d\n", &newStudent.semester) != 1)
            break;
        for (int j = 0; j < 8; j++){
            if(fscanf(file, "%d\n", &newStudent.marks[j]) != 1)
                break;
        }
        if(fscanf(file, "%d\n", &newStudent.total) != 1)
            break;
        if(fscanf(file, "%f\n", &newStudent.average) != 1)
            break;
        if(fscanf(file, "%d\n", &newStudent.high) != 1)
            break;
        if(fscanf(file, "%d\n", &newStudent.low) != 1)
            break;
        fgets(newStudent.grade, sizeof(newStudent.grade), file);
        students[*count] = newStudent;
        (*count)++;
    }
    fclose(file);
    printf("Records loaded successfully\n");
}

int main() {
    struct Student students[100];
    int count = 0;
    char filename[] = "student.txt";
    
    LoadRecords(students, &count, filename);
    
    while (1){
        DisplayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice){
            case 1:
                AddStudent(students, &count);
                break;
            case 2:
                ViewStudent(students, count);
                break;
            case 3:
                SearchStudent(students, count);
                break;
            case 4:
                UpdateStudent(students, count);
                break;
            case 5:
                DeleteStudent(students, &count);
                break;
            case 6:
                SaveRecords(students, count, filename);
                break;
            case 7:
                LoadRecords(students, &count, filename);
                break;
            case 8:
                SaveRecords(students, count, filename);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
