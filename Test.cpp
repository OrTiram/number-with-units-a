#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("operator++, operartor-- ,prefix"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{5,"kg"};
    NumberWithUnits b{4,"kg"};
    NumberWithUnits c{2,"kg"};
    NumberWithUnits d{1,"kg"};

//operator++
    d = ++b; //d = b = 5
    CHECK(d==a);
    CHECK(d==b);
    d = ++c;
    CHECK(d==c);
    CHECK(d.getVal()==3);
    CHECK(c.getVal()==3);

//operator--
    d = --c;
    CHECK(d.getVal()==2);
    CHECK(d==c);
    --d;
    CHECK(d.getVal()==1); 
}

TEST_CASE("operator++, operartor-- ,postfix"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{5,"kg"};
    NumberWithUnits b{4,"kg"};
    NumberWithUnits c{2,"kg"};
    NumberWithUnits d{1,"kg"};

//operator++
    d = ++b; //d = b = 5
    CHECK(d==a);
    CHECK(d==b);
    d = ++c;
    CHECK(d==c);
    CHECK(d.getVal()==3);
    CHECK(c.getVal()==3);

//operator--
    d = --c;
    CHECK(d.getVal()==2);
    CHECK(d==c);
    --d;
    CHECK(d.getVal()==1); 
}
TEST_CASE("operator+=, operartor-= "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{5,"ton"};
    NumberWithUnits b{4,"ton"};
    NumberWithUnits c{2,"ton"};
    NumberWithUnits d{1,"ton"};

//operator+=
    CHECK(d.getVal()==1);
    d+=b;
    CHECK(d.getVal()==5);
    CHECK(d==a);
    d+=c;
    CHECK(d.getVal()==7);

//operator-=
    d-=b;
    CHECK(d.getVal()==3);
    d-=c;
    CHECK(d.getVal()==1);
    d-=d;
    CHECK(d.getVal()==0);

}


TEST_CASE("operator+, operartor- "){//unary
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1,"km"};
    NumberWithUnits b{2,"km"};
    NumberWithUnits c{3,"km"};

//operator+
    NumberWithUnits d = +a;
    CHECK(d.getVal()==1);
    d = +b;
    CHECK(d.getVal()==2);
    CHECK(d!=a);
    d = +c;
    CHECK(d==c);

//operator-
    d = -b;
    CHECK(d.getVal()==-2);
    d+= d;
    CHECK(d.getVal()==0);
    d=-c;
    CHECK(d.getVal()==-3);

}

TEST_CASE("operator==, operartor!= "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1,"ton"};
    NumberWithUnits b{2,"ton"};
    NumberWithUnits c{3,"ton"};
    NumberWithUnits d{1,"ton"};
    NumberWithUnits e{2,"ton"};

//operator ==
    CHECK(a==d);
    CHECK(b==e);
    b = b + a ;
    CHECK(b.getVal()==3);
    CHECK(b==c);

//operator !=
    CHECK(a!=c);
    CHECK(b!=d);
    e = a + b ;
    CHECK(e!=b);
}

TEST_CASE("operator<, operartor>, operator<=, operartor>="){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1,"min"};
    NumberWithUnits b{2,"min"};
    NumberWithUnits c{3,"min"};
    NumberWithUnits d{4,"min"};
    NumberWithUnits e{5,"min"};
    NumberWithUnits f{6,"min"};

    CHECK(a < b);
    CHECK(b < c);
    CHECK(a < c);
    b--;
    CHECK(a <= b);
    CHECK(f > e);
    f--;
    CHECK(f >= e);

    CHECK(d > c);
    CHECK(c > b);
    CHECK(d > d);
    d--;
    CHECK(d >= c);
    }

TEST_CASE("operator+, operartor-"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1,"hour"};
    NumberWithUnits b{2,"hour"};
    NumberWithUnits c{3,"hour"};
    NumberWithUnits d{4,"hour"};
    NumberWithUnits e{5,"hour"};
    NumberWithUnits f{6,"hour"};

//operator+
    NumberWithUnits g = a+b;
    CHECK(g.getVal() == 3);
    c = d+e;
    CHECK(c.getVal() == 9);
    NumberWithUnits z = g+e;
    CHECK(z.getVal() == 12);
    CHECK(b == a);
    CHECK(b.getVal() == 1);
//operator-
    NumberWithUnits h = z-b;
    CHECK(h.getVal() == 11);
    c = h;
    CHECK(c == h);
    NumberWithUnits y = h-b;
    CHECK(y.getVal() == 10);

}

TEST_CASE("operator*"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1,"m"};
    NumberWithUnits b{2,"m"};
    NumberWithUnits c{3,"m"};
    NumberWithUnits d{4,"m"};
    NumberWithUnits e{5,"m"};
    NumberWithUnits g{6,"m"};
    NumberWithUnits f = a*2;

    CHECK(f==b);
    b = b*2;
    CHECK(b==d);
    c = 2*c;
    CHECK(c==g);  

}

TEST_CASE("operator>>"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    
	istringstream input1{"100 cm"};
	istringstream input2{"10 cm"};
	NumberWithUnits a{10, "cm"};
    NumberWithUnits b{7, "ton"};
    CHECK(a!=b);
 	input2 >> b;
	CHECK(a == b);
	input1 >> a;
	CHECK( a != b);	
}

TEST_CASE("operator<<"){
	ifstream units_file{"units.txt"};
	NumberWithUnits::read_units(units_file);
	 
    NumberWithUnits m(10, "m");
    NumberWithUnits t(5, "ton");
    NumberWithUnits kg(20, "kg");

    ostringstream s1, s2, s3;
    s1 << m;    
    s2 << t;    
    s3 << kg;   

    CHECK(s1.str() == "10[m]");
    CHECK(s2.str() == "5[ton]");
    CHECK(s3.str() == "20[kg]");	
}


TEST_CASE("good codes"){ 
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits USD{1,"USD"};
    NumberWithUnits ILS{3,"ILS"};
    NumberWithUnits km{3,"km"};
    NumberWithUnits m{40,"m"};
    NumberWithUnits kg{200,"kg"};
    NumberWithUnits ton{1,"ton"};
    NumberWithUnits hour{3,"hour"};
    NumberWithUnits min{30,"min"};

    CHECK(USD!=ILS);
    CHECK((km+m)==NumberWithUnits{3.4,"km"});
    CHECK((USD+ILS).getVal()==1.3);
    CHECK((hour+min).getVal()== 3.5);


 }

