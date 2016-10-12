juce-keyboard
=========

Use of the JUCE framework to create computer-keyboard synthesizer.

Implementation Basics
---------

Use of JUCE framework keyboard keypress detection generate midi values for randomly generated scales.

Use of FM synthesis for higher partials using a single modulation frequency and index value (changable using rotatory sliders!)
Main output gain controlled using main gain rotatory slider (much wow!)

The keys on the keyboard correspond to the notes of the scale to be played

i.e. if we start from the note C4

a -> C4
w -> C#4
s -> D4
e -> D#4
d -> E4
f -> F4
t -> F#4
g -> G4
y -> G#4
h -> A4
u -> A#4
j -> B4
k -> C5

Author
-------

Rahul Agnihotri (ragni@ccrma.stanford.edu)