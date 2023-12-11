// main program

#include<iostream>
#include<string>
#include "QuadEq.hpp"

int main() {

	// variable for holding the different types of roots and types of equation

	const std::string equation_types[] {"One real root", "two real roots", "Linear Equation", "Unknown Type of Equation"};

	// user input

	std::cout<<"Enter the coefficients of the quadratic: a, b & c"<<"\n";

	double a{0.0}, b{0.0}, c{0.0};

	std::cin>> a >> b >> c;

	// make an equation

	Quadratic equation(a, b, c);

	// variables for the roots

	double x1{0.0}, x2{0.0};

	//-- equation types

	Quadratic::EquationType equation_type{};

	// error checking

	try {

		equation_type = equation.GetRoots(x1, x2);
	}

	catch (const std::exception& equation) {

		std::cerr<<equation.what()<<"\n";

		// failed

		return -1;
	}

	// no errors found from try-catch block; print results

	std::cout<<equation_types[static_cast<int> (equation_type)];

	// if roots exist, print them out

	switch (equation_type) {

	// one real root: perfect square/bounded root

	case Quadratic::EquationType::one_real_roots:

		std::cout<<": "<<x1<<"\n";
		break;

	// two real root

	case Quadratic::EquationType::two_real_roots:

		std::cout<<": "<<x1<<", "<<x2<<"\n";
		break;

	default:

		break;

	}

	//end of program; everything OK

	return 0;


}
