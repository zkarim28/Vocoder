#include "PluginProcessor.h"
#include "PluginEditor.h"

PhaseVocoderAudioProcessorEditor::PhaseVocoderAudioProcessorEditor (PhaseVocoderAudioProcessor& p)
    : AudioProcessorEditor (p),
      processor (p),
      pitchAttachment (p.state, "Pitch", pitchSlider),
formantAttachment(p.state, "Formants", formantSlider)
{
    pitchSlider.setTextValueSuffix(" st");
    pitchSlider.setValue(0.0f);
    pitchSlider.setSliderStyle(juce::Slider::Rotary);
    
    formantSlider.setSliderStyle(juce::Slider::Rotary);
    
    getLookAndFeel().setColour (juce::Slider::thumbColourId, juce::Colours::green);
    
    addAndMakeVisible(pitchSlider);
    addAndMakeVisible(formantSlider);
    setSize (750, 300);
}

PhaseVocoderAudioProcessorEditor::~PhaseVocoderAudioProcessorEditor()
{
}

void PhaseVocoderAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void PhaseVocoderAudioProcessorEditor::resized()
{
    pitchSlider.setBounds (0, 0, 250, 250);
    formantSlider.setBounds(300, 0, 250, 250);
}
