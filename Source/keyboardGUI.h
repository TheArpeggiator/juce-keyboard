/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_DF51F3CC7AAABC3C__
#define __JUCE_HEADER_DF51F3CC7AAABC3C__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class keyboardGUI  : public Component,
                     public SliderListener,
                     public ButtonListener
{
public:
    //==============================================================================
    keyboardGUI (MainContentComponent *ptr);
    ~keyboardGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool keyStateChanged(bool isKeyDown);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainContentComponent *ptr;
    KeyPress key;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> mainGain;
    ScopedPointer<Slider> modFreq;
    ScopedPointer<Slider> modIndex;
    ScopedPointer<TextButton> textButton;
    ScopedPointer<Label> freqLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (keyboardGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DF51F3CC7AAABC3C__
