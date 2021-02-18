#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

class URL
{
    private:
        string name;

    public:
        URL(string name);
        void getContents()
};