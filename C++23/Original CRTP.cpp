template <typename Derived>
class Incrementable {
public:
    Derived& operator ++ () { // prefix
        auto& self = static_cast<Derived&>(*this);
        self.setValue(self.getValue() + 1);

        return self;
    }
    Derived& operator ++ (int) {
        auto& self = static_cast<Derived&>(*this);
        auto tmp = *this;
        self.setValue(self.getValue() + 1);
        return tmp;
    }
};


struct Age: public Incrementable<Age> {
private:
    int x;
public:
    Age(): x{0} {}
    int getValue() {
        return x;
    }
    void setValue(int newV) {
        x = newV;
        return;
    }

};
