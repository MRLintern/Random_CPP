// driver for the quadratic solver

#include<cmath>
#include "QuadEq.hpp"

/*

function checks the type of equation

input: discriminant = b**2 - 4*a*c

output: exact equation type represented by the coefficients

*/

Quadratic::EquationType Quadratic::GetNumOfRoots(const double discriminant) const
{
	if (coefficient_a == 0.0) {

		return coefficient_b == 0.0 ? EquationType::unknown_equation_type : EquationType::linear_equation;
	}
	else {

		if (discriminant < 0.0) {

			return EquationType::no_real_roots;
		}
		else {

			return discriminant == 0.0 ? EquationType::one_real_roots : EquationType::two_real_roots;
		}
	}
}

/*

function to calculate the roots of the equation

input: 

Root_1: an object which references root 1 if linear_equation, one_real_roots or two_real_roots

Root_2: an object which references root 2 if one_real_roots or two_real_roots.
Note: if Root_2 has one_real_roots, then one_real_roots = two_real_roots (AKA bounded roots) => perfect square.

output: number of roots

*/

Quadratic::EquationType Quadratic::GetRoots(double& root_1, double& root_2) const
{
	//constructor for built-in type

	auto discriminant(CalcDiscriminant());

	//enumerator which will hold the roots

	EquationType EquationTypeFlag = GetNumOfRoots(discriminant);

	// division threshold

	const double DivisionThreshold{1e-36};

	//different equation types due to the nature of the roots

	switch (EquationTypeFlag)
	{
		//cases where the equation is an unknown type or possibly complex

	case EquationType::unknown_equation_type:
	case EquationType::no_real_roots:

		break;

		//linear equation

	case EquationType::linear_equation:

		assert(coefficient_a == 0.0);
		assert(std::fabs(coefficient_b) > DivisionThreshold);

		if (std::fabs(coefficient_b) < DivisionThreshold) {

			throw std::overflow_error("Coefficient b of linear equation is too small");
		}

		//perfect square/bounded roots

		root_1 = root_2 =- coefficient_c/coefficient_b;

		break;

	// one solution	

	case EquationType::one_real_roots:

	// two solutions; or rather, theres two roots to the quadratic


   // recall formula for solving quadratic:  x = (-b +- sqrt(b^2 - 4ac))/2a; or, x = -b +- (sqrt(discriminant))/2a.

	case EquationType::two_real_roots:
	{

		//check that the discriminant is greater than (or equal to 0) for two roots to exist

		assert(discriminant >= 0.0); 

		// square-root of discriminant

		double discriminant_square_root {std::sqrt(discriminant)};

		// again refer to the quadratic formula

		double denominator {2.0*coefficient_a};

		// check denominator is greater than the division threshold

		assert(std::fabs(denominator) > DivisionThreshold);

		// if the above isn't true

		if (std::fabs(denominator) < DivisionThreshold) {

			throw std::overflow_error("Coefficient a of the Quadratic is too low");
		}

		// if assertion passes, calculate the two (real) roots

		root_1 = (-coefficient_b - discriminant_square_root)/denominator;
		root_2 = (-coefficient_b + discriminant_square_root)/denominator;


		}

		break;

	default:

	// if all fails...

	assert(false);

	break;

	}

	return EquationTypeFlag;
	
}

// -- input/output operations

// output

std::ostream& operator << (std::ostream& output, const Quadratic& equation) {

	output << equation.Get_coefficient_a() << " " << equation.Get_coefficient_b() << " " << equation.Get_coefficient_c() << "\n";

	return output;
}

// input

std::istream& operator >> (std::istream& input, Quadratic& equation) {

	// user input variable

	double user_input{0.0};

	input >> user_input; equation.Set_coefficient_a(user_input);
	input >> user_input; equation.Set_coefficient_b(user_input);
	input >> user_input; equation.Set_coefficient_c(user_input);

	return input;
}



