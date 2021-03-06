//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// QUESO - a library to support the Quantification of Uncertainty
// for Estimation, Simulation and Optimization
//
// Copyright (C) 2008-2015 The PECOS Development Team
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

#ifndef UQ_SURROGATE_BUILDER_BASE_H
#define UQ_SURROGATE_BUILDER_BASE_H

// C++
#include <vector>

namespace QUESO
{
  class GslVector;

  //! Base class for builders of surrogates
  /*! This class provides the interface to the user's model for which
      we are constructing a surrogate. */
  template<class V = GslVector>
  class SurrogateBuilderBase
  {
  public:

    SurrogateBuilderBase(){};

    virtual ~SurrogateBuilderBase(){};

    virtual void evaluate_model( const V & domainVector, std::vector<double>& values ) =0;

  };

} // end namespace QUESO

#endif // UQ_SURROGATE_BUILDER_BASE_H
