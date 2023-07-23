#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
FmFourEditor::FmFourEditor(FmFourProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p), mKeyboardComponent(mKeyBoardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    juce::ignoreUnused(processorRef);

    mSliderBounds.setBounds (0, 100, 100, 100);
    mComponentBounds.setBounds (0, 0, (mSliderBounds.getWidth() * 4), (mSliderBounds.getHeight()));

    std::array<std::string, 4> paramNames = { "attack", "decay", "sustain", "release" };
    
    for (auto paramName : paramNames) {
        auto* envControl = new juce::Slider(juce::Slider::RotaryVerticalDrag, juce::Slider::TextBoxBelow);
        // auto* envAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(p.getValueTree(), paramName, *envControl);
        mEnvControls.add(envControl);
        // mEnvAttachments.add(envAttachment);
        addAndMakeVisible(envControl);
    }

    addAndMakeVisible(mKeyboardComponent);

    setSize(1280, 720);
}

FmFourEditor::~FmFourEditor() {
}

//==============================================================================
void FmFourEditor::paint (juce::Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void FmFourEditor::resized() {
    auto area = getLocalBounds();
    
    auto xPos = area.getX();
    for (juce::Slider* control : mEnvControls) {
        control->setBounds(
            xPos, 
            mComponentBounds.getY(), 
            mSliderBounds.getWidth(), 
            mSliderBounds.getHeight()
        );
        xPos += (mSliderBounds.getX() + mSliderBounds.getWidth() + 10);
    }

    juce::Rectangle<int> componentBounds;
    componentBounds.setBounds(100, 100, 100, 100);
    mKeyboardComponent.setBounds(area.removeFromBottom(80).reduced(8));
}
