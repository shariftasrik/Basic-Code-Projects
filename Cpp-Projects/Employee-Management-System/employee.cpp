#include<bits/stdc++.h>
using namespace std;

vector<string> emp_names;
vector<int> emp_IDs;
vector<vector<pair<int, string>>> emp_tasks;


void addEmployee()
{
    string name;
    int id, numTasks;

    cout << "Enter employee name : ";
    cin >> name;
    emp_names.push_back(name);

    cout << "Enter employee ID : ";
    cin >> id;
    emp_IDs.push_back(id);

    cout << "Enter number of tasks for employees : ";
    cin >> numTasks;

    vector<pair<int, string>> tasks;
    for(int i=0; i<numTasks; i++)
    {
        int taskID;
        string taskDescrip;

        cout << "Enter task ID : ";
        cin >> taskID;

        cout << "Enter task description : ";
        cin >> taskDescrip;

        tasks.push_back(make_pair(taskID,taskDescrip));
    }
    emp_tasks.push_back(tasks);
    cout << "Employee added successfully !!" << endl;

}

void displayEmployeeDetails()
{
    if(emp_names.empty())
    {
        cout << "No employees added yet !" << endl;
        return;
    }

    for(size_t i=0; emp_names.size(); i++)
    {
        cout << "Employee name : " << emp_names[i] << endl;
        cout << "Employee ID : " << emp_IDs[i] << endl;
        cout << "Tasks : " << endl;

        for(const auto& task : emp_tasks[i])
        {
            cout << "Task ID : " << task.first << " , Task description : " << task.second << endl;

        }
        cout << endl;
    }
}

void updateEmployeeTask()
{
    if(emp_names.empty())
    {
        cout << "No employees added yet !" << endl;
        return ;
    }

    int id;
    cout << "Enter employees id whose task have to be updated : ";
    cin >> id;

    bool found =  false;

    for(size_t i=0; i<emp_IDs.size(); i++)
    {
        if(emp_IDs[i]== id)
        {
            found =  true;

            int taskID;
            cout << "Enter task id to update : ";
            cin >> taskID;

            bool taskFound = false;

            for(auto& task : emp_tasks[i])
            {
                if(task.first ==  taskID)
                {
                    taskFound =  true;

                    cout << "Enter new task description : ";
                    cin >> task.second;

                    cout << "Task update successfully !!" << endl;
                    break;
                }
            }
            if(!taskFound)
            {
                cout << "Task ID not found !" <<endl;
            }
        }
    }
}

int main()
{
    int choice;

    do{

        cout << "< Employee Management System >" << endl;
        cout << "................................" << endl;

        cout << endl;
        cout << "1. Add Employee "<< endl;
        cout << "2. Display Employee Details " << endl;
        cout << "3. Update Employee Task " << endl;
        cout << "4. Exit " << endl;

        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        cout << endl;

        switch(choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployeeDetails();
            break;
        case 3:
            updateEmployeeTask();
            break;
        case 4:
            cout << endl;
            cout << "Your task is completed, Thank you !!" << endl;
            cout << "Program exited !!"<< endl;
            break;
        default:
            cout << "Invalid choice. Please try again !!"<< endl;
        }


    }while(choice!=4);

    cout << endl;

    return 0;
}
