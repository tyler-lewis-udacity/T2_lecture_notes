// Write a function 'filter()' that implements a multi-
// dimensional Kalman Filter for the example given
//============================================================================
#include <iostream>
#include "Eigen/Dense"
#include <vector>

using namespace std;
using namespace Eigen;

int main() {
    /**
    * Working with the Eigen library
    */

    /*------------------------------------------------------------------------*/
    /* CREATING DYNAMIC VECTORS */
    // Create a (2,1) DYNAMIC (size X) column VECTOR of type DOUBLE (d) named "my_vector"
    VectorXd my_vector(2);// initializes with 'unknown' values

    // Use the so called comma initializer to set all the coefficients to some values
    my_vector << 1.1, 2.1;
    cout << "my_vector =\n" << my_vector << endl << endl;

    // ...or use set each value explicitly: v(row, col) ...zero indexed
    my_vector(0, 0) = 3.141;
    my_vector(1, 0) = 2.718;
    cout << "my_vector =\n" << my_vector << endl << endl;

    // Print out the size(num elements), num rows, and num cols of the vector
    cout << "my_vector.size() = " << my_vector.size() << endl;
    cout << "my_vector.rows() = " << my_vector.rows() << endl;
    cout << "my_vector.cols() = " << my_vector.cols() << endl;

    // Resize the vector from a (2,1) into a (3,1)
    // NOTE: ALL elements of the vector must be reset after resizing the vector! See the jibberish below
    my_vector.resize(3,1);
    cout << "my_vector.resize(3, 1) =\n" << my_vector << endl << endl;

    // Re-define the vector and fill it with zeros as a (4,1)
    my_vector = VectorXd::Constant(4, 1, 0.0);
    cout << "my_vector = VectorXd::Constant(4, 1, 0.0) =\n" << my_vector << endl << endl;

    // Re-define the vector and fill it with any constant (pi, for this example) as a (2,1)
    my_vector = VectorXd::Constant(2, 1, 3.141);
    cout << "my_vector = VectorXd::Constant(2, 1, 3.141) =\n" << my_vector << endl << endl;

    /*------------------------------------------------------------------------*/
    /* CREATING FIXED-SIZE VECTORS */
    // Create a (2,1) FIXED (size X) column VECTOR of type INT (i) named "my_vector"










    //-----------------------
    // Create another vector, this time using the

    // //the matrices can be created in the same way.
    // //For example, This is an initialization of a 2 by 2 matrix
    // //with the values 1, 2, 3, and 4
    // MatrixXd my_matrix(2,2);
    // my_matrix << 1, 2,
    //      3, 4;
    // cout << my_matrix << endl;


    // //you can use the same comma initializer or you can set each matrix value explicitly
    // // For example that's how we can change the matrix elements in the second row
    // my_matrix(1,0) = 11;    //second row, first column
    // my_matrix(1,1) = 12;    //second row, second column
    // cout << my_matrix << endl;


    // //Also, you can compute the transpose of a matrix with the following command
    // MatrixXd my_matrix_t = my_matrix.transpose();
    // cout << my_matrix_t << endl;


    // //And here is how you can get the matrix inverse
    // MatrixXd my_matrix_i = my_matrix.inverse();
    // cout << my_matrix_i << endl;


    // //For multiplying the matrix m with the vector b you can write this in one line as let’s say matrix c equals m times v.

    // MatrixXd another_matrix;
    // another_matrix = my_matrix*my_vector;
    // cout << another_matrix << endl;


    return 0;

    }

