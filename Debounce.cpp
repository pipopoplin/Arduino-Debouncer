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

#include "Debounce.h"

Debounce::Debounce(int pin, boolean pullup, boolean hur)
{
  _pin = pin;
  _pullup = pullup;
  _hur = hur;
  
  pinMode(_pin, INPUT);
  digitalWrite(_pin, _pullup);
}

boolean Debounce::_db(void)
{
  boolean t_v = digitalRead(_pin);
  boolean o_t_v;
  int cnt = 0;
  
  if(t_v != _pullup)
  {
    do
	{
		t_v = digitalRead(_pin);
		o_t_v = t_v;
		delayMicroseconds(_dtus);
		if(digitalRead(_pin) != o_t_v) cnt = 0;
		else cnt++;
	} while(cnt <= _cycles);
    return true;
  }
  else return false;
}

boolean Debounce::dbRead()
{
  boolean db_t_v = _db();
  if(_hur == true && db_t_v == true) while(_db() == true);
  if(db_t_v == true) return true;
  else return false;
}

void Debounce::set_pin(int pin)
{
	_pin = pin;
}

int Debounce::get_pin(void)
{
	return _pin;
}

void Debounce::set_pullup(boolean pullup)
{
	_pullup = pullup;
}

boolean Debounce::get_pullup(void)
{
	return _pullup;
}

void Debounce::set_hur(boolean hur)
{
	_hur = hur;
}

boolean Debounce::get_hur(void)
{
	return _hur;
}

void Debounce::set_cycles(int cycles)
{
	_cycles = cycles;
}

int Debounce::get_cycles(void)
{
	return _cycles;
}

void Debounce::set_dtus(int dtus)
{
	_dtus = dtus;
}
int Debounce::get_dtus(void)
{
	return _dtus;
}
