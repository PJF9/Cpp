#include <iostream>
#include <string>
#include <vector>


class Student {
    private:
        std::string name;
        int age;
        std::vector<std::string> courses;

    public:
        // Creating the constructors.
        Student() {
            this->name = "No Name";
            this->age = 0;
        }
        Student(std::string name, int age, std::vector<std::string> courses) {
            this->name = name;
            this->age = age;
            this-> courses = courses;
        }
        Student(std::string name, int age) {
            this->name = name;
            this->age = age;
        }

        // Creating the destructor.
        ~Student() {}

        // Creating the Setters.
        void set_name(std::string name) {
            this->name = name;
            if (this->name != name) {
                this->name = name;
            }
        }
        void set_age(int age) {
            if (this->age != age) {
                this->age = age;
            }
        }
        void set_courses(std::vector<std::string> courses) {
            if (this->courses != courses) {
                this->courses = courses;
            }
        }

        // Creating the Getters.
        inline std::string get_name() {
            return this->name;
        }
        inline int get_age() {
            return this->age;
        }
        inline std::vector<std::string> get_courses() {
            return this->courses;
        }

        // Some needed methods.
        bool add_course(std::string aCourse) {
            bool exists = false;
            for (std::string course: this->courses) {
                if (course == aCourse) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                this->courses.push_back(aCourse);
                return true;
            }
            return false;
        }

        bool remove_course(std::string aCourse) {
            for (int i=0; i<this->courses.size(); i++) {
                if (aCourse == this->courses[i]) {
                    std::string temp = this->courses[this->courses.size() - 1];
                    this->courses[this->courses.size() - 1] = this->courses[i];
                    this->courses[i] = temp;

                    this->courses.pop_back();

                    return true;
                }
            }
            return false;
        }
};


class Course {
    private:
        std::string name;
        int max_attendants;
        std::vector<Student> students;
    
    public:
        // Creating the constructors.
        Course() {
            this->name = "No Name";
            this->max_attendants = 0;
        }
        Course(std::string name, int max_attendants, std::vector<Student> students) {
            this->name = name;
            this->max_attendants = max_attendants;
            this->students = students;
        }
        Course(std::string name, int max_attendants) {
            this->name = name;
            this->max_attendants = max_attendants;
        }

        // Creating the destructor.
        ~Course() {}

        // Creating the Setters.
        void set_name(std::string name) {
            if (this->name != name) {
                this->name = name;
            }
        }
        void set_max_attendants(int max_attendants) {
            if (this->max_attendants != max_attendants) {
                this->max_attendants = max_attendants;
            }
        }
        void set_students(std::vector<Student> students) {
                this->students = students;
        }

        // Creating the Getters.
        inline std::string get_name() {
            return this->name;
        }
        inline int get_max_attendants() {
            return this->max_attendants;
        }
        inline std::vector<Student> get_students() {
            return this->students;
        }

        // Some needed methods.
        bool is_interested(Student student) {
            for (std::string course: student.get_courses()) {
                if (this->name == course) {
                    return true;
                }
            }
            return false;
        }

        bool add_student(Student student) {
            if (this->max_attendants > this->students.size()) {
                if (this->is_interested(student)) {
                    this->students.push_back(student);
                    return true;
                }
            }
            return false;
        }

        bool remove_student(Student aStudent) {
            for (int i=0; i<this->students.size(); i++) {
                if ((aStudent.get_name() == this->students[i].get_name()) && (aStudent.get_age() == this->students[i].get_age())) {
                    Student temp = this->students[this->students.size() - 1];
                    this->students[this->students.size() - 1] = this->students[i];
                    this->students[i] = temp;

                    this->students.pop_back();

                    return true;
                }
            }
            return false;
        }

        void print_students() {
            for (auto student: this->students) {
                std::cout << student.get_name() << "   " << student.get_age() << std::endl;
            }
        }
};


int main() {
    Student s1("Peter Floratos", 16, {"Math", "Sports"});
    Student s2("Jacob Floratos", 17, {"Math", "Physics", "Comp. Science"});
    Student s3("Allan Smith", 18, {"History", "English"});
    Student s4("Marry Jane", 19, {"Chemistry", "Biology"});
    Student s5("Joe El", 18, {"Physics", "Apply Science", "Math"});

    Course mathCourse("Math", 2);

    mathCourse.add_student(s1);
    mathCourse.add_student(s2);
    mathCourse.add_student(s5);

    mathCourse.remove_student(s1);
    mathCourse.add_student(s5);

    mathCourse.print_students();
}
