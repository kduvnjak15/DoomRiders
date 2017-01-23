#include <iostream>

class A
{
public: 
	void name()
	{
		std::cout<<" class A"<<std::endl; 
	}
}; 

class B : public A
{
public: 
	void name()
	{
		std::cout<<" Class B" <<std::endl;
	}
}; 

int main()
{

	A* bar = new B(); 
	bar->name(); 

return 0; 
}

