#include <iostream>
#include <string>

struct NamedInt
{
    int num;
    std::string name;
};

void PrintStruct(const NamedInt& s){
    std::cout << s.name << " " << s.num << std::endl;
}

int main(){
    NamedInt var{1, std::string{"hello"}};
    PrintStruct(var);
    PrintStruct({10, std::string{"world"}});
    return 0;
}
