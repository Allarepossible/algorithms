#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Container
{
private:
    int m_length;
    T* m_data; //указательна на данные
    void Create(int length)// функция заполнения матрицы
    {
        m_length = length;
        m_data = new T[length];
        for (int i = 0; i < m_length; i++)
        {
            m_data[i] = 0;
        }
    }
public:
    template <typename T1> friend ostream& operator<< (ostream& out, const Container<T1>& element);
    template <typename T1> friend istream& operator>> (istream& in, Container<T1>& element);
    Container()
    {
        m_length = 0;
        m_data = nullptr;
    }
    Container(int length)
    {
        Create(length);
    }
    ~Container()
    {
        delete[] m_data;
        m_length = 0;
        m_data = nullptr;
    }
    Container(Container<T>& element)
    {
        Create(element.m_length);
        for (int i = 0; i < m_length; i++)
        {
            m_data[i] = element.m_data[i];
        }
    }
    int operator[] (int x) //оператор индексации
    {
        if (x >= 0 && x < m_length)
        {
            return m_data[x];
        }
        else
        {
            cout << "Ошибка";
            return 0;
        }
    }
    int Size() //возращает длинну массива (контейнера)
    {
        return m_length;
    }
    bool isFull()
    {
        if (m_length != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Container& operator= (const Container<T>& element) //оператор присваивания
    {
        Create(element.m_length);
        for (int i = 0; i < m_length; i++)
        {
            m_data[i] = element.m_data[i];
        }

        return *this;
    }
    
    void AddLast(T a)
    {
        T* data = new T[m_length + 1];
        for (int i = 0; i < m_length; i++)
        {
            data[i] = m_data[i];
        }
        data[m_length] = a;
        m_length++;
        delete[] m_data;
        m_data = data;
    }

    void AddFirst(T a)
    {
        T* data = new T[m_length + 1];
        for (int i = 0; i < m_length; i++)
        {
            data[i + 1] = m_data[i];
        }
        data[0] = a;
        m_length++;
        delete[] m_data;
        m_data = data;
    }
    void RemoveLast()
    {
        if (m_length == 0)
        {
            cout << " Невозможно удалить элементы из пустого массива! ";
        }
        else
        {
            T* data = new T[m_length - 1];
            for (int i = 0; i < m_length - 1; i++)
            {
                data[i] = m_data[i];
            }
            m_length--;
            delete[] m_data;
            m_data = data;
        }
    }
    void RemoveFirst()
    {
        if (m_length == 0)
        {
            cout << " Невозможно удалить элементы из пустого массива! ";
        }
        else
        {
            T* data = new T[m_length - 1];
            for (int i = 1; i < m_length; i++)
            {
                data[i - 1] = m_data[i];
            }
            m_length--;
            delete[] m_data;
            m_data = data;
        }
    }
    void Sort()
    {
        for (int i = 0; i < m_length; i++)
        {
            for (int j = 0; j < m_length - i - 1; j++)
            {
                if (m_data[j] < m_data[j + 1])
                {
                    swap(m_data[j], m_data[j + 1]);
                }

            }
        }
    }
};

template <typename T>
class Iterator
{
private:
    int m_current; //индекс текущего положения итератора(адрес элемента)
    Container<T> m_element; //контейнер для итератора
public:
    Iterator(Container<T>& element)
    {
        m_element = element;
        m_current = 0;
    }
    T Current()
    {
        return m_element[m_current];
    }
    T Next()
    {
        m_current++;
        return Current();
    }
    T Begin()
    {
        m_current = 0;
        return Current();
    }
    T Set(int a)
    {
        if (a < m_element.Size())
        {
            m_current = a;
            return Current();
        }
        else
        {
            cout << "Ошибка доступа!";
        }
    }
    int Adress()
    {
        return m_current;
    }
    bool End(int a)
    {
        if (a == m_element.Size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsEmpty() //проверка массива пустой или нет
    {
        if (m_element.Size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
template <typename T>
ostream& operator<< (ostream& out, const Container<T>& element) // перегрузка оператора потокового вывода
{
    for (int i = 0; i < element.m_length; i++)
    {
        out << element.m_data[i] << " ";
    }
    return out;
}
template <typename T>
istream& operator>> (istream& in, Container<T>& element) //перегрузка оператора потокового ввод
{
    cout << "Введите длинну: ";
    in >> element.m_length;
    while (element.m_length <= 0)
    {
        cout << "Введите корректную длинну : ";
        in >> element.m_length;
    }
    element.Create(element.m_length);
    cout << "Введите элементы: ";
    for (int i = 0; i < element.m_length; i++)
    {
        in >> element.m_data[i];
    }
    element.Sort();
    return in;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    Container<int> A;
    cin >> A;
    cout << "Ваш контейнер: " << A << endl;
    cout << "Введите число:" << endl;
    cin >> a;

    A.AddLast(a);
    A.AddFirst(a);
    cout << "Ваш контейнер после дабавления: " << A << endl;

    A.RemoveLast();
    A.RemoveFirst();
    A.RemoveFirst();
    cout << "Ваш контейнер после удаления элементов: " << A << endl;
    Iterator<int>Ai(A);
    cout << "Текущий элемент итератора: " << Ai.Current() << endl;
    cout << "Следующий элемент итератора: " << Ai.Next() << endl;
    cout << "Следующий элемент итератора: " << Ai.Next() << endl;
}
