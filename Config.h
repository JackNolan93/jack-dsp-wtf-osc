class Config
{
public:

    enum ADCChannels 
    {
        windowWidth = 0,
        freq,
        fmMult,
        fmDepth,
        windowCV,
        vOct,

        numChannels,
    };

    //analogue pins
    static constexpr int windowWidthPin = 15;
    static constexpr int freqPin = 16;
    static constexpr int fmMultPin = 20;
    static constexpr int fmDepthPin = 21;
    static constexpr int windowCVPin = 24;
    static constexpr int vOctPin = 25;

    //digi pins
    static constexpr int waveform1Pin = 29;
    static constexpr int waveform2Pin = 30;
    static constexpr int windowConfigPin = 28;

    //mux pins
    static constexpr int waveform1MuxPin0 = 1;
    static constexpr int waveform1MuxPin1 = 2;
    static constexpr int waveform1MuxPin2 = 3;

    static constexpr int waveform2MuxPin0 = 7;
    static constexpr int waveform2MuxPin1 = 6;
    static constexpr int waveform2MuxPin2 = 5;

    Config() = default;
    ~Config() = default;
};


