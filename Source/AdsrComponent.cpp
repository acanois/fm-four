#include "AdsrComponent.h"

AdsrComponent::AdsrComponent (FmFourProcessor& p)
    : mProcessor (p)
{
    mSliderBounds.setBounds(0, 100, 100, 100);
    mComponentBounds.setBounds(
        0, 
        0, 
        (mSliderBounds.getWidth()), 
        (mSliderBounds.getHeight())
    );
    std::array<std::string, 4> paramNames = { "attack", "decay", "sustain", "release" };
    
    for (auto paramName : paramNames) {
        auto* envControl = new juce::Slider(
            juce::Slider::RotaryVerticalDrag, 
            juce::Slider::TextBoxBelow
        );
        // auto* envAttachment = new juce::AudioProcessorValueTreeState::SliderAttachment(p.getValueTree(), paramName, *envControl);
        mEnvControls.add(envControl);
        // mEnvAttachments.add(envAttachment);
        addAndMakeVisible(envControl);
    }
}

AdsrComponent::~AdsrComponent()
{
    
}

void AdsrComponent::sliderValueChanged (juce::Slider *slider)
{
    
}

void AdsrComponent::resized()
{
    int xPos = mComponentBounds.getX();
    for (juce::Slider* control : mEnvControls) {
        control->setBounds(
            xPos, 
            mComponentBounds.getY(), 
            mSliderBounds.getWidth(), 
            mSliderBounds.getHeight()
        );
        xPos += (mSliderBounds.getX() + mSliderBounds.getWidth() + 10);
    }
}

void AdsrComponent::paint (juce::Graphics &g)
{
    g.fillAll(juce::Colours::black);
}