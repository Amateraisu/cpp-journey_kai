#include <bits/stdc++.h>

class Button {
private:
    std::function<void(void)> handler_{};
public:
    Button(std::function<void(void)> click): handler_{click} {}
    void on_click() const {
        handler_();
    }
};

auto create_buttons() {
    auto beep = Button([](){
        std::cout <<"BEEP PRESSED!\n";
    });
    auto boop = Button([counter = 10]() mutable{
        std::cout <<"BOOP PRESSED!\n";
        std::cout <<"counter is " << counter << "\n";
        ++counter;
    });
    auto silent = Button([](){});

    return std::vector<Button>{beep, boop, silent};
}

int main() {
    std::vector<Button>buttons = create_buttons();
    for (Button& b: buttons) {
        b.on_click();
    }

}
