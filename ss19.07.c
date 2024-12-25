#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudentById(int id, Student students[], int *size) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j + 1];
            }
            (*size)--;
            printf("Sinh vien voi ID %d da duoc xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
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
    int idToDelete;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    deleteStudentById(idToDelete, students, &size);
    printStudents(students, size);

    return 0;
}

