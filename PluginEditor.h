#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

class PhaseVocoderAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    PhaseVocoderAudioProcessorEditor (PhaseVocoderAudioProcessor&);
    ~PhaseVocoderAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    PhaseVocoderAudioProcessor& processor; // Use a reference here
    
    //Here we create two knobs
    
    //One for shift/pitch
    juce::Slider pitchSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment pitchAttachment;
    
    //Another knob that controls the amount of formants
    juce::Slider formantSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment formantAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaseVocoderAudioProcessorEditor)
};
