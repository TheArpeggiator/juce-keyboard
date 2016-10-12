// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Rahul Agnihotri
// Description: Simple JUCE Keyboard

#include "MainComponent.h"
#include "keyboardGUI.h"

    MainContentComponent::MainContentComponent()
    :index(0.0),
    onOff (1.0)
    {
        //initialize pointer
        keyPtr = new keyboardGUI(this);

        addAndMakeVisible(keyPtr);
        setSize (600, 400);

		nChans = 2;
        setAudioChannels (0, nChans); // no inputs, one output

		audioBuffer = new float*[nChans];
    }

    MainContentComponent::~MainContentComponent()
    {
        shutdownAudio();
		delete [] audioBuffer;
    }

    void MainContentComponent::resized()
    {
        // placing the UI elements in the main window
        // getWidth has to be used in case the window is resized by the user
        keyPtr->setBounds(0,0,getWidth(),getHeight());
    }

    void MainContentComponent::updateFreq(int keyValue)
    {
        double j;
        j = pow(2,(midi+keyValue-69)/12) * 440;
        notes.setFrequency(j);
        noteFreq = j;
        //String str = MidiMessage::getMidiNoteName((int)midi,true,true,4);
        //keyPtr->freqLabel->setText(str, dontSendNotification);
    }

    void MainContentComponent::sliderValueChanged (Slider* slider)
    {
        if (slider == &modulatorSlider)
            modulator.setFrequency(modulatorSlider.getValue());
        else if (slider == &indexSlider)
            index = indexSlider.getValue();
    }

    void MainContentComponent::buttonClicked (Button* button)
    {
        if(button == &onOffButton && onOffButton.getToggleState())
        {
            midi = rand() % 37 + 48;
            notes.setFrequency(0);
            onOff = 1.0;
        }
        else{
            onOff = 0.0;
        }
    }

    void MainContentComponent::prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate)
    {
        notes.setSamplingRate(sampleRate);
        modulator.setSamplingRate(sampleRate);
        modulator.setFrequency(50.0);
        for(int i=0; i<4; i++){
            smooth[i].setSmooth(0.999);
        }

		reverb.init(sampleRate);
		reverb.buildUserInterface(&reverbControl);
    }

    void MainContentComponent::releaseResources()
    {
    }

    void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        //level = gainSlider.getValue(); // gain is updated every block
        // getting the audio output buffer to be filled
        //float* const buffer = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);

		for(int i=0; i<nChans; i++)
			audioBuffer[i] = bufferToFill.buffer->getWritePointer (i, bufferToFill.startSample);

        // computing one block
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            notes.setFrequency(smooth[0].tick(noteFreq) + modulator.tick()*smooth[3].tick(index)); // modulating freq of the carrier
            audioBuffer[0][sample] = notes.tick() * smooth[1].tick(level) * smooth[2].tick(onOff); // computing sample
        }
		reverb.compute(bufferToFill.numSamples,audioBuffer,audioBuffer);
    }



Component* createMainContentComponent()     { return new MainContentComponent(); }
