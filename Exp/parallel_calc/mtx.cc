#include <iostream>
#include <cstring>
#include <fstream>
#define THEAD_NUM 4

class Mat {
private:
    int row, col;
    int **val;
public:
    Mat(long long a = 0, long long b = 0): row(a), col(b) {
        val = new int*[a];
        for (int i = 0; i < row; ++i) {
            val[i] = new int[col];
            memset(val[i], 0, sizeof(int));
        }
    }
    ~Mat() {}
    int g_col() {
        return this->col;
    }
    int g_row() {
        return this->row;
    }
    int* operator[](int r) { return val[r]; }
    Mat operator*(Mat oth) {
        Mat ret(row, oth.col);
        if (col != oth.g_row()) {
            std::cout << "ValueError" << std::endl;
            exit(-1);
        }
#pragma omp parallel for num_threads(THEAD_NUM)
        for (long long i = 0; i < row; ++i) {
            for (long long j = 0; j < col; ++j) {
                for (long long k = 0; k < oth.col; ++k) {
                    ret[i][k] += val[i][j] * oth[j][k];
                }
            }
        }
        return ret;
    }
    friend std::ostream& operator<<(std::ostream& out, Mat& m) {
        for (int i = 0; i < m.g_row(); ++i) {
            for (int j = 0; j < m.g_col(); ++j) {
                out << m[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Mat& m) {
        for (int i = 0; i < m.g_row(); ++i) {
            for (int j = 0; j < m.g_col(); ++j) {
                in >> m[i][j];
            }
        }
        return in;
    }
};

int main() {
    std::ifstream in1("mtx1", std::ios::in);
    std::ifstream in2("mtx2", std::ios::in);
    int r, c;

    in1 >> r >> c;
    Mat m1(r, c);
    in1 >> m1;

    in2 >> r >> c;
    Mat m2(r, c);
    in2 >> m2;

    Mat m = m1 * m2;
    std::cout << m;
}

