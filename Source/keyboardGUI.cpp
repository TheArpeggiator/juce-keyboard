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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "keyboardGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
keyboardGUI::keyboardGUI (MainContentComponent *ptr)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->ptr = ptr;
    //[/Constructor_pre]

    addAndMakeVisible (mainGain = new Slider ("gainSlider"));
    mainGain->setRange (0, 1, 0);
    mainGain->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    mainGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    mainGain->setColour (Slider::backgroundColourId, Colour (0xff8a3d3d));
    mainGain->setColour (Slider::thumbColourId, Colour (0xff333341));
    mainGain->setColour (Slider::trackColourId, Colour (0xff661b1b));
    mainGain->setColour (Slider::rotarySliderFillColourId, Colour (0xffdc1414));
    mainGain->setColour (Slider::rotarySliderOutlineColourId, Colours::red);
    mainGain->setColour (Slider::textBoxHighlightColourId, Colour (0xff23235b));
    mainGain->setColour (Slider::textBoxOutlineColourId, Colour (0xb2ee0000));
    mainGain->addListener (this);

    addAndMakeVisible (modFreq = new Slider ("modFreqSlider"));
    modFreq->setRange (0, 300, 5);
    modFreq->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modFreq->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    modFreq->setColour (Slider::rotarySliderFillColourId, Colour (0x7f188f2c));
    modFreq->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff2b9a23));
    modFreq->addListener (this);

    addAndMakeVisible (modIndex = new Slider ("modIndexLabel"));
    modIndex->setRange (0, 150, 5);
    modIndex->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modIndex->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    modIndex->setColour (Slider::rotarySliderFillColourId, Colour (0x7f007cff));
    modIndex->setColour (Slider::rotarySliderOutlineColourId, Colour (0x7f007cff));
    modIndex->addListener (this);

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("RANDOMIZE!"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0xffff9849));

    addAndMakeVisible (freqLabel = new Label ("new label",
                                              String()));
    freqLabel->setFont (Font ("Nimbus Mono L", 47.30f, Font::plain));
    freqLabel->setJustificationType (Justification::centred);
    freqLabel->setEditable (false, false, false);
    freqLabel->setColour (Label::outlineColourId, Colours::black);
    freqLabel->setColour (TextEditor::textColourId, Colours::black);
    freqLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

