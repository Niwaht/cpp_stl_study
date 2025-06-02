#include <iostream>
#include <string_view>
using namespace std;

void print(string_view v) {
    const auto words_begin (v.find_first_not_of(" \t\n"));
    v.remove_prefix(min(words_begin, v.size()));
    const auto words_end   (v.find_last_not_of(" \t\n"));
    if(words_end != string_view::npos) v.remove_suffix(v.size() - words_end - 1);
    cout << "length: " << v.length() << " [" << v << "]\n";
}

int main(int argc, char* argv[])
{
    print(argv[0]);                             // runtime char* string from argv
    print({});                                  // empty string_view instance
    print("a const char* array");               // c-style static character string
    print("an std::string_view literal"sv);     // string_view literal instance
    print("an std::string instance"s);          // std::string instance

    print(" \t\n foobar \n \t ");

    char cstr[] {'a', 'b', 'c'};
    print(string_view(cstr, sizeof(cstr)));

    return 0;
}
