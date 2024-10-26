//
// Created by A00257049 on 2019-01-22.
//

#ifndef DOLLAR_DOLLAR_HPP
#define DOLLAR_DOLLAR_HPP
class Dollar {

private:
   int num; //private
   //friend function unaffected by visibility, not a member function
   friend Dollar sum(const Dollar &d1, const Dollar &d2);

public:
   Dollar(int d) : num(d){};
   int GetNum(){return num;}
};
#endif //DOLLAR_DOLLAR_HPP
