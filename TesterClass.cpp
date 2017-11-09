#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "TesterClass.h"

TesterClass::TesterClass() {
	num = 0;
}

TesterClass::TesterClass(int i) {
	num = i;
}

TesterClass::~TesterClass() {

}

bool TesterClass::operator==(const TesterClass& rhs) {
	if(this->num == rhs.num)
		return true;
	return false;
}

bool TesterClass::operator<(const TesterClass& rhs) {
	if(this->num < rhs.num)
		return true;
	return false;
}

bool TesterClass::operator>(const TesterClass& rhs) {
	if(this->num > rhs.num)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& o, const TesterClass& tc) {
	o << tc.num;
	return o;
}
