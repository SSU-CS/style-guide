/** ***********************************************************************
 * @remark  Entry:  a base class for entries within a School Directory    *
 *    A base entry holds a first name, last name, and email address       *
 *                                                                        *
 * @remark Base capabilities include:                                     *
 *    Base constructors                                                   *
 *    Comparison operations depend upon last names, then first names      *
 *    Formatted output                                                    *
 *                                                                        *
 * @remark: files include header (Entry.h) and Implementation (Entry.cpp) *
 *                                                                        *
 * @remark  Uncomment a main program for unit testing                     *
 *                                                                        *
 * @author Henry M. Walker                                                *
 * @date January 11, 2023                                                 *
 *                                                                        *
 * @remark References                                                     *
 * @remark A School Directory as an Example of Object-Oriented Design     *
 *    http://localhost/courses/cpp-style-guide/directory/index.php        *
 *                                                                        *
 **************************************************************************/

#include <iostream>
#include "Entry.h"

/** ***********************************************************************
 * @remark Default constructor (with no parameters)                       *
 **************************************************************************/
Entry::Entry() {
}

/** ***********************************************************************
 * @remark Full-parameter constructor                                     *
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 * @param eAddress a person's email address                               *
 *                                                                        *
 **************************************************************************/
Entry::Entry (std::string first, std::string last, std::string eAddress) {
  firstName = first;
  lastName = last;
  eMail = eAddress;
};

/** ***********************************************************************
 * @remark check whether first and last name of an Entry match two strings*
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 *                                                                        *
 * @return true if Entry names match first and last name strings          *
 *                                                                        *
 **************************************************************************/
bool Entry::equals (std::string first, std::string second) {
  return ((firstName.compare(first) == 0)
          && (lastName.compare(second) == 0));
};
  
/** ***********************************************************************
 * @remark  check if this object comes before the given first/last names  *
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 *                                                                        *
 * @return true if Entry's first/last names come before parameter names   *
 * in directory order                                                     *
 **************************************************************************/
 bool Entry::equals (Entry otherEntry) {
  // recall compare returns 0 for equal strings
  return ((firstName.compare(otherEntry.firstName) == 0)
          && (lastName.compare(otherEntry.lastName) == 0));
};

/** ***********************************************************************
 * @remark  check if this object comes before the given first/last names  *
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 *                                                                        *
 * @return true if Entry's first/last names come before parameter names   *
 * in directory order                                                     *
 **************************************************************************/
bool Entry::comesBefore (std::string first, std::string second) {
  if (lastName.compare(second) == 0)
    // last names equal, so look at first names
    return (firstName.compare(first) < 0);
  else
    // last names different
    return (lastName.compare(second) < 0);
};

/** ***********************************************************************
 * @remark  check if this object comes before the parameter object        *
 *                                                                        *
 * @param otherEntry  an entry to be compared with this object            *
 *                                                                        *
 * @return true if Entry's first/last names come before parameter's names *
 * in directory order                                                     *
 **************************************************************************/
bool Entry::comesBefore (Entry otherEntry) {
  if (lastName.compare(otherEntry.lastName) == 0)
    // last names equal, so look at first names
    return (firstName.compare(otherEntry.firstName) < 0);
  else
    // last names different
    return (lastName.compare(otherEntry.lastName) < 0);
};

/** ***********************************************************************
 * @remark output a format Entry object                                   *
 *                                                                        *
 * @param os  output stream which will receive the formatted Entry data   *
 *                                                                        *
 * @ewmrk  by being a virtual function, implementations in subclasses     *
 *         will be interpreted via polymorphism                           *
 *                                                                        *
 * @returns formatted string on the given output stream                   *
 *                                                                        *
 * @remark use of a to_string function with a string return type          *
 *         would require allocating space for a long string,              *
 *         yielding a potential memory leak                               *
 *                                                                        *
 **************************************************************************/

std::ostream& Entry::print (std::ostream &os) const {
  os << "\nName:  " << firstName <<  " " << lastName
     << "\n   E-mail Address:  " <<  eMail;
  return os;
};


/** ***********************************************************************
 * @remark overload << for printing an Entry                              *
 *                                                                        *
 * @remark use of the virtual print method allows tailored output         *
 *         by subclasses                                                  *
 *                                                                        *
 **************************************************************************/
std::ostream& operator<< (std::ostream &os, const Entry& ent) {
  return ent.print(os);
};

/** ***********************************************************************
 *  @remark a Default descructor                                          *
 **************************************************************************/
Entry::~Entry () {
  
};

#if$( UNITTEST)=Entry
/** ***********************************************************************
 *  @remark main procedure to control processing                          r
 *  uncomment this procedure for unit testing                             *
 **************************************************************************/
