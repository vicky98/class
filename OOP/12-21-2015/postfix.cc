// zadacha za 4

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
	}
	
	void eval_plus()
	{
		double value1 = get_value();
		double value2 = get_value();
		double result = value1 + value2;
		
		cout << "result: " << result << endl;
		
		value.push_back(result);
	}
	
	void eval_minus()
	{
		double value1 = get_value();
		double value2 = get_value();
		double result = value1 - value2;
		
		cout << "result: " << result << endl;
		
		value.push_back(result);
	}
	
	void eval_dup()
	{
		// duplicate
		values.push_back(values.back())
		
		cout << "result: " << values.back() << endl; 
	}
	
	void eval_neg()
	{
		// negative
		double value = get_value();
		values.push_back(-value)
		
		cout << "result: " << -value << endl;
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
					eval_plus();
				} else if (input == "-")
				{
					eval_minus();
				} else if (input == "dup")
				{
					eval_dup();
				} else if (input == "neg")
				{
					eval_neg();
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
