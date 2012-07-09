

#include "core/function.h"

#include "core/matrix.h"

#include <iostream>



class MyFunction : public Core::Math::IFunction1Base
{
public:
    float func(float _Value)
    {
        return _Value * _Value;
    }
};

void TEST_FUNCTION()
{
    MyFunction Function;
    
    std::cout << Function.func(0) << std::endl;
    std::cout << Function.func1(4) << std::endl;
    std::cout << Function.func2(4) << std::endl;
    
    std::cout << Function.Area(0, 1) << std::endl;
    
    std::cout << Function.Root(-5) << std::endl;
    std::cout << Function.Minima(-5, 5) << std::endl;
}

void TEST_MATRIX()
{
    Core::Math::CMatrix<float, 8, 8> Matrix;
    
    Matrix[0][0] = 0; Matrix[0][1] = 1; Matrix[0][2] = 0; Matrix[0][3] = 0; Matrix[0][4] = 1; Matrix[0][5] = 1; Matrix[0][6] = 0; Matrix[0][7] = 0;
    Matrix[1][0] = 1; Matrix[1][1] = 0; Matrix[1][2] = 1; Matrix[1][3] = 0; Matrix[1][4] = 0; Matrix[1][5] = 0; Matrix[1][6] = 0; Matrix[1][7] = 0;
    Matrix[2][0] = 0; Matrix[2][1] = 1; Matrix[2][2] = 0; Matrix[2][3] = 1; Matrix[2][4] = 0; Matrix[2][5] = 0; Matrix[2][6] = 1; Matrix[2][7] = 0;
    Matrix[3][0] = 0; Matrix[3][1] = 0; Matrix[3][2] = 1; Matrix[3][3] = 0; Matrix[3][4] = 0; Matrix[3][5] = 0; Matrix[3][6] = 0; Matrix[3][7] = 0;
    Matrix[4][0] = 1; Matrix[4][1] = 0; Matrix[4][2] = 0; Matrix[4][3] = 0; Matrix[4][4] = 0; Matrix[4][5] = 0; Matrix[4][6] = 0; Matrix[4][7] = 0;
    Matrix[5][0] = 1; Matrix[5][1] = 0; Matrix[5][2] = 0; Matrix[5][3] = 0; Matrix[5][4] = 0; Matrix[5][5] = 0; Matrix[5][6] = 1; Matrix[5][7] = 1;
    Matrix[6][0] = 0; Matrix[6][1] = 0; Matrix[6][2] = 1; Matrix[6][3] = 0; Matrix[6][4] = 0; Matrix[6][5] = 1; Matrix[6][6] = 0; Matrix[6][7] = 1;
    Matrix[7][0] = 0; Matrix[7][1] = 0; Matrix[7][2] = 0; Matrix[7][3] = 0; Matrix[7][4] = 0; Matrix[7][5] = 1; Matrix[7][6] = 1; Matrix[7][7] = 0;
    
    bool Gefunden;
    
    // Breitensuche
    Gefunden = Matrix.BreathFistSearch(0, 6);
    std::cout << "Breitensuche: " << Gefunden << std::endl;
    
    // Tiefensuche
    Gefunden = Matrix.DepthFirstSearch(0, 4);
    std::cout << "Tiefensuche: " << Gefunden << std::endl;
}


int main()
{
    TEST_MATRIX();
    
	return 0;
}