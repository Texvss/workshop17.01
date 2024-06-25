#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const double RUB_USD = 89.5;

class Human
{
private:
    std::string name;
    int age;
public:
    Human(std::string name, int age);
    std::string getInfo() const;
    virtual std::string getType() = 0;
    int getAge() const
    {
        return age;
    }
};

Human::Human(std::string name, int age):name(name), age(age) {}

std::string Human::getInfo() const
{
    return name + " " + std::to_string(age);
}

class Student : public Human
{
private:
    double mean;
public:
    Student(std::string name, int age, double mean) : Human(name, age), mean(mean){};
    std::string getInfo() const
    {
        return Human::getInfo() + " " + std::to_string(mean);
    }
    std::string getType()
    {
        return "student";
    }
};

class Professor : public Human
{
private:
    int salary;
public:
    Professor(std::string name, int age = 30, int salary = 10000) : Human(name, age), salary(salary){};
    std::string getInfo() const
    {
        return Human::getInfo() + " " + std::to_string(salary);
    }
    std::string getType()
    {
        return "professor";
    }
    static double convert2USD(int salary)
    {
        return salary / RUB_USD;
    }
    int getSalary() const
    {
        return salary;
    }
};

bool comp(Human* l, Human* r)
{
    return l->getAge() > r->getAge();
}

class University
{
private:
    std::vector<Human*> humans;
public:
    void addHuman(Human *human)
    {
        humans.push_back(human);
    }
    Human* operator [](int x) 
    {
        return humans[x];
    }
    size_t getSize() const
    {
        return humans.size();
    }
    void sortDESC()
    {
        std::sort(humans.begin(), humans.end(), comp);
    }
};

int main(int, char**)
{
    int a = 5;
    int *b = &a;
    int& c = a;
    int d = *b;
    // Human human("Kirill", 15);
    Student student("Svyat", 17, 7.5);
    Professor professor("Ivan");
    Professor prof("Vanya", 22);
    University university;
    university.addHuman(&prof);
    university.addHuman(&student);
    university.addHuman(&professor);
    university.sortDESC();
    for (int i = 0; i < university.getSize(); i++)
    {
        std::cout << university[i]->getInfo() << '\n';
    }
    std::cout << professor.convert2USD(professor.getSalary()) << " " << Professor::convert2USD(10000);
    // std::cout << human.getInfo() << '\n';
    // std::cout << student.getInfo() << '\n';
    // std::cout << professor.getInfo() << '\n';

}
