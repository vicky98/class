#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Point
{
	int x_, y_;
	
	public:
		
	Point(int x, int y) : x_(x), y_(y) {}

	int get_x()
	{
		return x_;
	}
	
	int get_y()
	{
		return y_;
	}	
	
		
		
	string to_string()
	{
		return to_string(x_) + " " + to_string(y_);
	}
};

class HilbertCurve
{
	vector<Point> curve_;

	void add_point(int x, int y)
	{
		curve_.push_back(Point(x, y));
	}

	 bulid_curve(int n)
	{
		if (n == 1)
		{
			add_point(50, 500);
			add_point(50,50);
			add_point(500, 50);
			add_point(500, 500);
		} 
		else 
		{
		
		}
	}
	
	public:
	
	HilbertCurve(int n)
	{
		build_curve(n);
	}
	
	void draw()
	{
		cout << "newpath" << endl;
		cout << curve_[0].to_string() << "moveto" << endl;
		
		for (int i = 1; i < curve_.size(); i++)
		{
			cout << curve_[i].to_string() << "lineto" << endl;
		}
		
		cout << "stroke" << endl;
	} 	
};

int main()
{
	HilbertCurve hc(1);
	hc.draw();
		
	return 0;
}
