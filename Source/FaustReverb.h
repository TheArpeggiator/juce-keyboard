//----------------------------------------------------------
//
// Code generated with Faust 0.9.92 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods :
         * - static class 'classInit' : static table initialisation
         * - 'instanceInit' : constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation : alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustReverb
#endif

class FaustReverb : public dsp {
  private:
	int 	IOTA;
	float 	fVec0[8192];
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fConst1;
	FAUSTFLOAT 	fslider1;
	float 	fConst2;
	float 	fRec11[2];
	FAUSTFLOAT 	fslider2;
	float 	fConst3;
	float 	fConst4;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fConst5;
	float 	fRec10[2];
	float 	fVec1[16384];
	float 	fConst6;
	int 	iConst7;
	float 	fVec2[1024];
	int 	iConst8;
	float 	fRec8[2];
	float 	fRec15[2];
	float 	fConst9;
	float 	fConst10;
	float 	fRec14[2];
	float 	fVec3[16384];
	float 	fConst11;
	int 	iConst12;
	float 	fVec4[2048];
	int 	iConst13;
	float 	fRec12[2];
	float 	fRec19[2];
	float 	fConst14;
	float 	fConst15;
	float 	fRec18[2];
	float 	fVec5[8192];
	float 	fConst16;
	int 	iConst17;
	float 	fVec6[2048];
	int 	iConst18;
	float 	fRec16[2];
	float 	fRec23[2];
	float 	fConst19;
	float 	fConst20;
	float 	fRec22[2];
	float 	fVec7[16384];
	float 	fConst21;
	int 	iConst22;
	float 	fVec8[2048];
	int 	iConst23;
	float 	fRec20[2];
	float 	fRec27[2];
	float 	fConst24;
	float 	fConst25;
	float 	fRec26[2];
	float 	fVec9[8192];
	float 	fConst26;
	int 	iConst27;
	float 	fVec10[1024];
	int 	iConst28;
	float 	fRec24[2];
	float 	fRec31[2];
	float 	fConst29;
	float 	fConst30;
	float 	fRec30[2];
	float 	fVec11[8192];
	float 	fConst31;
	int 	iConst32;
	float 	fVec12[2048];
	int 	iConst33;
	float 	fRec28[2];
	float 	fRec35[2];
	float 	fConst34;
	float 	fConst35;
	float 	fRec34[2];
	float 	fVec13[8192];
	float 	fConst36;
	int 	iConst37;
	float 	fVec14[2048];
	int 	iConst38;
	float 	fRec32[2];
	float 	fRec39[2];
	float 	fConst39;
	float 	fConst40;
	float 	fRec38[2];
	float 	fVec15[8192];
	float 	fConst41;
	int 	iConst42;
	float 	fVec16[1024];
	int 	iConst43;
	float 	fRec36[2];
	float 	fRec0[3];
	float 	fRec1[3];
	float 	fRec2[3];
	float 	fRec3[3];
	float 	fRec4[3];
	float 	fRec5[3];
	float 	fRec6[3];
	float 	fRec7[3];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	float 	fConst44;
	float 	fRec40[3];
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fslider8;
	float 	fRec41[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec42[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec43[2];
	float 	fRec44[3];
	float 	fRec45[3];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("reverb.lib/name", "Faust Reverb Library");
		m->declare("reverb.lib/version", "0.0");
		m->declare("route.lib/name", "Faust Signal Routing Library");
		m->declare("route.lib/version", "0.0");
		m->declare("delay.lib/name", "Faust Delay Library");
		m->declare("delay.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 1; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = (0.001f * fConst0);
		fConst2 = (3.1415927f / fConst0);
		fConst3 = floorf(((0.219991f * fConst0) + 0.5f));
		fConst4 = ((0 - (6.9077554f * fConst3)) / fConst0);
		fConst5 = (6.2831855f / float(fConst0));
		fConst6 = floorf(((0.019123f * fConst0) + 0.5f));
		iConst7 = int((int((fConst3 - fConst6)) & 16383));
		iConst8 = int((int((fConst6 + -1)) & 1023));
		fConst9 = floorf(((0.256891f * fConst0) + 0.5f));
		fConst10 = ((0 - (6.9077554f * fConst9)) / fConst0);
		fConst11 = floorf(((0.027333f * fConst0) + 0.5f));
		iConst12 = int((int((fConst9 - fConst11)) & 16383));
		iConst13 = int((int((fConst11 + -1)) & 2047));
		fConst14 = floorf(((0.192303f * fConst0) + 0.5f));
		fConst15 = ((0 - (6.9077554f * fConst14)) / fConst0);
		fConst16 = floorf(((0.029291f * fConst0) + 0.5f));
		iConst17 = int((int((fConst14 - fConst16)) & 8191));
		iConst18 = int((int((fConst16 + -1)) & 2047));
		fConst19 = floorf(((0.210389f * fConst0) + 0.5f));
		fConst20 = ((0 - (6.9077554f * fConst19)) / fConst0);
		fConst21 = floorf(((0.024421f * fConst0) + 0.5f));
		iConst22 = int((int((fConst19 - fConst21)) & 16383));
		iConst23 = int((int((fConst21 + -1)) & 2047));
		fConst24 = floorf(((0.125f * fConst0) + 0.5f));
		fConst25 = ((0 - (6.9077554f * fConst24)) / fConst0);
		fConst26 = floorf(((0.013458f * fConst0) + 0.5f));
		iConst27 = int((int((fConst24 - fConst26)) & 8191));
		iConst28 = int((int((fConst26 + -1)) & 1023));
		fConst29 = floorf(((0.127837f * fConst0) + 0.5f));
		fConst30 = ((0 - (6.9077554f * fConst29)) / fConst0);
		fConst31 = floorf(((0.031604f * fConst0) + 0.5f));
		iConst32 = int((int((fConst29 - fConst31)) & 8191));
		iConst33 = int((int((fConst31 + -1)) & 2047));
		fConst34 = floorf(((0.174713f * fConst0) + 0.5f));
		fConst35 = ((0 - (6.9077554f * fConst34)) / fConst0);
		fConst36 = floorf(((0.022904f * fConst0) + 0.5f));
		iConst37 = int((int((fConst34 - fConst36)) & 8191));
		iConst38 = int((int((fConst36 + -1)) & 2047));
		fConst39 = floorf(((0.153129f * fConst0) + 0.5f));
		fConst40 = ((0 - (6.9077554f * fConst39)) / fConst0);
		fConst41 = floorf(((0.020346f * fConst0) + 0.5f));
		iConst42 = int((int((fConst39 - fConst41)) & 8191));
		iConst43 = int((int((fConst41 + -1)) & 1023));
		fConst44 = (6.2831855f / fConst0);
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 6e+01f;
		fslider1 = 2e+02f;
		fslider2 = 2.0f;
		fslider3 = 3.0f;
		fslider4 = 6e+03f;
		fslider5 = 0.0f;
		fslider6 = 315.0f;
		fslider7 = 0.0f;
		fslider8 = 1.5e+03f;
		fslider9 = 0.0f;
		fslider10 = -2e+01f;
	}
	virtual void instanceClear() {
		IOTA = 0;
		for (int i=0; i<8192; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<16384; i++) fVec1[i] = 0;
		for (int i=0; i<1024; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<16384; i++) fVec3[i] = 0;
		for (int i=0; i<2048; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<8192; i++) fVec5[i] = 0;
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<16384; i++) fVec7[i] = 0;
		for (int i=0; i<2048; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<8192; i++) fVec9[i] = 0;
		for (int i=0; i<1024; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<8192; i++) fVec11[i] = 0;
		for (int i=0; i<2048; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<8192; i++) fVec13[i] = 0;
		for (int i=0; i<2048; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<8192; i++) fVec15[i] = 0;
		for (int i=0; i<1024; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec45[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual FaustReverb* clone() {
		return new FaustReverb();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER       ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverb.lib for documentation and       references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fslider0, "1", "");
		ui_interface->declare(&fslider0, "style", "knob");
		ui_interface->declare(&fslider0, "tooltip", "Delay in ms    before reverberation begins");
		ui_interface->declare(&fslider0, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fslider0, 6e+01f, 2e+01f, 1e+02f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fslider1, "1", "");
		ui_interface->declare(&fslider1, "scale", "log");
		ui_interface->declare(&fslider1, "style", "knob");
		ui_interface->declare(&fslider1, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fslider1, 2e+02f, 5e+01f, 1e+03f, 1.0f);
		ui_interface->declare(&fslider3, "2", "");
		ui_interface->declare(&fslider3, "scale", "log");
		ui_interface->declare(&fslider3, "style", "knob");
		ui_interface->declare(&fslider3, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fslider3, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fslider3, 3.0f, 1.0f, 8.0f, 0.1f);
		ui_interface->declare(&fslider2, "3", "");
		ui_interface->declare(&fslider2, "scale", "log");
		ui_interface->declare(&fslider2, "style", "knob");
		ui_interface->declare(&fslider2, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fslider2, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fslider2, 2.0f, 1.0f, 8.0f, 0.1f);
		ui_interface->declare(&fslider4, "4", "");
		ui_interface->declare(&fslider4, "scale", "log");
		ui_interface->declare(&fslider4, "style", "knob");
		ui_interface->declare(&fslider4, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fslider4, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fslider4, 6e+03f, 1.5e+03f, 2.352e+04f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fslider6, "1", "");
		ui_interface->declare(&fslider6, "scale", "log");
		ui_interface->declare(&fslider6, "style", "knob");
		ui_interface->declare(&fslider6, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fslider6, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fslider6, 315.0f, 4e+01f, 2.5e+03f, 1.0f);
		ui_interface->declare(&fslider5, "2", "");
		ui_interface->declare(&fslider5, "style", "knob");
		ui_interface->declare(&fslider5, "tooltip", "Peak level    in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fslider5, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fslider5, 0.0f, -15.0f, 15.0f, 0.1f);
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fslider8, "1", "");
		ui_interface->declare(&fslider8, "scale", "log");
		ui_interface->declare(&fslider8, "style", "knob");
		ui_interface->declare(&fslider8, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fslider8, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fslider8, 1.5e+03f, 1.6e+02f, 1e+04f, 1.0f);
		ui_interface->declare(&fslider7, "2", "");
		ui_interface->declare(&fslider7, "style", "knob");
		ui_interface->declare(&fslider7, "tooltip", "Peak level    in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fslider7, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fslider7, 0.0f, -15.0f, 15.0f, 0.1f);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fslider9, "1", "");
		ui_interface->declare(&fslider9, "style", "knob");
		ui_interface->declare(&fslider9, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Dry/Wet Mix", &fslider9, 0.0f, -1.0f, 1.0f, 0.01f);
		ui_interface->declare(&fslider10, "2", "");
		ui_interface->declare(&fslider10, "style", "knob");
		ui_interface->declare(&fslider10, "tooltip", "Output scale    factor");
		ui_interface->declare(&fslider10, "unit", "dB");
		ui_interface->addVerticalSlider("Level", &fslider10, -2e+01f, -7e+01f, 4e+01f, 0.1f);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		int 	iSlow0 = int((int((fConst1 * float(fslider0))) & 8191));
		float 	fSlow1 = (1.0f / tanf((fConst2 * float(fslider1))));
		float 	fSlow2 = (fSlow1 + 1);
		float 	fSlow3 = (0 - ((1 - fSlow1) / fSlow2));
		float 	fSlow4 = (1.0f / fSlow2);
		float 	fSlow5 = float(fslider2);
		float 	fSlow6 = expf((fConst4 / fSlow5));
		float 	fSlow7 = float(fslider3);
		float 	fSlow8 = ((expf((fConst4 / fSlow7)) / fSlow6) + -1);
		float 	fSlow9 = faustpower<2>(fSlow6);
		float 	fSlow10 = (1.0f - fSlow9);
		float 	fSlow11 = cosf((fConst5 * float(fslider4)));
		float 	fSlow12 = (1.0f - (fSlow9 * fSlow11));
		float 	fSlow13 = (fSlow12 / fSlow10);
		float 	fSlow14 = sqrtf(max((float)0, ((faustpower<2>(fSlow12) / faustpower<2>(fSlow10)) + -1.0f)));
		float 	fSlow15 = (fSlow6 * (fSlow14 + (1.0f - fSlow13)));
		float 	fSlow16 = (fSlow13 - fSlow14);
		float 	fSlow17 = expf((fConst10 / fSlow5));
		float 	fSlow18 = ((expf((fConst10 / fSlow7)) / fSlow17) + -1);
		float 	fSlow19 = faustpower<2>(fSlow17);
		float 	fSlow20 = (1.0f - fSlow19);
		float 	fSlow21 = (1.0f - (fSlow11 * fSlow19));
		float 	fSlow22 = (fSlow21 / fSlow20);
		float 	fSlow23 = sqrtf(max((float)0, ((faustpower<2>(fSlow21) / faustpower<2>(fSlow20)) + -1.0f)));
		float 	fSlow24 = (fSlow17 * (fSlow23 + (1.0f - fSlow22)));
		float 	fSlow25 = (fSlow22 - fSlow23);
		float 	fSlow26 = expf((fConst15 / fSlow5));
		float 	fSlow27 = ((expf((fConst15 / fSlow7)) / fSlow26) + -1);
		float 	fSlow28 = faustpower<2>(fSlow26);
		float 	fSlow29 = (1.0f - fSlow28);
		float 	fSlow30 = (1.0f - (fSlow11 * fSlow28));
		float 	fSlow31 = (fSlow30 / fSlow29);
		float 	fSlow32 = sqrtf(max((float)0, ((faustpower<2>(fSlow30) / faustpower<2>(fSlow29)) + -1.0f)));
		float 	fSlow33 = (fSlow26 * (fSlow32 + (1.0f - fSlow31)));
		float 	fSlow34 = (fSlow31 - fSlow32);
		float 	fSlow35 = expf((fConst20 / fSlow5));
		float 	fSlow36 = ((expf((fConst20 / fSlow7)) / fSlow35) + -1);
		float 	fSlow37 = faustpower<2>(fSlow35);
		float 	fSlow38 = (1.0f - fSlow37);
		float 	fSlow39 = (1.0f - (fSlow11 * fSlow37));
		float 	fSlow40 = (fSlow39 / fSlow38);
		float 	fSlow41 = sqrtf(max((float)0, ((faustpower<2>(fSlow39) / faustpower<2>(fSlow38)) + -1.0f)));
		float 	fSlow42 = (fSlow35 * (fSlow41 + (1.0f - fSlow40)));
		float 	fSlow43 = (fSlow40 - fSlow41);
		float 	fSlow44 = expf((fConst25 / fSlow5));
		float 	fSlow45 = ((expf((fConst25 / fSlow7)) / fSlow44) + -1);
		float 	fSlow46 = faustpower<2>(fSlow44);
		float 	fSlow47 = (1.0f - fSlow46);
		float 	fSlow48 = (1.0f - (fSlow11 * fSlow46));
		float 	fSlow49 = (fSlow48 / fSlow47);
		float 	fSlow50 = sqrtf(max((float)0, ((faustpower<2>(fSlow48) / faustpower<2>(fSlow47)) + -1.0f)));
		float 	fSlow51 = (fSlow44 * (fSlow50 + (1.0f - fSlow49)));
		float 	fSlow52 = (fSlow49 - fSlow50);
		float 	fSlow53 = expf((fConst30 / fSlow5));
		float 	fSlow54 = ((expf((fConst30 / fSlow7)) / fSlow53) + -1);
		float 	fSlow55 = faustpower<2>(fSlow53);
		float 	fSlow56 = (1.0f - fSlow55);
		float 	fSlow57 = (1.0f - (fSlow11 * fSlow55));
		float 	fSlow58 = (fSlow57 / fSlow56);
		float 	fSlow59 = sqrtf(max((float)0, ((faustpower<2>(fSlow57) / faustpower<2>(fSlow56)) + -1.0f)));
		float 	fSlow60 = (fSlow53 * (fSlow59 + (1.0f - fSlow58)));
		float 	fSlow61 = (fSlow58 - fSlow59);
		float 	fSlow62 = expf((fConst35 / fSlow5));
		float 	fSlow63 = ((expf((fConst35 / fSlow7)) / fSlow62) + -1);
		float 	fSlow64 = faustpower<2>(fSlow62);
		float 	fSlow65 = (1.0f - fSlow64);
		float 	fSlow66 = (1.0f - (fSlow11 * fSlow64));
		float 	fSlow67 = (fSlow66 / fSlow65);
		float 	fSlow68 = sqrtf(max((float)0, ((faustpower<2>(fSlow66) / faustpower<2>(fSlow65)) + -1.0f)));
		float 	fSlow69 = (fSlow62 * (fSlow68 + (1.0f - fSlow67)));
		float 	fSlow70 = (fSlow67 - fSlow68);
		float 	fSlow71 = expf((fConst40 / fSlow5));
		float 	fSlow72 = ((expf((fConst40 / fSlow7)) / fSlow71) + -1);
		float 	fSlow73 = faustpower<2>(fSlow71);
		float 	fSlow74 = (1.0f - fSlow73);
		float 	fSlow75 = (1.0f - (fSlow11 * fSlow73));
		float 	fSlow76 = (fSlow75 / fSlow74);
		float 	fSlow77 = sqrtf(max((float)0, ((faustpower<2>(fSlow75) / faustpower<2>(fSlow74)) + -1.0f)));
		float 	fSlow78 = (fSlow71 * (fSlow77 + (1.0f - fSlow76)));
		float 	fSlow79 = (fSlow76 - fSlow77);
		float 	fSlow80 = powf(10,(0.05f * float(fslider5)));
		float 	fSlow81 = float(fslider6);
		float 	fSlow82 = (fConst44 * (fSlow81 / sqrtf(max((float)0, fSlow80))));
		float 	fSlow83 = ((1.0f - fSlow82) / (fSlow82 + 1.0f));
		float 	fSlow84 = ((0 - cosf((fConst44 * fSlow81))) * (fSlow83 + 1));
		float 	fSlow85 = powf(10,(0.05f * float(fslider7)));
		float 	fSlow86 = float(fslider8);
		float 	fSlow87 = (fConst44 * (fSlow86 / sqrtf(max((float)0, fSlow85))));
		float 	fSlow88 = ((1.0f - fSlow87) / (fSlow87 + 1.0f));
		float 	fSlow89 = ((0 - cosf((fConst44 * fSlow86))) * (fSlow88 + 1));
		float 	fSlow90 = (0.001f * float(fslider9));
		float 	fSlow91 = (0.001f * powf(10,(0.05f * float(fslider10))));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input0[i];
			fVec0[IOTA&8191] = fTemp0;
			float fTemp1 = (0.3f * fVec0[(IOTA-iSlow0)&8191]);
			fRec11[0] = ((fSlow4 * (fRec7[1] + fRec7[2])) + (fSlow3 * fRec11[1]));
			fRec10[0] = ((fSlow16 * fRec10[1]) + (fSlow15 * (fRec7[1] + (fSlow8 * fRec11[0]))));
			fVec1[IOTA&16383] = ((0.35355338f * fRec10[0]) + 1e-20f);
			float fTemp2 = (((0.6f * fRec8[1]) + fVec1[(IOTA-iConst7)&16383]) - fTemp1);
			fVec2[IOTA&1023] = fTemp2;
			fRec8[0] = fVec2[(IOTA-iConst8)&1023];
			float 	fRec9 = (0 - (0.6f * fVec2[IOTA&1023]));
			float fTemp3 = (fRec8[1] + fRec9);
			fRec15[0] = ((fSlow4 * (fRec3[1] + fRec3[2])) + (fSlow3 * fRec15[1]));
			fRec14[0] = ((fSlow25 * fRec14[1]) + (fSlow24 * (fRec3[1] + (fSlow18 * fRec15[0]))));
			fVec3[IOTA&16383] = ((0.35355338f * fRec14[0]) + 1e-20f);
			float fTemp4 = (((0.6f * fRec12[1]) + fVec3[(IOTA-iConst12)&16383]) - fTemp1);
			fVec4[IOTA&2047] = fTemp4;
			fRec12[0] = fVec4[(IOTA-iConst13)&2047];
			float 	fRec13 = (0 - (0.6f * fVec4[IOTA&2047]));
			float fTemp5 = (fRec13 + (fRec12[1] + fTemp3));
			fRec19[0] = ((fSlow4 * (fRec5[1] + fRec5[2])) + (fSlow3 * fRec19[1]));
			fRec18[0] = ((fSlow34 * fRec18[1]) + (fSlow33 * (fRec5[1] + (fSlow27 * fRec19[0]))));
			fVec5[IOTA&8191] = ((0.35355338f * fRec18[0]) + 1e-20f);
			float fTemp6 = (fVec5[(IOTA-iConst17)&8191] + (fTemp1 + (0.6f * fRec16[1])));
			fVec6[IOTA&2047] = fTemp6;
			fRec16[0] = fVec6[(IOTA-iConst18)&2047];
			float 	fRec17 = (0 - (0.6f * fVec6[IOTA&2047]));
			fRec23[0] = ((fSlow4 * (fRec1[1] + fRec1[2])) + (fSlow3 * fRec23[1]));
			fRec22[0] = ((fSlow43 * fRec22[1]) + (fSlow42 * (fRec1[1] + (fSlow36 * fRec23[0]))));
			fVec7[IOTA&16383] = ((0.35355338f * fRec22[0]) + 1e-20f);
			float fTemp7 = (fVec7[(IOTA-iConst22)&16383] + (fTemp1 + (0.6f * fRec20[1])));
			fVec8[IOTA&2047] = fTemp7;
			fRec20[0] = fVec8[(IOTA-iConst23)&2047];
			float 	fRec21 = (0 - (0.6f * fVec8[IOTA&2047]));
			float fTemp8 = (fRec21 + (fRec20[1] + (fRec17 + (fRec16[1] + fTemp5))));
			fRec27[0] = ((fSlow4 * (fRec6[1] + fRec6[2])) + (fSlow3 * fRec27[1]));
			fRec26[0] = ((fSlow52 * fRec26[1]) + (fSlow51 * (fRec6[1] + (fSlow45 * fRec27[0]))));
			fVec9[IOTA&8191] = ((0.35355338f * fRec26[0]) + 1e-20f);
			float fTemp9 = (fVec9[(IOTA-iConst27)&8191] - (fTemp1 + (0.6f * fRec24[1])));
			fVec10[IOTA&1023] = fTemp9;
			fRec24[0] = fVec10[(IOTA-iConst28)&1023];
			float 	fRec25 = (0.6f * fVec10[IOTA&1023]);
			fRec31[0] = ((fSlow4 * (fRec2[1] + fRec2[2])) + (fSlow3 * fRec31[1]));
			fRec30[0] = ((fSlow61 * fRec30[1]) + (fSlow60 * (fRec2[1] + (fSlow54 * fRec31[0]))));
			fVec11[IOTA&8191] = ((0.35355338f * fRec30[0]) + 1e-20f);
			float fTemp10 = (fVec11[(IOTA-iConst32)&8191] - (fTemp1 + (0.6f * fRec28[1])));
			fVec12[IOTA&2047] = fTemp10;
			fRec28[0] = fVec12[(IOTA-iConst33)&2047];
			float 	fRec29 = (0.6f * fVec12[IOTA&2047]);
			fRec35[0] = ((fSlow4 * (fRec4[1] + fRec4[2])) + (fSlow3 * fRec35[1]));
			fRec34[0] = ((fSlow70 * fRec34[1]) + (fSlow69 * (fRec4[1] + (fSlow63 * fRec35[0]))));
			fVec13[IOTA&8191] = ((0.35355338f * fRec34[0]) + 1e-20f);
			float fTemp11 = ((fTemp1 + fVec13[(IOTA-iConst37)&8191]) - (0.6f * fRec32[1]));
			fVec14[IOTA&2047] = fTemp11;
			fRec32[0] = fVec14[(IOTA-iConst38)&2047];
			float 	fRec33 = (0.6f * fVec14[IOTA&2047]);
			fRec39[0] = ((fSlow4 * (fRec0[1] + fRec0[2])) + (fSlow3 * fRec39[1]));
			fRec38[0] = ((fSlow79 * fRec38[1]) + (fSlow78 * (fRec0[1] + (fSlow72 * fRec39[0]))));
			fVec15[IOTA&8191] = ((0.35355338f * fRec38[0]) + 1e-20f);
			float fTemp12 = ((fTemp1 + fVec15[(IOTA-iConst42)&8191]) - (0.6f * fRec36[1]));
			fVec16[IOTA&1023] = fTemp12;
			fRec36[0] = fVec16[(IOTA-iConst43)&1023];
			float 	fRec37 = (0.6f * fVec16[IOTA&1023]);
			fRec0[0] = (fRec37 + (fRec36[1] + (fRec33 + (fRec32[1] + (fRec29 + (fRec28[1] + (fRec25 + (fRec24[1] + fTemp8))))))));
			fRec1[0] = ((fRec37 + (fRec36[1] + (fRec33 + (fRec32[1] + (fRec29 + (fRec28[1] + (fRec24[1] + fRec25))))))) - fTemp8);
			float fTemp13 = (fRec21 + (fRec20[1] + (fRec16[1] + fRec17)));
			fRec2[0] = ((fRec37 + (fRec36[1] + (fRec33 + (fRec32[1] + fTemp13)))) - (fRec29 + (fRec28[1] + (fRec25 + (fRec24[1] + fTemp5)))));
			fRec3[0] = ((fRec37 + (fRec36[1] + (fRec33 + (fRec32[1] + fTemp5)))) - (fRec29 + (fRec28[1] + (fRec25 + (fRec24[1] + fTemp13)))));
			float fTemp14 = (fRec17 + (fRec16[1] + fTemp3));
			float fTemp15 = (fRec12[1] + fRec13);
			float fTemp16 = (fRec21 + (fRec20[1] + fTemp15));
			fRec4[0] = ((fRec37 + (fRec36[1] + (fRec29 + (fRec28[1] + fTemp16)))) - (fRec33 + (fRec32[1] + (fRec25 + (fRec24[1] + fTemp14)))));
			fRec5[0] = ((fRec37 + (fRec36[1] + (fRec29 + (fRec28[1] + fTemp14)))) - (fRec33 + (fRec32[1] + (fRec25 + (fRec24[1] + fTemp16)))));
			float fTemp17 = (fRec17 + (fRec16[1] + fTemp15));
			float fTemp18 = (fRec21 + (fRec20[1] + fTemp3));
			fRec6[0] = ((fRec37 + (fRec36[1] + (fRec25 + (fRec24[1] + fTemp18)))) - (fRec33 + (fRec32[1] + (fRec29 + (fRec28[1] + fTemp17)))));
			fRec7[0] = ((fRec37 + (fRec36[1] + (fRec25 + (fRec24[1] + fTemp17)))) - (fRec33 + (fRec32[1] + (fRec29 + (fRec28[1] + fTemp18)))));
			float fTemp19 = (0.37f * (fRec1[0] + fRec2[0]));
			float fTemp20 = (fSlow84 * fRec40[1]);
			fRec40[0] = (fTemp19 - (fTemp20 + (fSlow83 * fRec40[2])));
			float fTemp21 = (fTemp20 + fRec40[2]);
			float fTemp22 = (fSlow83 * fRec40[0]);
			float fTemp23 = (0.5f * ((fTemp22 + (fTemp19 + fTemp21)) + (fSlow80 * ((fTemp22 + fTemp21) - fTemp19))));
			float fTemp24 = (fSlow89 * fRec41[1]);
			fRec41[0] = (fTemp23 - (fTemp24 + (fSlow88 * fRec41[2])));
			float fTemp25 = ((fSlow88 * fRec41[0]) + (fTemp24 + fRec41[2]));
			fRec42[0] = (fSlow90 + (0.999f * fRec42[1]));
			float fTemp26 = (fRec42[0] + 1.0f);
			float fTemp27 = (1.0f - (0.5f * fTemp26));
			float fTemp28 = (fVec0[IOTA&8191] * fTemp26);
			fRec43[0] = (fSlow91 + (0.999f * fRec43[1]));
			output0[i] = (FAUSTFLOAT)(0.5f * (fRec43[0] * (fTemp28 + (fTemp27 * ((fTemp23 + fTemp25) + (fSlow85 * (fTemp25 - fTemp23)))))));
			float fTemp29 = (0.37f * (fRec1[0] - fRec2[0]));
			float fTemp30 = (fSlow84 * fRec44[1]);
			fRec44[0] = (fTemp29 - (fTemp30 + (fSlow83 * fRec44[2])));
			float fTemp31 = (fSlow83 * fRec44[0]);
			float fTemp32 = (0.5f * ((fTemp31 + (fRec44[2] + (fTemp29 + fTemp30))) + (fSlow80 * ((fTemp31 + (fTemp30 + fRec44[2])) - fTemp29))));
			float fTemp33 = (fSlow89 * fRec45[1]);
			fRec45[0] = (fTemp32 - (fTemp33 + (fSlow88 * fRec45[2])));
			float fTemp34 = ((fSlow88 * fRec45[0]) + (fTemp33 + fRec45[2]));
			output1[i] = (FAUSTFLOAT)(0.5f * (fRec43[0] * (fTemp28 + (fTemp27 * ((fTemp32 + fTemp34) + (fSlow85 * (fTemp34 - fTemp32)))))));
			// post processing
			fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1]; fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1]; fRec41[1] = fRec41[0];
			fRec40[2] = fRec40[1]; fRec40[1] = fRec40[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec28[1] = fRec28[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			IOTA = IOTA+1;
		}
	}
};


