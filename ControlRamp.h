namespace JackDsp
{

class ControlRamp
{
public:
    ControlRamp();
    ~ControlRamp();

    void setBlockSize (int blocksize)
    {
        _blockSize = blocksize; 
    }

    void setValue (float value)
    {
        _targetVal = value;
        _inc = (_targetVal - _currentVal) / _blockSize;
    }

    void setValueImmediate (float value)
    {
        _currentVal = value;
        _targetVal = value;
    }

    bool isRamping ()
    {
        return _targetVal != _currentVal;
    }

    void tick ()
    {   
        if (abs (_targetVal -  _currentVal) <= abs (_inc))
        {
            _currentVal = _targetVal;
            _inc = 0;
            return;
        }

        _currentVal += _inc;
    }

    void tickMultiple (int numTicks)
    {   
        while (numTicks > 0)
        {
            if (abs (_targetVal -  _currentVal) <= abs (_inc))
            {
                _currentVal = _targetVal;
                _inc = 0;
                return;
            }

            _currentVal += _inc;
            --numTicks;
        }
    }

    float getValue () { return _currentVal; }

private:

    float _currentVal = 0;
    float _targetVal = 0;
    float _inc = 0;
    int _blockSize = 0;

};

}
