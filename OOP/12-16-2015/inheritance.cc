// - private
// + public

#include <iostream>
#include <string>

using namespace std;

class Employee // базов клас
{
	long id_;
	
// protected:

	string name_;

public:

	Employee(long id, const string& name)
	: id_(id), name_(name)
	{}
	
	long get_id() const
	{
		return id_;
	}
	
	string get_name() const
	{
		return name_;
	}
	
	virtual void print() const // като добавим virtual, свързването става динамично
	{
		cout << "id: " << id_ << "; " << name_ << endl;
	}
};

class Manager: public Employee // Manager е наследник
{
	long level_;
	
public:

	Manager(long id, string name, long level)
	// : id_(id), name_(name), level_(level)  -> не е добра идея
 	: Employee(id, name),
	  level_(level)
	{} 	
	
	long get_level() const
	{
		return level_;
	}
	
	// ако имаме методи с еднакви имена, този на наследника overwritе-ва този на базовия
	
	/*
	void print() const
	{
		cout << "id: " << get_id() << endl; 
		cout << name_ << endl; // изписва се ако е name_ e protected или public
		get_name() << "; level: " << level_ << endl;
	}
	*/
	
	void print() const 
	{
		cout << "M: " << level_ << "; ";
		Employee::print();
	}
};

int main()
{
	Employee e1(1, "Pesho");
	Employee e2(2, "Gosho");
	
	Manager m1(3, "Ivancho", 2);
	// cout << e1.name_ << endl  -> няма да го изпише ако е protected	
	
	e1.print();
	e2.print();
	m1.print();
	
	Employee* pe;
	pe = &e1;
	pe -> print();
	
	pe = &m1;
	pe -> print(); // изписва Иванчо и id без M:, защото свързването е статично (виж 33 ред), трябва ни динамично свързване
	
	return 0;
}
