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

#include "dictionary.H"
#include "primitiveEntry.H"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
T Foam::dictionary::lookupOrDefault
(
    const word& keyword,
    const T& deflt,
    bool recursive,
    bool patternMatch
) const
{
    const entry* entryPtr = lookupEntryPtr(keyword, recursive, patternMatch);

    if (entryPtr)
    {
        return pTraits<T>(entryPtr->stream());
    }
    else
    {
        return deflt;
    }
}


template<class T>
T Foam::dictionary::lookupOrAddDefault
(
    const word& keyword,
    const T& deflt,
    bool recursive,
    bool patternMatch
)
{
    const entry* entryPtr = lookupEntryPtr(keyword, recursive, patternMatch);

    if (entryPtr)
    {
        return pTraits<T>(entryPtr->stream());
    }
    else
    {
        add(new primitiveEntry(keyword, deflt));
        return deflt;
    }
}


template<class T>
bool Foam::dictionary::readIfPresent
(
    const word& k,
    T& val,
    bool recursive,
    bool patternMatch
) const
{
    const entry* entryPtr = lookupEntryPtr(k, recursive, patternMatch);

    if (entryPtr)
    {
        entryPtr->stream() >> val;
        return true;
    }
    else
    {
        return false;
    }
}


template<class T>
void Foam::dictionary::add(const keyType& k, const T& t, bool overwrite)
{
    add(new primitiveEntry(k, t), overwrite);
}


template<class T>
void Foam::dictionary::set(const keyType& k, const T& t)
{
    set(new primitiveEntry(k, t));
}


// ************************************************************************* //
