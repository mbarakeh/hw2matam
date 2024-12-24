//
// Created by moham on 24/12/2024.
//

#include "Matrix.h"
#include "cmath"

Matrix::Matrix(): length(0),width(0) {
    m_matrix = nullptr;
}

Matrix::Matrix(int length, int width): length(length),width(width),m_matrix (new int[length*width]()){}

Matrix::Matrix(int length, int width, int num) : length(length),width(width),m_matrix(new int[length*width]()){
    for (int i = 0; i < length*width ; ++i) {
        this->m_matrix[i] = num;
    }

}

Matrix::Matrix(const Matrix &other) : length(other.length), width(other.width) {
    if (length!=0 && width!=0) {
        m_matrix = new int[length * width]();
        for (int i = 0; i < length * width; i++) {
            m_matrix[i] = other.m_matrix[i];
        }
    }
    else {
        m_matrix= nullptr;
    }
}
Matrix::~Matrix() {
    delete[] m_matrix;
}


Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }
    if (this->m_matrix != nullptr) {
        delete[] this->m_matrix;
    }
    this->length = other.length;
    this->width = other.width;

    if (length!=0 && width!=0) {
        this->m_matrix = new int[this->length * this->width]();
        for (int i = 0; i < this->length * this->width; i++) {
            m_matrix[i] = other.m_matrix[i];
        }
    }
    else {
        this->m_matrix= nullptr;
    }
    return *this;
}

const int &Matrix::operator()(int row, int col) const {
    if (row < 0 || col < 0 || row > length - 1 || col > width - 1) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return m_matrix[row * width + col];
}

int &Matrix::operator()(int row, int col) {
    if (row < 0 || col < 0 || row > length - 1 || col > width - 1) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return m_matrix[row * width + col];
}


std::ostream& operator<<(std::ostream &os, const Matrix& matrix) {
    for (int i = 0; i < matrix.length; ++i) {
        os << "|";
        for (int j = 0; j < matrix.width; ++j) {
            os<< matrix.m_matrix[i*matrix.width+j] << "|";
        }
        os<< std::endl;
    }
    return os;
}


Matrix &Matrix::operator+=(const Matrix &other) {
    if (this->length!=other.length||this->width!=other.width){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (int i=0;i<other.length*other.width;i++){
        this->m_matrix[i]+= other.m_matrix[i];
    }
    return *this;
}

Matrix Matrix::operator+( const Matrix& other) const{
    if (this->length!=other.length|| this->width!=other.width){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix newMatrix(*this);
    return newMatrix += other;
}


Matrix Matrix::operator-() const {
    Matrix newMatrix(*this);
    for(int i=0;i< this->length* this->width;i++){
        newMatrix.m_matrix[i]=-newMatrix.m_matrix[i];
    }
    return newMatrix;
}


Matrix &Matrix::operator-=(const Matrix &other) {
    return (*this += -other);
}


Matrix Matrix::operator-(const Matrix &other) const {
    Matrix newMatrix(*this);
    newMatrix-=other;
    return newMatrix;
}



Matrix &Matrix::operator*=(const Matrix &other) {
    if (this->width!=other.length){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    if(this->length==0||this->width==0||other.width==0){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix newMatrix(this->length,other.width);
    for (int row=0;row < newMatrix.length;row++){
        for (int col=0;col < newMatrix.width;col++) {

            int current_sum = 0;
            int current_count=0;
            while(current_count<other.length){
                current_sum+= (*this)(row,current_count)* other(current_count,col);
                current_count++;
            }
            newMatrix.m_matrix[row*newMatrix.width + col] = current_sum;
        }
    }
    *this= newMatrix;
    return *this;
}


Matrix Matrix::operator*(const Matrix &other) const {
    Matrix newMatrix(*this);
    return (newMatrix*= other);
}


Matrix &Matrix::operator*=(int number) {
    if (m_matrix!= nullptr) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                (*this)(i, j) = (*this)(i, j) * number;
            }
        }
    }
    return *this;
}

Matrix Matrix::operator*(int number) const {
    Matrix newMatrix(*this);
    return newMatrix*= number;
}


Matrix operator*(int number, const Matrix& matrix){
    return (matrix * number);
}


bool Matrix::operator==(const Matrix &other) const {
    if (this->width!=other.width) return false;
    if (this->length!=other.length) return false;
    for (int row=0; row< this->length;row++){
        for( int col=0;col< this->width;col++){
            if ((*this)(row,col)!= other(row,col)) return false;
        }
    }
    return true;
}


bool Matrix::operator!=(const Matrix &other) const {
    return !((*this)==other);
}



Matrix Matrix::rotateClockwise() const {
    Matrix newMatrix(this->width, this->length);
    for (int i = this->length-1;i > -1;i--){
        for (int j=0;j<this->width;j++){
            newMatrix(j,this->length-1-i)= (*this)(i,j);
        }
    }
    return newMatrix;
}


Matrix Matrix::rotateCounterClockwise() const {
    Matrix newMatrix(*this);
    newMatrix= newMatrix.rotateClockwise();
    newMatrix= newMatrix.rotateClockwise();
    newMatrix= newMatrix.rotateClockwise();
    return newMatrix;
}


Matrix Matrix::transpose() const{
    Matrix T_matrix(this->width, this->length);
    for (int row=0;row<T_matrix.length;row++){
        for (int col = 0; col < T_matrix.width; ++col) {
            T_matrix(row,col)=(*this)(col,row);
        }
    }
    return T_matrix;
}

double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {

    int sum = 0;

    for(int i = 0; i < matrix.length * matrix.width ; i++){
        sum += matrix.m_matrix[i] * matrix.m_matrix[i];
    }
    return std::sqrt(sum);

}

