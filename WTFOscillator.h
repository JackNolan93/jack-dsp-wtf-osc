#include "daisysp.h"
#include "WTFWindow.h"
#include "SinOsc.h"
#include <utility>
 
namespace JackDsp
{


class WTFOscillator 
{
public:

    enum WaveShape
    {
        WS_SIN = 0,
        WS_SAW, 
        WS_RAMP,
        WS_SQUARE,
        WS_TRIANGLE,
        WS_HARMONIC,
        WS_ZERO,
        WS_NUM,
    };

    enum WindowConfig
    {
        Single = 0,
        Dual,
    };

    WTFOscillator () = default;
    ~WTFOscillator () = default;

    void Init (float sampleRate);

    float Process ();

    void SetFreq (float frequency);

    void SetWindowW (float pw);
    void SetWindowConfig (WindowConfig config);

    void SetFrontWaveshape (WaveShape waveshape);
    void SetBackWaveshape (WaveShape waveshape);

    void setFMModDepth (float depth);

    void IncrementFrontWaveshape ();
    void IncrementBackWaveshape ();

    std::pair<int, int> getWaveshapeIndexes ();

private:

    float ComputeNaiveSample (float phase, WaveShape wave);
    float ComputeHarmonicWaveForm (float phase);

    float computeFMPhaseIncrement ();

    // Oscillator state.
    float sample_rate_;
    float frequency_;
    float phase_;
    
    WaveShape _fWave;
    WaveShape _bWave;

    SinOsc _fmOsc;
    float _fmModDepth = 0;
    bool _fmOn = false;

    WTFWindow _window;
    WTFWindow _windowAux;
    float ww_;
};
}