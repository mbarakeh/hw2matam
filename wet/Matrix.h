//
// Created by moham on 24/12/2024.
//

#ifndef WET_MATRIX_H
#define WET_MATRIX_H

#endif //WET_MATRIX_H
#include "Utilities.h"
#include <ostream>


class Matrix{
    int length;
    int width;
    int* m_matrix;
public:
    Matrix();
    Matrix(int length, int width);
    Matrix(int length,int width,int num);
    Matrix(const Matrix& other);

    ~Matrix();

    const int& operator()(int row, int col) const;

    Matrix& operator=(const Matrix& other);

    int& operator()(int row, int col);

    friend std::ostream& operator<<(std::ostream& os,const Matrix& Matrix);

    Matrix& operator+=(const Matrix& other);

    Matrix& operator*=(const Matrix& other);

    Matrix operator-() const;

    Matrix& operator-=(const Matrix& other);

    Matrix& operator*=(int number);

    bool operator==(const Matrix& other) const;

    bool operator!=(const Matrix& other) const;

    Matrix operator+( const Matrix& other) const;
    Matrix operator*( const Matrix& other) const;
    Matrix operator-( const Matrix& matrix2) const;
    Matrix operator*( int number) const;


    Matrix rotateClockwise() const;

    Matrix rotateCounterClockwise() const;

    Matrix transpose() const;

  static  double CalcFrobeniusNorm( const Matrix& matrix);

};


Matrix operator*(int num, const Matrix& matrix);