#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
FmFourEditor::FmFourEditor(FmFourProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p), mKeyboardComponent(mKeyBoardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    juce::ignoreUnused(processorRef);

    mSliderBounds.setBounds (0, 100, 100, 100);
    mComponentBounds.setBounds (0, 0, (mSliderBounds.getWidth() * 4), (mSliderBounds.getHeight()));

    addAndMakeVisible(mKeyboardComponent);
    addAndMakeVisible(*mAdsrComponent);

    setSize(1280, 720);
}

FmFourEditor::~FmFourEditor() {
}

//==============================================================================
void FmFourEditor::paint (juce::Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void FmFourEditor::resized() {
    auto area = getLocalBounds();

    juce::Rectangle<int> componentBounds;
    componentBounds.setBounds(100, 100, 100, 100);
    mKeyboardComponent.setBounds(area.removeFromBottom(80).reduced(8));

    mAdsrComponent->setBounds(area.removeFromTop(mAdsrComponent->getComponentHeight()));
}
