#include<bits/stdc++.h>
using namespace std;

class Matrix {
	int **p;
	int r, c;
	public:
		Matrix(int row =10, int column = 10){
			r = row;
			c = column;
			p = new int*[r];
			for(int i = 0;i<r;i++)
				p[i] = new int[c];
			for(int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					p[i][j] = 0;
		}

		void initialise() {
			cout<<"Enter the Matrix: "<<endl;
				for(int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						cin>>p[i][j];
		}

		// Addition
		friend Matrix& operator+(Matrix const &A, Matrix const &B){
			static Matrix sum(A.r, A.c);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < A.c; j++)
					sum.p[i][j] = A.p[i][j] + B.p[i][j];
			return sum;
		}
		friend Matrix& operator+(int value, Matrix const &B){
			static Matrix sum(B.r, B.c);
			for(int i = 0; i < B.r; i++)
				for (int j = 0; j < B.c; j++)
					sum.p[i][j] = value + B.p[i][j];
			return sum;
		}
		friend Matrix& operator+(Matrix const &A, int value){
			static Matrix sum(A.r, A.c);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < A.c; j++)
					sum.p[i][j] = A.p[i][j] + value;
			return sum;
		}

		// Subtraction
		friend Matrix& operator-(Matrix const &A, Matrix const &B){
			static Matrix sum(A.r, A.c);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < B.c; j++)
					sum.p[i][j] = A.p[i][j] - B.p[i][j];
			return sum;
		}
		friend Matrix& operator-(int value, Matrix const &B){
			static Matrix sum(B.r, B.c);
			for(int i = 0; i < B.r; i++)
				for (int j = 0; j < B.c; j++)
					sum.p[i][j] = value - B.p[i][j];
			return sum;
		}
		friend Matrix& operator-(Matrix const &A, int value){
			static Matrix sum(A.r, A.c);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < A.c; j++)
					sum.p[i][j] = A.p[i][j] - value;
			return sum;
		}

		// Multplication
		friend Matrix& operator*(Matrix const &A, Matrix const &B){
			static Matrix mul(A.c, B.r);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < B.c; j++){
					int sum = 0;
					for( int k = 0; k < A.c ; k++)
						sum += A.p[i][k]*B.p[k][j];
					mul.p[i][j] = sum;
				}
			return mul;
		}


		// Transpose
		friend Matrix& operator~(Matrix const &A){
			static Matrix transpose(A.c, A.r);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < A.c; j++)
					transpose.p[j][i] = A.p[i][j];
			return transpose;
		}

		// Negation
		friend Matrix& operator!(Matrix const &A){
			static Matrix negation(A.r, A.c);
			for(int i = 0; i < A.r; i++)
				for (int j = 0; j < A.c; j++)
					negation.p[i][j] = -1*A.p[i][j];
			return negation;
		}

		void display() {
			for(int i = 0; i < r; i++){
				for (int j = 0; j < c; j++)
					cout<<p[i][j]<<" ";
				cout<<endl;
			}

		}

		~ Matrix(){
			delete [] p;
		}

};

int main() {
	Matrix m1(3,3);
	m1.initialise();
	Matrix m2(3,3);
	m2.initialise();
	cout<<endl;

	Matrix m3 = m1+m2;
	cout<<"Addition of the Matrices: "<<endl;
	m3.display();
	cout<<endl;	


	cout<<"Subtraction of the Matrices: "<<endl;
	m3 = m1-m2;
	m3.display();
	cout<<endl;

	cout<<"Multiplication of the Matrices: "<<endl;
	m3 = m1*m2;
	m3.display();
	cout<<endl;


	cout<<"Transpose of the Matrix: "<<endl;
	m3 = ~m3;
	m3.display();
	cout<<endl;

	cout<<"Negation of the Matrix: "<<endl;
	m3 = !m3;
	m3.display();
	cout<<endl;
  
	return 0;
}

