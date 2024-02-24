#include <iostream>
#include <vector>

class Student {
    private:
        std::string f_name;
        std::string l_name;
        std::string major;
        int age;
    
    public:
        Student() {};
        Student(std::string aF_name, std::string aL_name ,int aAge, std::string aMajor) {
            f_name = aF_name;
            l_name = aL_name;
            age = aAge;
            major = aMajor;
        }

        std::string get_fname() {
            return f_name;
        }
        std::string get_l_name() {
            return l_name;
        }
        int get_age() {
            return age;
        }
        std::string get_major() {
            return major;
        }
};

class lClass: public Student {
    private:
        std::string class_name;
        int max_students;
        std::vector <Student> students;

    public:
        lClass(std::string aClass_name, int aMax_students) {
            class_name = aClass_name;
            max_students = aMax_students;
        }

        void add_student(Student lStudent) {
            bool found;
            int index = 1;
            for (int i=0; i<students.size(); i++) {
                if (lStudent.get_fname() == students[i].get_fname() && lStudent.get_l_name() == students[i].get_l_name() && lStudent.get_age() == students[i].get_age()) {
                    found = true;  
                    break;                  
                } else {
                    found == false;
                }
                index = i;
            }
            if (!found && index<=max_students) {
                students.push_back(lStudent);
                index ++;
            } 
            if (index>max_students) {
                std::cout << "\n--- Not Enought Space For Students to Come ---\n" << std::endl; 
            }
        }

        void print_students() {
            for (int j=0; j<students.size(); j++) {
                std::cout << "Student No." << j+1 << std::endl;
                std::cout << "--- First Name: " << students[j].get_fname() << std::endl;
                std::cout << "--- Last Name: " << students[j].get_l_name() << std::endl;
                std::cout << "--- Age: " << students[j].get_age() << std::endl;
                std::cout << "--- Major: " << students[j].get_major() << std::endl;
                std::cout << std::endl;
            }
        }
};

int main() {
    // system("cls");
    Student p1("Petros", "Floratos", 17, "Comp. Science");
    Student p2("Jacob", "Floratos", 18, "Physics");
    Student p3("Antonis", "Floratos", 17, "Maths");
    Student p4("Antonis", "Floratos", 17, "Maths");
    Student p5("Antonis", "Floratosa", 17, "Maths");

    lClass c("Class Name", 20);

    c.add_student(p1);
    c.add_student(p2);
    c.add_student(p2);
    c.add_student(p4);
    c.add_student(p5);

    c.print_students();

    return 0;
}