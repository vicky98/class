// zadacha za 4
// ne raboti

#include <iostream>
#include <string>
#include <list>

using namespace std;

class CalculationError
{
	public:
	
	CalculationError(string msg) : message_(msg) {}
	
	string get_message()
	{
		return message_;
	}
	
	void print_message()
	{
		cout << message_ << endl;
	}
};

class Calculator
{
	list <double> values;

	double get_value()
	{
		if (values.empty())
		{
			throw CalculationError("no values in stack...")
		}
		
		double value = values.back();
		values.pop_back();
	
		return double;
	}
	
	void eval(void (*function)(double, double))
	{
		double value1 = get_value();
		double value2 = get_value();
		double result = function(value1, value2);
		
		cout << "result: " << result << endl;
		values.push_back();
	}
	
	void eval(double (*function)(double))
	{
		double value = get_value();
		double result = function(value);
		
		cout << "result: " << result << endl;
		values.push_back(result);
	}
	
	void plus(double value1, double value2)
	{
		return value1 + value2;
	}
	
	void minus(double value1, double value2)
	{
		reutn value1 - value2;
	}
	
	void dup()
	{
		// duplicate
		values.push_back(value);
		
		return value;
	}
	
	void neg()
	{
		// negative
		return -value;
	}
	
	void evag_mult()
	{
		// multiplication
	}
	
	void evag_div()
	{
		// division
	}	
	
	void evag_sqrt()
	{
		// square root
	}
	
	public:
	
	void run(istream& in)
	{
		try
		{
			while(true)
			{
				cout << "stack(" << values.size() << "): "; 
				
				string input;
				in >> input;
				
				if (!in)
				{
					break;
				}
				
				if (input == "+")
				{
					eval(&plus);
				} else if (input == "-")
				{
					eval(&minus);
				} else if (input == "dup")
				{
					eval(&dup);
				} else if (input == "neg")
				{
					eval(&neg);
				} else {
					// double?
					// превръща стринга в double : 
					istringstream istr(input);
					double value;
					
					istr >> value;
						
					if (!istr)
					{
						throw CalculationError("wtf");
					}
					
					values.push_back(value);
				}
			}	
		} catch (CalculationError e) {
			e.print_message();
		}
	}
};

int main()
{
	Calculator c;
	c.run(cin);
	
	return 0;
}
