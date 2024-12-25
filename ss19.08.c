#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;
void sortStudentsByName(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
void printStudents(Student students[], int size) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van C", 22, "0345678901"},
        {4, "Pham Thi D", 19, "0765432109"},
        {5, "Hoang Van E", 23, "0912345678"}
    };
    int size = 5; 
    printStudents(students, size);
    sortStudentsByName(students, size);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, size);

    return 0;
}

