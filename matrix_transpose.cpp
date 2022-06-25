#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class array
{
	
	int m[4][4] = {};
	int size;
public:
	//setting 2D array
	array()
	{
		size = 4;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m[i][j] = 0;
			}
		}
	}
	//matrix initialization
	void initialize()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m[i][j] = rand() % 50;
			}
		}
	}
	//print function
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[ ";
			for (int j = 0; j < size; j++)
			{
				cout << m[i][j] << " ";
			}
			cout << " ]" << endl;
		}
	}
	// printing transpose
	void transpose()
	{
		int trans_m[4][4] = {};

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				trans_m[i][j] =m[j][i];
			}
		}
		for (int i = 0; i < size; i++)
		{
			cout << "[ ";
			for (int j = 0; j < size; j++)
			{
				cout << trans_m[i][j] << " ";
			}
			cout << " ]" << endl;
		}
	}
	//symmetry checking function
	bool isSymmetry()
	{
		int trans_m[4][4] = {};
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				trans_m[i][j] = m[j][i];
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (trans_m[i][j] == m[i][j])
				{
					counter = counter ;
				}
				else
				{
					counter++;
				}
			}
		}
		if (counter = 0)
			return true;
		else
			return false;

	}
	//multiplication of matrices
	array multiply(array obj1, array obj2)
	{
		int m1[4][4] = {};
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m1[i][j] = 0;
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++) 
				{
					m1[i][j] = m1[i][j] + obj1.m[i][k] * obj2.m[k][j];
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			cout << "[ ";
			for (int j = 0; j < size; j++)
			{
				cout << m1[i][j] << " ";
			}
			cout << " ]" << endl;
		}
		return obj1;
	}


};
int main()
{
	array m1;
	array m2;
	
	m1.initialize(); cout << endl;
	
	m2.initialize(); cout << endl;
	cout << "Your matrix 1 is : " << endl;
	m1.print();
	cout << endl;
	cout << "Your matrix 2 is : "; cout << endl;
	m2.print();
	cout << "The transpose of matrix 1: "; cout << endl;
	m1.transpose(); cout << endl;
	cout << "The transpose of matrix 2: "; cout << endl;
	m2.transpose();
	cout << " Matrix 1 symmetry : "; cout << endl;
	cout << m1.isSymmetry(); cout << endl;
	cout << "Matrix 2 symmetry : "; cout << endl;
	cout << m2.isSymmetry(); cout << endl;

	m1.multiply(m1, m2);

	system("pause");
	return 0;
}
