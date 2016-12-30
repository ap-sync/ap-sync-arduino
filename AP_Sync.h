#ifndef AP_Sync_h
#define AP_Sync_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

const char valueStart = ':';
const char dataStart = '#';
const char dataEnd = '|';

class AP_Sync{
  public:
    AP_Sync(Stream& s):serial(s){}
    
    template <typename T>
    void sync(T t) {
      serial.print(valueStart);
      serial.print(t);
      serial.print(dataEnd);
      serial.println();
    }
    
    template<typename T, typename... Args>
    void sync(T t, Args... args) // recursive variadic function
    {   
        serial.print(dataStart); 
        serial.print(t);
        sync(args...);
    }

  private:
    Stream& serial;  
};

#endif