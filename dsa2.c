
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee *emp[MAX_EMPLOYEES];
int count = 0;

void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }

    struct Employee *e = malloc(sizeof(struct Employee));

    if (e == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter ID: ");
    if (scanf("%d", &e->id) != 1) {
        free(e);
        printf("Invalid ID!\n");
        return;
    }

    printf("Enter Name: ");
    if (scanf("%49s", e->name) != 1) {
        free(e);
        printf("Invalid name!\n");
        return;
    }

    printf("Enter Salary: ");
    if (scanf("%f", &e->salary) != 1) {
        free(e);
        printf("Invalid salary!\n");
        return;
    }

    emp[count] = e;
    count++;

    printf("Employee added successfully!\n\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees to show.\n\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n",
           "ID", "Name", "Salary");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %.2f\n",
               emp[i]->id,
               emp[i]->name,
               emp[i]->salary);
    }

    printf("\n");
}

void searchEmployee() {
    int id;

    printf("Enter ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (emp[i]->id == id) {
            printf("Employee found!\n");
            printf("ID: %d\n", emp[i]->id);
            printf("Name: %s\n", emp[i]->name);
            printf("Salary: %.2f\n\n", emp[i]->salary);
            return;
        }
    }

    printf("Employee not found.\n\n");
}

void deleteEmployee() {
    int id;

    printf("Enter ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (emp[i]->id == id) {
            free(emp[i]);

            for (int j = i; j < count - 1; j++) {
                emp[j] = emp[j + 1];
            }

            count--;
            printf("Employee deleted successfully!\n\n");
            return;
        }
    }

    printf("Employee not found.\n\n");
}

void freeAll() {
    for (int i = 0; i < count; i++) {
        free(emp[i]);
    }

    count = 0;
}

int main() {
    int choice;

    do {
        printf("----- Employee Record System -----\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeAll();
            return 1;
        }

        printf("\n");

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                deleteEmployee();
                break;

            case 5:
                freeAll();
                printf("Bye!\n");
                break;

            default:
                printf("Invalid choice!\n\n");
        }

    } while (choice != 5);

    return 0;
}