keyboardGUI::~keyboardGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mainGain = nullptr;
    modFreq = nullptr;
    modIndex = nullptr;
    textButton = nullptr;
    freqLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void keyboardGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x3affffff));

    g.setGradientFill (ColourGradient (Colours::white,
                                       304.0f, 192.0f,
                                       Colours::black,
                                       static_cast<float> (-176), static_cast<float> (-152),
                                       true));
    g.fillRoundedRectangle (4.0f, 3.0f, 596.0f, 397.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font ("URW Chancery L", 31.90f, Font::plain));
    g.drawText (TRANS("Main Gain"),
                44, 243, 204, 37,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font ("URW Chancery L", 21.30f, Font::plain));
    g.drawText (TRANS("Modulation Frequency"),
                332, 147, 200, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font ("URW Chancery L", 23.20f, Font::plain));
    g.drawText (TRANS("Modulation Index"),
                332, 243, 200, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font ("Nimbus Mono L", 33.10f, Font::plain));
    g.drawText (TRANS("JUCE_Keyboard"),
                140, 27, 332, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void keyboardGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mainGain->setBounds (40, 104, 215, 128);
    modFreq->setBounds (344, 80, 176, 64);
    modIndex->setBounds (344, 176, 176, 64);
    textButton->setBounds (352, 296, 168, 64);
    freqLabel->setBounds (72, 296, 152, 64);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void keyboardGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mainGain)
    {
        //[UserSliderCode_mainGain] -- add your slider handling code here..
        ptr->level = mainGain->getValue();
        //[/UserSliderCode_mainGain]
    }
    else if (sliderThatWasMoved == modFreq)
    {
        //[UserSliderCode_modFreq] -- add your slider handling code here..
        ptr->modulator.setFrequency(modFreq->getValue());
        //[/UserSliderCode_modFreq]
    }
    else if (sliderThatWasMoved == modIndex)
    {
        //[UserSliderCode_modIndex] -- add your slider handling code here..
        ptr->index = modIndex->getValue();
        //[/UserSliderCode_modIndex]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void keyboardGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        ptr->midi = rand() % 37 + 50;
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool keyboardGUI::keyStateChanged(bool isKeyDown)
    {

     double j;
        if(key.isKeyCurrentlyDown('a'))
        {
            ptr->updateFreq(0);
            String str = MidiMessage::getMidiNoteName(ptr->midi+0,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('w'))
        {
            ptr->updateFreq(1);
            String str = MidiMessage::getMidiNoteName(ptr->midi+1,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('s'))
        {
            ptr->updateFreq(2);
            String str = MidiMessage::getMidiNoteName(ptr->midi+2,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('e'))
        {
            ptr->updateFreq(3);
            String str = MidiMessage::getMidiNoteName(ptr->midi+3,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }

        else if(key.isKeyCurrentlyDown('d'))
        {
            ptr->updateFreq(4);
            String str = MidiMessage::getMidiNoteName(ptr->midi+4,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }

        else if(key.isKeyCurrentlyDown('f'))
        {
            ptr->updateFreq(5);
            String str = MidiMessage::getMidiNoteName(ptr->midi+5,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }

        else if(key.isKeyCurrentlyDown('t'))
        {
            ptr->updateFreq(6);
            String str = MidiMessage::getMidiNoteName(ptr->midi+6,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }

        else if(key.isKeyCurrentlyDown('g'))
        {
            ptr->updateFreq(7);
            String str = MidiMessage::getMidiNoteName(ptr->midi+7,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('y'))
        {
            ptr->updateFreq(8);
            String str = MidiMessage::getMidiNoteName(ptr->midi+8,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }

        else if(key.isKeyCurrentlyDown('h'))
        {
            ptr->updateFreq(9);
            String str = MidiMessage::getMidiNoteName(ptr->midi+9,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('u'))
        {
            ptr->updateFreq(10);
            String str = MidiMessage::getMidiNoteName(ptr->midi+10,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('j'))
        {
            ptr->updateFreq(11);
            String str = MidiMessage::getMidiNoteName(ptr->midi+11,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else if(key.isKeyCurrentlyDown('k'))
        {
            ptr->updateFreq(12);
            String str = MidiMessage::getMidiNoteName(ptr->midi+12,true,true,4);
            freqLabel->setText(str, dontSendNotification);
        }
        else
        {
            ptr->notes.setFrequency(0);
            ptr->noteFreq = j;
        }
    }
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="keyboardGUI" componentName=""
                 parentClasses="public Component" constructorParams="MainContentComponent *ptr"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="3affffff">
    <ROUNDRECT pos="4 3 596 397" cornerSize="10" fill=" radial: 304 192, -176 -152, 0=ffffffff, 1=ff000000"
               hasStroke="0"/>
    <TEXT pos="44 243 204 37" fill="solid: ff000000" hasStroke="0" text="Main Gain"
          fontname="URW Chancery L" fontsize="31.899999999999998579" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="332 147 200 30" fill="solid: ff000000" hasStroke="0" text="Modulation Frequency"
          fontname="URW Chancery L" fontsize="21.300000000000000711" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="332 243 200 30" fill="solid: ff000000" hasStroke="0" text="Modulation Index"
          fontname="URW Chancery L" fontsize="23.199999999999999289" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="140 27 332 30" fill="solid: ff000000" hasStroke="0" text="JUCE_Keyboard"
          fontname="Nimbus Mono L" fontsize="33.100000000000001421" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="gainSlider" id="1842705a3cacf5aa" memberName="mainGain"
          virtualName="" explicitFocusOrder="0" pos="40 104 215 128" bkgcol="ff8a3d3d"
          thumbcol="ff333341" trackcol="ff661b1b" rotarysliderfill="ffdc1414"
          rotaryslideroutline="ffff0000" textboxhighlight="ff23235b" textboxoutline="b2ee0000"
          min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="modFreqSlider" id="413662b03fe8a655" memberName="modFreq"
          virtualName="" explicitFocusOrder="0" pos="344 80 176 64" rotarysliderfill="7f188f2c"
          rotaryslideroutline="ff2b9a23" min="0" max="300" int="5" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="modIndexLabel" id="a877f16c2ea9ef2d" memberName="modIndex"
          virtualName="" explicitFocusOrder="0" pos="344 176 176 64" rotarysliderfill="7f007cff"
          rotaryslideroutline="7f007cff" min="0" max="150" int="5" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="new button" id="200726ce09414cbb" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="352 296 168 64" bgColOff="ffff9849"
              buttonText="RANDOMIZE!" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="71b159c4861c049b" memberName="freqLabel"
         virtualName="" explicitFocusOrder="0" pos="72 296 152 64" outlineCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Nimbus Mono L"
         fontsize="47.299999999999997158" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
