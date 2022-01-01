#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct Employee{
    int id ;
    char name[30] ;
    int age ;
    double salary ;
    double commission ;
    double deduction ;
};

struct Employee *global_emp_ptr ;
size_t arr_size ;
int employees_number = 0;
int salary_size ;




void init(){
    system("cls");
    printf("How many Employee you want to Enter:: ");
    _flushall();
    scanf("%d", &arr_size);
    salary_size = (int)arr_size ;
    global_emp_ptr = malloc(arr_size * sizeof(*global_emp_ptr));
}

void arrow_here(int current_position, int arrow_nxtPosition){
    if(current_position == arrow_nxtPosition){
        printf("--> ");
    }else{
        printf("    ");
    }
}
double calculate_salary(double salary,double commission, double deduction){
    double total_salary, comm_value, deduc_value;
    comm_value = salary * (commission / 100);
    deduc_value = salary * (deduction / 100);
    total_salary = salary + comm_value - deduc_value;
    return total_salary;
}
int find_employee_byName(char name[30]) {
	for (int i = 0; i < arr_size; i++){
		if (strcmp(global_emp_ptr[i].name, name)== 0){
			return i;
			}
        }
	return -1;
}
int find_employee_byId(int id) {
	for (int i = 0; i < arr_size; i++){
		if (global_emp_ptr[i].id == id){
			return i;
		}
	}
	return -1;
}

void delete_from_employees(int index) {
	for (int i = index; i < arr_size - 1; i++){
		global_emp_ptr[i] = global_emp_ptr[i + 1];
	}
	arr_size--;

}


void add_employee(){
    init();
    int position = 1;
    int keyPressed = 0;
    system("cls");
    for(int i=employees_number ; i<arr_size ; i++, employees_number++){
        do{
            printf("Enter ID:: ");
            _flushall();
            scanf("%i", &global_emp_ptr[i].id);
        }while(find_employee_byId(global_emp_ptr[i].id) == find_employee_byId(global_emp_ptr[i-1].id));
        printf("Enter Name:: ");
        _flushall();
        scanf("%[^\n]%*c", &global_emp_ptr[i].name);
        do{
            printf("Enter Age \'the age must be between 18 to 60\':: ");
            _flushall();
            scanf("%i", &global_emp_ptr[i].age);
        }while(global_emp_ptr[i].age<18 || global_emp_ptr[i].age>60);
        printf("Enter Salary:: ");
        _flushall();
        scanf("%lf", &global_emp_ptr[i].salary);
        printf("Enter Commission:: ");
        _flushall();
        scanf("%lf", &global_emp_ptr[i].commission);
        printf("Enter Deduction:: ");
        _flushall();
        scanf("%lf", &global_emp_ptr[i].deduction);
        printf("\n\t\t\t You Added %i Successfully........... \n\n", i+1);
    }

    while(keyPressed != 13){
        system("cls");
        printf("\n\t\t............You Added %i Successfully........... \n\n", employees_number);
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}

}

