#include <stdio.h>
#include <string>
using namespace std;

class fsHandler{
    private:
        string* loadfile(string* path);
        void writefile(string path, string data);
        void createdir(string path);
        bool direxists(string path);
        bool filexists(string path);
    public:
        string hello = "hello";
};