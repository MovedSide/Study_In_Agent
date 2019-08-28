#include<iostream>
#include<stdio.h>


class numb
{
private:
	int n1, n2;
public:
	numb();
	numb(int a, int b);
	void show_numb();
	
	numb operator+(const numb& t);
	numb operator+=(const numb& t);

};
numb::numb()
{
	this->n1 = 0;
	this->n2 = 0;
}
numb::numb(int a, int b)
{
	this->n1 = a;
	this->n2 = b;
}
numb numb::operator+(const numb& t)
{
	numb tmp(this->n1 + t.n1, this->n2 + t.n2);
	return tmp;
}
numb numb::operator+=(const numb& t)
{
	numb tmp(0, 0);
	*this = *this + t;
	return tmp;
}
void numb::show_numb()
{
	std::cout << "n1 = " << this->n1 << std::endl;
	std::cout << "n2 = " << this->n2 << std::endl;
}
int main()
{
	numb a(1, 1);
	numb b(2, 4);
	numb c;
	a += b;
	a.show_numb();
	b.show_numb();
	return 0;
}