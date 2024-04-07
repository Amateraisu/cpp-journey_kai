#include <bits/stdc++.h>



class X {
private:
    connection_info connection_details;
    connection_handle connection;
    std::once_flag connection_init_flag;
    void open() {
        connection = open_connection(connection_details);
    }

public:
    X(connection_info const& connection_details_):connection_details(connection_details_){}
    std::call_once on send and receive;
};
