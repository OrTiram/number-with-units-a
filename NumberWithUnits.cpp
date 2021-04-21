#include "NumberWithUnits.hpp"

using namespace std;
namespace ariel{

        
       const NumberWithUnits NumberWithUnits::operator+() const{
            return *this;
        }

       const NumberWithUnits NumberWithUnits::operator-() const{
            return *this;
        }

        NumberWithUnits&  NumberWithUnits::operator++(){
            return *this;
        }    
        NumberWithUnits&  NumberWithUnits::operator--(){
            return *this;
        }

        NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& c) {
            return *this;
        }
        
        NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& c) {
            return *this;
        }
   
        const NumberWithUnits NumberWithUnits::operator++(int dummy_flag_for_postfix_increment){
            return *this;
        }
        const NumberWithUnits NumberWithUnits::operator--(int dummy_flag_for_postfix_increment){
            return *this;
        }

        ostream& operator<<(ostream& output, const NumberWithUnits& c){
            return output;
        }
		istream& operator>>(istream& input, NumberWithUnits& c){
            return input;
        }

		 bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2){
            return true;
         }
		 bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return true;
         }
		 bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return true;
         }	
		 bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return true;
         }
		 bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return true;
         }
		 bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return true;
         }
		 const NumberWithUnits operator-(const NumberWithUnits& c1, const NumberWithUnits& c2){
             return NumberWithUnits(c1.value - c2.value ,"-");
         }
		 const NumberWithUnits operator+(const NumberWithUnits& c1, const NumberWithUnits& c2){
                return NumberWithUnits(c1.value + c2.value ,"+");
         }

		 const NumberWithUnits operator*(const NumberWithUnits& c1, double num){
             return NumberWithUnits(c1.value*num,"*");
         }
         const NumberWithUnits operator*(double num, const NumberWithUnits& c1 ){
             return NumberWithUnits(num*c1.value,"*");
         }

};
