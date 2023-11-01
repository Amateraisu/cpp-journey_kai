


#ifndef KAI_H
#define KAI_H
class Kai {
public:
    Kai(); // default constructor
    Kai(Kai const& other); //copy constructor
    ~Kai(); // destructor
    Kai(Kai const&& other);
    Kai& operator = (Kai const& other);
    Kai& operator = (Kai const&& other); // this is the same as the copy constructor

};
#endif // KAI_H