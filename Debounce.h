/*************************************
  Filename: Debounce.cpp
  Version: v0.01
  last update: 28. September 2015
  Purpose: Debouncing Switches
  Author: Simon Aeschbacher
  Licence: GPLv2
*************************************/

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Debounce
{
  public:
    Debounce(int pin, boolean pullup, boolean hur);			// pin(Pin on Arduino, en_pullup (Enables pullupresistor), hur (hold until release))
	boolean dbRead(void);									// returns if switch is active
	
	void    set_pin(int pin);
	int     get_pin(void);
	void    set_pullup(boolean pullup);
	boolean get_pullup(void);
	void    set_hur(boolean hur);
	boolean get_hur(void);
	void    set_cycles(int cycles);
	int     get_cycles(void);
	void    set_dtus(int dtus);
	int     get_dtus(void);
	
  private:
    boolean _db(void);

    	int  	_pin;
	boolean _pullup;
	boolean _hur;
	int     _cycles = 20;
	int     _dtus = 100;
};
