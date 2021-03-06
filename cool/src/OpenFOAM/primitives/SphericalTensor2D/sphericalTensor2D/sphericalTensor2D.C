/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

\*---------------------------------------------------------------------------*/

#include "sphericalTensor2D.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

template<>
const char* const sphericalTensor2D::typeName = "sphericalTensor2D";

template<>
const char* sphericalTensor2D::componentNames[] = {"ii"};

template<>
const sphericalTensor2D sphericalTensor2D::zero(0);

template<>
const sphericalTensor2D sphericalTensor2D::one(1);

template<>
const sphericalTensor2D sphericalTensor2D::max(VGREAT);

template<>
const sphericalTensor2D sphericalTensor2D::min(-VGREAT);

template<>
const sphericalTensor2D sphericalTensor2D::I(1);

template<>
const sphericalTensor2D sphericalTensor2D::oneThirdI(1.0/3.0);

template<>
const sphericalTensor2D sphericalTensor2D::twoThirdsI(2.0/3.0);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
