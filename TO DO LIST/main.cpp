#include <iostream>
#include <windows.h>
using namespace std;

void print_tasks(string tasks[], int task_count)
{
    cout << "Task To Do: " << endl;

    cout << "---------------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i << " : " << tasks[i] << endl;
    }
    cout << "----------------------------------" << endl;
    cout << endl;
}

int main()
{
    system("color fc");
    string tasks[10] = {""};
    // counter var -> know how many tasks we have
    int task_count = 0;

    int option = -1;
    while (option != 0)
    {
        // we will make menu here
        cout << "-------------------TO DO LIST----------------" << endl;
        cout << "1 - To Add New Task " << endl;
        cout << "2 - To View Tasks " << endl;
        cout << "3 - Delete The Tasks " << endl;
        cout << "0 - Terminate The Program " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            if (task_count > 9)
            {
                cout << "'''TASK LIST IS FULL'''" << endl;
            }
            else
            {
                cout << "Enter A New Task: ";
                cin.ignore(); // to clear the newline character from the input buffer
                getline(cin, tasks[task_count]);
                task_count++;
            }
            break;
        }

        case 2:
        {
            system("cls");
            print_tasks(tasks, task_count);
            break;
        }

        case 3:
        {
            system("cls");

            int del_task = 0;
            cout << "Enter A Task TO Delet: ";
            cin >> del_task;

            if (del_task < 0 || del_task > 9)
            {
                cout << "You Entered Invalid Task No. " << endl;
                break;
            }

            for (int i = del_task; i < task_count; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            task_count = task_count - 1;
            break;
        }

        case 0:
        {
            cout << "Terminating the ProGram- -- ---- -----" << endl;
            break;
        }

        default:
        {
            cout << "You entered Invalid value! " << endl;
        }
        }
    }
    return 0;
}