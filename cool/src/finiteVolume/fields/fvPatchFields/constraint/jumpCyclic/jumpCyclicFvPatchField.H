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

Class
    Foam::jumpCyclicFvPatchField

Description
    Foam::jumpCyclicFvPatchField

SourceFiles
    jumpCyclicFvPatchField.C

\*---------------------------------------------------------------------------*/

#ifndef jumpCyclicFvPatchField_H
#define jumpCyclicFvPatchField_H

#include "cyclicFvPatchField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class jumpCyclicFvPatchField Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class jumpCyclicFvPatchField
:
    public cyclicFvPatchField<Type>
{

public:

    //- Runtime type information
    TypeName("jumpCyclic");


    // Constructors

        //- Construct from patch and internal field
        jumpCyclicFvPatchField
        (
            const fvPatch&,
            const DimensionedField<Type, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        jumpCyclicFvPatchField
        (
            const fvPatch&,
            const DimensionedField<Type, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given jumpCyclicFvPatchField onto a new patch
        jumpCyclicFvPatchField
        (
            const jumpCyclicFvPatchField<Type>&,
            const fvPatch&,
            const DimensionedField<Type, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        jumpCyclicFvPatchField
        (
            const jumpCyclicFvPatchField<Type>&
        );

        //- Construct as copy setting internal field reference
        jumpCyclicFvPatchField
        (
            const jumpCyclicFvPatchField<Type>&,
            const DimensionedField<Type, volMesh>&
        );


    // Member functions

        // Access

            //- Return the interface type
            virtual const word& interfaceFieldType() const
            {
                return cyclicFvPatchField<Type>::type();
            }

            //- Return the "jump" across the patch as a "half" field 
            virtual tmp<Field<Type> > jump() const = 0;


        // Evaluation functions

            //- Return neighbour coupled given internal cell data
            virtual tmp<Field<Type> > patchNeighbourField() const;

            //- Update result field based on interface functionality
            virtual void updateInterfaceMatrix
            (
                const scalarField& psiInternal,
                scalarField& result,
                const lduMatrix&,
                const scalarField& coeffs,
                const direction cmpt,
                const Pstream::commsTypes commsType
            ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "jumpCyclicFvPatchField.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
