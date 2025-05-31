#pragma once
#include <initializer_list>
#include <string>
#include <stdexcept> // Для std::out_of_range

/**
 * @class IntVector
 * @brief Динамический массив целых чисел с базовыми операциями коллекции.
 */
class IntVector {
public:
    /**
     * @brief Конструктор по умолчанию. Создает пустой вектор.
     */
    IntVector() : data(nullptr), count(0) {}
    /**
    * @brief Конструктор со списком инициализации.
    * @param list Список значений для инициализации вектора.
    */
    IntVector(std::initializer_list<int> list) : data(nullptr), count(0) {
        resize(list.size());
        for (const auto& value : list) {
            data[count++] = value;
        }
    }
    /**
     * @brief Конструктор копирования.
     * @param other Другой объект IntVector для копирования.
     */
    IntVector(const IntVector& other) : data(nullptr), count(other.count) {
        if (count > 0) {
            data = new int[count];
            for (size_t i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    /**
    * @brief Конструктор перемещения.
    * @param other Временный объект IntVector.
    */
    IntVector(IntVector&& other) noexcept : data(other.data), count(other.count) {
        other.data = nullptr;
        other.count = 0;
    }
    /**
     * @brief Деструктор.
     */
    ~IntVector() {
        delete[] data;
    }

    /**
     * @brief Оператор копирующего присваивания.
     * @param other Другой объект IntVector.
     * @return Ссылка на текущий объект.
     */
    IntVector& operator=(const IntVector& other) {
        if (this != &other) {
            delete[] data;
            count = other.count;
            if (count > 0) {
                data = new int[count];
                for (size_t i = 0; i < count; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }
    /**
    * @brief Оператор перемещающего присваивания.
    * @param other Временный объект IntVector.
    * @return Ссылка на текущий объект.
    */
    IntVector& operator=(IntVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            count = other.count;

            other.data = nullptr;
            other.count = 0;
        }
        return *this;
    }
    /**
     * @brief Индексация с доступом по ссылке.
     * @param index Индекс элемента.
     * @return Ссылка на элемент по индексу.
     */
    int& operator[](size_t index) {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    /**
        * @brief Индексация (константная версия).
        * @param index Индекс элемента.
        * @return Константная ссылка на элемент.
        * @throw std::out_of_range если индекс выходит за границы.
        */
    const int& operator[](size_t index) const {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    /**
     * @brief Вставка элемента в конец (<<).
     * @param value Значение для вставки.
     * @return Ссылка на текущий объект.
     */
    IntVector& operator<<(int value) {
        resize(count + 1);
        data[count - 1] = value;
        return *this;
    }
    /**
     * @brief Удаление элемента из конца (>>).
     * @param value Переменная, в которую помещается удаленное значение.
     * @return Ссылка на текущий объект.
     * @throw std::out_of_range если вектор пуст.
     */
    IntVector& operator>>(int& value) {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        value = data[--count];
        resize(count);
        return *this;
    }

    /**
     * @brief Проверка на пустоту.
     * @return true если вектор пуст, иначе false.
     */
    bool empty() const {
        return count == 0;
    }

    /**
     * @brief Получить количество элементов в векторе.
     * @return Количество элементов.
     */
    size_t size() const {
        return count;
    }
    /**
     * @brief Преобразует содержимое вектора в строку.
     * @return Строка с элементами вектора.
     */
    std::string to_string() const {
        std::string result = "[";
        for (size_t i = 0; i < count; ++i) {
            result += std::to_string(data[i]);
            if (i != count - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    /**
     * @brief Поиск индекса первого вхождения элемента.
     * @param value Значение для поиска.
     * @return Индекс элемента или -1, если не найден.
     */
    int find(int value) const {
        for (size_t i = 0; i < count; ++i) {
            if (data[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

private:
    int* data;
    size_t count;

    /**
    * @brief Изменяет вместимость массива до точного размера count.
    * @param new_capacity Новый размер массива, равный текущему количеству элементов.
    */
    void resize(size_t new_capacity) {
        delete[] data;
        if (new_capacity > 0) {
            data = new int[new_capacity];
        } else {
            data = nullptr;
        }
        // при вызове resize из методов вставки или удаления
        // массив выделяется под точное число элементов.
    }
};
