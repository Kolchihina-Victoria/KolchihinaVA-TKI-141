#pragma once
#include <initializer_list>
#include <string>

/**
 * @class IntVector
 * @brief Динамический массив целых чисел с базовыми операциями коллекции.
 */
class IntVector {
public:
    /**
     * @brief Конструктор по умолчанию. Создает пустой вектор.
     */
    IntVector();
    /**
    * @brief Конструктор со списком инициализации.
    * @param list Список значений для инициализации вектора.
    */
    IntVector(std::initializer_list<int> list);  
    /**
     * @brief Конструктор копирования.
     * @param other Другой объект IntVector для копирования.
     */
    IntVector(const IntVector& other);
    /**
    * @brief Конструктор перемещения.
    * @param other Временный объект IntVector.
    */
    IntVector(IntVector&& other) noexcept;
    /**
     * @brief Деструктор.
     */
    ~IntVector();                                

    /**
     * @brief Оператор копирующего присваивания.
     * @param other Другой объект IntVector.
     * @return Ссылка на текущий объект.
     */
    IntVector& operator=(const IntVector& other);  
    /**
    * @brief Оператор перемещающего присваивания.
    * @param other Временный объект IntVector.
    * @return Ссылка на текущий объект.
    */
    IntVector& operator=(IntVector&& other) noexcept;  
    /**
     * @brief Индексация с доступом по ссылке.
     * @param index Индекс элемента.
     * @return Ссылка на элемент по индексу.
     */
    int& operator[](size_t index);    

    /**
        * @brief Индексация (константная версия).
        * @param index Индекс элемента.
        * @return Константная ссылка на элемент.
        * @throw std::out_of_range если индекс выходит за границы.
        */
    const int& operator[](size_t index) const;

    /**
         * @brief Вставка элемента в конец (<<).
         * @param value Значение для вставки.
         * @return Ссылка на текущий объект.
         */
    IntVector& operator<<(int value);
    /**
     * @brief Удаление элемента из конца (>>).
     * @param value Переменная, в которую помещается удаленное значение.
     * @return Ссылка на текущий объект.
     * @throw std::out_of_range если вектор пуст.
     */
    IntVector& operator>>(int& value);    

    /**
     * @brief Проверка на пустоту.
     * @return true если вектор пуст, иначе false.
     */
    bool empty() const;

    /**
     * @brief Получить количество элементов в векторе.
     * @return Количество элементов.
     */

    size_t size() const;
    /**
         * @brief Преобразует содержимое вектора в строку.
         * @return Строка с элементами вектора.
         */
    std::string to_string() const;

    /**
     * @brief Поиск индекса первого вхождения элемента.
     * @param value Значение для поиска.
     * @return Индекс элемента или -1, если не найден.
     */
    int find(int value) const;

private:
    int* data;
    size_t count;
    size_t capacity;

    /**
    * @brief Изменяет вместимость массива.
    * @param new_capacity Новая вместимость.
    */

    void resize(size_t new_capacity);
};
