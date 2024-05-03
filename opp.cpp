#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& _name, int _age) : name(_name), age(_age) {}

    void setName(const string& _name) {
        name = _name;
    }

    string getName() const {
        return name;
    }

    void setAge(int _age) {
        age = _age;
    }

    int getAge() const {
        return age;
    }
};

// Derived class 1
class Employee : public Person {
private:
    double salary;

public:
    Employee(const string& _name, int _age, double _salary)
        : Person(_name, _age), salary(_salary) {}

    void setSalary(double _salary) {
        salary = _salary;
    }

    double getSalary() const {
        return salary;
    }
};

// Derived class 2
class Student : public Person {
private:
    string major;

public:
    Student(const string& _name, int _age, const string& _major)
        : Person(_name, _age), major(_major) {}

    void setMajor(const string& _major) {
        major = _major;
    }

    string getMajor() const {
        return major;
    }
};

// Derived class 3
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(const string& _name, int _age, const string& _subject)
        : Person(_name, _age), subject(_subject) {}

    void setSubject(const string& _subject) {
        subject = _subject;
    }

    string getSubject() const {
        return subject;
    }
};

// Derived class 4 with multiple inheritance
class TeachingAssistant : public Student, public Teacher {
private:
    string university;

public:
    TeachingAssistant(const string& _name, int _age, const string& _major,
                      const string& _subject, const string& _university)
        : Student(_name, _age, _major), Teacher(_name, _age, _subject), university(_university) {}

    void setUniversity(const string& _university) {
        university = _university;
    }

    string getUniversity() const {
        return university;
    }

    // Method overriding
    void setName(const string& _name) {
        Student::setName(_name);
        Teacher::setName(_name);
    }

    // Method overloading
    void displayInfo() const {
        cout << "Name: " << Person::getName() << endl;
        cout << "Age: " << Person::getAge() << endl;
        cout << "Major: " << Student::getMajor() << endl;
        cout << "Subject: " << Teacher::getSubject() << endl;
        cout << "University: " << getUniversity() << endl;
    }
};

int main() {
    TeachingAssistant ta("John Doe", 25, "Computer Science", "Programming", "ABC University");

    ta.displayInfo();

    cout << endl;

    // Using getter and setter methods
    ta.setAge(26);
    ta.setMajor("Software Engineering");
    ta.setSubject("Algorithms");
    ta.setUniversity("XYZ University");

    cout << "Updated Information:" << endl;
    cout << "Name: " << ta.getName() << endl;
    cout << "Age: " << ta.getAge() << endl;
    cout << "Major: " << ta.getMajor() << endl;
    cout << "Subject: " << ta.getSubject() << endl;
    cout << "University: " << ta.getUniversity() << endl;

    return 0;
}