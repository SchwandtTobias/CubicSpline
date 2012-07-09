

#include "core/function.h"

#include "core/matrix.h"

#include <iostream>



class MyFunction : public Core::Math::IFunction1Base
{
public:
    float func(float _Value)
    {
        return _Value * _Value - 1;
    }
};

void TEST_FUNCTION()
{
    MyFunction Function;
    
    std::cout << "Y bei 0: "             << Function.func(0) << std::endl;
    std::cout << "Y' bei 4: "            << Function.func1(4) << std::endl;
    std::cout << "Y'' bei 4: "           << Function.func2(4) << std::endl;
    
    std::cout << "Fläche (0 bis 1): "    << Function.Area(0, 1) << std::endl;
    
    std::cout << "Nullstelle (Newton): " << Function.Root(-5) << std::endl;
    std::cout << "Nullstelle (Bisect): " << Function.Root(0, 5) << std::endl;
    std::cout << "Nullstelle (Regula): " << Function.RootRegula(0, 5) << std::endl;
    std::cout << "Minima: "              << Function.Minima(-5, 5) << std::endl;
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
    
    bool Found;
    
    // Breitensuche
    Found = Matrix.BreathFistSearch(0, 6);
    std::cout << "Breitensuche: " << Found << std::endl;
    
    // Tiefensuche
    Found = Matrix.DepthFirstSearch(0, 4);
    std::cout << "Tiefensuche: " << Found << std::endl;


    Core::Math::CMatrix<int, 3, 3> LRMatrix;

    LRMatrix[0][0] = 3; LRMatrix[0][1] = 2;  LRMatrix[0][2] = 1;
    LRMatrix[1][0] = 6; LRMatrix[1][1] = 6;  LRMatrix[1][2] = 3;
    LRMatrix[2][0] = 9; LRMatrix[2][1] = 10; LRMatrix[2][2] = 6;

    Core::Math::CMatrix<int, 3, 3> LMatrix;
    Core::Math::CMatrix<int, 3, 3> RMatrix;

    LRMatrix.TriangularDecomposition(LMatrix, RMatrix);

    std::cout << "R-Matrix" << std::endl;
    for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < RMatrix.s_MaxNumberOfColumns; ++IndexOfColomnElement)
    {
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < RMatrix.s_MaxNumberOfColumns; ++IndexOfRowElement)
        {
            std::cout << RMatrix[IndexOfColomnElement][IndexOfRowElement] << ";";
        }
        std::cout << std::endl;
    }

    std::cout << "L-Matrix" << std::endl;
    for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < LMatrix.s_MaxNumberOfColumns; ++IndexOfColomnElement)
    {
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < LMatrix.s_MaxNumberOfColumns; ++IndexOfRowElement)
        {
            std::cout << LMatrix[IndexOfColomnElement][IndexOfRowElement] << ";";
        }
        std::cout << std::endl;
    }

    std::cout << "Determinante: " << LRMatrix.Determinate() << std::endl;
}


int main()
{
    TEST_MATRIX();
    
	return 0;
}