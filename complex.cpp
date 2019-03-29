#include<bits/stdc++.h>
using namespace std;

class Complex {
	float real, img;
	public:
		Complex(float x = 20.0, float y = 10.0){
			real = x;
			img = y;
		}
		friend Complex &operator+(Complex const &complex_1, Complex const &complex_2){
			Complex s;
			s.real = complex_1.real + complex_2.real;
			s.img = complex_1.img + complex_2.img;
			return s;
		}
		friend Complex &operator+(float value, Complex const &complex_2){
			Complex s;
			s.real = value + complex_2.real;
			s.img = complex_2.img;
			return s;
		}
		friend Complex &operator+(Complex const &complex_2, float value){
			Complex s;
			s.real = value + complex_2.real;
			s.img = complex_2.img;
			return s;
		}
		friend Complex &operator-(Complex const &complex_1, Complex const &complex_2){
			Complex s;
			s.real = complex_1.real - complex_2.real;
			s.img = complex_1.img - complex_2.img;
			return s;
		}
		friend Complex &operator-(float value, Complex const &complex_2){
			 Complex s;
			s.real = value - complex_2.real;
			s.img = complex_2.img;
			return s;
		}
		friend Complex &operator-(Complex const &complex_2, float value){
			 Complex s;
			s.real = complex_2.real - value;
			s.img = complex_2.img;
			return s;
		}
		friend Complex &operator*(Complex const &complex_1, Complex const &complex_2){
			 Complex s;
			s.real = complex_1.real*complex_2.real - complex_1.img*complex_2.img;
			s.img = complex_1.real*complex_2.img + complex_1.img*complex_1.real;
			return s;
		}
		friend Complex &operator*(float value, Complex const &complex_2){
			 Complex s;
			s.real = value*complex_2.real;
			s.img = value*complex_2.img;
			return s;
		}
		friend Complex &operator*(Complex const &complex_2, float value){
			 Complex s;
			s.real = value*complex_2.real;
			s.img = value*complex_2.img;
			return s;
		}
		friend float operator~(Complex const &complex_2){
			return sqrt((complex_2.real*complex_2.real) + (complex_2.img*complex_2.img));
		}
		void display() {
			cout<<"Real Part of the Complex Number is: "<<real<<endl;
			cout<<"Imaginary Part of the Complex Number is: "<<img<<endl;
		}		
};

int main() {
	Complex c;
	cout<<"Init with (20 + 10i) "<<endl;
	Complex c1(10.0, 5.0);
	cout<<endl;

	cout<<"Add with (10.0 + 5i)"<<endl;
	Complex s = c+c1;
	s.display();
	cout<<endl;

	cout<<"Add with 10.0"<<endl;
	s = c+10.0;
	s.display();
	cout<<endl;

	cout<<"Subtract by (10.0 + 5i)"<<endl;
	s = c-c1;
	s.display();
	cout<<endl;

	cout<<"Subtract by 10.0"<<endl;
	s = c-10.0;
	s.display();
	cout<<endl;

	float mod = ~s;
	cout<<"Modulus is: "<<mod<<endl;
	cout<<endl;

    // (ac-bd) + i(ad+bc)
	cout<<"Multiply with (10.0 + 5i)"<<endl;
	s = c*c1;
	s.display();
	cout<<endl;
	return 0;
}
