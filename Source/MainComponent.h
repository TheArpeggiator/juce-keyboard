// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Rahul Agnihotri
// Description: Simple JUCE Keyboard

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "Sine.h"
#include "Smooth.h"
#include "FaustReverb.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

class keyboardGUI;

class MainContentComponent :
    public AudioAppComponent,
    private Slider::Listener,
    private ToggleButton::Listener
{
public:
    MainContentComponent();


    ~MainContentComponent();

    void resized() override;


    //function to set freq and gain when keyboard key press is made
    //bool keyStateChanged(bool isKeyDown);

    void sliderValueChanged (Slider* slider) override;

    void buttonClicked (Button* button) override;

    void prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate) override;

    void releaseResources() override;

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;



    void updateFreq(int keyValue);

public:
    //Sliders for UI
    Slider modulatorSlider;
    Slider indexSlider;
    Slider gainSlider;
    ToggleButton onOffButton;

    //Pointer to the keyboard
    keyboardGUI *keyPtr;

    //Labels for the sliders
    Label modulatorLabel;
    Label indexLabel;
    Label gainLabel;
    Label onOffLabel;

    //define obj for keypresses


	FaustReverb reverb;
	MapUI reverbControl;

	float** audioBuffer;

	int nChans;
    float level;
    //osc definitions
    Sine modulator;
    Sine notes;
    Smooth smooth[4]; // to prevent cliking of some of the parameters

    double index, onOff, midi, noteFreq;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//Component* createMainContentComponent()     { return new MainContentComponent(); }

#endif  // MAINCOMPONENT_H_INCLUDED
