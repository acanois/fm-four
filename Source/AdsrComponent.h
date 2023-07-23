#pragma once

#include "PluginProcessor.h"

#include "juce_audio_utils/juce_audio_utils.h"
#include "juce_audio_basics/juce_audio_basics.h"

class AdsrComponent 
    : public juce::Component,
      public juce::Slider::Listener
{
public:
    AdsrComponent(FmFourProcessor& p);
    ~AdsrComponent();
    
    void resized() override;
    void paint(juce::Graphics& g) override;
    void sliderValueChanged(juce::Slider* slider) override;
    void initControls(FmFourProcessor& p);
    
    int getComponentHeight() { return mComponentBounds.getHeight(); }

private:
    juce::OwnedArray<juce::Slider> mEnvControls;
    // juce::OwnedArray<juce::AudioProcessorValueTreeState::SliderAttachment> mEnvAttachments;
    juce::Rectangle<int> mComponentBounds;
    juce::Rectangle<int> mSliderBounds;

    FmFourProcessor& mProcessor;
};