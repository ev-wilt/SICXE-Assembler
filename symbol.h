#include <string>

class Symbol {
    public:
        Symbol(std::string label, int location, std::string value);
        std::string getLabel();
        int getLocation();
        std::string getValue();

    private:
        std::string label;
        int location;
        std::string value;
        
};