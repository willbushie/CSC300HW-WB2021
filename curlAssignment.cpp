#include <string.h>
#include <iostream>
#include <curl/curl.h>
#include <curlAssignment.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    // create the new URL objects
    URL u1 = new URL(“http://www.google.com");
    URL u2 = new URL(“http://www.yahoo.com");
    
    // run getContents() method on both URL objects
    cout << u1.getContents() << endl;
    cout << u2.getContents() << endl;
    return 0;
}
