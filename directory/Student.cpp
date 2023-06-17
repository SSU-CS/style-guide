#include <iostream>
#include "Student.h"

Student::Student (std::string first, std::string last, std::string addr, int yr, std::string box) 
  :  Entry(first, last, addr)
    {
      year = yr;
      POBox = box;
    }

/** ***********************************************************************
 * @remark output a format Faculty object                                 *
 *                                                                        *
 * @param os  output stream which will receive the formatted Faculty data *
 *                                                                        *
 * @ewmrk  by being a virtual function, implementations in subclasses     *
 *         will be interpreted via polymorphism                           *
 *                                                                        *
 * @returns formatted string on the given output stream                   *
 *                                                                        *
 **************************************************************************/
std::ostream& Student::print (std::ostream &os) const {
   os <<  Entry::print(os)
      << "   Class Year:  " << this->year
      << "\n   Campus P. O. Box:  " << this->POBox + "\n";
 return os;
}


/** ***********************************************************************
 *  @remark main procedure to control processing                          *
 *  uncomment this procedure for unit testing                             *
 **************************************************************************/
/*
int main ( ) {
        // set up three objects
  Student A ("Terry", "Walker", "walkert@math.grin.edu",
             1970, "off-campus");
  Student B ("Henry", "Walker", "walker@cs.grinnell.edu",
             1969, "Y-06");
  Student C ("Barbara", "Walker", "barbara@cs.grin.edu",
             2002, "12-34-56");
  
  // print objects
  std::cout <<  "Results of equals" << std::endl;
  std::cout <<  "Person A:" << A << std::endl;
  std::cout <<  "Person B:" << B << std::endl;
  std::cout <<  "Person C:" << C << std::endl;
  
  // since methods equals and comesBefore are inherited, 
  //     testing may or may not be done here
  
  //check comparisons
  std::cout << "Entries declared in reverse order"  << std::endl;
  std::cout <<  "\tA\tB\tC" << std::endl;
  std::cout <<  "A\t"
            << A.equals(A) << "\t"
            << A.equals(B) << "\t"
            << A.equals(C)
            << std::endl;
  std::cout <<  "B\t"
            << B.equals(A) << "\t"
            << B.equals(B) << "\t"
            << B.equals(C)
            << std::endl;
  std::cout <<  "C\t"
            << C.equals(A) << "\t"
            << C.equals(B) << "\t"
            << C.equals(C)
            << std::endl << std::endl;
  
  std::cout <<  "Results of comesBefore"
            << std::endl;
  std::cout << "\tA\tB\tC"
            << std::endl;
  std::cout << "A\t"
            << A.comesBefore(A)<<  "\t"
            << A.comesBefore(B)<<  "\t"
            << A.comesBefore(C)
            << std::endl;
  std::cout << "B\t"
            << B.comesBefore(A) <<  "\t"
            << B.comesBefore(B)<<  "\t"
            << B.comesBefore(C)
            << std::endl;
  std::cout << "C\t"
            << C.comesBefore(A) <<  "\t"
            << C.comesBefore(B) <<  "\t"
            << C.comesBefore(C)
            << std::endl << std::endl;
}

*/
