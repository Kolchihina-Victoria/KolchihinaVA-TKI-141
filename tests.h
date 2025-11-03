#pragma once

#include "matrix.h"
#include "matrix.cpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>

class MatrixTests {
private:
    // Вспомогательные методы для тестирования
    static void testConstructor();
    static void testCopyConstructor();
    static void testAssignment();
    static void testAccessOperators();
    static void testFillMethods();
    static void testReplaceLastNegative();
    static void testRemoveElementsWithEqualDigits();
    static void testTransformArray();
    static void testEdgeCases();
    static void testExceptions();

    // Вспомогательные функции
    static bool arraysEqual(const Matrix<int>& matrix, const std::vector<int>& expected);
    static void captureOutput(const Matrix<int>& matrix, std::string& output);

public:
    static void runAllTests();
};