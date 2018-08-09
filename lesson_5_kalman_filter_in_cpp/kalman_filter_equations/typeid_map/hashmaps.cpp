#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Create a hashmap of string keys and string values
    map<string, string> my_map;

    // Add some items to the map
    my_map["first"] = "Tom";
    my_map["last"] = "Bean";

    // Replace the value "Bean" with "Thumb"
    my_map["last"] = "Thumb";

    // Access the values by slicing with the appropriate key
    cout << my_map["first"] << endl;
    cout << my_map["last"] << endl;

    // Create an iterator
    map<int, string>::iterator it;

    // Iterate through all the keys (it->first) and values (it->second) in the map
    for(it = my_map.begin(); it != my_map.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;

    } cout << endl;

    return 0;
}
