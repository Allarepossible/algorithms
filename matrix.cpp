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
    friend DMatrix operator+ (const DMatrix& m1, const DMatrix& m2);
    friend DMatrix operator* (const DMatrix& el, int a);
    friend DMatrix operator* (double p, const DMatrix& el) {return el*p;}
    
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

    DMatrix(const DMatrix &ob){      // this
        f(ob.m_row,ob.m_column);

        for(int i = 0;i < ob.m_row; i++){
            for(int j = 0; j<ob.m_column; j++)
            {
                m_d[i][j]=ob.m_d[i][j];
            }
        }
    }
    DMatrix& operator=(const DMatrix &ob){
        f(ob.m_row,ob.m_column);

        for(int i = 0;i < ob.m_row; i++){
            for(int j = 0; j<ob.m_column; j++)
            {
                m_d[i][j]=ob.m_d[i][j];
            }
        }
        return *this;
    }

    double& operator()(int row, int col){
        return m_d[row][col];
    }
};

DMatrix operator*(const DMatrix& el, int a) {
    DMatrix pr(el.m_row, el.m_column);
    for(int i = 0; i < el.m_row; i++){
        for(int j = 0; j < el.m_column; j++)
        {
            pr.m_d[i][j]=el.m_d[i][j]*a;
        }
    }
    return pr;
}

DMatrix operator+ (const DMatrix& m1, const DMatrix& m2) {
    DMatrix sum(m1.m_row, m1.m_column);
    
    for(int i = 0; i < m1.m_row; i++){
        for(int j = 0; j < m1.m_column; j++)
        {
            sum.m_d[i][j] = m1.m_d[i][j] + m2.m_d[i][j];
        }
    }
    
    return sum;
}

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
    DMatrix V, U;
    double x;
    cin >> x;
    cin >> V;
    cin >> U;

    DMatrix Y = x * V + 2 * U;

    cout << endl << endl;
    cout << Y;

    DMatrix Z = V(1,2) * U + U(2,1) * V;

    cout << Z;
    
    return 0;

}

