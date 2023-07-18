/*
  ==============================================================================

    LowpassHighpassFilter.h
    Created: 15 Jul 2023 12:06:53am
    Author:  Rohan Buch

  ==============================================================================
*/

#pragma once
#include <vector>
#include "JuceHeader.h"

class LowpassHighpassFilter
{
public:
    void setHighpass(bool highpass);
    void setCutoffFrequency(float cutoffFrequency);
    void setSamplingRate(float samplingRate);
    
    // Does not necessarily need to use JUCE's audio buffer
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
    bool highpass;
    float cutoffFrequency;
    float samplingRate;

  // allpass filters' buffers: 1 sample per channel
  std::vector<float> dnBuffer;
};
