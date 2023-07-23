#pragma once

// include first
#include "PluginProcessor.h"
#include "AdsrComponent.h"

#include "juce_audio_utils/juce_audio_utils.h"
#include "juce_audio_basics/juce_audio_basics.h"

//==============================================================================
class FmFourEditor : public juce::AudioProcessorEditor
{
public:
    explicit FmFourEditor (FmFourProcessor&);
    ~FmFourEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // Processor reference
    FmFourProcessor& processorRef;

    // Keyboard
    juce::MidiKeyboardState mKeyBoardState;
    juce::MidiKeyboardComponent mKeyboardComponent;

    std::unique_ptr<AdsrComponent> mAdsrComponent = std::make_unique<AdsrComponent>(processorRef);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmFourEditor)
};
