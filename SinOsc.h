#include "daisysp.h"

class SinOsc
{

public:
    SinOsc() = default;
    ~SinOsc() = default;

    void init (float sampleRate)
    {
        _sampleRate = sampleRate;
    }

    void setFreq (float freq)
    {
        freq  = freq / _sampleRate;
        freq  = freq >= .25f ? .25f : freq;
        _freq = freq;
    }

    float Process()
    {
        _phase += _freq;
        while (_phase > 1.f)
            _phase -= 1.f;

        return sinf (_phase * PI_F * 2); 
    }

private:

    float _sampleRate = 0;
    float _freq = 0;
    float _phase = 0;
};

