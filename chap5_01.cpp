// preincluded

int main(){

    int a = 10;

    {
        int a = 20;
        // 20
        std::cout << a << std::endl;

        {
            int a = 30;
            // 30
            std::cout << a << std::endl;
        } 

        a = 42;
        // 42
        std::cout << a << std::endl;
    }
    // 10
    std::cout << a << std::endl;

    return 0;
}