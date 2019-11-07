#include <iostream>
#include <string>
using namespace std;

class DMatrix
{
private:
    double** m_d;
    int m_row;
    int m_column;
public:
    friend istream& operator>> (istream& in, DMatrix& matrix);
    friend ostream& operator<< (ostream& out, const DMatrix& matrix);
    void f (int m, int n) {
        m_d = new double* [m];
        for (int i = 0; i < m; i++) {
            m_d[i] = new double [n];
            for (int j = 0; j < n; j++) {
                m_d[i][j] = 1;
            }
        }
        m_row = m;
        m_column = n;
    }
    void show(){
        for(int i=0; i<m_row ;i++)
        {
            for(int j=0; j<m_column; j++)
            {
                cout<<m_d[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    DMatrix() : m_row(1), m_column(1) {}
    DMatrix(int row, int column) {
        f(row, column);
    }
    ~DMatrix(){
        for(int i=0; i<m_row ;i++)
        {
            delete[] m_d[i];
        }
        delete[] m_d;
    }
    DMatrix(const DMatrix &ob){
        f(ob.m_row,ob.m_column);
        
        for(int i = 0;i < ob.m_row; i++){
            for(int j = 0; j<ob.m_column; j++)
            {
                m_d[i][j]=ob.m_d[i][j];
            }
        }
    }
};

istream& operator>> (istream& in, DMatrix& matrix) {
    cout << "Введите количество строк и столбцов: ";
    in >> matrix.m_row >> matrix.m_column;
    matrix.f(matrix.m_row, matrix.m_column);
    cout << "Введите " << matrix.m_row * matrix.m_column << " элементов" << endl;
    
    for(int i = 0; i< matrix.m_row; i++){
        for(int j = 0; j<matrix.m_column; j++)
        {
            in >> matrix.m_d[i][j];
        }
    }
    
    return in;
}

ostream& operator<< (ostream& out, const DMatrix& matrix) {
    cout << "Матрица из " << matrix.m_row << " строк и " << matrix.m_column << " столбцов" << endl;

    for(int i = 0; i< matrix.m_row; i++){
        for(int j = 0; j<matrix.m_column; j++)
        {
             out << matrix.m_d[i][j] << "\t";
        }
        out << endl;
    }
    out << endl;
    
    return out;
}

int main()
{
    int x,y;
    DMatrix matrix;
    cout<<"Введите колличество строк=";
    cin>>x;
    cout<<"Введите количество столбцов=";
    cin>>y;
    DMatrix M(x,y);
    M.show();
    cout << endl;
    cin >> matrix;
    cout << endl;
    cout << matrix;
    
    return 0;
}
