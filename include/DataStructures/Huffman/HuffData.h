#ifndef HUFFDATA_H
#define HUFFDATA_H

#include <string>

class HuffData
{
    public:
        HuffData(char rawSymbol):_rawSymbol(rawSymbol), _frequency(1){};
        virtual ~HuffData();
        operator<(HuffData &other){return _frequency < other._frequency;};
        operator>(HuffData &other){return _frequency > other._frequency;};
        operator==(HuffData &other){return _frequency == other._frequency;};

        char _rawSymbol;
        std::string _huffCode;
        unsigned _frequency;
    private:
};

#endif // HUFFDATA_H
