#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//i dont recommend using this in any other header instead this Console.hpp
//this is really fucking dumb.

class Concatenate{
    public:
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string string6, string string7, string string8, string string9, string string10, string seperator){
            string finalString = "";
            string strings[10] = {string1, string2, string3, string4, string5, string6, string7, string8, string9, string10};
            for(int i = 0; i < (sizeof(strings)/sizeof(*strings)); i++){
                string add = strings[i];
                finalString = finalString + add + seperator;
            }
            return finalString;
        }
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string string6, string string7, string string8, string string9, string seperator){
            return JoinString(string1, string2, string3, string4, string5, string6, string7, string8, string9, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string string6, string string7, string string8, string seperator){
            return JoinString(string1, string2, string3, string4, string5, string6, string7, string8, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string string6, string string7, string seperator){
            return JoinString(string1, string2, string3, string4, string5, string6, string7, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string string6, string seperator){
            return JoinString(string1, string2, string3, string4, string5, string6, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string string4, string string5, string seperator){
            return JoinString(string1, string2, string3, string4, string5, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string string4, string seperator){
            return JoinString(string1, string2, string3, string4, "", seperator);
        }
        static string JoinString(string string1, string string2, string string3, string seperator){
            return JoinString(string1, string2, string3, "", seperator);
        }
        static string JoinString(string string1, string string2, string seperator){
            return JoinString(string1, string2, "", seperator);
        }
};