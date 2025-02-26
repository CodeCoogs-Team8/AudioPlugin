#include "Equalizer/PluginEditor.h"
#include "Equalizer/PluginProcessor.h"

namespace audio_plugin {
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p) {
  juce::ignoreUnused(processorRef);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(300, 500);
  gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
  gainSlider.setRange(48.0, 0.0);
  gainSlider.addListener(this);

  addAndMakeVisible(gainSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
  
  
}

void AudioPluginAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  gainSlider.setBounds(getLocalBounds());
}

void AudioPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
  
  if (slider == &gainSlider) {
    processorRef.rawVolume = pow(10, gainSlider.getValue() / 20);
  }
}
}  // namespace audio_plugin
