#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[50];
} Student;

Student studentMenu[100] = {
    {1, "nguyen A", 23, "034298723"},
    {2, "le Van", 20, "0349834"},
    {3, "ngo B", 99, "0934578"},
    {4, "ba Duy", 5, "03454612"},
    {5, "ninh pon", 100, "0983489734"}
};
int studentCount = 5;

void menu();
void outputStudents();
void inputStudent(int index);
void addStudent(int index);
void editStudent(int index);
void deleteStudent(int index);
void sortStudents();
int searchStudentByName(char* name);

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                outputStudents();
                break;
            case 2: {
                int index;
                printf("Nhap vi tri muon them (0-99): ");
                scanf("%d", &index);
                addStudent(index);
                break;
            }
            case 3: {
                int index;
                printf("Nhap vi tri muon sua (0-%d): ", studentCount - 1);
                scanf("%d", &index);
                editStudent(index);
                break;
            }
            case 4: {
                int index;
                printf("Nhap vi tri muon xoa (0-%d): ", studentCount - 1);
                scanf("%d", &index);
                deleteStudent(index);
                break;
            }
            case 5: {
                char name[50];
                printf("Nhap ten sinh vien can tim: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                int index = searchStudentByName(name);
                if (index != -1) {
                    printf("Tim thay sinh vien: id: %d, ten: %s, tuoi: %d, sdt: %s\n",
                           studentMenu[index].id, studentMenu[index].name,
                           studentMenu[index].age, studentMenu[index].phoneNumber);
                } else {
                    printf("Khong tim thay sinh vien\n");
                }
                break;
            }
            case 6:
                sortStudents();
                printf("Danh sach sinh vien da duoc sap xep\n");
                break;
            case 7:
                printf("Cam on ban da su dung menu cua minh\n");
                return 0;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (1);
}

void menu() {
    printf("\n--------------MENU--------------\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n");
    printf("6. Sap xep danh sach sinh vien\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

void outputStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("id: %d, ten: %s, tuoi: %d, sdt: %s\n",
               studentMenu[i].id, studentMenu[i].name,
               studentMenu[i].age, studentMenu[i].phoneNumber);
    }
}

void inputStudent(int index) {
    printf("Moi ban nhap id: ");
    scanf("%d", &studentMenu[index].id);

    printf("Moi ban nhap ten: ");
    getchar(); 
    fgets(studentMenu[index].name, sizeof(studentMenu[index].name), stdin);
    studentMenu[index].name[strcspn(studentMenu[index].name, "\n")] = 0;

    printf("Moi ban nhap tuoi: ");
    scanf("%d", &studentMenu[index].age);

    printf("Moi ban nhap so dien thoai: ");
    getchar();
    fgets(studentMenu[index].phoneNumber, sizeof(studentMenu[index].phoneNumber), stdin);
    studentMenu[index].phoneNumber[strcspn(studentMenu[index].phoneNumber, "\n")] = 0;
}

void addStudent(int index) {
    if (index < 0 || index >= 99 || studentCount >= 99) {
        printf("Vi tri khong hop le hoac danh sach da day\n");
        return;
    }

    if (index > studentCount) {
        printf("Them vao vi tri ngoai danh sach hien tai, se bo qua cac vi tri trung gian\n");
    } else {
        for (int i = studentCount; i > index; i--) {
            studentMenu[i] = studentMenu[i - 1];
        }
    }

    inputStudent(index);
    studentCount++;
}

void editStudent(int index) {
    if (index < 0 || index >= studentCount) {
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Sua thong tin sinh vien o vi tri %d\n", index);
    inputStudent(index);
}

void deleteStudent(int index) {
    if (index < 0 || index >= studentCount) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = index; i < studentCount - 1; i++) {
        studentMenu[i] = studentMenu[i + 1];
    }
    studentCount--;
    printf("Da xoa sinh vien o vi tri %d\n", index);
}

void sortStudents() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (studentMenu[i].id > studentMenu[j].id) {
                Student temp = studentMenu[i];
                studentMenu[i] = studentMenu[j];
                studentMenu[j] = temp;
            }
        }
    }
}

int searchStudentByName(char* name) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentMenu[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}


