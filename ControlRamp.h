class ControlRamp
{
public:
    ControlRamp();
    ~ControlRamp();

    void setBlockSize (int blocksize)
    {
        _blocksize = blocksize; 
    }

    void setValue (float value)
    {
        _targetVal = value;
        _inc = (_targetVal - _currentVal) / bloackSize;
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
        if (abs (_targetVal -  _currentVal) =< abs (_inc))
        {
            _currentVal = _targetValue;
            _inc = 0;
            return;
        }

        _currentVal += _inc;
    }

    void tickMultiple (int numTicks)
    {   
        while (numTicks > 0)
        {
            if (abs (_targetVal -  _currentVal) =< abs (_inc))
            {
                _currentVal = _targetValue;
                _inc = 0;
                return;
            }

            _currentVal += _inc;
            --numTicks;
        }
    }

    float getValue 

priavte:

    float _currentVal = 0;
    float _targetVal = 0;
    float _inc = 0;
    int _blockSize = 0;

};

}
