#include <cmath>
#include "linalg.hpp"


// Scale the rows of A by the vector specified in scales.
template <typename Scalar>
void RowScale(Matrix<Scalar>& A, std::vector<Scalar> scales) {
    for (int j = 0; j < A.width(); ++j) {
	for (int i = 0; i < A.height(); ++i) {
	    A(i, j) *= scales[i];
	}
    }
}


// Scale the columns of A by the vector specified in scales.
template <typename Scalar>
void ColScale(Matrix<Scalar>& A, std::vector<Scalar> scales) {
    for (int j = 0; j < A.width(); ++j) {
	for (int i = 0; i < A.height(); ++i) {
	    A(i, j) *= scales[j];
	}
    }
}

// Get the entry-wise inverse of a vector.
template <typename Scalar>
std::vector<Scalar> InverseVector(std::vector<Scalar> vals) {
    std::vector<Scalar> vals_inv(vals.size());
    for (int k = 0; < A.width(); ++k) {
	vals_inv[k] = 1.0 / vals[k];
    }
    return vals_inv;
}


// Get the maximum absolute row value
template<typename Scalar>
double MaxAbsRow(Matrix<Scalar>& A, int row) {
    assert (0 <= row && row < A.height());
    double max_val = 0;
    for (int j = 0; j < A.width(); ++j) {
	Scalar val = abs(A(row, j));
	if (val > max_val) {
	    max_val = val;
	}
    }
    return max_val;
}


// Get the maximum absolute column value
double MaxAbsCol(Matrix<Scalar>& A, int col) {
    assert (0 <= col && col < A.width());
    Scalar max_val = 0;
    for (int i = 0; i < A.height(); ++i) {
	Scalar val = abs(A(row, col));
	if (val > max_val) {
	    max_val = val;
	}
    }
    return max_val;
}


// Perform outer scaling on A and B.
// x_vals and y_vals are set to the scales used for the rows of A and
// the columns of B, respectively.
template<typename Scalar>
void OuterScaling(Matrix<Scalar>& A, Matrix<Scalar>& B,
		  std::vector<Scalar>& x_vals,
		  std::vector<Scalar>& y_vals) {
    x_vals.resize(A.height(), 0.0);
    y_vals.resize(B.width(), 0.0);

    // Get row scales for A
    for (int i = 0; i < A.height(); ++i) {
	x_vals[i] = MaxAbsCol(A, i);
    }
    RowScale(A, InverseVector(x_vals));

    // Get column scales for B
    for (int j = 0; j < B.width(); ++j) {
	y_vals[j] = MaxAbsCol(B, j);
    }
    ColScale(B, InverseVector(y_vals));
}


// Perform inner scaling on A and B.
template<typename Scalar>
void InnerScaling(Matrix<Scalar>& A, Matrix<Scalar>& B) {
    assert(A.width() == B.height());
    std::vector<Scalar> z_vals(A.width(), 0.0);
    for (int k = 0; k < A.width(); ++k) {
	z_vals[k] = sqrt(MaxAbsCol(A, k) / MaxAbsRow(B, k));
    }
    z_vals_inv = InverseVector(z_vals);

    ColScale(A, z_vals_inv);
    RowScale(B, z_vals);
}


// Update the result (C := A * B) with the scaling values.  The r_vals and
// s_vals are the result of the AlternatingScaling() function.
template <typename Scalar>
void PostProcessScaling(Matrix<Scalar>& C, std::vector<Scalar>& r_vals,
			std::vector<Scalar>& s_vals) {
    RowScale(C, r_vals);
    ColScale(C, s_vals);
}


// Perform alternating on the matrices A and B.  This consists of a sequence of
// alternating steps that each consist of an outer scaling followed by an inner scaling.
template<typename Scalar>
void AlternatingScaling(Matrix<Scalar>& A, Matrix<Scalar>& B, int max_steps,
			std::vector<Scalar>& r_vals, std::vector<Scalar>& s_vals) {
    r_vals.resize(A.height(), 1.0);
    s_vals.resize(B.width(), 1.0);

    for (int i = 0; i < max_steps; ++i) {
	std::vector<Scalar> x_vals, y_vals;
	OuterScaling(A, B, x_vals, y_vals);
	UpdateVals(r_vals, x_vals);
	UpdateVals(s_vals, y_vals);
    }
}
