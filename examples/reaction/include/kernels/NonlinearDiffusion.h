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

#ifndef NONLINEARDIFFUSION_H
#define NONLINEARDIFFUSION_H

// Including the "Diffusion" Kernel here so we can extend it
#include "Kernel.h"

class NonlinearDiffusion;

template<>
InputParameters validParams<NonlinearDiffusion>();

/**
 * Represents K/mu * grad_u * grad_phi
 *
 * We are inheriting from Diffusion instead of from Kernel because
 * the grad_u * grad_phi is already coded in there and all we
 * need to do is specialize that calculation by multiplying by K/mu
 */
class NonlinearDiffusion : public Kernel
{
public:
  NonlinearDiffusion(const InputParameters & parameters);
  virtual ~NonlinearDiffusion();

protected:
  /**
   * Kernels _must_ override computeQpResidual()
   */
  virtual Real computeQpResidual() override;

  /**
   * This is optional (but recommended!)
   */
  virtual Real computeQpJacobian() override;

  /// Will be set from the input file
  Real _constant;
};


#endif // NONLINEARDIFFUSION_H
