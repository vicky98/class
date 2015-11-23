#include <iostream>

using namespace std;

enum Direction
{
	UP = 1,           // 0001
	RIGHT = 1 << 1,  //  0010
	DOWN = 1 << 2,  //   0100
	LEFT = 1 << 3 //    1000
};

class Cell
{
	friend class Board;
	
	int row_, col_;
	bool visited_;
	int walls_;
	Cell* up;
	Cell* right;
	Cell* down;
	Cell* left;
	
	void set_up(Cell* c)
	{
		up = c;
	}
	
	void set_down(Cell* c)
	{
		down = c;
	}
	
	void set_right(Cell* c)
	{
		right = c;
	}
	
	void set_left(Cell* c)
	{
		left = c;
	}
	
	public:
	
	Cell(int row, int col) : visited_(false), row_(row), col_(col), walls_(UP | RIGHT | DOWN | LEFT) {}	
	// | - pobitovo ili
	// ~ - invertirane
	
	void drill(Direction dir)
	{
		// dir = 1000
		// ~dir = 0111
		// walls_ = 1111
		// wall_ & ~dir = 0111
	
		walls_ &= ~dir;
	}
	
	bool has_wall(Direction dir)
	{
		// walls_= 1011
		// dir =   1000 => 1000  true
		// dir =   0010	=> 0010  true
		// dir =   0100 => 0000  false

		return walls_ & dir;
	}
	
	void print(int length)
	{
		cout << row_ * length << " " << col_ * length << " moveto" << endl;
		cout << length << " " << 0 << (has_wall(DOWN) ? " rlineto" : " rmoveto") << endl;
		cout << 0 << " " << length << (has_wall(RIGHT) ? " rlineto" : " rmoveto") << endl;
		cout << -length << " " << 0 << (has_wall(UP) ? " rlineto" : " rmoveto") << endl;
		cout << 0 << " " << -length << (has_wall(LEFT) ? " rlineto" : " rmoveto") << endl;
	}

	Board(int rows, int col) : rows_(rows), cols_(col)
	{
		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cells.push_back(Cell(i, j));
			}
		}
		
		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Cell& c = at(i, j);
				if (i < rows - 1)
				{	
					c.set_up(at(i + 1, j));
				}
				
				if (i > 0)
				{
					c.set_down(at(i - 1, j));
				}
				
				if (j < cols - 1)
				{
					c.set_right(at(i, j + 1));
				}
				
				if (j > 0)
				{
					c.set_left(at(i, j - 1));
				}
			}
		}
	}

	Cell& at(int i, int j)
	{
		return vector[i * cols + j];
	}

};

int main()
{
	cout << "newpath" << endl;
	Cell c1(4, 4);
	c1.drill(DOWN);
	c1.print(20);			
	cout << "stroke" << endl;
	
	return 0;
}
