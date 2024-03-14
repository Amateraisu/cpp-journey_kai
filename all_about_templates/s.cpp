
#include <bits/stdc++.h>
using namespace std;


std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str); // Initialize stringstream with the input string
    std::string token;

    // Extract each word
    while (getline(ss, token, ' ')) {
        result.push_back(token);
    }

    return result;
}





int main(ll time_to_live, vector<string>& queries) {
    using ll = long long;
    ll TTL = time_to_live;
    map<string, int>mp; // this one keeps track of each token's expiry
    set<pair<int, string>>s;
    multiset<pair<int, string>>ms;
    vector<int>res;
    for (auto& q: queries ) {
        auto qs = split(q);
        if (qs.size() == 3) {

        } else {
            string token = qs[1];
            int time = stoi(qs[2]);
            if (qs[0] == "generate") {
                ms.insert()
            } else {

            }
        }
    }
}
