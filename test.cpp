
int a = 2;

void func1(int a){
    a = a + 1;
}
void func2(){
    a = a + 1;
}

int main(){

    func1(a);
    std::cout << a << std::endl;
    func2();
    std::cout << a << std::endl;

}