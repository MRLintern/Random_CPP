/*

class for solving the quadratic equation (2nd order polynomial): P2(x) = 0

a*x**2 + b*x + c = 0

*/

#pragma once

#include<iostream>
#include<cassert>

class Quadratic
{
	//coefficients of the quadratic equation

private:

	double coefficient_a{}, coefficient_b{}, coefficient_c{};

public:

	//default constructor

	Quadratic() : coefficient_a{0.0}, coefficient_b{0.0}, coefficient_c{0.0}

	{}

	//parametric constructor; coefficients to be initialised

	Quadratic(double a, double b, double c) : coefficient_a{a}, coefficient_b{b}, coefficient_c{c}

	{}

	//--Getters and Setters

	//read all or selected coefficients

	double Get_coefficient_a() const {return coefficient_a;}
	double Get_coefficient_b() const {return coefficient_b;}
	double Get_coefficient_c() const {return coefficient_c;}

	//initialise coefficients

	void Set_coefficient_a(double a) {coefficient_a = a;}
	void Set_coefficient_b(double b) {coefficient_b = b;}
	void Set_coefficient_c(double c) {coefficient_c = c;}

	/*

	functions to calculate the discriminant of the quadratic:

	discriminant = b**2 - 4*a*c

	*/

	double CalcDiscriminant() const {return coefficient_b*coefficient_b - 4*coefficient_a*coefficient_c;}

	/*

	classify the equation type: quadratic with 1 or 2 real roots, complex with no real roots, a linear equation
	where a = 0 or an equation which isn't a 1st or 2nd order equation

	*/

	enum class EquationType {no_real_roots, one_real_roots, two_real_roots, linear_equation, unknown_equation_type};

	//a function to check equation type

	virtual EquationType GetNumOfRoots(const double discriminant) const;

	/*

	function to calculate the roots of the equation:

	Root_1: reference to object root_1 which has: one_real_roots, two_real_roots or linear_equation

	Root_2: reference to object root_2 which has: one_real_roots or two_real_roots; 
	Note: if Root_2 has one_real_roots, then one_real_roots = two_real_roots => perfect square.

	*/

	EquationType GetRoots(double& Root_1, double& Root_2) const;

};

//--Input/Output operations
std::ostream& operator << (std::ostream& output, const Quadratic& equation);
std::istream& operator >> (std::istream& input, Quadratic& equation);