#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    int stud_cand;
    int level;
    int mode;
    string problem;
    Student(int i, int s, int l, int mo, string p)
    {
        id = i;
        stud_cand = s;
        level = l;
        mode = mo;
        problem = p;
    }
};

int last_e;
int last_i;
int last_t;
queue<Student> electronics;
queue<Student> informatics;
queue<Student> teleinformatics;

void add_new_student()
{
    int stud_cand;
    int major;
    int level;
    int mode;
    string problem;

    cout << "Student or Candidate?\n1 - Student\n2 - Candidate?" << endl;
    cin >> stud_cand;
    cout << "Which major?\n1 - Electronics\n2 - Informatics\n3 - Telecom" << endl;
    cin >> major;
    cout << "Which level?\n1 - engineer\n2 - magister\n3 - dr" << endl;
    cin >> level;
    cout << "Which mode?\n1 - part-time\n2 - part-time" << endl;
    cin >> mode;
    cout << "What problem do you have?" << endl;
    getchar();
    getline(cin, problem);


    cout << stud_cand << endl << major << endl << level << endl << mode << endl << problem << endl;

    if (major == 1)
    {
        last_t=last_e++%100 + 1;
        electronics.push(Student(last_t, stud_cand, level, mode, problem));
    }
    else if (major == 2)
    {
        last_i=last_i++%100 + 1;
        informatics.push(Student(last_t, stud_cand, level, mode, problem));
    }
    else if (major == 3)
    {
        last_t=last_t++%100 + 1;
        teleinformatics.push(Student(last_t, stud_cand, level, mode, problem));
    }
}

void student_finish()
{
    int major;

    cout << "In which major student finished his business?\n1 - Electronics\n2 - Informatics\n3 - Telecom" << endl;
    cin >> major;

    if (major == 1)
    {
        if (!electronics.empty())
        {
            electronics.pop();
        }
    }
    else if (major == 2)
    {
        if (!informatics.empty())
        {
            informatics.pop();
        }
    }
    else if (major == 3)
    {
        if (!teleinformatics.empty())
        {
            teleinformatics.pop();
        }
    }
}

void show()
{
    cout << "Next students are: " << endl;
    if (!electronics.empty())
    {
        cout << "Electronics - " << electronics.front().id << endl;
    }
    else
    {
        cout << "Electronics - no one is waiting" << endl;
    }

    if (!informatics.empty())
    {
        cout << "Informatics - " << informatics.front().id << endl;
    }
    else
    {
        cout << "Informatics - no one is waiting" << endl;
    }

    if (!teleinformatics.empty())
    {
        cout << "Telecom - " << teleinformatics.front().id << endl;
    }
    else
    {
        cout << "Telecom - no one is waiting" << endl;
    }
}

int main() {

    int chosen_option = 0;

    while (chosen_option != 4)
    {
        cout << "Welcome to university queue" << endl;
        cout << "Menu:\n1 - Add new student to queue\n2 - Student is served\n3 - Show who should go next\n4 - exit" << endl;

        cin >> chosen_option;

        while (chosen_option <=0 || chosen_option > 4)
        {
            cout << "Please provide correct option\n" << endl;
            cin >> chosen_option;
        }
        if (chosen_option == 1)
        {
            add_new_student();
        }
        else if (chosen_option == 2)
        {
            student_finish();
        }
        else if (chosen_option == 3)
        {
            show();
        }
    }


    return 0;
}
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    int stud_cand;
    int level;
    int mode;
    string problem;
    Student(int i, int s, int l, int mo, string p)
    {
        id = i;
        stud_cand = s;
        level = l;
        mode = mo;
        problem = p;
    }
};

int last_e;
int last_i;
int last_t;
queue<Student> electronics;
queue<Student> informatics;
queue<Student> teleinformatics;

void add_new_student()
{
    int stud_cand;
    int major;
    int level;
    int mode;
    string problem;

    cout << "Student or Candidate?\n1 - Student\n2 - Candidate?" << endl;
    cin >> stud_cand;
    cout << "Which major?\n1 - Electronics\n2 - Informatics\n3 - Telecom" << endl;
    cin >> major;
    cout << "Which level?\n1 - engineer\n2 - magister\n3 - dr" << endl;
    cin >> level;
    cout << "Which mode?\n1 - part-time\n2 - part-time" << endl;
    cin >> mode;
    cout << "What problem do you have?" << endl;
    getchar();
    getline(cin, problem);


    cout << stud_cand << endl << major << endl << level << endl << mode << endl << problem << endl;

    if (major == 1)
    {
        last_t=last_e++%100 + 1;
        electronics.push(Student(last_t, stud_cand, level, mode, problem));
    }
    else if (major == 2)
    {
        last_i=last_i++%100 + 1;
        informatics.push(Student(last_t, stud_cand, level, mode, problem));
    }
    else if (major == 3)
    {
        last_t=last_t++%100 + 1;
        teleinformatics.push(Student(last_t, stud_cand, level, mode, problem));
    }
}

void student_finish()
{
    int major;

    cout << "In which major student finished his business?\n1 - Electronics\n2 - Informatics\n3 - Telecom" << endl;
    cin >> major;

    if (major == 1)
    {
        if (!electronics.empty())
        {
            electronics.pop();
        }
    }
    else if (major == 2)
    {
        if (!informatics.empty())
        {
            informatics.pop();
        }
    }
    else if (major == 3)
    {
        if (!teleinformatics.empty())
        {
            teleinformatics.pop();
        }
    }
}

void show()
{
    cout << "Next students are: " << endl;
    if (!electronics.empty())
    {
        cout << "Electronics - " << electronics.front().id << endl;
    }
    else
    {
        cout << "Electronics - no one is waiting" << endl;
    }

    if (!informatics.empty())
    {
        cout << "Informatics - " << informatics.front().id << endl;
    }
    else
    {
        cout << "Informatics - no one is waiting" << endl;
    }

    if (!teleinformatics.empty())
    {
        cout << "Telecom - " << teleinformatics.front().id << endl;
    }
    else
    {
        cout << "Telecom - no one is waiting" << endl;
    }
}

int main() {

    int chosen_option = 0;

    while (chosen_option != 4)
    {
        cout << "Welcome to university queue" << endl;
        cout << "Menu:\n1 - Add new student to queue\n2 - Student is served\n3 - Show who should go next\n4 - exit" << endl;

        cin >> chosen_option;

        while (chosen_option <=0 || chosen_option > 4)
        {
            cout << "Please provide correct option\n" << endl;
            cin >> chosen_option;
        }
        if (chosen_option == 1)
        {
            add_new_student();
        }
        else if (chosen_option == 2)
        {
            student_finish();
        }
        else if (chosen_option == 3)
        {
            show();
        }
    }


    return 0;
}