int main ( ) {
  // set up three objects
  Entry A ("Muffin", "Cat", "purr@cats.meow");
  Entry B ("Barbara", "Walker", "barbara@cs.grin.edu");
  Entry C ("Henry", "Walker", "walker@cs.grinnell.edu");
  Entry D ("Terry", "Walker", "walkert@math.grin.edu");
  
  // print objects
  std::cout << "Entries declared in directory orer" << std::endl;
  std::cout <<  "Person A:" << A << std::endl;
  std::cout <<  "Person B:" << B << std::endl;
  std::cout <<  "Person C:" << C << std::endl;
  std::cout <<  "Person D:" << D<< std::endl;
  
  // check comparisons
  // print true for 1, false for 0
  std::cout << std::boolalpha;
  
  std::cout << std::endl;
  std::cout <<  "Results of equals for entries"<< std::endl;
  std::cout <<  "\tA\tB\tC\tD"<< std::endl;
  std::cout <<  "A\t" << A.equals(A) << "\t" << A.equals(B) << "\t" << A.equals(C)
            << "\t" << A.equals(D) << std::endl;
  std::cout <<  "B\t" << B.equals(A) << "\t" << B.equals(B) << "\t" << B.equals(C)
            << "\t"  << B.equals(D) << std::endl;
  std::cout <<  "C\t" << C.equals(A) << "\t" << C.equals(B) << "\t" << C.equals(C)
            << "\t" << C.equals(D) << std::endl;
  std::cout <<  "D\t" << D.equals(A) << "\t" << D.equals(B) << "\t" << D.equals(C)
            << "\t" << D.equals(D) << std::endl;
  
  std::cout << std::endl;
  std::cout <<  "Results of equals for two strings" << std::endl;
  std::cout <<  "\tA\tB\tC\tD" << std::endl;
  std::cout <<  "A\t"
            << A.equals("Muffin", "Cat")  << "\t"
            << A.equals("Barbara", "Walker") << "\t" 
            << A.equals("Henry", "Walker") << "\t"
            << B.equals("Terry", "Walker")
            << std::endl;
  std::cout <<  "B\t"
            << B.equals("Muffin", "Cat") << "\t"
            << B.equals("Barbara", "Walker") << "\t" 
            << B.equals("Henry", "Walker") << "\t"
            << B.equals("Terry", "Walker")
            << std::endl;
  std::cout << "C\t"
            << C.equals("Muffin", "Cat") << "\t"
            << C.equals("Barbara", "Walker") << "\t" 
            << C.equals("Henry", "Walker") << "\t"
            << C.equals("Terry", "Walker") 
            << std::endl;
  std::cout << "D\t"
            << D.equals("Muffin", "Cat") << "\t"
            << D.equals("Barbara", "Walker") << "\t" 
            << D.equals("Henry", "Walker") << "\t"
            << D.equals("Terry", "Walker") 
            << std::endl << std::endl;
  
  std::cout <<  "Results of comesBefore for entries" << std::endl;
  std::cout <<  "\tA\tB\tC\tD" << std::endl;
  std::cout <<  "A\t"
            << A.comesBefore(A) << "\t" << A.comesBefore(B) << "\t"
            << A.comesBefore(C) << "\t" << A.comesBefore(D)
            << std::endl;
  std::cout <<  "B\t"
            << B.comesBefore(A) << "\t" << B.comesBefore(B) << "\t"
            << B.comesBefore(C) << "\t" << C.comesBefore(D)
            << std::endl;
  std::cout <<  "C\t"
            << C.comesBefore(A) << "\t" << C.comesBefore(B) << "\t"
            << C.comesBefore(C) << "\t" << C.comesBefore(D)
            << std::endl;
  std::cout <<  "D\t"
            << D.comesBefore(A) << "\t" << D.comesBefore(B) << "\t"
            << D.comesBefore(C) << "\t" << D.comesBefore(D)
            << std::endl << std::endl;
  
  std::cout <<  "Results of comesBefore for two strings" << std::endl;
  std::cout <<  "\tA\tB\tC\tD" << std::endl;
  std::cout <<  "A\t"
            << A.comesBefore("Muffin", "Cat") << "\t"
            << A.comesBefore("Barbara", "Walker") << "\t"
            << A.comesBefore("Henry", "Walker") << "\t" 
            << A.comesBefore("Terry", "Walker")
            << std::endl;
  std::cout <<  "B\t"
            << B.comesBefore("Muffin", "Cat") << "\t"
            << B.comesBefore("Barbara", "Walker") << "\t"
            << B.comesBefore("Henry", "Walker") << "\t"
            << B.comesBefore("Terry", "Walker")
            << std::endl;
  std::cout <<  "C\t"
            << C.comesBefore("Muffin", "Cat") << "\t"
            << D.comesBefore("Barbara", "Walker") << "\t"
            << C.comesBefore("Henry", "Walker") << "\t"
            << C.comesBefore("Terry", "Walker")
            << std::endl;
  std::cout <<  "D\t"
            << D.comesBefore("Muffin", "Cat") << "\t"
            << D.comesBefore("Barbara", "Walker") << "\t"
            << D.comesBefore("Henry", "Walker") << "\t"
            << D.comesBefore("Terry", "Walker")
            << std::endl;
  
  return 0;
}; // end of testing in main

#endif
