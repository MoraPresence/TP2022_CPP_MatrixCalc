// Copyright 2022 mora

#ifndef MATRIXCALC_MATRIXCOLUMN_H
#define MATRIXCALC_MATRIXCOLUMN_H

#include "MatrixBase.h"

template<typename T, size_t row_num>
class MatrixColumn : public MatrixBase<T, row_num, 1> {
    using MatrixBase<T, row_num, 1>::cells;
    using MatrixBase<T, row_num, 1>::MatrixBase;

 public:
    using MatrixBase<T, row_num, 1>::operator+=;
    using MatrixBase<T, row_num, 1>::operator+;
    using MatrixBase<T, row_num, 1>::operator-=;
    using MatrixBase<T, row_num, 1>::operator-;
    using MatrixBase<T, row_num, 1>::operator*=;
    using MatrixBase<T, row_num, 1>::operator*;
    using MatrixBase<T, row_num, 1>::operator=;
    using MatrixBase<T, row_num, 1>::operator==;
    using MatrixBase<T, row_num, 1>::begin;
    using MatrixBase<T, row_num, 1>::end;

    MatrixColumn() : MatrixBase<T, row_num, 1>(){};
    MatrixColumn(const MatrixColumn &other)
        : MatrixBase<T, row_num, 1>(other){};
    MatrixColumn(const MatrixBase<T, row_num, 1> &other)
        : MatrixBase<T, row_num, 1>(other){};
    MatrixColumn(const MatrixBase<T, row_num, 1> &&other)
        : MatrixBase<T, row_num, 1>(other){};

    typename std::array<T, row_num>
            ::const_iterator operator()(const size_t &i) const;

    typename std::array<T, row_num>
            ::iterator operator()(const size_t &i);
};

template<typename T, size_t row_num>
typename std::array<T, row_num>
        ::const_iterator MatrixColumn<T, row_num>
                ::operator()(const size_t &i) const {
    return MatrixBase<T, row_num, 1>::operator()(i, 0);
}

template<typename T, size_t row_num>
typename std::array<T, row_num>
        ::iterator MatrixColumn<T, row_num>
                ::operator()(const size_t &i) {
    return MatrixBase<T, row_num, 1>::operator()(i, 0);
}

template<typename T, size_t row_num>
MatrixColumn<T, row_num>
        operator+=(const T &num, MatrixColumn<T, row_num> &matrix) {
    return matrix += num;
}

template<typename T, size_t row_num>
MatrixColumn<T, row_num>
        operator+(const T &num, MatrixColumn<T, row_num> &matrix) {
    return operator+=(num, matrix);
}

#endif//MATRIXCALC_MATRIXCOLUMN_H
