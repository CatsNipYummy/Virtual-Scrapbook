#include <iostream>
#include <octave/oct.h>
#include <octave/dMatrix.h>

 int main()
 {
	ComplexMatrix A,B,A1;
	A = ComplexMatrix (8,8);
	A1 = ComplexMatrix (8,8);
	B = ComplexMatrix (8,1);
	
	float x0,x1,x2,x3,y0,y1,y2,y3,W,H;
	std::cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3>>W>>H;
	A(0,0)=x0;
	A(0,1)=y0;
	A(0,2)=1;
	A(0,3)=0;
	A(0,4)=0;
	A(0,5)=0;
	A(0,6)=0;
	A(0,7)=0;
	A(1,0)=x1;
	A(1,1)=y1;
	A(1,2)=1;
	A(1,3)=0;
    A(1,4)=0;
    A(1,5)=0;
    A(1,6)=-(W*x1);
    A(1,7)=-(W*y1);
    A(2,0)=x2;
    A(2,1)=y2;
    A(2,2)=1;
    A(2,3)=0;
    A(2,4)=0;
    A(2,5)=0;
    A(2,6)=-(W*x2);
    A(2,7)=-(W*y2);
    A(3,0)=x3;
    A(3,1)=y3;
    A(3,2)=1;
    A(3,3)=0;
    A(3,4)=0;
    A(3,5)=0;
    A(3,6)=0;
    A(3,7)=0;
    A(4,0)=0;
    A(4,1)=0;
    A(4,2)=0;
    A(4,3)=x0;
    A(4,4)=y0;
    A(4,5)=1;
    A(4,6)=0;
    A(4,7)=0;
    A(5,0)=0;
    A(5,1)=0;
    A(5,2)=0;
    A(5,3)=x1;
    A(5,4)=y1;
    A(5,5)=1;
    A(5,6)=0;
    A(5,7)=0;
    A(6,0)=0;
    A(6,1)=0;
    A(6,2)=0;
    A(6,3)=x2;
    A(6,4)=y2;
    A(6,5)=1;
    A(6,6)=-(H*x2);
    A(6,7)=-(H*y2);
    A(7,0)=0;
    A(7,1)=0;
    A(7,2)=0;
    A(7,3)=x3;
    A(7,4)=y3;
    A(7,5)=1;
    A(7,6)=-(H*x3);
    A(7,7)=-(H*y3);

	std::cout<<"\n The Matrix Is:\n"<<A;
	
	A1 = A.inverse();
	
	std::cout<<"\n The Inverse Is:\n"<<A1;
	
	B(0,0)=0;
	B(1,0)=W;
	B(2,0)=W;
	B(3,0)=0;
	B(4,0)=0;
	B(5,0)=0;
	B(6,0)=H;
	B(7,0)=H;
	
	std::cout<<"\n"<<A1*B;

	
}
