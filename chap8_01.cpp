
int func(int a, int b){

    return a*b;
}

int main(){

    int i = 1;

    while(i != 10){
        int j = 1;
        while(j != 10){
            std::cout << func(i, j) << "\t"s;
            j++;
        }
        std::cout << "\n";
        i++;
    }

    return 0;
}