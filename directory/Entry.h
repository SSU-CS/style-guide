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

#ifndef ENTRY_H
#define ENTRY_H

class Entry {

public:
  // constructors
/** ***********************************************************************
 * @remark Default constructor (with no parameters)                       *
 **************************************************************************/
  Entry () ;

/** ***********************************************************************
 * @remark Full-parameter constructor                                     *
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 * @param eAddress a person's email address                               *
 *                                                                        *
 **************************************************************************/
  Entry (std::string first, std::string last, std::string eAddress) ;

/** ***********************************************************************
 * @remark check whether first and last name of an Entry match two strings*
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 *                                                                        *
 * @return true if Entry names match first and last name strings          *
 *                                                                        *
 **************************************************************************/
  bool equals (std::string first, std::string second) ;
  
/** ***********************************************************************
 *                                                                        *
 * @remark check whether first and last names or two Entries match        *
 *                                                                        *
 * @param otherEntry  an entry to be compared with this object            *
 *                                                                        *
 * @return true if this Entr'sy names match those of the parameter        *
 **************************************************************************/
  bool equals (Entry otherEntry) ;

/** ***********************************************************************
 * @remark  check if this object comes before the given first/last names  *
 *                                                                        *
 * @param first    a person's first name                                  *
 * @param last     a person's last name                                   *
 *                                                                        *
 * @return true if Entry's first/last names come before parameter names   *
 * in directory order                                                     *
 **************************************************************************/
  bool comesBefore (std::string first, std::string second) ;

/** ***********************************************************************
 * @remark  check if this object comes before the parameter object        *
 *                                                                        *
 * @param otherEntry  an entry to be compared with this object            *
 *                                                                        *
 * @return true if Entry's first/last names come before parameter's names *
 * in directory order                                                     *
 **************************************************************************/
  bool comesBefore (Entry otherEntry) ;

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
  virtual
    std::ostream& print (std::ostream &os) const;

/** ***********************************************************************
 * @remark overload << for printing an Entry                              *
 *                                                                        *
 * @remark use of the virtual print method allows tailored output         *
 *         by subclasses                                                  *
 *                                                                        *
 **************************************************************************/
  friend std::ostream& operator<< (std::ostream &os, const Entry& ent) ;

/** ***********************************************************************
 *  @remark a Default destructor                                          *
 *  @remark identify as virtual, since Entry has virtual functions        *
 **************************************************************************/
  virtual
    ~Entry () ;

private:
  // could use "protected" here, so variables may be accessed in subclasses
  std::string firstName;
  std::string lastName;
  std::string eMail;

};

#endif
