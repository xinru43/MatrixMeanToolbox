/*
This file defines the class for 
min_{X \in S^{n-1}} tr((X.^2)^T W^T P W (X.^2)), where P is a N by N symmetric positive definite matrix
and W is a N by n matrix.

Problem --> SphereConvexHull

---- WH
*/

#ifndef SPHEREHESSIANSTEINMIN_H
#define SPHEREHESSIANSTEINMIN_H

#include "Sphere.h"
#include "SphereVariable.h"
#include "SphereVector.h"
#include "Problem.h"
#include "SharedSpace.h"
#include "def.h"
#include "MyMatrix.h"


/*Define the namespace*/
namespace ROPTLIB{

	class SphereHessianSteinMin : public Problem{
	public:
		/*W is an array of vectors, which are tangent vectors in the tangent space at x, lengthW is the length of W.
		HvRBFGSSub defines a linear mapping: P: v --> Pv. The manifold, Mani, of x and W is not necessary the same as the domain of this problem.*/
		SphereHessianSteinMin(double *inCs, double *inDs, integer inn, integer innum);
		virtual ~SphereHessianSteinMin();
		virtual double f(Variable *x) const;

		virtual void EucGrad(Variable *x, Vector *egf) const;
		virtual void EucHessianEta(Variable *x, Vector *etax, Vector *exix) const;
        
        double *Cs;
		double *Ds;
		integer n;
		integer num;
	};

}; /*end of ROPTLIB namespace*/
#endif // end of GRASSRQ_H
