#include <iostream>

using namespace std;

/*
Darren Sweeney.
Demonstrating Cramer's Rule.

Order of matrix representation:
0 1 2
3 4 5
6 7 8
*/

// Note: Uses the + - + sign pattern for the terms in the expansion.
// Find the determinate of a 3x3 Matrix.
int determinateOfMatrix(int matrix[9])
{
	return matrix[0] * ((matrix[4] * matrix[8]) - (matrix[5] * matrix[7])) -
		matrix[3] * ((matrix[1] * matrix[8]) - (matrix[2] * matrix[7])) +
		matrix[6] * ((matrix[1] * matrix[5]) - (matrix[2] * matrix[4]));
}

void main(int argc, char* argv[])
{
	cout << "Please enter 3 eqations in the form x y z b\nE.g 2 1 1 0 which represents 2x + 1y + 1z = 0\n" << endl;

	int matrix[12];

	int element;
	for (int i = 0; i < 12; i++)
	{
		cin >> element;
		matrix[i] = element;
	}
	cout << "\n";

	int matrix_D[9]{ matrix[0], matrix[1] , matrix[2],
		matrix[4] , matrix[5] , matrix[6] ,
		matrix[8] , matrix[9] , matrix[10] };
	int deter_D = determinateOfMatrix(matrix_D);

	int matrix_Dx[9]{ matrix[3], matrix[1] , matrix[2],
		matrix[7] , matrix[5] , matrix[6] ,
		matrix[11] , matrix[9] , matrix[10] };
	int deter_Dx = determinateOfMatrix(matrix_Dx);

	int matrix_Dy[9]{ matrix[0], matrix[3] , matrix[2],
		matrix[4] , matrix[7] , matrix[6] ,
		matrix[8] , matrix[11] , matrix[10] };
	int deter_Dy = determinateOfMatrix(matrix_Dy);

	int matrix_Dz[9]{ matrix[0], matrix[1] , matrix[3],
		matrix[4] , matrix[5] , matrix[7] ,
		matrix[8] , matrix[9] , matrix[11] };
	int deter_Dz = determinateOfMatrix(matrix_Dz);

	cout << "determinate D = " << deter_D << endl;
	cout << "determinate Dx = " << deter_Dx << endl;
	cout << "determinate Dy = " << deter_Dy << endl;
	cout << "determinate Dz = " << deter_Dz << "\n" << endl;

	if (deter_D != 0)
	{
		int x = deter_Dx / deter_D;
		int y = deter_Dy / deter_D;
		int z = deter_Dz / deter_D;


		cout << "Answere is (" << x << "," << y << "," << z << ")" << endl;
	}
	else
		cout << "Your equation can not be solved with Cramer's Rule\n" << endl;
}