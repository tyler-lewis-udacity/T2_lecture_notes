// Write a function 'filter()' that implements a multi-
// dimensional Kalman Filter for the example given
//============================================================================
#include <iostream>
#include "Eigen/Dense"
#include <vector>

using namespace std;
using namespace Eigen;

//Kalman Filter variables
VectorXd x; // object state
MatrixXd P; // object covariance matrix
VectorXd u; // external motion
MatrixXd F; // state transition matrix
MatrixXd H; // measurement matrix
MatrixXd R; // measurement covariance matrix
MatrixXd I; // Identity matrix
MatrixXd Q; // process covariance matrix


vector<VectorXd> measurements;// Create a vector of "Eigen vectors"
void filter(VectorXd &x, MatrixXd &P);
void print_vector(vector<VectorXd> &v);

int main() {

    //design the KF with 1D motion
    x = VectorXd(2);
    x << 0, 0;

    P = MatrixXd(2, 2);
    P << 1000, 0, 0, 1000;

    u = VectorXd(2);
    u << 0, 0;

    F = MatrixXd(2, 2);
    F << 1, 1, 0, 1;

    H = MatrixXd(1, 2);
    H << 1, 0;

    R = MatrixXd(1, 1);
    R << 1;

    I = MatrixXd::Identity(2, 2);

    Q = MatrixXd(2, 2);
    Q << 0, 0, 0, 0;

    //create a list of measurements (...each element is a vector of type VectorXd)
    VectorXd single_meas(1);
    single_meas << 1;
    measurements.push_back(single_meas);
    single_meas << 2;
    measurements.push_back(single_meas);
    single_meas << 3;
    measurements.push_back(single_meas);

    print_vector(measurements);

    //call Kalman filter algorithm
    filter(x, P);

    return 0;

}

// Apply the Extended Kalman Filter
void filter(VectorXd &x, MatrixXd &P) {

    for (unsigned int n = 0; n < measurements.size(); ++n) {

        VectorXd z = measurements[n];
        /*
         * KF Measurement update step
         */
        VectorXd y = z - H * x;
        MatrixXd Ht = H.transpose();
        MatrixXd S = H * P * Ht + R;
        MatrixXd Si = S.inverse();
        MatrixXd K =  P * Ht * Si;

        //new state
        x = x + (K * y);
        P = (I - K * H) * P;

        /*
         * KF Prediction step
         */
        x = F * x + u;
        MatrixXd Ft = F.transpose();
        P = F * P * Ft + Q;

        // print out the new state vector "x" and the new covariance matrix "P"
        std::cout << "x=" << std::endl <<  x << std::endl;
        std::cout << "P=" << std::endl <<  P << std::endl;
    }
}


// Print out all elements in a vector
void print_vector(vector<VectorXd> &v)
{
    // Create a vector iterator called "it"
    vector<VectorXd>::iterator it;
    // Iterate through the vector and print out each element
    for(it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
}
