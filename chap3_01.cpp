// all.hをpreinclude

std::string func(std::string s1, std::string s2){

    return s1 + s2;
}

int main(){

    std::cout << func("abc"s, "def"s);
    return 0;
}