void display_byId(){
    int position = 1;
    int keyPressed = 0;
    int x,temp = 0;
    system("cls");
    if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Display!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}
	}
    printf("Enter ID To Display It:: ");
    _flushall();
    scanf("%i", &temp);

    x = find_employee_byId(temp);

    if(x == -1){
        while(keyPressed != 13){
        system("cls");
        printf("\t\tThis ID is not Exist in the Employees's ID List!!\n\n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}
	}


    while(keyPressed != 13){
        system("cls");
        printf("ID:: %i\n", global_emp_ptr[x].id);
        printf("Name:: %s\n", global_emp_ptr[x].name);
        printf("Age:: %i\n", global_emp_ptr[x].age);
        printf("Salary:: %.2lf\n", global_emp_ptr[x].salary);
        printf("Commission:: %.2lf\n", global_emp_ptr[x].commission);
        printf("Deduction:: %.2lf\n", global_emp_ptr[x].deduction);
        printf("Total Salary :: %.2lf\n", calculate_salary(global_emp_ptr[x].salary, global_emp_ptr[x].commission, global_emp_ptr[x].deduction));
        printf("-------------------------------------------------------------\n");
        printf("\n\t\t"); arrow_here(1, position); printf(" Display Another Employee \n");
        printf("\t\t"); arrow_here(2, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 2){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        display_byId();
        break;
    case 2 :
        main_menu();
	}

}

void display_byName(){
    int position = 1;
    int keyPressed = 0;
    int x;
    char temp[30];
    system("cls");
    if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Display!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}
    }
    printf("Enter Name To Display It:: ");
    _flushall();
    scanf("%s", &temp);

    x = find_employee_byName(temp);
    if(x == -1){
        while(keyPressed != 13){
        system("cls");
        printf("\t\tThis Name is not Exist in the Employees's Name List!!\n\n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}
	}
    while(keyPressed != 13){
        system("cls");
        printf("ID:: %i\n", global_emp_ptr[x].id);
        printf("Name:: %s\n", global_emp_ptr[x].name);
        printf("Age:: %i\n", global_emp_ptr[x].age);
        printf("Salary:: %.2lf\n", global_emp_ptr[x].salary);
        printf("Commission:: %.2lf\n", global_emp_ptr[x].commission);
        printf("Deduction:: %.2lf\n", global_emp_ptr[x].deduction);
        printf("Total Salary :: %.2lf\n", calculate_salary(global_emp_ptr[x].salary, global_emp_ptr[x].commission, global_emp_ptr[x].deduction));
        printf("-------------------------------------------------------------------\n");
        printf("\n\t\t"); arrow_here(1, position); printf(" Display Another Employee \n");
        printf("\t\t"); arrow_here(2, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 2){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        display_byName();
        break;
    case 2 :
        main_menu();
	}

}

void display_all(){
    int position = 1;
    int keyPressed = 0;
	system("cls");
	 if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Display!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	 }
    return;
	}


	while(keyPressed != 13){
        system("cls");
        for (int i = 0; i < arr_size; i++) {
        printf("================Employee Number %i=================\n", i+1);
		printf(" ID ::  %i\n", global_emp_ptr[i].id);
		printf(" Name ::  %s\n", global_emp_ptr[i].name);
		printf(" Age ::  %i\n", global_emp_ptr[i].age);
		printf(" Salary ::  %.2lf\n", global_emp_ptr[i].salary);
		printf(" Commission ::  %.2lf\n", global_emp_ptr[i].commission);
		printf(" Deduction ::  %.2lf\n", global_emp_ptr[i].deduction);
		printf(" Total Salary :: %.2lf\n", calculate_salary(global_emp_ptr[i].salary, global_emp_ptr[i].commission, global_emp_ptr[i].deduction));
		printf("------------------------------------\n");
	}
        printf("\n\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	}
}

void delete_byId(){
    int position = 1;
    int keyPressed = 0;
    int id ;
	system("cls");

    if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Delete!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	 }
    return;
	}

	printf("Enter Employee Id :: ");
	_flushall();
	scanf("%i", &id);
	int idx = find_employee_byId(id);
	if (idx != -1){
        delete_from_employees(idx);
	}
	while(keyPressed != 13){
        system("cls");
        if (idx != -1) {
            printf("\n\n\t\t\t Employee Deleted successfully....\n\n");
        } else {
            printf("\n\n\t\t\t Employee Dosen't Exist ..... \n\n");
        }
        printf("\t\t"); arrow_here(1, position); printf(" Delete Another Employee \n");
        printf("\t\t"); arrow_here(2, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 2){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        delete_byId();
        break;
    case 2 :
        main_menu();
	}

}

void delete_byName(){
    int position = 1;
    int keyPressed = 0;
    char name[30] ;
	system("cls");

    if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Delete!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	 }
    return;
	}

	printf("Enter Employee Name :: ");
	_flushall();
	scanf("%[^\n]%*c", &name);
	int idx = find_employee_byName(name);
	if (idx != -1) {
		delete_from_employees(idx);
	}
	while(keyPressed != 13){
        system("cls");
        if (idx != -1) {
            printf("\n\n\t\t\t Employee Deleted successfully....\n\n");
        } else {
            printf("\n\n\t\t\t Employee Dosen't Exist ..... \n\n");
        }
        printf("\t\t"); arrow_here(1, position); printf(" Delete Another Employee \n");
        printf("\t\t"); arrow_here(2, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 2){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        delete_byName();
        break;
    case 2 :
        main_menu();
	}



}

void delete_all(){
    int position = 1;
    int keyPressed = 0;
    system("cls");
    char ch ;
    if (arr_size == 0) {
		while(keyPressed != 13){
        system("cls");
        printf("No Data Exist to Delete!!! \n");
        printf("\t\t"); arrow_here(1, position); printf(" Main Menu \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 1){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        main_menu();
        break;
	 }
    return;
	}

    printf("Do you want to delete all Employees Y or N?\n");

    while(keyPressed != 13){
        system("cls");
        printf("\t\t"); arrow_here(1, position); printf(" Yes \n");
        printf("\t\t"); arrow_here(2, position); printf(" No \n");
        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != 2){
            position++;
        }else if(keyPressed == 72 && position != 1){
            position--;
        }else{
            position = position;
        }
    }

	switch(position){
    case 1 :
        arr_size = 0 ;
        free(global_emp_ptr);
        printf("\n\t\t\tEmployees Information Deleted Successfully............");
        break;
    case 2 :
        main_menu();
        break;
	}


}



void main_menu() {
    #define MAX 8
    #define MIN 1
	int position = 1;
	int keyPressed = 0;


	while(keyPressed != 13){

        system("cls");
        arrow_here(1, position); printf(" Add Employee \n");
        arrow_here(2, position); printf(" Display By ID \n");
        arrow_here(3, position); printf(" Display By Name \n");
        arrow_here(4, position); printf(" Display All \n");
        arrow_here(5, position); printf(" Delete By ID \n");
        arrow_here(6, position); printf(" Delete By Name \n");
        arrow_here(7, position); printf(" Delete All \n");
        arrow_here(8, position); printf(" Exit \n");

        keyPressed = getch();
        _flushall();
        if(keyPressed == 80 && position != MAX){
            position++;
        }else if(keyPressed == 72 && position != MIN){
            position--;
        }else{
            position = position;
        }

    }

	switch (position)
	{
	case 1:
		add_employee();
		break;
	case 2:
		display_byId();
		break;
	case 3:
		display_byName();
		break;
	case 4:
		display_all();
		break;
	case 5:
		delete_byId();
		break;
    case 6:
		delete_byName();
		break;
    case 7:
		delete_all();
		break;
	case 8:
		exit(0);
		break;
	}

	main_menu();

}

int main()
{
    main_menu();
    free(global_emp_ptr);
    return 0;
}
