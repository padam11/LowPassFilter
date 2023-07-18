/*
  ==============================================================================

    LowpassHighpassFilter.cpp
    Created: 15 Jul 2023 12:06:53am
    Author:  Rohan Buch

  ==============================================================================
*/

#include "LowpassHighpassFilter.h"

void LowpassHighpassFilter::setHighpass(<#bool highpass#>) {
    this->highpass = highpass;
}

void LowpassHighpassFilter::setCutoffFrequency(float cutoffFrequency) {
  this->cutoffFrequency = cutoffFrequency;
}

void LowpassHighpassFilter::setSamplingRate(float samplingRate) {
  this->samplingRate = samplingRate;
}

