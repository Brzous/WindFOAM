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
    Foam::movingConeTopoFvMesh

Description
    Sample topoChangerFvMesh that moves an object in x direction
    and introduces/removes layers.

SourceFiles
    movingConeTopoFvMesh.C

\*---------------------------------------------------------------------------*/

#ifndef movingConeTopoFvMesh_H
#define movingConeTopoFvMesh_H

#include "topoChangerFvMesh.H"
#include "motionSolver.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class movingConeTopoFvMesh Declaration
\*---------------------------------------------------------------------------*/

class movingConeTopoFvMesh
:
    public topoChangerFvMesh
{
    // Private data

        //- Motion dictionary
        dictionary motionDict_;

        //- Motion velocity amplitude
        vector motionVelAmplitude_;

        //- Motion velocity period
        scalar motionVelPeriod_;

        //- Motion velocity period
        vector curMotionVel_;

        //- Left edge
        scalar leftEdge_;

        //- Current left obstacle position
        scalar curLeft_;

        //- Current right obstacle position
        scalar curRight_;

        //- Vertex motion mask
        scalarField motionMask_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        movingConeTopoFvMesh(const movingConeTopoFvMesh&);

        //- Disallow default bitwise assignment
        void operator=(const movingConeTopoFvMesh&);


        //- Add mixer zones and modifiers
        void addZonesAndModifiers();

        //- Markup motion vertices
        tmp<scalarField> vertexMarkup
        (
            const pointField& p,
            const scalar& curLeft,
            const scalar& curRight
        ) const;


public:

    //- Runtime type information
    TypeName("movingConeTopoFvMesh");


    // Constructors

        //- Construct from database
        explicit movingConeTopoFvMesh(const IOobject& io);


    // Destructor

        virtual ~movingConeTopoFvMesh();


    // Member Functions

        //- Update the mesh for both mesh motion and topology change
        virtual bool update();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
