#include<iostream>
using namespace std;

int const MAX = 10000;
string name[MAX] = {};
double age[MAX] = {0};
int salary[MAX] = {};
char gender[MAX] = {};
int num = 0;

int menu() 
{
    int o = 1;
    while (o--) {
        cout << "Enter your choice:\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update salary by name\n";
        cout << "5) Exit\n";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > 5) 
        {
            cout << "Wrong Choice, please enter a valid choice\n";
            o++;
        } 
        else 
            return choice;
        
    }
}

void add_employee() 
{
     
    cout << "************************\n";
    cout << "Enter name: ";
    cin >> name[num];
    cout << "Enter age: ";
    cin >> age[num];
    cout << "Enter salary: ";
    cin >> salary[num];
    cout << "Enter gender (M/F): ";
    cin >> gender[num];
    cout << "************************\n";
    num++;

}

void print_employees() 
{
    cout << "************************\n";
    for (int j = 0; j < num; j++) {
        if (age[j] == 0)
            continue;
        cout << name[j] << " ";
        cout << age[j] << " ";
        cout << salary[j] << " ";
        cout << gender[j] << "\n";
    }
    cout << "************************\n";

}

void delete_by_age() 
{
    cout << "************************\n";
    int start, end;
    cout << "Enter start and end age: ";
    cin >> start >> end;
    for (int j = 0; j < num; j++) {
        if (age[j] >= start && age[j] <= end) {
            name[j] = "";
            age[j] = 0;
            salary[j] = 0;
        }
    }
    cout << "************************\n";

}

void update_salary() 
{
    cout << "************************\n";
    string n;
    int s;
    cout << "Enter the name and salary: ";
    cin >> n >> s;
    bool is_found = false;
    for (int j = 0; j < num; j++) {
        if (name[j] == n) {
            is_found = true;
            salary[j] = s;
            break;
        }
    }
    if (!is_found)
        cout << "No employee with this name\n";
    cout << "************************\n";

}

void employee_system() 
{
    while (true) {
        int choice = menu();
        if (choice == 1)
            add_employee();
        else if (choice == 2)
            print_employees();
        else if (choice == 3)
            delete_by_age();
        else if (choice == 4)
            update_salary();
        else if (choice == 5)
            break; 
    }
}

int main() 
{
    employee_system();
    return 0;
}
