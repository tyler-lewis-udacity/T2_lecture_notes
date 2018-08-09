// Write a function 'filter()' that implements a multi-
// dimensional Kalman Filter for the example given
//============================================================================
#include <iostream>
#include "Eigen/Dense"
#include <vector>
#include <string>

using namespace std;
using namespace Eigen;

int main() {
    /**
    * Working with the Eigen library
    */
cout << "----------------------- VECTORS -----------------------" << endl;
    // // Create a DYNAMIC doubles vector called "x".  Fill "x" with zeros.
    // VectorXd x; // initialize...
    // x = VectorXd::Zero(2); //...then set by filling with ZEROS. (or ::Ones or ::Randome (-1,1) or ::Identity)
    // cout << "x = " << endl << x << endl << endl;

    // // Access the elements of "x".  Store them in seperate variables "x1" and "x2"
    // double x1, x2;
    // string element_data_type;
    // x1 = x(0,0); // ...or, because it is a vector, just use x1 = x(0);
    // x2 = x(1,0); // ...or, because it is a vector, just use x2 = x(1);
    // element_data_type = typeid(x(0)).name();

    // cout << "x(0,0) = " << x1 << endl;
    // cout << "x(1,0) = " << x2 << endl;
    // cout << "element_data_type = " << element_data_type << endl << endl;

    // // Create a DYNAMIC doubles row-vector called "x_row".  Fill "x_row" with ones.
    // RowVectorXd x_row = RowVectorXd::Ones(2);// initialize and set in one line
    // cout << "x_row = " << endl << x_row << endl << endl;

    // // Create a (3,1) DYNAMIC doubles vector called "rands_vec".  Store (uniformly-distributed) random values ranging from (-1, 1)
    // VectorXd rands_vec = VectorXd::Random(10);// initialize and set in one line
    // cout << "rands_vec = " << endl << rands_vec << endl << endl;

    // // Multiply rands_vec by scalar=10.0
    // rands_vec = rands_vec * 10.0;
    // cout << "rands_vec * 10.0 = " << endl << rands_vec << endl << endl;

    // // Cast to int vector
    // VectorXi rands_vec_casted = rands_vec.cast<int>();
    // cout << "rands_vec_casted = " << endl << rands_vec_casted << endl << endl;
cout << "-------------- VECTOR ARITHMETIC --------------" << endl;

    // // Create 2 (3,1) column-vectors "a" and "b"
    // VectorXi a = VectorXi::Constant(3, 1);
    // VectorXi b = VectorXi::Constant(3, 0);
    // b << 30,40,50;
    // cout << "a = " << endl << a << endl << endl;
    // cout << "b = " << endl << b << endl << endl;

    // // Scalar arithmatic:
    // cout << "a * 10 = " << endl << a * 10 << endl << endl;
    // cout << "a / 10 = " << endl << a / 10 << endl << endl;

    // // Vector/Matrix arithmatic:
    // cout << "a + b = " << endl << a + b << endl << endl;
    // cout << "a - b = " << endl << a - b << endl << endl;
    // cout << "a * b^T = " << endl << a * b.transpose() << endl;

cout << "-------------- DOT AND CROSS PRODUCTS --------------" << endl;

    // // Create fixed size (3,1) vectors of ints called "u" and "v"
    // Vector3i u = Vector3i::Zero(3,1);
    // Vector3i v = Vector3i::Zero(3,1);
    // u << 1,2,3;
    // v << 4,5,6;

    // // Dot-product and Cross-Product
    // cout << "u.dot(v) = " << u.dot(v) << endl;
    // cout << "u.cross(v) = " << endl << u.cross(v) << endl << endl;// NOTE: Requires fixed size vector or matrix!!!


cout << "----------------------- MATRICES -----------------------" << endl;

    // Create a dynamic matrix "A" and set its dimensions (...for now) to 3x3
    MatrixXd A(3,3);
    A << 1,2,1,
         2,1,0,
         -1,1,2;
    VectorXd b(3);
    b << 2, 2, 2;
    cout << "A = " << endl << A << endl;
    cout << endl;
    cout << "b = " << endl << b << endl;
    cout << endl;

    // Find the determinant of A
    double det_A = A.determinant();
    cout << "A.determinant() = " << det_A << endl;

    // Find the inverse of A
    MatrixXd A_inv = A.inverse();
    cout << "A.inverse() = " << endl << A_inv << endl;

    // Check to make sure that A*A_inv = I
    cout << "A*A_inv = " << endl << A*A_inv << endl;

    // Solve for x (...Ax = b --> x = A_inv*b)
    VectorXd x;
    x = A_inv*b;
    cout << "x = " << endl << x << endl;

    // Check to make sure that Ax = b
    cout << "Ax = " << endl << A*x << endl;

    return 0;

    }

