// lab_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "vector.hpp"
#include "codes.h"
#include <malloc.h>
#include <iostream>
#include <array>
#include <stack>

int main(int argc, char* argv[])
{
    Vector<double> initializing = { 5, 2, 15 };
    const Vector<int> constVect = { 0, 1, 2, 3, 4 };
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(3, 6.66, 7.5, 8.6);
    Vector<double> emptyVector(0);
    Vector<double> begendcntExample(lenFillExample.begin(), lenFillExample.end(), 3);
    Vector<double> begendExample(lenFillExample.begin() + 1, lenFillExample.end());
    Vector<double> begExample(lenFillExample.begin(), 2);
    std::array<double, 3> arr = { 1, 2, 3 };
    Vector<double> vecArr(arr);

    Iterator<double> f = vecArr.begin();
    ConstIterator<double> cf = ConstIterator(f);
    /*emptyVector + 2;
    emptyVector - 2;
    emptyVector * 2;
    emptyVector / 2;*/
    Vector<double> r1(constVect);

    cout << "---------------Vectors (Construction)-------------" << endl;
    cout << "  Vector with initialization: " << initializing << endl;
    cout << "  Vector with a given length " << lenExample << endl;
    cout << "  Vector of a given length with initialization: " << lenFillExample << endl;
    cout << "  Vector with (begin-end-cnt): " << begendcntExample << endl;
    cout << "  Vector with (begin-end): " << begendExample << endl;
    cout << "  Vector with (begin-cnt): " << begExample << endl;
    cout << "  Vector based on container (std::array): " << vecArr << endl;
    cout << "  Empty vector: " << emptyVector << endl << endl;

    Vector<int> vecInit = { 1, 2, 3 };
    Vector<int> vec2 = { 1, 2, 3 };
    Vector<double> vec1 = { 3, 2, 1 };
    cout << "---------------Vectors (Assignment)-------------" << endl;
    cout << "  Vector1 = Vector2 (copy): " << vec2 << "=" << vec1 << endl;
    vec2 = vec1;
    cout << "  Vector1 = " << vec2 << endl;
    vec2 = vecInit;
    cout << "  Vector1 = Vector2 (redirect): " << vec2 << "=" << vec1 << endl;
    vec2 = std::move(vec1);
    cout << "  Vector1 = " << vec2 << endl;
    vec2 = arr;
    cout << "  Vector1 = array: " << vec2 << endl << endl;
    

    Vector<double> operVecF = { 4, 2, 4 };
    Vector<double> operVecS = { 3, 1, 5 };

    cout << "---------------Vectors (Checks)-------------" << endl;
    cout << "   Is the vector zero: " << initializing << " => " << initializing.IsZero() << endl;
    cout << "   Is a single vector: " << initializing << " => " << initializing.IsSingle() << endl;
    cout << "   Normalization of the vector: " << operVecS << "=>" << operVecS.GetSingle() << endl;
    cout << "   Size vector: " << initializing << " => " << initializing.GetSize() << endl;
    cout << "   Vector length: " << initializing << " => " << initializing.GetLength() << endl;
    cout << "   Angle between vectors: " << lenFillExample << " and " << initializing << " => " << lenFillExample.GetAngleBetweenVectors(initializing) << endl << endl;

    cout << "---------------Vectors (Gets and Sets)-------------" << endl;
    cout << "   Setting the second element to 10: " << initializing.SetItem(1, 10) << endl;
    cout << "   The second element of the vector: " << initializing.GetItem(1) << endl;
    cout << "   The second element of the constant vector: " << constVect.GetItem(1) << endl;
    initializing[1] = 1;
    cout << "   Setting the second element to 1: " << initializing[1] << endl << endl;

    cout << "---------------Vectors (Operations)-------------" << endl;
    cout << "1. vector + vector:" << endl;
    cout << "   Vectors +: " << operVecF << " + " << operVecS << " = " << operVecF + operVecS << endl;
    cout << "   Vectors +: " << operVecF << ".sum(" << operVecS << ") = " << operVecF.sum(operVecS) << endl;
    cout << "   Vectors +=: " << operVecF << " += " << operVecS << " => " << (operVecF += operVecS) << endl;
    cout << "   Vectors +=: " << operVecF << ".sumEqual(" << operVecS << ") => " << operVecF.SumEqual(operVecS) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "   vector + number:" << endl;
    int sumNumber = 10;
    cout << "   Vectors +: " << operVecF << " + " << sumNumber << " = " << operVecF + sumNumber << endl;
    cout << "   Vectors +: " << operVecF << ".sumNum(" << sumNumber << ") = " << operVecF.SumNum(sumNumber) << endl;
    cout << "   Num +: " << 3 << " + " << constVect << " = " << 3 + constVect << endl;
    cout << "   Vectors +=: " << operVecF << " += " << sumNumber << " => " << (operVecF += sumNumber) << endl;
    cout << "   Vectors +=: " << operVecF << ".sumNumEqual(" << sumNumber << ") => " << operVecF.SumNumEqual(sumNumber) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "2. vector - vector:" << endl;
    cout << "   Vectors -: " << operVecF << " - " << operVecS << " = " << operVecF - operVecS << endl;
    cout << "   Vectors -: " << operVecF << ".sub(" << operVecS << ") = " << operVecF.Sub(operVecS) << endl;
    cout << "   Vectors -=: " << operVecF << " -= " << operVecS << " => " << (operVecF -= operVecS) << endl;
    cout << "   Vectors -=: " << operVecF << ".subEqual(" << operVecS << ") => " << operVecF.SubEqual(operVecS) << endl << endl;

    cout << "   vector - number:" << endl;
    cout << "   Vectors -: " << operVecF << " - " << sumNumber << " = " << operVecF - sumNumber << endl;
    cout << "   Vectors -: " << operVecF << ".subNum(" << sumNumber << ") = " << operVecF.SubNum(sumNumber) << endl;
    cout << "   Num -: " << 3 << " - " << constVect << " = " << 3 - constVect << endl;
    cout << "   Vectors -=: " << operVecF << " -= " << sumNumber << " => " << (operVecF -= sumNumber) << endl;
    cout << "   Vectors -=: " << operVecF << ".subNumEqual(" << sumNumber << ") => " << operVecF.SumNumEqual(sumNumber) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "3. Scalar Multiplication:" << endl;
    cout << "   Vectors * : " << operVecF << " * " << operVecS << " = " << operVecF * operVecS << endl;
    cout << "   Vectors * : " << operVecF << ".scalarMul(" << operVecS << ") = " << operVecF.ScalarMul(operVecS) << endl;
    cout << "   Vectors *=: " << operVecF << " *= " << operVecS << " => " << (operVecF *= operVecS) << endl;
    cout << "   Vectors *=: " << operVecF << ".scalarMulEqual(" << operVecS << ") => " << operVecF.ScalarMulEqual(operVecS) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "4. vector * number:" << endl;
    int multyNumber = 2;
    cout << "   Vectors *: " << operVecF << " * " << multyNumber << " = " << operVecF * multyNumber << endl;
    cout << "   Vectors *: " << operVecF << ".mulNum(" << multyNumber << ") = " << operVecF.MulNum(multyNumber) << endl;
    cout << "   Num *: " << 3 << " * " << constVect << " = " << 3 * constVect << endl;
    cout << "   Vectors *=: " << operVecF << " *= " << multyNumber << " => " << (operVecF *= multyNumber) << endl;
    cout << "   Vectors *=: " << operVecF << ".mulNumEqual(" << multyNumber << ") => " << operVecF.MulNumEqual(multyNumber) << endl << endl;

    operVecF = { 4, 2, 4 };
    Vector<double> vc1 = { 1, 2, 3, 4, 5 };
    Vector<double> vc2 = { 5, 2, 3, 1, 5 };
    Vector<double> vc3 = { 5, 2, 3, 1, 5, 4, 2 };
    Vector<double> vc4 = { 5, 2, 3, 1, 9, 0, 1 };
    cout << "5. Vector Multiplication:" << endl;
    cout << "   Vectors &: " << operVecF << " & " << operVecS << " = " << (operVecF & operVecS) << endl;
    cout << "   Vectors &: " << operVecF << ".vectorMul(" << operVecS << ") = " << operVecF.VectorMul(operVecS) << endl;
    cout << "   Vectors &(x5): " << vc1 << " & " << vc2 << " = " << (vc1 & vc2) << endl;
    cout << "   Vectors &(x7): " << vc3 << " & " << vc4 << " = " << (vc3 & vc4) << endl;
    cout << "   Vectors &=: " << operVecF << " &= " << operVecS << " => " << (operVecF &= operVecS) << endl;
    cout << "   Vectors &=: " << operVecF << ".vectorMulEqual(" << operVecS << ") => " << operVecF.VectorMulEqual(operVecS) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "6. vector(elems) * vector(elems):" << endl;
    cout << "   Vectors ^: " << operVecF << " ^ " << operVecS << " = " << (operVecF ^ operVecS) << endl;
    cout << "   Vectors ^: " << operVecF << ".mulElems(" << operVecS << ") = " << operVecF.MulElems(operVecS) << endl;
    cout << "   Vectors ^=: " << operVecF << " ^= " << operVecS << " => " << (operVecF ^= operVecS) << endl;
    cout << "   Vectors ^=: " << operVecF << ".mulElemsEqual(" << operVecS << ") => " << operVecF.MulElemsEqual(operVecS) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "7. vector / number:" << endl;
    int divNum = 2;
    cout << "   Vectors /: " << operVecF << " / " << divNum << " = " << operVecF / divNum << endl;
    cout << "   Vectors /: " << operVecF << ".divNum(" << divNum << ") = " << operVecF.DivNum(divNum) << endl;
    cout << "   Num /: " << 3 << " / " << initializing << " = " << 3 / initializing << endl;
    cout << "   Vectors /=: " << operVecF << " /= " << divNum << " => " << (operVecF /= divNum) << endl;
    cout << "   Vectors /=: " << operVecF << ".divNumEqual(" << divNum << ") => " << operVecF.DivNumEqual(divNum) << endl << endl;

    operVecF = { 4, 2, 4 };

    cout << "8. vector / vector:" << endl;

    cout << "   Vectors /: " << operVecF << " / " << operVecS << " = " << operVecF / operVecS << endl;
    cout << "   Vectors /: " << operVecF << ".div(" << operVecS << ") = " << operVecF.Div(operVecS) << endl;
    cout << "   Vectors /=: " << operVecF << " /= " << operVecS << " => " << (operVecF /= operVecS) << endl;
    cout << "   Vectors /=: " << operVecF << ".divEqual(" << operVecS << ") => " << operVecF.DivEqual(operVecS) << endl << endl;

    

    Vector<int> colVecF = { 1, 1, 0 };
    Vector<int> colVecS = { 1, 1, 0 };

    cout << "  Collinearity: " << colVecF.IsCollinear(colVecS) << endl;
    colVecF = { 5, 2, 0 };
    cout << "  Not collinearity: " << colVecF.IsCollinear(colVecS) << endl << endl;

    cout << "---------------Vectors (Checks)-------------" << endl;
    Vector<float> orthVecF = { 1, 0, 0 };
    Vector<float> orthVecS = { 0, 1, 0 };
    Vector<float> nonOrthVec = { 1, 2, 3 };
    Vector<float> xy = { 1, 2 };

    cout << "  Orthogonality: " << orthVecF.IsOrthgonal(orthVecS) << endl;
    cout << "  Not orthogonality: " << orthVecF.IsOrthgonal(nonOrthVec) << endl << endl;

    cout << "---------------Vectors (Errors)-------------" << endl;
    try {
        orthVecF.IsCollinear(lenExample);
    }
    catch (DivByZeroExcept& er) {
        cout << "Find error: " << er.get_except_info() << endl;
    }

    try {
        Vector<float> vectempty(0, 1, 2, 3);
        orthVecF.IsCollinear(vectempty);
    }
    catch (EmptyVectorExcept& er) {
        cout << "Find error: " << er.get_except_info() << endl;
    }

    try {
        orthVecF.GetItem(-1);
    }
    catch (IndexVectorExcept& er) {
        cout << "Find error: " << er.get_except_info() << endl;
    }

    try {
        xy.GetAngleBetweenVectors(orthVecF);
    }
    catch (DiffSizeVectorsExcept& er) {
        cout << "Find error: " << er.get_except_info() << endl;
    }

    return OK;
}
