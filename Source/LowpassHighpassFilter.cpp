/*
  ==============================================================================

    LowpassHighpassFilter.cpp
    Created: 15 Jul 2023 12:06:53am
    Author:  Rohan Buch

  ==============================================================================
*/

#include "LowpassHighpassFilter.h"

void LowpassHighpassFilter::setHighpass(<#bool highpass#>) { //determine if highpass
    this->highpass = highpass;
}

void LowpassHighpassFilter::setCutoffFrequency(float cutoffFrequency) {
  this->cutoffFrequency = cutoffFrequency;
}

void LowpassHighpassFilter::setSamplingRate(float samplingRate) {
  this->samplingRate = samplingRate;
}

void LowpassHighpassFilter::processBlock(juce::AudioBuffer<float>& buffer,
                                         juce::MidiBuffer&)
{
    constexpr auto PI = 3.14159265359f; //pi
    // now adjust buffers with respect to the channels
    dnBuffer.resize(buffer.getNumChannels(), 0.f);
    
    //highpass is different than lowpass. in fact, it's the opposite. therefore,
    //if it is highpass, invert all output values.
    const auto sign = highpass ? -1.f : 1.f;
    
    //other const vars
    const auto tan = std::tan(PI * cutoffFrequency / samplingRate);
    //allpass coefficient
    const auto al = (tan - 1.f) / (tan + 1.f);
    //processing begins. process each channnel spearately.
    for (auto channel = 0; channel < buffer.getNumChannels(); ++channel) {
    // to access the sample in the channel as a C-style array
    auto channelSamples = buffer.getWritePointer(channel);

    // for each sample in the channel
    for (auto i = 0; i < buffer.getNumSamples(); ++i) {
      const auto inputSample = channelSamples[i];

      // allpass filtering
      const auto allpassFilteredSample = al * inputSample +
                                            dnBuffer[channel];
      dnBuffer[channel] = inputSample - al * allpassFilteredSample;

      // here the final filtering occurs
      // we scale by 0.5 to stay in the [-1, 1] range
      const auto filterOutput =
          0.5f * (inputSample + sign * allpassFilteredSample);

      // assign to the output
      channelSamples[i] = filterOutput;
    }
  }
    
    
    
}
