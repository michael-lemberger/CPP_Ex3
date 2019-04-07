#include "PhysicalNumber.h"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;
PhysicalNumber::PhysicalNumber(double value, Unit type){
	this->value=value;
	this->type=type;
}

PhysicalNumber::PhysicalNumber(const PhysicalNumber &other){
	this->value=other.value;
	this->type=other.type;
}

const PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other){
PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	this->setValue(cpy.value);
	return *this;
}

PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& other) const{
	PhysicalNumber cpy(other);
		if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}

return PhysicalNumber(this->getValue()+(cpy.getValue()),this->getType());
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const{
PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}

return PhysicalNumber(this->getValue()-(cpy.getValue()),this->getType());
}


PhysicalNumber PhysicalNumber::operator+() const{
	return *this;
}

PhysicalNumber PhysicalNumber::operator-(){
	if(this->getValue()>0)
		this->setValue(-(this->getValue()));
	return *this;
}


const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other){
	PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	this->setValue(this->value+cpy.getValue());
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
	PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	this->setValue(this->value+cpy.getValue());
	return *this;
}

 	PhysicalNumber& PhysicalNumber::operator++()
    {
        this->setValue(this->getValue()+1);
        return *this;
    }

    PhysicalNumber PhysicalNumber::operator++(int)
    {
        PhysicalNumber tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

    PhysicalNumber& PhysicalNumber::operator--()
    {
        this->setValue(this->getValue()-1);
        return *this;
    }

    PhysicalNumber PhysicalNumber::operator--(int)
    {
        PhysicalNumber tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

bool PhysicalNumber::operator==(const PhysicalNumber& other){
	PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	if(this->getValue()==cpy.getValue())
		return true;
	return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber& other){
	PhysicalNumber cpy(other);
		if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	if(this->getValue()<=cpy.value)
		return true;
	return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber& other){
	PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
	else{this->conversion(cpy);}
	if(this->getValue()>=cpy.value)
		return true;
	return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber& other){
		PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
		else{this->conversion(cpy);}
		if(this->getValue()!=cpy.value)
		return true;
	return false;
}

bool PhysicalNumber::operator<(const PhysicalNumber& other){
		PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
		else{this->conversion(cpy);}
		if(this->getValue()<cpy.value)
		return true;
	return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber& other){
		PhysicalNumber cpy(other);
	if(abs(this->getType()-(other.getType()))>=7){
		throw std::invalid_argument("Error: not the same type!");}
		else{this->conversion(cpy);}
		if(this->getValue()>cpy.value)
		return true;
	return false;
}

ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& obj){
	switch(obj.getType()){
		case 0: stream<<obj.getValue()<<"[g]";
		break;
		case 1: stream<<obj.getValue()<<"[kg]";
		break;
		case 2: stream<<obj.getValue()<<"[ton]";
		break;
		case 10: stream<<obj.getValue()<<"[cm]";
		break;
		case 11: stream<<obj.getValue()<<"[m]";
		break;
		case 12: stream<<obj.getValue()<<"[km]";
		break;
		case 20: stream<<obj.getValue()<<"[sec]";
		break;
		case 21: stream<<obj.getValue()<<"[min]";
		break;
		case 22: stream<<obj.getValue()<<"[hour]";
		break;
	}
	return stream;
}

std::istream& ariel::operator>>(std::istream& is, const PhysicalNumber& other){
	return is;
}

void PhysicalNumber::conversion(PhysicalNumber& b) const{
	if(this->getType()<10){
		this->Mconvert(this->getType() ,b);
}
	else if(this->getType()>=10&&this->getType()<20){
		this->Lconvert(this->getType(), b);
	}
	else{
		this->Tconvert(this->getType(), b);
	}

}

	void PhysicalNumber::Mconvert(int x,PhysicalNumber& y) const{
		switch(x){
		case 0:
		if(y.getType()==1){
			y.setValue(y.getValue()*1000);
		}
		if(y.getType()==2){
			y.setValue(y.getValue()*1000*1000);
		}
		break;
		case 1:
		if(y.getType()==0){
			y.setValue(y.getValue()/1000);
		}
		if(y.getType()==2){
			y.setValue(y.getValue()*1000);
		}
		break;	
		case 2:
		if(y.getType()==0){
			y.setValue(y.getValue()/(1000*1000));
		}
		if(y.getType()==1){
			y.setValue(y.getValue()/1000);
		}		
		break;
	}
	}
	void PhysicalNumber::Lconvert(int x,PhysicalNumber& y) const{
		switch(x){
		case 10:
		if(y.getType()==11){
			y.setValue(y.getValue()*100);
		}
		if(y.getType()==12){
			y.setValue(y.getValue()*(1000*100));
		}
		break;
		case 11:
		if(y.getType()==10){
			y.setValue(y.getValue()/100);
		}
		if(y.getType()==12){
			y.setValue(y.getValue()*1000);
		}
		break;	
		case 12:
		if(y.getType()==10){
			y.setValue(y.getValue()/(100*1000));
		}
		if(y.getType()==11){
			y.setValue(y.getValue()/1000);
		}		
		break;
	}
	}
	void PhysicalNumber::Tconvert(int x,PhysicalNumber& y) const{
		switch(x){
		case 20:
		if(y.getType()==21){
			y.setValue(y.getValue()*60);
		}
		if(y.getType()==22){
			y.setValue(y.getValue()*(60*60));
		}
		break;
		case 21:
		if(y.getType()==20){
			y.setValue(y.getValue()/60);
		}
		if(y.getType()==22){
			y.setValue(y.getValue()*60);
		}
		break;	
		case 22:
		if(y.getType()==20){
			y.setValue(y.getValue()/(60*60));
		}
		if(y.getType()==21){
			y.setValue(y.getValue()/60);
		}		
		break;
	}
	}
//add unars operator like p=-a;
// int main(){
// PhysicalNumber p(100,Unit::G);
// PhysicalNumber a(100,Unit::KG);
// p.conversion(a);
// return 0;
// };

