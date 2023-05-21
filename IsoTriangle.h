// IsoTriangle.h
#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H
#include "polygon.h"
#include <math.h>

using namespace std;
/*! \file IsoTriangle.h
 \brief Declaration of the class IsoTriangle

 Details.
*/

/// @class IsoTriangle
/// @brief to manage an object with the shape of a IsoTriangle
class IsoTriangle : public Polygon
{
private:
    float base, height;
    float Area();
    float Perimeter();


public:

    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    IsoTriangle();
    IsoTriangle(float b, float h);
    IsoTriangle(const IsoTriangle& t);

    ~IsoTriangle();
    /// @}

    /// @name OPERATORS
    /// @{
    IsoTriangle& operator=(const IsoTriangle& t);
    bool operator==(const IsoTriangle& t);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const IsoTriangle& t);
    void Reset();
    /// @}


    /// @name GETTERS / SETTERS
    /// @{
    void SetDim(float b, float h);
    void SetBase(float b);
    void SetHeight(float h);
    void GetDim(float& b, float& h);
    float GetBase();
    float GetSide();
    float GetHeight();

    /// @}

    /// @name DEBUG and SERIALIZATION 
    /// @{
    void ErrorMessage(const char* string);
    void WarningMessage(const char* string);
    void Dump();
    /// @}

    void Draw();
    
    void Update(); //function to update parameters of the objects;

};

#endif

