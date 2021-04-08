#include <iostream>
#include <optional>


class FirstNRepeatingStream {
public:
    FirstNRepeatingStream(int N);
    std::optional<char> next(char c);

private:
    int N;
    char c;
};

FirstNRepeatingStream::FirstNRepeatingStream(int N) : N(N) {

}

std::optional<char> FirstNRepeatingStream::next(char c){
    if (c)
        return c;
    return std::nullopt;
}


int main(){
    int N;
    char c;
    std::optional<char> first_c;
    std::cin >> N;

    FirstNRepeatingStream fnrs(N);

    while(std::cin >> c){
        first_c = fnrs.next(c);
        std::cout << first_c.value();
    }
    return 0;
}