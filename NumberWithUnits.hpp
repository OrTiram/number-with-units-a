#pragma once
#include <string>
#include <fstream>
#include <map>


namespace ariel{

class NumberWithUnits{


    private:
      double value;
	    std::string type;   
      static std::map<std::string, std::map<std::string, int>> units;

    public:

      NumberWithUnits(double value, std::string type){
          this -> value = value;
          this -> type = type;
        }

        double getVal() const{
          return this->value;
        }

        static void read_units(std::ifstream& f){}

        NumberWithUnits& operator++();//prefix increment  
        NumberWithUnits& operator--();

        NumberWithUnits& operator+=(const NumberWithUnits& c) ;
        NumberWithUnits& operator-=(const NumberWithUnits& c) ;

        const NumberWithUnits operator+() const;
        const NumberWithUnits operator-() const;

        const NumberWithUnits operator++(int dummy_flag_for_postfix_increment);//postfix increment
        const NumberWithUnits operator--(int dummy_flag_for_postfix_increment);

        friend std::ostream& operator<<(std::ostream& output, const NumberWithUnits& c);
        friend std::istream& operator>>(std::istream& input, NumberWithUnits& c);

        friend bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);	
        friend bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2);

        friend const NumberWithUnits operator-(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend const NumberWithUnits operator+(const NumberWithUnits& c1, const NumberWithUnits& c2);
        friend const NumberWithUnits operator*(const NumberWithUnits& c1, double num);
        friend const NumberWithUnits operator*(double num, const NumberWithUnits& c1);



  };

}





