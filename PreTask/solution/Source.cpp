#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>

using namespace std;

class Matrix
{
private:
	int rows;
	int cols;
	vector<vector<int>> elements;
public:
	Matrix();
	Matrix(int rows_num, int cols_num);
	~Matrix() = default;

	void Reset(int rows_num, int cols_num);
	int At(int row, int col) const;
	int& At(int row, int cols);
	int GetNumRows() const;
	int GetNumColumns() const;

};

bool operator==(const Matrix& lhs, const Matrix& rhs);
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
ostream& operator<<(ostream& out, const Matrix& matrix);
istream& operator>>(istream& in, Matrix& matrix);

int main()
{
	Matrix a, b;

	cin >> a >> b;
	cout << a + b << endl;

	return 0;
}

Matrix::Matrix():
	rows(0),
	cols(0)
{}

Matrix::Matrix(int rows_num, int cols_num) :
	rows(rows_num),
	cols(cols_num)
{
	if (rows < 0 || cols < 0)
	{
		stringstream ss;
		ss << rows << " " << cols;
		throw out_of_range(ss.str());
	}
	
	if (rows == 0 || cols == 0)
	{
		rows = 0;
		cols = 0;
		elements.resize(0);
	}

	elements.resize(rows);
	for (size_t i = 0; i < rows; i++)
	{
		elements[i].resize(cols);
		for (size_t j = 0; j < cols; j++)
		{
			elements[i][j] = 0;
		}
	}
}

void Matrix::Reset(int rows_num, int cols_num)
{
	if (rows_num < 0 || cols_num < 0)
	{
		throw out_of_range("");
	}

	if (rows_num == 0 || cols_num == 0)
	{
		rows = 0;
		cols = 0;
		elements.resize(0);
	}

	rows = rows_num;
	cols = cols_num;

	elements.resize(rows);
	for (size_t i = 0; i < rows; i++)
	{
		elements[i].resize(cols);
		for (size_t j = 0; j < cols; j++)
		{
			elements[i][j] = 0;
		}
	}
}

int Matrix::At(int row, int col) const
{
	if (row < 0 || row > (rows - 1) || col < 0 || col > (cols-1))
	{
		stringstream ss;
		ss << row << " " << col;
		throw out_of_range(ss.str());
	}

	return elements[row][col];
}

int& Matrix::At(int row, int col)
{
	if (row < 0 || row> (rows - 1) || col < 0 || col >(cols - 1))
	{
		stringstream ss;
		ss << row << " " << col;
		throw out_of_range(ss.str());
	}

	return elements[row][col];
}

int Matrix::GetNumRows() const
{
	return rows;
}

int Matrix::GetNumColumns() const
{
	return cols;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows())
	{
		return false;
	}

	for (size_t i = 0; i < lhs.GetNumRows(); i++)
	{
		for (size_t j = 0; j < rhs.GetNumColumns(); j++)
		{
			if (rhs.At(i, j) != lhs.At(i, j))
			{
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	if ((lhs.GetNumColumns() == 0 || lhs.GetNumRows() == 0) && (rhs.GetNumColumns() == 0 || rhs.GetNumRows() == 0))
	{
		return Matrix();
	}
	if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows())
	{
		throw invalid_argument("");
	}

	Matrix result = Matrix(lhs.GetNumRows(), lhs.GetNumColumns());

	for (size_t i = 0; i < result.GetNumRows(); i++)
	{
		for (size_t j = 0; j < result.GetNumColumns(); j++)
		{
			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}

	return result;
}

ostream& operator<<(ostream& out, const Matrix& matrix)
{
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns();
	for (size_t i = 0; i < matrix.GetNumRows(); i++)
	{
		out << endl;
		for (size_t j = 0; j < matrix.GetNumColumns(); j++)
		{
			out << matrix.At(i, j) << " ";
		}
	}

	return out;
}

istream& operator>>(istream& in, Matrix& matrix)
{
	int rows, cols;

	in >> rows >> cols;
	matrix.Reset(rows, cols);
	for (size_t i = 0; i < matrix.GetNumRows(); i++)
	{
		for (size_t j = 0; j < matrix.GetNumColumns(); j++)
		{
			in >> matrix.At(i, j);
		}
	}

	return in;
}