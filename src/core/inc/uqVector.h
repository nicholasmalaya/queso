//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// QUESO - a library to support the Quantification of Uncertainty
// for Estimation, Simulation and Optimization
//
// Copyright (C) 2008,2009,2010 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, 
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
// 
// $Id$
//
//--------------------------------------------------------------------------

#ifndef __UQ_VECTOR_H__
#define __UQ_VECTOR_H__

#include <uqEnvironment.h>
#include <Epetra_Map.h>
#include <gsl/gsl_randist.h>
#include <iostream>

class uqVectorClass
{
public:
           uqVectorClass();
           uqVectorClass(const uqBaseEnvironmentClass& env, const Epetra_Map& map);
           uqVectorClass(const uqVectorClass& rhs);
  virtual ~uqVectorClass();

  uqVectorClass& operator=(const uqVectorClass& rhs);
  uqVectorClass& operator*=(double a);
  uqVectorClass& operator/=(double a);
  uqVectorClass& operator+=(const uqVectorClass& rhs);
  uqVectorClass& operator-=(const uqVectorClass& rhs);

    const uqBaseEnvironmentClass& env                 ()           const;
    const Epetra_Map&             map                 ()           const;
          unsigned int            numOfProcsForStorage()           const;
          void                    setPrintHorizontally(bool value) const; // Yes, 'const'
          bool                    getPrintHorizontally()           const;
          void                    setPrintScientific  (bool value) const; // Yes, 'const'
          bool                    getPrintScientific  ()           const;

  virtual unsigned int            sizeLocal           () const = 0;
  virtual unsigned int            sizeGlobal          () const = 0;
  virtual void                    cwSet               (double value) = 0;
  virtual void                    cwSetGaussian       (const gsl_rng* rng, double mean, double stdDev) = 0;
  virtual void                    cwInvert            () = 0;
  virtual void                    sort                () = 0;
  virtual void                    print               (std::ostream& os) const = 0;

protected:
  virtual void                    copy                (const uqVectorClass& src);

  const uqBaseEnvironmentClass& m_env;
  const Epetra_Map&             m_map;
  mutable bool                  m_printHorizontally;
  mutable bool                  m_printScientific;
};

#endif // __UQ_VECTOR_H__