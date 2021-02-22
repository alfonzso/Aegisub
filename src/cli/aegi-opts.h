#ifndef AEGIOPTS_H
#define AEGIOPTS_H

#include "cxxopts.hpp"

class AegisubOpts {
  cxxopts::Options *oOpts;
  cxxopts::ParseResult Result;
public:
	AegisubOpts();

  void init_cli(int , char** );
  cxxopts::ParseResult GetResult();
  bool isCliEnabled();

  std::string  getIn();
  std::string  getOut();

};

#endif