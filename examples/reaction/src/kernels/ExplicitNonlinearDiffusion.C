/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "ExplicitNonlinearDiffusion.h"


template<>
InputParameters validParams<ExplicitNonlinearDiffusion>()
{
  // Start with the parameters from our parent
  InputParameters params = validParams<Kernel>();


  // Now add any extra parameters this class needs:


  return params;
}


ExplicitNonlinearDiffusion::ExplicitNonlinearDiffusion(const InputParameters & parameters) :
    Kernel(parameters)
{
}

ExplicitNonlinearDiffusion::~ExplicitNonlinearDiffusion()
{
}

Real
ExplicitNonlinearDiffusion::computeQpResidual()
{
  // (u * grad_u + grad_u * phi) * _grad_test
	return   _u[_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
ExplicitNonlinearDiffusion::computeQpJacobian()
{
  // u' * grad_u + u* grad_u'
  return  (_phi[_j][_qp] * _grad_u[_qp] + _u[_qp] * _grad_phi[_j][_qp] ) * _grad_test[_i][_qp];
}
