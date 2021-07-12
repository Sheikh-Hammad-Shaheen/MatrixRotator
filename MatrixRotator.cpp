#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void fill_data(int* *&mat, int &row_size,int &col_size)
{
	
	cout << "Enter Row and Column size: ";
	cin >> row_size >> col_size;
	cout << "Fill matrix of " << row_size << "x" << col_size << " : ";
	mat = new int*[row_size];
	for (int i = 0; i < row_size; i++)
	{
		mat[i] = new int[col_size];
		for (int j = 0; j < col_size; j++)
			cin >> mat[i][j];
	}
}
void delete_memory(int* *&data,const int &start,const int &end)
{
	for (int i = start; i<end; i++)
		delete[]data[i];
	if (data != nullptr)
		delete[]data;
	data = nullptr;
}
void display(const int *const *const data, const int &row_size, const int &col_size)
{
	for (int i = 0; i<row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
			cout << setw(3) << data[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}
void menu(void)
{
	cout << "1 for 90-Degree rotate." << endl;
	cout << "2 for 180-Degree rotate." << endl;
	cout << "3 for 270-degree rotate." << endl;
	cout << "Press any key to exit." << endl;
}
void take_transpose(int* *mat, const int &mat_size,const int &col_size)
{
	for (int i = 0; i < mat_size; i++)
	{
		for (int j = i ; j < col_size; j++)
			swap(mat[i][j], mat[j][i]);
	}
}
void reverse_column(int* *mat, const int  &row_size, const int  &col_size)
{
	int end = 0;
	for (int i = 0; i < row_size; i++)
	{
		end = col_size - 1;
		for (int j = 0; j < end; j++)
		{
			swap(mat[i][j], mat[i][end]);
			end--;
		}
	}
}
void rotate_90(int* *mat, const int &row_size, const int &col_size)
{
	take_transpose(mat, row_size, col_size);
	reverse_column(mat,row_size,col_size);
	cout << "Matrix After 90-degree rotate: " << endl;
	display(mat,row_size,col_size);
}
void rotate_180(int* *mat, const int &row_size, const int &col_size)
{
	take_transpose(mat, row_size, col_size);
	reverse_column(mat, row_size, col_size);
	cout << "Matrix After 180-degree rotate: " << endl;
	display(mat, row_size, col_size);
}
void rotate_270(int* *mat, const int &row_size, const int &col_size)
{
	take_transpose(mat, row_size, col_size);
	reverse_column(mat, row_size, col_size);
	cout << "Matrix After 270-degree rotate: " << endl;
	display(mat, row_size, col_size);
}
int main()
{
	int* *mat = nullptr, mat_row = 0,mat_col=0;
	char opt = 0;
	fill_data(mat, mat_row,mat_col);
	cout << "Main Matrix: " << endl;
	display(mat,mat_row,mat_col);
	rotate_90(mat, mat_row, mat_col);
	rotate_180(mat, mat_row, mat_col);
	rotate_270(mat, mat_row, mat_col);
	delete_memory(mat,0,mat_row);
}