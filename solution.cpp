#include <iostream>
#include <optional>


class FirstNRepeatingStream {
public:
    FirstNRepeatingStream(int N);
    std::optional<char> next(char c);

private:  // dbg
    int N;
    int state_zero_N;
    bool state_zero;
    int slave_N;

    char lead_c;
    char slave_c;
};

FirstNRepeatingStream::FirstNRepeatingStream(int N) : N(N), state_zero_N(N), state_zero(true), slave_N(N) {}

std::optional<char> FirstNRepeatingStream::next(char c){
    if (this->state_zero == false){
        if (this->N > 0) {
            if (this->lead_c == c){
                --this->N;
                if (this->N == 0)
                    this->lead_c = this->slave_c;
            }
            if (this->slave_N > 0){
                if (this->slave_c == c)
                    --this->slave_N;
            } else {
                this->slave_N = this->state_zero_N;
                this->slave_c = c;
            }
        } else {
            this->N = this->state_zero_N;
            this->lead_c = this->slave_c;
            this->slave_c = c;
            if (this->lead_c == this->slave_c) {
                this->state_zero = true;
                return std::nullopt;
            }
        }
    } else {
        this->state_zero = false;
        this->lead_c = c;
        this->slave_c = c;

        if (this->N > 0){
            --this->N;
        } else {
            return std::nullopt;
        }
    }
    return this->lead_c;
}


int main(){
    int N;
    char c;
    std::optional<char> first_c;
    std::cin >> N;

    FirstNRepeatingStream fnrs(N);

    while(std::cin >> c){
        first_c = fnrs.next(c);
        if (first_c != std::nullopt)
            std::cout << c << " --> " << first_c.value();  // << "   N: " << fnrs.N << " | lead_c: " << fnrs.lead_c << " | slave_c: " << fnrs.slave_c << " | slave_N: " << fnrs.slave_N << std::endl;  // dbg
    }
    return 0;
}