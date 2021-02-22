#include "aegi-opts.h"

AegisubOpts::AegisubOpts(void){
  oOpts = new cxxopts::Options("Aegisub", "Aegisub cli interface");
}

cxxopts::ParseResult AegisubOpts::GetResult(){
  return Result;
}

bool AegisubOpts::isCliEnabled(){
  return (bool)(Result.count("convert") > 0);
}

std::string AegisubOpts::getIn(){
  return Result["in"].as<std::string>();
}

std::string AegisubOpts::getOut(){
  return Result["out"].as<std::string>();
}

void AegisubOpts::init_cli(int argc, char** argv){

  oOpts->add_options()
    // ("b,bar", "Param bar", cxxopts::value<std::string>())
    ("c,convert", "Convert subtitle.x to subtitle.y ", cxxopts::value<bool>()->default_value("false"))
    ("i,in", "Read subtitle.x to convert ", cxxopts::value<std::string>())
    ("o,out", "Write subtitle.x to subtitle.y after convertation ", cxxopts::value<std::string>())
    // ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
    // ("f,foo", "Param foo", cxxopts::value<int>()->default_value("10"))
    ("h,help", "Print usage")
  ;

  Result = oOpts->parse(argc, argv);

  if (Result.count("help"))
  {
    std::cout << oOpts->help() << std::endl;
    exit(0);
  }

  std::cout << std::boolalpha;
  std::cout << " isCliEnabled: " << isCliEnabled() << std::endl;
  if (Result.count("in"))
     std::cout << " getIn: " << getIn() << std::endl;
  if (Result.count("bar"))
     std::cout << " out: " << getOut() << std::endl;


  // bool debug = result["debug"].as<bool>();
  // std::string bar;
  // if (result.count("bar"))
  //   bar = result["bar"].as<std::string>();
  // int foo = result["foo"].as<int>();

}