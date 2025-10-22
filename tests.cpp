#include "matrix.h"
#include "matrix.cpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
class MatrixTests {
private:
    // Вспомогательные функции
    static bool arraysEqual(const Matrix<int>& matrix, const std::vector<int>& expected) {
        if (matrix.size() != expected.size()) {
            return false;
        }
        
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i] != expected[i]) {
                return false;
            }
        }
        
        return true;
    }

    static void captureOutput(const Matrix<int>& matrix, std::string& output) {
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        
        matrix.print();
        
        std::cout.rdbuf(oldCout);
        output = buffer.str();
    }

public:
    static void testConstructor() {
        std::cout << "Testing constructors... ";
        
        // Тест конструктора матрицы
        Matrix<int> mat(2, 3);
        assert(mat.getRows() == 2);
        assert(mat.getColumns() == 3);
        assert(mat.size() == 3);
        
        // Тест конструктора вектора
        Matrix<int> vec(5);
        assert(vec.getRows() == 1);
        assert(vec.getColumns() == 5);
        assert(vec.size() == 5);
        
        std::cout << "PASSED\n";
    }

    static void testCopyConstructor() {
        std::cout << "Testing copy constructor... ";
        
        Matrix<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;
        
        // Копирование
        Matrix<int> copy = original;
        
        // Проверка, что данные скопированы
        assert(copy[0] == 1);
        assert(copy[1] == 2);
        assert(copy[2] == 3);
        
        // Проверка независимости копии
        original[0] = 100;
        assert(copy[0] == 1); // Копия не должна измениться
        
        std::cout << "PASSED\n";
    }

    static void testAssignment() {
        std::cout << "Testing assignment operator... ";
        
        Matrix<int> vec1(3);
        vec1[0] = 1;
        vec1[1] = 2;
        vec1[2] = 3;
        
        Matrix<int> vec2(2);
        vec2 = vec1; // Присваивание
        
        // Проверка копирования
        assert(vec2[0] == 1);
        assert(vec2[1] == 2);
        assert(vec2[2] == 3);
        assert(vec2.size() == 3);
        
        // Проверка независимости
        vec1[0] = 100;
        assert(vec2[0] == 1);
        
        // Самоприсваивание
        vec2 = vec2;
        assert(vec2[0] == 1);
        assert(vec2[1] == 2);
        assert(vec2[2] == 3);
        
        std::cout << "PASSED\n";
    }

    static void testAccessOperators() {
        std::cout << "Testing access operators... ";
        
        Matrix<int> vec(4);
        vec[0] = 10;
        vec[1] = 20;
        vec[2] = 30;
        vec[3] = 40;
        
        // Тест оператора []
        assert(vec[0] == 10);
        assert(vec[1] == 20);
        assert(vec[2] == 30);
        assert(vec[3] == 40);
        
        // Тест изменения через оператор []
        vec[1] = 25;
        assert(vec[1] == 25);
        
        // Тест константного доступа
        const Matrix<int>& constVec = vec;
        assert(constVec[0] == 10);
        assert(constVec[1] == 25);
        
        // Тест для матриц
        Matrix<int> mat(2, 2);
        mat(0, 0) = 1;
        mat(0, 1) = 2;
        mat(1, 0) = 3;
        mat(1, 1) = 4;
        
        assert(mat(0, 0) == 1);
        assert(mat(0, 1) == 2);
        assert(mat(1, 0) == 3);
        assert(mat(1, 1) == 4);
        
        std::cout << "PASSED\n";
    }

    static void testFillMethods() {
        std::cout << "Testing fill methods... ";
        
        // Тест fillRandom
        Matrix<int> vec1(10);
        vec1.fillRandom(-5, 5);
        
        // Проверяем, что все значения в диапазоне
        for (size_t i = 0; i < vec1.size(); ++i) {
            assert(vec1[i] >= -5 && vec1[i] <= 5);
        }
        
        // Тест fillFromKeyboard (эмулируем ввод)
        Matrix<int> vec2(3);
        std::istringstream input("5\n-3\n10\n");
        
        // Сохраняем оригинальный cin
        auto oldCin = std::cin.rdbuf(input.rdbuf());
        vec2.fillFromKeyboard(-10, 10);
        std::cin.rdbuf(oldCin);
        
        assert(vec2[0] == 5);
        assert(vec2[1] == -3);
        assert(vec2[2] == 10);
        
        std::cout << "PASSED\n";
    }

    static void testReplaceLastNegative() {
        std::cout << "Testing replaceLastNegative... ";
        
        // Тест 1: Есть отрицательные элементы
        Matrix<int> vec1(5);
        vec1[0] = 1;
        vec1[1] = -2;
        vec1[2] = 3;
        vec1[3] = -4;
        vec1[4] = 5;
        
        vec1.replaceLastNegative();
        assert(vec1[3] == 1); // Последний отрицательный (-4) заменен на |1|
        assert(vec1[1] == -2); // Первый отрицательный не тронут
        
        // Тест 2: Нет отрицательных элементов
        Matrix<int> vec2(3);
        vec2[0] = 1;
        vec2[1] = 2;
        vec2[2] = 3;
        
        Matrix<int> vec2Copy = vec2;
        vec2.replaceLastNegative();
        assert(arraysEqual(vec2, {1, 2, 3})); // Массив не изменился
        
        // Тест 3: Все элементы отрицательные
        Matrix<int> vec3(3);
        vec3[0] = -1;
        vec3[1] = -2;
        vec3[2] = -3;
        
        vec3.replaceLastNegative();
        assert(vec3[2] == 1); // Последний отрицательный заменен на |1|
        
        std::cout << "PASSED\n";
    }

    static void testRemoveElementsWithEqualDigits() {
        std::cout << "Testing removeElementsWithEqualDigits... ";
        
        // Тест 1: Элементы с одинаковыми цифрами
        Matrix<int> vec1(6);
        vec1[0] = 11;    // одинаковые
        vec1[1] = 23;    // разные
        vec1[2] = 33;    // одинаковые
        vec1[3] = 45;    // разные
        vec1[4] = 100;   // одинаковые (1 и 0)
        vec1[5] = 123;   // разные
        
        vec1.removeElementsWithEqualDigits();
        assert(vec1.size() == 3);
        assert(vec1[0] == 23);
        assert(vec1[1] == 45);
        assert(vec1[2] == 123);
        
        // Тест 2: Все элементы с одинаковыми цифрами
        Matrix<int> vec2(3);
        vec2[0] = 11;
        vec2[1] = 22;
        vec2[2] = 33;
        
        vec2.removeElementsWithEqualDigits();
        assert(vec2.size() == 0);
        
        // Тест 3: Нет элементов с одинаковыми цифрами
        Matrix<int> vec3(3);
        vec3[0] = 12;
        vec3[1] = 34;
        vec3[2] = 56;
        
        Matrix<int> vec3Copy = vec3;
        vec3.removeElementsWithEqualDigits();
        assert(arraysEqual(vec3, {12, 34, 56}));
        
        std::cout << "PASSED\n";
    }

    static void testTransformArray() {
        std::cout << "Testing transformArray... ";
        
        // Тест 1: Смешанные четные и нечетные
        Matrix<int> vec1(5);
        vec1[0] = 2;  // четный -> 0 * 2 = 0
        vec1[1] = 3;  // нечетный -> -3
        vec1[2] = 4;  // четный -> 2 * 4 = 8
        vec1[3] = 5;  // нечетный -> -5
        vec1[4] = 6;  // четный -> 4 * 6 = 24
        
        Matrix<int> result1 = vec1.transformArray();
        assert(result1.size() == 5);
        assert(result1[0] == 0);
        assert(result1[1] == -3);
        assert(result1[2] == 8);
        assert(result1[3] == -5);
        assert(result1[4] == 24);
        
        // Тест 2: Только четные
        Matrix<int> vec2(3);
        vec2[0] = 10;
        vec2[1] = 20;
        vec2[2] = 30;
        
        Matrix<int> result2 = vec2.transformArray();
        assert(result2[0] == 0);   // 0 * 10
        assert(result2[1] == 20);  // 1 * 20
        assert(result2[2] == 60);  // 2 * 30
        
        // Тест 3: Только нечетные
        Matrix<int> vec3(3);
        vec3[0] = 1;
        vec3[1] = 3;
        vec3[2] = 5;
        
        Matrix<int> result3 = vec3.transformArray();
        assert(result3[0] == -1);
        assert(result3[1] == -3);
        assert(result3[2] == -5);
        
        std::cout << "PASSED\n";
    }

    static void testEdgeCases() {
        std::cout << "Testing edge cases... ";
        
        // Тест пустого вектора
        Matrix<int> emptyVec(0);
        assert(emptyVec.size() == 0);
        
        // Тест с одним элементом
        Matrix<int> singleVec(1);
        singleVec[0] = 42;
        assert(singleVec[0] == 42);
        
        // Тест replaceLastNegative с одним отрицательным
        Matrix<int> singleNegative(1);
        singleNegative[0] = -5;
        singleNegative.replaceLastNegative();
        assert(singleNegative[0] == 5);
        
        // Тест removeElementsWithEqualDigits с однозначными числами
        Matrix<int> singleDigit(3);
        singleDigit[0] = 1;
        singleDigit[1] = 5;
        singleDigit[2] = 9;
        singleDigit.removeElementsWithEqualDigits();
        assert(singleDigit.size() == 3); // Все должны остаться
        
        // Тест с отрицательными числами для проверки цифр
        Matrix<int> negativeDigits(2);
        negativeDigits[0] = -11;  // одинаковые цифры (1 и 1)
        negativeDigits[1] = -12;  // разные цифры (1 и 2)
        negativeDigits.removeElementsWithEqualDigits();
        assert(negativeDigits.size() == 1);
        assert(negativeDigits[0] == -12);
        
        std::cout << "PASSED\n";
    }

    static void testExceptions() {
        std::cout << "Testing exceptions... ";
        
        Matrix<int> vec(3);
        
        // Тест выхода за границы
        try {
            vec[5] = 10;
            assert(false); // Не должно дойти сюда
        } catch (const std::out_of_range& e) {
            // Ожидаемое исключение
        }
        
        try {
            int value = vec[10];
            assert(false);
        } catch (const std::out_of_range& e) {
            // Ожидаемое исключение
        }
        
        // Тест для матриц
        Matrix<int> mat(2, 2);
        try {
            mat(5, 1) = 10;
            assert(false);
        } catch (const std::out_of_range& e) {
            // Ожидаемое исключение
        }
        
        try {
            mat(1, 5) = 10;
            assert(false);
        } catch (const std::out_of_range& e) {
            // Ожидаемое исключение
        }
        
        std::cout << "PASSED\n";
    }

    static void testPrintMethod() {
        std::cout << "Testing print method... ";
        
        Matrix<int> vec(3);
        vec[0] = 1;
        vec[1] = 2;
        vec[2] = 3;
        
        // Захватываем вывод
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        
        vec.print();
        
        std::cout.rdbuf(oldCout);
        
        std::string output = buffer.str();
        // Проверяем, что вывод содержит ожидаемые элементы
        assert(output.find("1") != std::string::npos);
        assert(output.find("2") != std::string::npos);
        assert(output.find("3") != std::string::npos);
        assert(output.find("Массив [3]") != std::string::npos);
        
        std::cout << "PASSED\n";
    }

    static void testMoveSemantics() {
        std::cout << "Testing move semantics... ";
        
        Matrix<int> vec1(3);
        vec1[0] = 1;
        vec1[1] = 2;
        vec1[2] = 3;
        
        // Move конструктор
        Matrix<int> vec2 = std::move(vec1);
        assert(vec2.size() == 3);
        assert(vec2[0] == 1);
        assert(vec2[1] == 2);
        assert(vec2[2] == 3);
        
        // Исходный объект должен быть в валидном состоянии
        assert(vec1.size() == 0);
        
        // Move присваивание
        Matrix<int> vec3(2);
        vec3 = std::move(vec2);
        assert(vec3.size() == 3);
        assert(vec3[0] == 1);
        assert(vec3[1] == 2);
        assert(vec3[2] == 3);
        
        std::cout << "PASSED\n";
    }

    static void runAllTests() {
        std::cout << "=== RUNNING MATRIX TESTS ===\n\n";
        
        testConstructor();
        testCopyConstructor();
        testAssignment();
        testAccessOperators();
        testFillMethods();
        testReplaceLastNegative();
        testRemoveElementsWithEqualDigits();
        testTransformArray();
        testEdgeCases();
        testExceptions();
        testPrintMethod();
        testMoveSemantics();
        
        std::cout << "\n=== ALL TESTS PASSED ===\n";
    }
};

int main() {
    try {
        MatrixTests::runAllTests();
        std::cout << "\n🎉 All tests completed successfully!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n❌ Test failed: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\n❌ Unknown test failure occurred" << std::endl;
        return 1;
    }
}