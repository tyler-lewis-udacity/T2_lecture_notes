#include <iostream>
#include "Eigen/Dense"
#include <vector>
#include <string>

using namespace std;
using namespace Eigen;

// Prototypes
void print_vector(vector<float> &v);


// Main
int main()
{


    return 0;
}




// Function Definitions
// Print out all elements in a vector
void print_vector(vector<float> &v)
{
    // Create a vector iterator called "it"
    vector<float>::iterator it;
    // Iterate through the vector and print out each element
    for(it = v.begin(); it != v.end(); ++it)
    {
        cout << &(*it) << " ";
    }
}
