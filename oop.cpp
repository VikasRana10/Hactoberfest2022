// OOPs Program covering these concepts
// 1 Class & Object
// 2 Constructor
// 3 Encapsulation
// 4 Abstraction
// 5 Inheritance
// 6 Polymorphism (using this pointer & virtual function)


#include<iostream>
using namespace std;

class AbstractEmployee // Abstract class
{
   virtual void AskforPromotion()=0; // Pure virtual Function	
};

// Base class(inheritance)
class Employee    // Employee class with member functions
{
private: // Encpsulation
	//string Name;
	string Company;
	int Age;
protected: 
		string Name;
//protected:(This is for inheriting member function from derived class using protected access modifier)
      //string Name;	
	
public:      // access modifier is set to be public
	void setName(string name) // setter
	{
		Name = name;
	}
	
	string getName() // getter
	{
		return Name;
	}
	
	void setCompany(string company)
	{
		Company = company;
	}
	
	string getCompany()
	{
		return Company;
	}
	
	void setAge(int age)
	{
		Age = age;
	}
	
	int getAge()
	{
		return Age;
	}
	
	//string Name;
	//string Company;
	//int Age;
	
	void introduceyourself()  // void function
	{
		cout<<"Name-"<<Name<<endl;
		cout<<"Company-"<<Company<<endl;
		cout<<"age-"<<Age<<endl;
	}
	Employee(string name, string company, int age) // Pramartized Contructor
	{
	  Name = name;
	  Company = company;
	  Age = age;	
	}
	void AskforPromotion() 
	{
		if (Age>=15)
		cout<<Name<<" Got Promoted"<<endl;
		
		else
		cout<<Name<<" Not Promoted"<<endl;
	}
	// using virtual function the most derived functionality will work intead of this
	virtual void work()// implementation of polymorphism
	{
		cout<<Name<<" is checking email, task backlog, performing tasks...."<<endl;
	}
	
};
// Derived class of base class employee
class Developer:public Employee // this inheritance is by default private
{
public:
     string FavProgLang;
     Developer(string name, string company, int age, string favProgLang )
     :Employee(name,company,age)
	 {
	 	FavProgLang = favProgLang;
	 }
	 void Fixbug()
	 {
	 	cout<< getName() <<" fixed bug using "<<FavProgLang<<endl;
	 }
	 void work() // implementation of polymorphism
	{
		cout<<Name<<" is writing "<<FavProgLang<<" code"<<endl;
	}
};
// another derived class of base class Employee
class Teacher:public Employee 
{
	public:
		string Subject;
		void PrepareLesson()
		{
		  cout<< Name<<" is preparing "<< Subject <<" Lesson "<<endl;
		}
		Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
		{
			Subject = subject;
		}
		void work()// implementation of polymorphism
	{
		cout<<Name<<" is teaching "<<Subject<<" on youtube"<<endl;
	}
};
int main()
{
	// object of Emloyee class to access member functions
	//Employee employee1 = Employee("Vikas Rana", "Google", 19);
	//employee1.Name = "Vikas Rana";
	//employee1.Company = "Google";
	//employee1.age = 19;
	//employee1.introduceyourself(); 
	//employee1.AskforPromotion();
	Developer d = Developer("Vikas Rana","Google",19,"C++");
	d.Fixbug();
	d.AskforPromotion();
	Teacher t = Teacher("Harry", "CWH", 25, "Programming");
	t.PrepareLesson();
	t.AskforPromotion();
	
	//The most common use of polymorphism is when a
	//parent class refrence is used to refer to a child class object
	//d.work();
	//t.work();
	
	// implementing polymorphism using pointers
	//base class pointer using derived class object
	Employee* e1 = &d;
	Employee* e2 = &t;
	
	e1->work();  // '->' this symbol is for accessing the member of base class using poiters
	e2->work();
	
	//employee1.setAge(20);
	//cout<< employee1.getName()<<" will be "<< employee1.getAge() <<" Years old"<<endl;
	
}
