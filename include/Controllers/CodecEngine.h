#ifndef CODECENGINE_H
#define CODECENGINE_H

class CodecEngine
{
    public:
        CodecEngine();
        virtual ~CodecEngine();
        virtual void encode() = 0;
        virtual void decode() = 0;

    protected:

    private:
};

#endif // CODECENGINE_H
